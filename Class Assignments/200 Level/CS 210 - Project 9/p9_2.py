# Replace with your implementation of a universal rail decryption, 
# you must have a main() function as described in the prompt, all 
# other functions are at your discretion.
def railDecryption(cipher, num_rails):
    """
    Decrypts an already encrypted cipher when given the number of rails used to encryoted it
    Args:
        cipher(string): The encrypted message
        num_rails(int): The number of rails used to encrypt
    Returns:
        answer(str): The decrypted message
    """
    strings = ''
    railLen = len(cipher) // num_rails
    solution = ''
    for i in range(railLen):
        for rail in range(num_rails):
            nextLetter = i + (rail * railLen)
            solution += cipher[nextLetter]
    x= solution.split()
    for string in x:
        strings += string + ' '
    answer = strings.replace('_', '')
    return answer

if __name__ == '__main__':
    text = input("Enter a message to decrypt: ")
    num_rails = int(input("Enter the number of rails: "))
    print(railDecryption(text, num_rails))