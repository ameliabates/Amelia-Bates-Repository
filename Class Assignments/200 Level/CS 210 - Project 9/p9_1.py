"""
Author: Amelia Bates
Class: CIS 210
Description: each function takes a str parameter and returns a bool
"""

import re

def validate_social_security_number(social_security: str) -> bool: 
    """Validate social security number, e.g., 123-45-6789 (no spaces)
    Args:
        social_security: social security number to validate
    Returns:
        True if social security is syntactically valid, False otherwise
    Example:
        >>> validate_social_security_number('123-45-6789')
        True
        >>> validate_social_security_number('123-45-678910')
        False
    """
    x = social_security.split('-')
    count = 1
    string1 = ''
    string2 = ''
    string3 = ''
    acceptable_char = '1234567890-'
    if (all(map(str.isdigit, x))) == True:
        if len(x) == 3:
            for string in x:
                if count == 1:
                    string1 += string
                elif count == 2:
                    string2 += string
                elif count == 3:
                    string3 += string
                count +=1     
            if len(string1) == 3 and len(string2) == 2 and len(string3) == 4:
                return True
            else:
                return False   
        else:
            return False
    else:
        return False

def validate_zip(zip: str) -> bool: 
    """Validate zip code (5 digits), e.g, '12345' is valid, '1 23 45' is not.
    Args:
        zip: zip code to validate
    Returns:
        True if zip is syntactically valid, False otherwise
    Example:
        >>> validate_zip('12345')
        True
        >>> validate_zip('12 34 5')
        False
    """
    if (all(map(str.isdigit, zip))) == True:
        if len(zip) == 5:
            return True
        else:
            return False
    else:
        return False

def validate_zip_plus(zip_plus: str) -> bool:
    """Validate zip plus code, five digits followed by a dash and four more digits, 
        e.g., 41243-1234 (no spaces).
    Args:
        zip_plus: zip plus code to validate
    Returns:
        True if zip plus is syntactically valid, False otherwise
    Example:
        >>> validate_zip_plus('41243-1234')
        True
        >>> validate_zip_plus('412435-12345')
        False
    """
    x = zip_plus.split('-')
    if len(x) == 2:
        if validate_zip(x[0]) == True:
            if (all(map(str.isdigit, x[1]))) == True:
                if len(x[1]) == 4:
                    return True
                else:
                    return False
            else:
                return False
        else:
            return False
    else: 
        return False

def validate_phone(phone: str) -> bool:
    """Validate phone number, e.g., 123-456-7890 or (123)456-7890 or 123.456.7890
    Args:
        phone: phone number to validate
    Returns:
        True if phone is syntactically valid, False otherwise

    Examples:
        The following are examples of valid phone numbers:
            (123) 456-7890
            (123)456-7890
            123-456-7890
            123.456.7890
        The following are examples of invalid phone numbers:
            (123)4567890
            456-7890
            123 456-7890
        >>> validate_phone('(123) 456-7890')
        True
        >>> validate_phone('(123)4567890')
        False
    """
    phone = phone.replace(' ', '')
    x = re.split('[())-.]', phone)
    if '' in x:
        x.remove('')
    if (all(map(str.isdigit, x ))) == True:
        if len(x) == 3:
            if len(x[0]) == 3 and len(x[1]) == 3 and len(x[2]) == 4:
                return True
            else:
                return False
        else:
            return False
    else:
        return False

def validate_email(email: str) -> bool:
    """Validate email address, e.g., myname212@thing1.thing2.com (case-insensitive).
    Args:
        email: email address to validate
    Returns:
        True if email is syntactically valid, False otherwise
    Examples:
        The following are examples of valid email addresses:
            bnorris2@uoregon.edu
            norris@cs.uoregon.edu
            yippee_skippy@yee-haw.wheeeee
            fun-times@Deschutes.hall.uoregon.edu
        The following are examples of invalid email addresses:
            b@norris2@uoregon.edu
            b norris@uoregon.edu
            bnorris2@uoregon..edu
            norris@uoregon.edu-org
        >>> validate_email('bnorris2@uoregon.edu')
        True
        >>> validate_email('b@norris2@uoregon.edu')
        False
    """
    count = email.count('@')
    count_period = email.count('.')
    if count_period >= 1:
        if count == 1:
            if ' ' not in email:
                x = re.split('[@.]', email)
                if '' not in x:
                    if '-' not in x[-1]:
                        return True
                    else:
                        return False
                else:
                    return False
            else:
                return False
        else:
            return False
    else:
        return False

def main():
    """Use this main to do your own function calls and other testing, it will not be used in 
    grading."""


# --- You shouldn't need to change final_main ----
def final_main():
    """Run all the functions in this file."""
    for what in ['social_security_number', 'zip', 'zip_plus', 'email', 'phone']:
        func = globals()['validate_' + what]  # the function to call
        user_input = input(f"Please enter {what}: ")
        if func(user_input):   # call the function
            print(f"{user_input} is a valid {' '.join(what.split('_'))}.")
        else:
            print(f"{user_input} is NOT a valid {' '.join(what.split('_'))}.")


if __name__ == '__main__':
    main()
    final_main()  # uncomment if you want to call all functions in this file
