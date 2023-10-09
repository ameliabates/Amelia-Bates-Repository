#CIS 122 Fall 2021 lab 7
#Author: Amelia Bates
#Partner:
#Discription: prompt the user for input, exit if nothing entered, or search through the list of words to determine if the word is found
Enter = True
#Loop until nothing entered
while True:
    #Prompt for input
    word = input("Enter a search word (blank to exit): ")
    word = word.strip() #Remove leading/trailing
    if len(word) == 0:
        #Exit if nothing entered
        break
    else:
        #Perform search
        print(word)
        #Open file
        fin = open("words_alpha.txt") #Open file
        #Search for word by looping over file
        #Intitialize default search results to False
        word_found = False
        for line in fin:
            #Remove file line leading/trailing white space and line endings
            line = line.strip()
            #Test for match changing to same case
            if word.upper() == line.upper():
                #Set result status and exit loop
                word_found = True
                break
            
    #Close file
    fin.close()
    #Print results
    if word_found == True:
        print("Word " + word + " found")
    else:
        print("Word " + word + " not found")
