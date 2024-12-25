"""
Project 10 solution
Author: Amelia Bates
Date: 3/13/22
"""

def count_smaller(lst: list, item: int) -> int:
    """
    counts how many values in the list lst are smaller than item using recursion
    ARGS:
        lst(list): a list of values 
        item(int): an integer that is to be compared to each value in lst
    Return:
        length(int): the length of the remaining values in lst that are smaller than item 
    Example:
        >>> count_smaller([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 5) 
            4
        >>> count_smaller([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 1) 
            0
    """
    if lst[0] == item:
        return 0

    elif len(lst) > 1:
        if lst[-1] >= item:
            lst.pop(-1)
            count_smaller(lst, item)
    
        length = len(lst)
        return length
        
    else:
        return None

def is_palindrome(s: str) -> bool:
    '''
    determines if a string is a palindrome(same backwards and forwards) or not using recursion
    ARGS:
        s(str): the string that is being checked to see if palindrome 
    Return:
        boolean: True if string is palindrome, False is string is not palindrome
    Example:
        >>> is_palindrome('racecar') 
        True 
        >>> is_palindrome('racecars') 
        False   
    '''
    if len(s) < 2:
        return True

    elif s[0] != s[-1]:
        return False

    palindrome = is_palindrome(s[1:-1])
    return palindrome

def avg_word_length(lst: list, length: int = 0, count: int = 0) -> float:
    """
    returns the average length of each word in a list
    Args:
        lst(list): a list of strings
    Return: 
        float: the total length divided by the amount of strings, which is the average length of the strings in the list
    Example:
        >>> avg_word_length(['hello', 'world'])
        5.0
        >>> avg_word_length(['hello', 'world', 'meh'])
        4.3
    """
    '''
    for i in lst:
        length += len(i)
    if length >= 1:
        return length / len(lst)
    else:
        return 0
    '''
    if len(lst) == 0:
        return round(length / count, 1)

    word = lst[0]
    new_lst = lst[1:]

    length += len(word)
    count += 1
    
    return avg_word_length(new_lst, length, count)
    
    
    '''
    return round(sum(map(len, lst))/len(lst), 1)
    '''
    
def flatten(a_list:list) -> list:
    """
    flattens a list of lists into a single list
    Args:
        a_list(list): a list that will be flattened
    Return:
        the flattened list
    Example:
        >>> flatten([1, 2, 3]) 
        [1, 2, 3]
        >>> flatten([1, [2, 3], 4])
        [1, 2, 3, 4]
        >>> flatten([1, [2, [3, 4, [5], 6], 7], 8]) 
        [1, 2, 3, 4, 5, 6, 7, 8]
    """
    if len(a_list) == 0:
        return a_list

    if isinstance(a_list[0], list):
        return flatten(a_list[0]) + flatten(a_list[1:])

    return a_list[:1] + flatten(a_list[1:])