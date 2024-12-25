#CIS 122 Fall 2021 lab 8
#Author: Amelia Bates
#Partner:
#Discription: lists

import random

def gen_random_integer_list(num, start_range = 1, end_range = 100, sort_list = 'N'):
    '''the number must be greater than 0, a number, and the start and end points must be intergers.
    '''
    t = []
    if num <= 0:
        print('num must be > 0')
    elif not isinstance(num, int):
        print('num must be an integer')
    elif not isinstance(start_range, int) or not isinstance(end_range, int):
        print('start_range and end_range must be integers')
    else:
        for i in range(num):
            r = random.randint(start_range, end_range)
            t.append(r)

        if sort_list.upper() == 'Y':
            t.sort()

    return t


t = gen_random_integer_list(100)

def get_high_score(t):
    if not isinstance(t,list):
        print("List argument expected")
        return -1
    elif len(t) == 0:
        return 0
    else:
       copy_test_scores = t[::]
       copy_test_scores.sort()
       return copy_test_scores[-1]
    
def get_low_score(t):
    if not isinstance(t,list):
        print("List argument expected")
        return -1
    elif len(t) == 0:
        return 0
    else:
       copy_test_scores = t[::]
       copy_test_scores.sort()
       return copy_test_scores[0]

def get_mean_score(t):
    if not isinstance(t,list):
        print("List argument expected")
        return -1
    elif len(t) == 0:
        return 0
    else:
        total_test_scores = (sum(t))/(len(t))
        return total_test_scores

def get_median_score(t):
    if not isinstance(t,list):
        print("List argument expected")
        return -1
    elif len(t) == 0:
        return 0
    elif len(t) == 1:
        return t[0]
    else:
        copy_test_scores = t[::]
        copy_test_scores.sort()
        n = len(copy_test_scores)
        if len(copy_test_scores)%2:
            return copy_test_scores[n//2]
        else:
            return(copy_test_scores[n//2-1]+copy_test_scores[n//2])/2

def count_range(t,start,end):
    if not isinstance(t,list):
        print("List argument expected")
        return -1
    elif not isinstance (start,int):
        print("start and end must be integers")
        return -1
    elif not isinstance (end,int):
        print("start and end must be integers")
        return -1
    elif start > end:
        print("start must be < end")
        return -1
    elif start == end:
        print("start must be < end")
        return -1
    elif len(t) == 0:
        return 0
    num = 0
    for score in t:
        if start<=score<=end:
            num += 1
    return num

    
def list_range(t):
    print("A -",count_range(t, 90, 100))
    print("B -",count_range(t, 80, 89))
    print("C -",count_range(t, 60, 79))
    print("D -",count_range(t, 50, 69))
    print("F -",count_range(t, 0, 59))
