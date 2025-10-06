"""
Author: Amelia Bates
Class: CIS 210
Description: Simple Transposition Cipher: the cipher divides the orihinal message into two strings corresponding to its even and odd characters. Those are then concatenated to form the ciphertext
"""
def encrypt(msg:str) -> str:
    """
    Encrypts a string using the transposition cipher
    Args:
        msg(str): orginal message before being encrypted
    Return:
        encrypted_msg(str): returns an encrypted message using the transposition cipher
    Example:
        >>> encrypted = encrypt("It was a dark and stormy night")
        >>> encrypted
        'twsadr n tryngtI a  akadsom ih'
    """
    evenChar = ""
    oddChar = ""
    charCount = 0
    for ch in msg:
        if charCount % 2 == 0:
            evenChar = evenChar + ch
        else:
            oddChar = oddChar + ch
        charCount = charCount + 1
    encrypted_msg = oddChar + evenChar
    return encrypted_msg
def decrypt(msg:str) -> str:
    """
    Decrypts a string using the transposition cipher
    Args:
        msg(str): the encrypted code after using the encrypt(msg) function
    Return:
        plainText(msg): deciphers the encrypted code using the transposition cipher
    Example:
        >>> orginal = decrypt(encrypted)
        >>> orginal
        'It was a dark and stormy night'
    """
    halfLength = len(msg) // 2
    evenChar = msg[halfLength:]
    oddChar = msg[:halfLength]
    plainText = ""

    for i in range(halfLength):
        plainText = plainText + evenChar[i]
        plainText = plainText + oddChar[i]

    if len(oddChar)< len(evenChar):
        plainText = plainText + evenChar[-1]

    return plainText