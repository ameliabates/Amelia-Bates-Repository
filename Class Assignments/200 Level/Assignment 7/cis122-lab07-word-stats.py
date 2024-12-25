#CIS 122 Fall 2021 lab 7
#Author: Amelia Bates
#Partner:
#Discription: prompt the user for input, exit if nothing entered, or search through the list of words to determine if the word is found

count = 0
palindrome = 0
fin = open("words_alpha.txt")
count_a = 0
count_b = 0
count_c = 0
count_d = 0
count_e = 0
count_f = 0
count_g = 0
count_h = 0
count_i = 0
count_j = 0
count_k = 0
count_l = 0
count_m = 0
count_n = 0
count_o = 0
count_p = 0
count_q = 0
count_r = 0
count_s = 0
count_t = 0
count_u = 0
count_v = 0
count_w = 0
count_x = 0
count_y = 0
count_z = 0
count_other = 0

for line in fin:
    longest = 0
    for word in line:   
        if len(word) > longest:
            longest = len(word)
            longest_word = word

    shortest = 99999999999
    for word in line:
        if len(word) < shortest:
            shortest = len(word)
            shortest_word = word
     
    for line in fin:
        strs = line.strip('\n')
        if strs[0] == 'a':
            count_a += 1
        elif strs[0] == 'b':
            count_b += 1
        elif strs[0] == 'c':
            count_c += 1
        elif strs[0] == 'd':
            count_d += 1
        elif strs[0] == 'e':
            count_e += 1
        elif strs[0] == 'f':
            count_f += 1
        elif strs[0] == 'g':
            count_g += 1
        elif strs[0] == 'h':
            count_h += 1
        elif strs[0] == 'i':
            count_i += 1
        elif strs[0] == 'j':
            count_j += 1
        elif strs[0] == 'k':
            count_k += 1
        elif strs[0] == 'l':
            count_l += 1
        elif strs[0] == 'm':
            count_m += 1
        elif strs[0] == 'n':
            count_n += 1
        elif strs[0] == 'o':
            count_o += 1
        elif strs[0] == 'p':
            count_p += 1
        elif strs[0] == 'q':
            count_q += 1
        elif strs[0] == 'r':
            count_r += 1
        elif strs[0] == 's':
            count_s += 1
        elif strs[0] == 't':
            count_t += 1
        elif strs[0] == 'u':
            count_u += 1
        elif strs[0] == 'v':
            count_v += 1
        elif strs[0] == 'w':
            count_w += 1
        elif strs[0] == 'x':
            count_x += 1
        elif strs[0] == 'y':
            count_y += 1
        elif strs[0] == 'z':
            count_z += 1
        else:
            count_other += 1
        count += 1
        if line == line[::-1]:
            palindrome += 1
             
print("Count:", count)
print("Palindromes:", palindrome, "(" , round(palindrome/count, 2), "%)" )
print("Longest word is", longest_word, "(", longest, ")")
print("Shortest word is", shortest_word, "(", shortest, ")")
print("A:", count_a, "(", round(100 * (count_a / count), 2), "%)")
print("B:", count_b, "(", round(100 * (count_b / count), 2), "%)")
print("C:", count_c, "(", round(100 * (count_c / count), 2), "%)")
print("D:", count_d, "(", round(100 * (count_d / count), 2), "%)")
print("E:", count_e, "(", round(100 * (count_e / count), 2), "%)")
print("F:", count_f, "(", round(100 * (count_f / count), 2), "%)")
print("G:", count_g, "(", round(100 * (count_g / count), 2), "%)")
print("H:", count_h, "(", round(100 * (count_h / count), 2), "%)")
print("I:", count_i, "(", round(100 * (count_i / count), 2), "%)")
print("J:", count_j, "(", round(100 * (count_j / count), 2), "%)")
print("K:", count_k, "(", round(100 * (count_k / count), 2), "%)")
print("L:", count_l, "(", round(100 * (count_l / count), 2), "%)")
print("M:", count_m, "(", round(100 * (count_m / count), 2), "%)")
print("N:", count_n, "(", round(100 * (count_n / count), 2), "%)")
print("O:", count_o, "(", round(100 * (count_o / count), 2), "%)")
print("P:", count_p, "(", round(100 * (count_p / count), 2), "%)")
print("Q:", count_q, "(", round(100 * (count_q / count), 2), "%)")
print("R:", count_r, "(", round(100 * (count_r / count), 2), "%)")
print("S:", count_s, "(", round(100 * (count_s / count), 2), "%)")
print("T:", count_t, "(", round(100 * (count_t / count), 2), "%)")
print("U:", count_u, "(", round(100 * (count_u / count), 2), "%)")
print("V:", count_v, "(", round(100 * (count_v / count), 2), "%)")
print("W:", count_w, "(", round(100 * (count_w / count), 2), "%)")
print("X:", count_x, "(", round(100 * (count_x / count), 2), "%)")
print("Y:", count_y, "(", round(100 * (count_y / count), 2), "%)")
print("Z:", count_z, "(", round(100 * (count_z / count), 2), "%)")
print("Other:", count_other, "(", round(100 * (count_other / count), 2), "%)")
    
