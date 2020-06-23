import pandas as pd
import numpy as np
from functools import reduce

def LEM2(dataframe, concept):

    attribute_colnames = dataframe.columns[:-1]
    decision_colname = dataframe.columns[-1]
    attribute_value_pairs = {}
    decision_concept = np.where(dataframe[decision_colname] == concept)[0]
    for attributes in attribute_colnames:
        dataframe_grouped = dataframe.groupby(attributes).indices
        for value in dataframe_grouped.keys():
            attribute_value_pairs["({}, {})".format(attributes, value)] = dataframe_grouped[value]
    goal = decision_concept
    covering = []
    num_goal = len(goal)
    while (num_goal > 0):
        selected_pairs = {}
        poss_pairs = {x:y for x, y in attribute_value_pairs.items() if np.isin(y, goal).any()}
        num_selected_pairs = len(selected_pairs)
        is_selected_pairs_subset_concept = False
        while ((num_selected_pairs == 0) or (not is_selected_pairs_subset_concept)):
            max_size_intersection = np.max([len(value) for value in poss_pairs.values()])
            pair_selected = {x:y for x, y in poss_pairs.items() if len(y) == max_size_intersection}
            if (len(pair_selected) > 1):
                min_cardinality = np.min([len(value) for value in pair_selected.values()])
                pair_selected = {x:y for x, y in pair_selected.items() if len(y) == min_cardinality}
                if (len(pair_selected) > 1):
                    pair_key = list(pair_selected.keys())[0]
                    pair_selected = {pair_key: pair_selected[pair_key]}
            pair_key, pair_value = list(pair_selected.items())[0]
            selected_pairs[pair_key] = pair_value
            goal = np.intersect1d(pair_value, goal)
            poss_pairs = {x:y for x, y in attribute_value_pairs.items() if np.isin(y, goal).any()}
            poss_pairs = {x:y for x, y in poss_pairs.items() if selected_pairs.get(x) is None}
            num_selected_pairs = len(selected_pairs)
            is_selected_pairs_subset_concept = np.isin(reduce(np.intersect1d, selected_pairs.values()), decision_concept).all()
        list_pair_key = list(selected_pairs.keys())
        for pair_key in list_pair_key:
            pair_value = selected_pairs[pair_key]
            del selected_pairs[pair_key]
            num_pair = len(selected_pairs)
            if ((num_pair == 0) or (not np.isin(reduce(np.intersect1d, selected_pairs.values()), decision_concept).all())):
                selected_pairs[pair_key] = pair_value
        covering.append(selected_pairs)
        union_covering = reduce(np.union1d, [reduce(np.intersect1d, pairs.values()) for pairs in covering])
        goal = [item for item in decision_concept if not np.isin(item, union_covering)]
        num_goal = len(goal)
    return (covering, decision_concept)



def computeRuleInfo(rule, decision_concept):

    specificity = len(rule)
    matching_cases = reduce(np.intersect1d, rule.values())
    strength = np.sum(np.isin(matching_cases, decision_concept))
    num_matching_cases = len(matching_cases)
    return (specificity, strength, num_matching_cases)
