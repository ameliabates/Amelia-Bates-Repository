#CIS 122 Fall 2021 lab 8
#Author: Amelia Bates
#Partner:
#Discription: Tuples

def number_stats(*args, ):
    copy_test_scores = args[::]
    n = len(copy_test_scores)
    if len(copy_test_scores)%2:
        median = copy_test_scores[n//2]
    else:
        median = (copy_test_scores[n//2-1]+copy_test_scores[n//2])/2
    a = len(args), args[0], args [-1], (sum(args))/(len(args)), median
    print("Count:",a[0])
    print("Min:", a[1])
    print("Max:",a[2])
    print("Mean:",a[3])
    print("Median:",a[4])

args = 10,20,30,40
number_stats(*args)
