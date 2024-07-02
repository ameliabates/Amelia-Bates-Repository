#CIS 122 Fall 2021 assignment 7
#Author: Amelia Bates
#Partner:
#Discription: simple list manager

list = []
t1 = []
def cmd_help():
    print("*** Available commands ***")
    command_names = [ "Add", "Delete", "List", "Clear"]
    command_description = ["Add to list", "Delete information", "List information", "Clear list"]
    get_max_list_item_size(command_names)
    label_spacing = get_max_list_item_size(command_names)
    num_spacing = get_max_list_item_size(command_names)   
    for line in range(len(command_names)):
        print(pad_right(command_names[line], label_spacing + 5),command_description[line])
        line += 1
    print("Empty to exit")
def cmd_add(t):
    while True:
        t = (input("Enter information (empty to stop): "))
        if t == "":
            break
        else:
            t1.append(t)
            print("Added, item count =", len(t1))
    return t1  
def cmd_delete(t):
    length = 0
    list_object = 0
    for line in range(len(t1)):
        print(pad_right(length, 2), t1[list_object])
        list_object += 1
        length += 1
    while True:
        del_t = input("Enter number to delete (empty to stop): ")
        del_t.strip()
        if del_t == "":
            break
        if del_t.isdigit() == True:
            if int(del_t) < int(len(t1)):
                length = 0
                list_object = 0
                del_t = int(del_t)
                del t1[del_t]
                for line in range(len(t1)):
                    print(pad_right(length, 2), t1[list_object])
                    list_object += 1
                    length += 1
            elif len(t1) == 0:
                    print("All items deleted")
            else:
                print("Error must be in range")
        
        else:
            print("Error must be digit")

def cmd_list(t):
    object = 0
    print("List contains", len(t1), "item(s)")
    for line in range(len(t1)):
       print(t1[object])
       object += 1

def cmd_clear(t):
    print(len(t1), "item(s) removed, list empty")
    t1.clear()

def get_max_list_item_size(t):
    max_size = 0
    for item in t:
        if len(item) > max_size:
            max_size = len(item)

    return max_size

def pad_string(data, size, dir = 'L', chr = ' '):
   data = str(data)
   if len(data) > size:
      return data
   elif dir.upper() == 'L':
      return chr * (size - len(data)) + data
   else:
      return data + chr * (size - len(data))

def pad_left(data, size, chr = ' '):
   return pad_string(data, size, 'L', chr)

def pad_right(data, size, chr = ' '):
   return pad_string(data, size, 'R', chr)


while True:
    command = input("Enter a command (? for help): ")
    
    if command == '':
        break
    if command == '?':
        cmd_help()
    if command == "add":
        cmd_add(0)
    if command == "list":
        cmd_list(0)
    if command == "del":
        cmd_delete(0)              
    if command == "clear":
        cmd_clear(0)
