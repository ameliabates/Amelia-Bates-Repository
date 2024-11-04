from flask import Flask, render_template, request, redirect, url_for, send_file
import pandas as pd
import os

app = Flask(__name__)
app.config['UPLOAD_FOLDER'] = 'uploads'
app.config['PROCESSED_FOLDER'] = 'processed'

# check if directories exist
os.makedirs(app.config['UPLOAD_FOLDER'], exist_ok=True)
os.makedirs(app.config['PROCESSED_FOLDER'], exist_ok=True)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/upload', methods=['POST'])
def upload_files():
    register_file = request.files.get('register_file')
    chase_file = request.files.get('chase_file')

    if not register_file or not chase_file:
        return "Please upload both files", 400

    register_path = os.path.join(app.config['UPLOAD_FOLDER'], register_file.filename)
    chase_path = os.path.join(app.config['UPLOAD_FOLDER'], chase_file.filename)

    # Save files
    register_file.save(register_path)
    chase_file.save(chase_path)

    # Read register file
    register_df = pd.read_csv(register_path, usecols=["Opened", "Cash Posted"])

    # Convert 'Opened' to datetime, handling non-date entries
    register_df['Opened'] = pd.to_datetime(register_df['Opened'], errors='coerce', utc=True)
    register_df.dropna(subset=['Opened'], inplace=True)  # Remove rows with invalid dates
    register_df['Date'] = register_df['Opened'].dt.strftime('%m/%d/%Y')
    formatted_register_path = os.path.join(app.config['PROCESSED_FOLDER'], 'formatted_vend_register_closures.csv')
    register_df.to_csv(formatted_register_path, index=False)

    # Read and process chase file
    chase_df = pd.read_csv(chase_path, usecols=["Posting Date", "Amount"])
    chase_df.rename(columns={"Posting Date": "Date"}, inplace=True)

    # Convert 'Date' to datetime, handling non-date entries
    chase_df['Date'] = pd.to_datetime(chase_df['Date'], errors='coerce', format='%m/%d/%Y')
    chase_df.dropna(subset=['Date'], inplace=True)  # Remove rows with invalid dates
    combined_amounts_path = os.path.join(app.config['PROCESSED_FOLDER'], "Combined_Amounts.csv")
    chase_df.to_csv(combined_amounts_path, index=False)

    # Find matches
    matches = pd.merge(register_df, chase_df, left_on='Cash Posted', right_on='Amount', how='inner')
    matches = matches[matches['Date_y'] >= matches['Date_x']]
    matches_path = os.path.join(app.config['PROCESSED_FOLDER'], 'amount_matches.csv')
    matches[['Date_x', 'Cash Posted', 'Date_y', 'Amount']].to_csv(matches_path, index=False)

    # Find discrepancies
    merged_df = pd.merge(register_df, chase_df, left_on='Cash Posted', right_on='Amount', how='left', indicator=True)
    not_matched_df = merged_df[merged_df['_merge'] == 'left_only'][['Date_x', 'Cash Posted']]
    discrepancies_path = os.path.join(app.config['PROCESSED_FOLDER'], 'discrepancies.csv')
    not_matched_df.to_csv(discrepancies_path, index=False)

    return redirect(url_for('index', files_processed=True))

@app.route('/download/<filename>')
def download_file(filename):
    path = os.path.join(app.config['PROCESSED_FOLDER'], filename)
    return send_file(path, as_attachment=True)

if __name__ == '__main__':
    app.run(debug=True)
