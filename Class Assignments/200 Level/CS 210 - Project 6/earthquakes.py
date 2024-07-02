# Implement your solutions here. Remember to follow 210 Style and PEP8.
# Do not forget to click SUBMIT -- you can submit multiple times without penalty.
#
# Include doctests whenever appropriate. Feel free to delete these comments.
# To run doctests, at the "Console" below, type: python -m doctest p6.py -v
# (if you get an error that p6 cannot be found, click the round arrow "Reset Instance" button in the Console.)
"""
Author: Amelia Bates
Class: CIS 210
Description: Earthquake data from 2020 and 2021
help: https://www.geeksforgeeks.org/python-convert-list-of-dictionaries-to-dictionary-value-list/
"""
import csv
import matplotlib
import matplotlib.pyplot as plt


def load_data(file_name: str) -> list:
    """
    opens andreads the file whose filename is passed as an argument, creates a list of the data described in the following steps, and returns it. 
    Args:
        file_name(str): csv file that is to be opened and read
    Return:
        dataEQ(list): a dictionary inside a list of the earthquake          information
    """
    dataDict = {}
    dataEQ = []
    with open(file_name, newline='', encoding='utf8') as data:
        for line in csv.DictReader(data):
            dataDict = line
            dataEQ.append(dataDict)
    return dataEQ
        

def get_series(raw_data: list, col_name: str, col_type: type) -> list: 
    """
     takes the list you created in 1 as the first argument, a column name 
(e.g., ‘mag’, ‘gap’, ‘depth’, etc.), and a column type (e.g., int, float, str) and returns a single list of values in that column, converted to that type. 
    Args:
        raw_data(list): the list of dictinaries from the previous function
        col_name(str): the key that is being searched 
        col_type(type):
    Return:
        values(list):
    Example:
        >>> get_series([], '', int)
        []
        >>> get_series([{'key1': 1.2, 'key2': 3.1}, {'key1': 2.1, 'key2': 4.9}], 'key2', float)
        [3.1, 4.9]
    """
    values = []
    for my_dict in raw_data:
        value = my_dict[col_name]
        value_convertion = col_type(value)
        values.append(value_convertion)
    return values


def get_categories(data: list, print_table = True) -> dict:
    """
    Implements a function that will group earthquake magnitudes in light, moderate, major, and strong.
    Args:
        data(list): a data list containing the magnitude of earthquakes in float values
        print_table(boolean): if true will both print the data table and return the dictionary, otherwise will only return the dictionary
    Return:
        strength_dict(dict): a dictionary seperating the data into strong, major, moderate, and light based on the magnitude 
    Example: 
    >>> get_categories([4.5, 5.6, 4.6, 6.5, 6.7, 7.9, 8.6, 4.7, 9.2, 9.6, 7])
    Light : 3
    Moderate : 1
    Major : 2
    Strong : 5
    {'light': 3, 'moderate': 1, 'major': 2, 'strong': 5}
    >>> get_categories([], False) 
    {'light': 0, 'moderate': 0, 'major': 0, 'strong': 0}
    """
    strong = 0
    major = 0
    moderate = 0
    light = 0
    for number in data:
        if number >= 7:
            strong += 1
        elif 6.9 >= number >= 6:
            major += 1
        elif 5.9 >= number >= 5:
            moderate += 1
        elif 4.9 >= number >= 4:
            light += 1
    strength_dict = {'light': light, 'moderate': moderate, 'major': major,   'strong': strong} 
    if print_table:
        print("Light :", light)
        print("Moderate :", moderate) 
        print("Major :",    major)
        print("Strong :", strong)
    return strength_dict 

def plot_bar(x: list, y: list, title: str) -> matplotlib.pyplot.Figure :
    """
    visualize the differences in earthquakes between 2021 and 2020
    Args:
        x(list): the different serverities of earthquakes
        y(list): the diferences between 2021 and 2020
        title(str): the title
    Return:
        fig: the bar graph
    """
    fig = plt.figure()
    ax = fig.add_axes([0,0,1,1])
    ax.bar(x,y)
    plt.title(label = title, 
          fontweight=10, 
          pad='2.0')
    plt.savefig('barplot-{title}.png')
    plt.show(block=False)
    return fig

def plot_scatter(x: list, y: list, title: str) -> matplotlib.pyplot.Figure:
    """
     create a scatterplot with the provided x and y lists (of the same length) and a title for the plot as the third argument. 
     Args:
        x(list): one variable
        y(list): second variable to compare the first
        title(str): The title of the graph
     Return:
        fig: the scatter plot
    """
    fig = plt.figure()
    plt.scatter(x, y)
    plt.title(label = title, 
        fontweight=10, 
        pad='2.0')
    plt.savefig('scatterplot-{title}.png')
    plt.show(block=False)
    return fig

# --- You shouldn't have to change main()

def main():
    """Perform all required steps for this project by calling other functions.
    """
    # Parts 6.1 and 6.2
    # 2020 data
    eq_data = load_data('earthquakes-2020.csv')
    magnitudes = get_series(eq_data, 'mag', float)
    print("2020 Earthquakes:")
    categories20 = get_categories(magnitudes)

    # 2021 data
    eq_data = load_data('earthquakes-2021.csv')
    magnitudes = get_series(eq_data, 'mag', float)
    print("\n2021 Earthquakes:")
    categories21 = get_categories(magnitudes)

    # Part 6.3
    diff21_20 = []
    for key in categories20.keys():
        diff21_20.append(categories21[key] - categories20[key])

    # Part 6.4
    plot_bar(categories21.keys(), diff21_20, '2021 - 2020 Earthquakes')
    
    depths = get_series(eq_data, 'depth', float)
    plot_scatter(depths, magnitudes, '2020 Depth vs Magnitude')


if __name__ == '__main__':
    main()


