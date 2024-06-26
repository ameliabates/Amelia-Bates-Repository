import pandas as pd

# Prompt user for input csv file names
register_file_name = input("Enter the filename for register file (e.g., vend-register-closures-24847.csv): ").strip()
chase_file_name = input("Enter the filename for chase file (e.g., Chase2761_Activity_20240219.csv): ").strip()

# Read register file and format 'Opened' column
registerFile = pd.read_csv(register_file_name, header=0, usecols=["Opened", "Cash Posted"])
registerFile['Opened'] = pd.to_datetime(registerFile['Opened'], utc=True)
registerFile['Date'] = registerFile['Opened'].dt.strftime('%m/%d/%Y')

# Save formatted register file
registerFile.to_csv('formatted_vend_register_closures.csv', index=False)

# Read chase file and rename 'Posting Date' column to 'Date'
chaseFile = pd.read_csv(chase_file_name, header=0, usecols=["Posting Date", "Amount"])
chaseFile.rename(columns={"Posting Date": "Date"}, inplace=True)

# Save chase file with renamed column
chaseFile.to_csv("Combined_Amounts.csv", index=False)

# Convert 'Date' columns to datetime objects in order to compare
registerFile['Date'] = pd.to_datetime(registerFile['Date'], format='%m/%d/%Y')
chaseFile['Date'] = pd.to_datetime(chaseFile['Date'], format='%m/%d/%Y')

# Find matches where 'Cash Posted' equals 'Amount' and date in chaseFile is equal to or greater than date in registerFile
matches = pd.merge(registerFile, chaseFile, left_on='Cash Posted', right_on='Amount', how='inner')
matches = matches[matches['Date_y'] >= matches['Date_x']]
matches.to_csv('amount_matches.csv', index=False)
matches[['Date_x', 'Cash Posted', 'Date_y', 'Amount']].to_csv('amount_matches.csv', index=False)
print("Matches saved to amount_matches.csv.")

# Find discrepancies
merged_df = pd.merge(registerFile, chaseFile, left_on='Cash Posted', right_on='Amount', how='left', indicator=True)
not_matched_df = merged_df[merged_df['_merge'] == 'left_only']
not_matched_df = not_matched_df[['Date_x', 'Cash Posted']]
not_matched_df.to_csv('discrepancies.csv', index=False)

print("Amount discrepancies saved to discrepancies.csv.")


"""
import pandas

registerFile = pandas.read_csv('vend-register-closures-24847.csv', header=0, usecols=["Opened", "Cash Posted"])
registerFile['Opened'] = pandas.to_datetime(registerFile['Opened'], utc=True)
registerFile['Opened'] = registerFile['Opened'].dt.strftime('%m/%d/%Y')

registerFile.to_csv('formatted_vend_register_closures.csv', index=False)

chaseFile = pandas.read_csv("Chase2761_Activity_20240219.csv", header=0, usecols=["Posting Date", "Amount"])


chaseFile.to_csv("Combined_Amounts.csv", index=False)

chaseFile.rename(columns={"Posting Date": "Date"}, inplace=True)
registerFile.rename(columns={"Opened": "Date"}, inplace=True)

chaseFile['Date'] = pandas.to_datetime(chaseFile['Date'], utc=True)
chaseFile['Date'] = chaseFile['Date'].dt.strftime('%m/%d/%Y')

registerFile.to_csv('formatted_vend_register_closures.csv', index=False)
chaseFile.to_csv("Combined_Amounts.csv", index=False)


registerFile['Date'] = pandas.to_datetime(registerFile['Date'], format='%m/%d/%Y')
chaseFile['Date'] = pandas.to_datetime(chaseFile['Date'], format='%m/%d/%Y')

matches = pandas.merge(registerFile, chaseFile, left_on='Cash Posted', right_on='Amount', how='inner')
matches = matches[matches['Date_y'] >= matches['Date_x']]
matches.to_csv('amount_matches.csv', index=False)


merged_df = pandas.merge(registerFile, chaseFile, left_on='Cash Posted', right_on='Amount', how='left', indicator=True)
not_matched_df = merged_df[merged_df['_merge'] == 'left_only']


not_matched_df = not_matched_df[['Date_x', 'Cash Posted']]

not_matched_df.to_csv('discrepancies.csv', index=False)
"""