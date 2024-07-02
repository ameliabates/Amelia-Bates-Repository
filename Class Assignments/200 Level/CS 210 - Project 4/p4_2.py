"""
Author: Amelia Bates
Class: CIS 210
Description: Implement a transposition cipher that seperates into three sets of characters
"""
def encrypt(msg:str)->str:
    """
    Encypts a string using the railroad method
    Args:
        msg(str): the string that is to be encrypted
    Return:
        encrypted(str): the encrypted string
    Example:
        >>> encrypt("There is no reason anyone would want a computer in their home.")
        'Trinrs yeoda cpeitihehesoeoao u naournhro.e   annnwlwt mt  e m'
        >>> encrypt("Hello there!")
        'Hltreohel e!'
    """
    rail_1 = ""
    rail_2 = ""
    rail_3 = ""

    i = 0
    for i in range(len(msg)):
        if i % 3 == 0:
            rail_1 += msg[i]
            i += 1
        elif i % 3 == 1:
            rail_2 += msg[i]
            i += 1
        elif i % 3 == 2:
            rail_3 += msg[i]
            i += 1
    encrypted = rail_1 + rail_2 + rail_3
    return encrypted
    
import math
def decrypt(msg:str)->str:
    """
    Decrypts an encrypted message using the railroad method
    Args:
        msg(str): The encrypted message that is to be decrypted
    Return:
        decrypted(str): the decrypted message from the orginal message
    Example:
    """
    decrypted = ''
    total_1 = math.ceil(len(msg) / 3)
    rail_1 = msg[0:total_1]
    rail_2 = msg[total_1: total_1 * 2]
    rail_3 = msg[total_1 * 2: ]
    '''
    print(total_1)
    print(rail_1, rail_2, rail_3)
    '''
    if len(msg) % 3 != 0:
        total_1 -= 1
    
    for i in range(total_1):
        decrypted += rail_1[i]
        decrypted += rail_2[i]
        decrypted += rail_3[i]
        if len(msg) % 3 == 1:
            decrypted += rail_1[i+1]
        elif len(msg) % 3 == 2:
            decrypted += rail_1[i+1]
            decrypted += rail_2[i+1]

    
  
    return decrypted
