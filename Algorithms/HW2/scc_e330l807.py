from __future__ import print_function
import fileinput
import sys 
   
class Graph: 
   
    def __init__(self,v): 
        self.Vertices = v 
        self.graph = {new_list: [] for new_list in range(self.Vertices)}
        self.sorted = [[] for x in range(self.Vertices)]
        self.counter = 0
   
    #adds an edge to the graph
    def addEdge(self,u,v): 
        self.graph[u].append(v) 
   
    #DFS that finds all the strongly connected components
    def DFSSCC(self,v,visited): 
        visited[v] = True
        self.sorted[self.counter].append(v + 1)
        for i in self.graph[v]: 
            if visited[i] == False: 
                self.DFSSCC(i, visited) 
  
  
    #fill the stack 
    def fillStack(self,v,visited, stack): 
        visited[v] = True
        for i in self.graph[v]:
            #print(i)
            if visited[i] == False: 
                self.fillStack(i, visited, stack) 
        stack = stack.append(v) 
      
  
    #get a graph that is the transpose of the graph
    def getTranspose(self): 
        g = Graph(self.Vertices) 
  
        for i in self.graph: 
            for j in self.graph[i]: 
                g.addEdge(j, i) 
        return g 
  
   
   
    def SCC(self): 
          
        #declare the stack and initialize the visited array
        stack = [] 
        visited = [False] * (self.Vertices)

        #fill the stack using DFS 
        for i in range(self.Vertices): 
            if visited[i] == False: 
                self.fillStack(i, visited, stack) 
  
        #get the transpose of the graph and reset up the visited array
        gr = self.getTranspose() 
        visited = [False] * (self.Vertices) 
  
        #recursing down the stack that was generated
        while stack: 
            i = stack.pop() 
            if visited[i] == False: 
                gr.DFSSCC(i, visited)
                gr.counter += 1
                
        #sort the lists        
        for x in range(len(self.sorted)):
            gr.sorted[x].sort()
        gr.sorted.sort()

        #printing the lists
        for y in range(len(self.sorted)):
            for z in range(len(gr.sorted[y])):
                if(len(gr.sorted[y]) == 0):
                    pass
                elif gr.sorted[y][z] == gr.sorted[y][-1]:
                    print ("{}".format(gr.sorted[y][z]), end = '')
                else:
                    print ("{} ".format(gr.sorted[y][z]), end = '')
            if(len(gr.sorted[y]) == 0):
                pass
            elif gr.sorted[y] == gr.sorted[-1]:
                pass
            else:
                print("")

def main():
    in_file = open(sys.argv[1], "r")

    #reading the first two lines
    num_nodes = in_file.readline()
    num_nodes = num_nodes.strip("\t\n\r")
    num_nodes = int(num_nodes)
    empty = in_file.readline()

    edge_list = in_file.readlines()
    in_file.close()
    
    grap = Graph(num_nodes)

    #stripping all useless characters
    helper1 = 0
    for x in edge_list:
        edge_list[helper1] = edge_list[helper1].strip("\t\n\r")
        helper1 += 1

    #add all edges to the graph
    helper2 = -1
    for y in edge_list:
        helper2 += 1
        for chay in y:
            if chay == ' ':
                pass
            else:
                grap.addEdge(helper2, (int(chay) - 1))

    #run algorithm and print
    grap.SCC()

    

main()