import sys, getopt
import numpy as np
from helpers import *
from parser import *

def run(input_file, output_file):
    dataframe = parseInput(input_file)
    rule_set = {}
    rule_info = {}
    decision_colname = dataframe.columns[-1]
    attribute_colnames = dataframe.columns[:-1]
    concepts = dataframe[decision_colname].unique()
    for concept in concepts:
        if (dataframe[attribute_colnames].select_dtypes(include = "number").shape[1] > 0):
            dataframe = findCutPoints(dataframe)
        rules, decision_concept = LEM2(dataframe, concept)
        rules_info = [computeRuleInfo(rule, decision_concept) for rule in rules]
        rule_set["({}, {})".format(decision_colname, concept)] = rules
        rule_info["({}, {})".format(decision_colname, concept)] = rules_info
    file_handler_output = open(output_file + ".txt", "w")
    for concept, rules in rule_set.items():
        infos = rule_info[concept]
        for rule_index, rule in enumerate(rules):
            info = infos[rule_index]
            rule_info_string = str(info[0]) + ", " + str(info[1]) + ", " + str(info[2]) + "\n"
            conditions = list(rule.keys())
            rule_string = str(conditions[0])
            for i in range(1, len(conditions)):
                rule_string = rule_string + " & " + str(conditions[i])
            rule_string = rule_string + " -> " + str(concept) + "\n"
            file_handler_output.write(rule_info_string)
            file_handler_output.write(rule_string)
    file_handler_output.close()

    return

def main():
    answer = ""
    run_again = True
    input_file = ""
    output_file = ""

    while run_again:
        while answer not in ("yes", "no"):
            answer = input("Run? (yes, no): ")
        run_again = answer == "yes"
        if(answer == "no"):
            break
        input_file = input("Input file: ")
        output_file = input("Output file (no file extenion needed): ")
        try:
            run(input_file, output_file)
        except:
            print("Try again.")
        answer = ""


if __name__ == "__main__":
    main()
