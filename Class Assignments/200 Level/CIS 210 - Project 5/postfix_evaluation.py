"""
Author: Amelia Bates
Class: CIS 210
Description: Postfix notation is a mathematical notation in which the operator follows their operand
"""

def is_operand(operand:str)->bool:
    """
    returns true if the operand is a valid operand
    Args:
        operand(str): valid operands are integer number
    Return:
        True(boolean): valid operand
        False(boolean): not a valid operand
    Example:
        >>> is_operand("3")
        True
        >>> is_operand("3.5")
        False
    """
    '''
    errors = 0
    if type(operand) == str:
        x = 0
        for x in operand[:1]:
            if x == '-':
                errors += 0
            elif x == '.':
                errors += 1
            elif x == '1' or x == '2' or x == '3' or x == '4' or x == '5' or x == '6' or x == '7' or x == '8' or x == '9' or x == '0':
                errors += 0
            else:
                errors += 1
        for x in operand[1:]:
            if x == '1' or x == '2' or x == '3' or x == '4' or x == '5' or x == '6' or x == '7' or x == '8' or x == '9' or x == '0':
                errors += 0
            else:
                errors += 1
               
        if errors == 0:
            return True
        elif errors > 0:
            return False
        else:
            print("Error")
        
    else:
        return False
    '''
    if type(operand) == str:
        isInt = True
        try:
            int(operand)
        except ValueError:
            isInt = False
            
        if isInt == True:
            return True
        else:
            return False
    else:
        print("Error")
    
def is_operator(operator:str)->bool:
    """
    checks if the string is an approved operator or not
    Args:
        operator(str): the string should be '+', '-', '*', or '/'
    Return:
        True(boolean): the string is one of the approved operators
        False(boolean): the string isn't one of the approved operators
    Example:
        >>> is_operator('/')
        True
        >>> is_operator('abc')
        False
    """
    if type(operator) == str:
        if operator == '+' or operator == '-' or operator == '*' or operator == '/':
            return True
        else:
            return False
    else:
        return False

def apply_operator(op:str, oper_1:float, 
oper_2:float)->float:
    """
    returns the result of the application of the operator 'op' to the operands 'oper_1' and 'oper_2'
    Args:
        op(str): either '+', '-', '*', or '/'
        oper_1(float): the first operand in the equation
        oper_2(float): the second operand in the equation
    Return:
        total(float): the result of applying the operator to the operands
    Example:
        >>> apply_operator('*', 3, 4)
        12
        >>> apply_operator('/', 2, 4)
        0.5
    """
    if is_operator(op) == True:
        if op == '+':
            total = oper_1 + oper_2
            return total
        elif op == '-':
            total = oper_1 - oper_2
            return total
        elif op == '*':
            total = oper_1 * oper_2
            return total
        elif op == '/':
            total = oper_1 / oper_2
            return total
        else:
            print("Error")
    else:
        print("Error")
def eval_postfix(expr_str:str)->float:
    """
    returns the result of the evaluation of the postfix expression
    Args:
        expr_str(str): the string to be evaluated via the postfix expression
    Return:
        total(float): the sum
        error(str): error on postfix expression
    Example:
        >>> eval_postfix("3 4 + 7")
        7.0
        >>> eval_postfix("3 4 + 7 *")
        49.0
    """
    operandStack = []
    expr_str = expr_str.split()
    for x in expr_str[:]:
        if is_operand(x) == True:
            operandStack.append(x)
        elif is_operator(x) == True:
            if operandStack == []:
                error = 'error on postfix expression'
                return error
            else:
                one = float(operandStack.pop())
            if operandStack == []:
                error = 'error on postfix expression'
                return error
            else:
                two = float(operandStack.pop())
            operandStack.append(apply_operator(x, two, one))
        elif x == ' ':
            pass
        else:
            error = 'error on postfix expression'
            return error
    total = float(operandStack.pop())
    return total
     
        