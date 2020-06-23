for lines in in_file.input():
        if(first_read == true):
            num_men = int(lines)
        else:
            if(counter < num_men):
                tempM[counter] = lines
                #men_pref[counter] = lines
                counter = counter + 1
            else:
                tempF[counterF] = lines
                #women_pref[counterF] = lines
                counterF = counterF + 1
    
    in_file.close()
    counter = 0

    #parsing the lines from the file into
    for values in tempM:
        if(values == ','):
            #skip these values
        else:
            men_pref[counter] = int(values)
            counter = counter + 1