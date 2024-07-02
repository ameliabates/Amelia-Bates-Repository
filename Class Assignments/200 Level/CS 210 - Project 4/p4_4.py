"""
Author: Amelia Bates
Class: CIS 210
Description: call the 3 different ciphers
"""
import p4_1
import p4_2
import p4_3
def crypt(msg, cipher) -> str:
    """
    Call the 3 different ciphers and return the encrypted/decrypted message
    Args:
        msg(string): the string that is to be encrypted/decrypted
        cipher(function): the cipher method the user wishes to use
    Return:
        cipher(msg)(str): returns the encrypted/decrypted message
    Example:
        >>> crypt("Ahoy, there!", p4_3.encrypt)
        'nubl, gurer!'
        >>> crypt("Nubl, gurer!", p4_3.decrypt)
        'ahoy, there!'
    """
    return cipher(msg)