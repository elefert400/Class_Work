import fileinput
import sys

class Node(object):
    def __init__(self, data = None, next_node = None):
        self.data = data
        self.next_node = next_node

    def get_data(self):
        return self.data

    def get_next(self):
        return self.next_node
    
    def set_next(self, new_next):
        self.next_node = new_next

class LL(object):
    def __init__(self, head=None):
        self.head = head

    def size(self):
        current = self.head
        count = 0
        while current:
            count += 1
            current = current.next_node
        return count

    def push_front(self, new_data):
        new_node = Node(new_data)
        new_node.set_next(self.head)
        self.head = new_node

    def push_back(self, new_data):
        new_node = Node(new_data)
        my_size = self.size()
        current = self.head
        if(my_size == 0):
            self.head = new_node
        else:
            while my_size > 1:
                current = current.get_next()
                my_size -= 1
            current.set_next(new_node)

    def pop_front(self):
        self.head = self.head.get_next()

    def get_front(self):
        return self.head



def main():
    in_file = open(sys.argv[1], "r")
    #variables for parsing
    counterM = 0
    counterF = 0
    first_read = True
    tempM = []
    tempF = []

    #data structures for GS
    num_men = 0
    #men_pref = []
    #women_pref = []
    #women_rank = []
    #men_proposed = []
    #women_partners = []
    single_men = LL()

    
    #opening and reading file
    for line in in_file:

        #getting the first value in the file as the number of men/women
        if first_read == True:
            num_men = int(line, base=10)
            first_read = False
            #initializing the arrays
            men_pref = [[0]*num_men for i in range(num_men)]
            women_pref = [[0]*num_men for o in range(num_men)]
            men_proposed = [0]*num_men
            women_partners = [0]*num_men
            women_rank = [[0]*num_men for p in range(num_men)]

            #to keep track of men's partner for output
            men_partner = [0]*num_men
        
        #all values that are not the first value
        else:

            #getting the current line and removing the commas
            current_line = line.strip("\t\n\r")
            #getting the int values into a 2D array for men and women
            if(current_line == "\n" or current_line == ""):
                pass
            elif counterM < num_men:
                counter = 0
                counterM = counterM + 1
                for char in current_line:
                    if(char != ','):
                        men_pref[counterM - 1][counter] = (men_pref[counterM - 1][counter] * 10) + int(char)
                    if(char == ','):
                        counter += 1
            else:
                counter = 0
                for chars in current_line:
                    if(chars != ','):
                        women_pref[counterF][counter] = (women_pref[counterF][counter] * 10) + int(chars)
                    if(chars == ','):
                        counter = counter + 1
                counterF = counterF + 1
    #setting up LL, men proposed, and women partners array
    for men in range(num_men):
        men_proposed[men] = 0
        women_partners[men] = -1
        single_men.push_front(num_men - men)

    #begin algorithm

    while(single_men.size() != 0):
        #getting the front man and his number
        lead_man = single_men.get_front()
        lead_man_num = lead_man.get_data() - 1

        #getting the number of women he has proposed to, getting his preferance list,
        #then getting the woman's number from the list
        lead_man_women_choice = men_proposed[lead_man_num]
        
        lead_man_choice = men_pref[lead_man_num][lead_man_women_choice] - 1

        if(women_partners[lead_man_choice] == -1):
            women_partners[lead_man_choice] = lead_man_num
            men_partner[lead_man_num] = lead_man_choice
            single_men.pop_front()
        
        else:
            #getting the woman's current partner number
            womans_partner_current = women_partners[lead_man_choice]
            current_partner_index = 0
            proposal_guy_index = 0

            #finding the index number for the current partner and the bachelor
            current_partner_index = women_pref[lead_man_choice].index(womans_partner_current + 1)
            proposal_guy_index = women_pref[lead_man_choice].index(lead_man_num + 1)

            #if she likes the new guy more he will have a lower number
            if(current_partner_index > proposal_guy_index):
                #add the rejected man to the back of the list, and set the woman's current partner to the new man
                #pop the newly engaged man off the singles list
                single_men.push_back(womans_partner_current + 1)
                women_partners[lead_man_choice] = lead_man_num
                single_men.pop_front()
                men_partner[lead_man_num] = lead_man_choice
                men_partner[womans_partner_current] = -1
            else:
                #move on to next woman on the list
                pass
        
        #regardless of what happens the man's number of woman proposed to needs to increase
        men_proposed[lead_man_num] = men_proposed[lead_man_num] + 1
            

    #end algorithm, run output
    keeper = 0
    while keeper < num_men:
        print("{},{}".format(keeper + 1, men_partner[keeper] + 1))
        keeper += 1


main()

