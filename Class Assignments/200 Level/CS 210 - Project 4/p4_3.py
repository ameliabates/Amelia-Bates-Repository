"""
Author: Amelia Bates
Class: CIS 210
Help: https://www.geeksforgeeks.org/rot13-cipher/
Description: Implement a ROT13 simple replacement cipher
"""
alphabet = {'a': 1, 'b': 2, 'c': 3, 'd':4, 'e': 5, 'f': 6, 'g': 7, 'h': 8, 'i': 9, 'j': 10, 'k': 11, 'l': 12, 'm': 13
            , 'n': 14, 'o': 15, 'p': 16, 'q': 17, 'r': 18, 's': 19, 't': 20, 'u': 21, 'v': 22, 'w': 23, 'x': 24, 'y': 25, 'z': 26}
dictCipher = {0: 'z', 1: 'a', 2: 'b', 3: 'c', 4: 'd', 5: 'e', 6: 'f', 7: 'g', 8: 'h', 9: 'i', 10: 'j', 11: 'k', 12: 'l',
         13: 'm', 14: 'n', 15: 'o', 16: 'p', 17: 'q', 18: 'r', 19: 's', 20: 't', 21: 'u', 22: 'v', 23: 'w', 24: 'x', 25: 'y'}
def encrypt(msg:str)->str:
    """
    Uses the ROT13 method to encrypt a string
    Args:
        msg(str): the string that will be encrypted using the ROT13 methos
    Return:
        cipher(str): returns the encrypted string of the orginal message
    Example:
        >>> encrypt("Two driven jocks help fax my big quix")
        'gjb qevira wbpxf uryc snk zl ovt dhvk'
        >>> encrypt("Hello! My name is Amelia Bates")
        'uryyb! zl anzr vf nzryvn ongrf'
    """
    cipher = ''
    msg = msg.lower()
    for letter in msg:
        if letter != ' ' and letter != '.' and letter != '!' and letter != ',':
            num = (alphabet[letter] + 13) % 26
            cipher += dictCipher[num]
        elif letter == ' ' or letter == '.' or letter == '!' or letter == ',':
            if letter == ' ':
                cipher += ' '
            elif letter == ',':
                cipher += ','
            elif letter == '.':
                cipher += '.'
            elif letter == '!':
                cipher += '!'
        else:
            print("ERROR: do not recognize letter")
    return cipher
def decrypt(msg:str)->str:
    """
    decypher the encrypted message using ROT13 method
    Args:
        msg(str): the encrypted message that was returned from the function encrypt(msg)
    Return:
        decipher(str): the deciphered message
    Example:
        >>> encrypted = encrypt("Two driven jock help fax my big test")
        >>> encrypted
        'gjb qevira wbpx uryc snk zl ovt grfg'
        >>> orginal = decrypt(encrypted)
        >>> orginal
        'two driven jock help fax my big test'

        >>> encrypted = encrypt("Hello! My name is Amelia Bates.")
        >>> encrypted
        'uryyb! zl anzr vf nzryvn ongrf.'
        >>> orginal = decrypt(encrypted)
        >>> orginal
        'hello! my name is amelia bates.'
    """
    msg = msg.lower()
    decipher = ''
    for letter in msg:
        if letter != ' ' and letter != '.' and letter != '!' and letter != ',':
            num = ((alphabet[letter] - 13 + 26) % 26)
            decipher += dictCipher[num]
        elif letter == ' ' or letter == '.' or letter == '!' or letter == ',':
            if letter == ' ':
                decipher += ' '
            elif letter == ',':
                decipher += ','
            elif letter == '.':
                decipher += '.'
            elif letter == '!':
                decipher += '!'
        else:
            print("ERROR: do not recognize letter")
            
    return decipher

