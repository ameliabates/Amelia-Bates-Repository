"""File: rail_encrypt.py
(optional Project 9.2)
A universal rail fence encryption algorithm with padding to make the message 
a multiple of the number of rails.

Author: Boyana Norris
Date: November 15, 2021
"""
import math

def rail_encrypt(message: str, num_rails: int) -> str:
    """
    Encrypts a message using rail fence cipher. The message will be padded with 
    underscores (_) to make it a multiple of the number of rails.

    Args:
        message: message to be encrypted
        rails: number of rails

    Returns:
        str: encrypted message, length is a multiple of num_rails
    """
    # Create a list of rail_num rails
    rails = ['' for x in range(num_rails)]

    # If the message length is not divisible by the number of rails, pad
    padding = len(message) % num_rails
    if padding != 0:
        message += '_' * (num_rails - padding)

    # Encrypt the message
    char_index = 0
    while char_index < len(message):
        for rail_index in range(num_rails):
            if char_index < len(message):
                rails[rail_index] += message[char_index]
                char_index += 1

    # Concatenate the rails
    encrypted_message = ''.join(rails)
    return encrypted_message


if __name__ == '__main__':
    text = input("Enter a message to encrypt: ")
    num_rails = int(input("Enter the number of rails: "))
    print(rail_encrypt(text, num_rails))
