import pandas as pd
from enum import Enum

class parse_state(Enum):
    BEGIN = 0
    VARIABLE = 1
    ATTRIBUTE = 2
    INFO = 3
    COMMENT = 4
    END = 5

def parseInput(input_file):
    file_handler_input = open(input_file, "r")
    read_lines = file_handler_input.readlines()
    file_handler_input.close()
    curr_state = parse_state.BEGIN
    prev_state = curr_state
    curr_data = []

    variables = None
    attributes = None
    dataframe = None
    curr_attribute = 0
    num_attributes = 0

    for line in read_lines:
        if (curr_state == parse_state.COMMENT):
            curr_state = prev_state
        for token in line.split():
            if (curr_state == parse_state.BEGIN):
                curr_data = []
                if (token == "<"):
                    curr_state = parse_state.VARIABLE
                elif (token == "!"):
                    prev_state = curr_state
                    curr_state = parse_state.COMMENT
                elif (token == "["):
                    curr_state = parse_state.ATTRIBUTE
                else:
                    curr_attribute = 0
                    curr_state = parse_state.INFO

            elif (curr_state == parse_state.COMMENT):
                pass

            elif (curr_state == parse_state.END):
                pass

            elif (curr_state == parse_state.VARIABLE):
                if (token == ">"):
                    variables = curr_data
                    curr_state = parse_state.BEGIN
                else:
                    curr_data.append(token)

            elif (curr_state == parse_state.ATTRIBUTE):
                if (token == "]"):
                    attributes = curr_data
                    dataframe = pd.DataFrame([], columns = attributes)
                    num_attributes = len(curr_data)
                    curr_state = parse_state.BEGIN
                else:
                    curr_data.append(token)

            if (curr_state == parse_state.INFO):
                try:
                    token = float(token)
                except:
                    pass
                curr_data.append(token)
                curr_attribute += 1
                if (curr_attribute == num_attributes):
                    dataframe = dataframe.append(pd.DataFrame([curr_data], columns = attributes))
                    curr_state = parse_state.BEGIN
    dataframe = dataframe.reset_index(drop = True)
    return (dataframe)
