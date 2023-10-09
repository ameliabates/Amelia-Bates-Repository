#CIS 122 Fall 2021 assignment 8
#Author: Amelia Bates
#Partner:
#Discription: diction manager
diction = {}

def create_group(d):
    while True:
        group_name_list = []
        group_name = input("Enter group name (empty to cancel): ")
        if group_name in diction:
            print("Group name already exists")
            continue
        
        elif group_name == "":
            break

        else:
            group_name_list += [group_name]
            diction[group_name] = {}
            diction[group_name]["_keys_"] = []
            diction[group_name]["_data_"] = []

            while True:
                field_name = input("Enter field name (empty to stop): ")
                if field_name == "":
                    break
                else:
                    diction[group_name]["_keys_"].append(field_name)
                    continue
def list_groups(d):
    print("*** List of groups ***")
    for items in list(diction):
         print(items,":",len(diction[items]["_keys_"]), "properties", tuple(diction[items]["_keys_"]))  

def add_group_data(d):
    print("*** Add group data ***")
    list_groups(diction)

    while True:
        prompt = input("Enter group (empty to cancel): ")
        if prompt == "":
            break
        elif prompt not in diction:
            print("Not found")
            continue
        else:
            for items in diction[prompt]["_keys_"]:
                item = input("Enter " + str(items) + ": ")
                diction[prompt]["_data_"].append({items:item})
                
        
def list_group_data(d):
    list_groups(diction)
    while True:
        prompt = input("Enter group name (empty to cancel): ")
        if prompt == "":
            break
        elif prompt not in diction:
            print("Not found")
            continue
        else:
            count = 0
            total_count = 0
            string = ""
            for items in diction[prompt]["_keys_"]:
                string += (diction[prompt]["_keys_"][count] + " = " + diction[prompt]["_data_"][count][items] + ", ")
                print(total_count , string)
                string = ""
                count += 1
                total_count += 1
print(">> Welcome to Group Manager <<", "\nThis program creates groups with dynamic properties")
while True:
    input_command = input("Command (empty or X to quit, ? for help): ")
    input_command = input_command.strip()
    input_command = input_command.upper()
    if input_command == "" or input_command == "X":
        break
    elif input_command == "?":
        command_names = ["?:", "C:", "A:", "G:", "L:", "X:"]
        command_descriptions = ["List commands", "Create a new group", "Add data to a group", "List groups", "List data for a group", "Exit"]
        line = 0
        for line in range(len(command_names)):
            print(command_names[line], command_descriptions[line])
            line += 1
    elif input_command == "C":
        create_group(diction)
    elif input_command == "G":
        list_groups(diction)
    elif input_command == "A":
        add_group_data(diction)
    elif input_command == "L":
        list_group_data(diction)
    else:
        print("Unknow command")
                
