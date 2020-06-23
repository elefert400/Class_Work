import sys

# A function for making a matrix of zeroes
def zeros(rows, cols):
    retval = []
    for x in range(rows):
        retval.append([])
        for y in range(cols):
            retval[-1].append(0)

    return retval

def match_score(x, y):
    if x == y:
        return 0
    elif x == '-' or y == '-':
        return 1
    else:
        return 1

def sequence_alignment(seq1, seq2, total_score):

    n = len(seq1)  
    m = len(seq2)
    
    #generate score matrix
    score = zeros(m+1, n+1)
    
    #Fill out first column and row
    for i in range(0, m + 1):
        score[i][0] = 1 * i
    for j in range(0, n + 1):
        score[0][j] = 1* j
    
    #Fill score matrix
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            match = score[i - 1][j - 1] + match_score(seq1[j-1], seq2[i-1])
            delete = score[i - 1][j] + 1
            insert = score[i][j - 1] + 1
            score[i][j] = min(match, delete, insert)
    
    #Final alignment
    align1 = ""
    align2 = ""
    
    #Start at the end
    i = m
    j = n
    total_score = score[m][n]
    while i > 0 and j > 0:
        score_current = score[i][j]
        score_diagonal = score[i-1][j-1]
        score_up = score[i][j-1]
        score_left = score[i-1][j]
        
        #fill alignments based on the scores
        #following mismatch over insertion, and insertion over deletion
        if score_current == score_diagonal + match_score(seq1[j-1], seq2[i-1]):
            align1 += seq1[j-1]
            align2 += seq2[i-1]
            i -= 1
            j -= 1
        elif score_current == score_left + 1:
            align1 += '-'
            align2 += seq2[i-1]
            i -= 1
        elif score_current == score_up + 1:
            align1 += seq1[j-1]
            align2 += '-'
            j -= 1
        

    #Finish tracing if one sequence is bigger
    while j > 0:
        align1 += seq1[j-1]
        align2 += '-'
        j -= 1
    while i > 0:
        align1 += '-'
        align2 += seq2[i-1]
        i -= 1
    
    #Flip the alignments since they are filled in backwards
    align1 = align1[::-1]
    align2 = align2[::-1]

    print(total_score)
    
    return(align1, align2)

def main():

    first_line = True
    seq1 = ''
    seq2 = ''
    total_score = 0

    F = open(sys.argv[1], "r")
    a = F.readlines()
    for line in a:
        if first_line == True:
            seq1 = line
            first_line = False
        else:
            seq2 = line



    output1, output2 = sequence_alignment(seq1, seq2, total_score)

    print(output1 + output2, end ='')

main()