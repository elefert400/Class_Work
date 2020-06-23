import sys

class Graph: 
  
    def __init__(self,vertices,edges): 
        self.vertices = vertices 
        self.graph = edges 
  
    def cycle(self, parent, i): 
        if parent[i] == i: 
            return i 
        return self.cycle(parent, parent[i]) 

    def Kruskal(self): 
  
        result = [] 
  
        i = 0 
        edges = 0 
        #sort the edges 
        self.graph =  sorted(self.graph, key=lambda item: item[2]) 
  
        #parents in the tree
        parents = []
  
        for node in range(self.vertices): 
            parents.append(node) 
      
        while edges < self.vertices -1 : 
            u,v,w =  self.graph[i] 
            i = i + 1
            #check for cycles
            x = self.cycle(parents, u) 
            y = self.cycle(parents, v) 
            if x != y: 
                edges = edges + 1     
                result.append([u,v,w]) 
                parents[x] = y       
            else:
                pass
  
        for u,v,w  in result: 
            print ("%d %d" % (u,v)) 



def main():

    #parse edges from file
    F = open(sys.argv[1], "r")
    a = F.readlines()
    read_in = []
    visited = []
    edges_in_tree = []
    for line in a:
        line = line.strip('\r\n ')
        line = line.split(' ')
        read_in.append(line)
        visited.append(False)
    for i in range(len(read_in)):
        read_in[i] = [int(x) for x in read_in[i]]


    #get number of vertices
    vertices = len(read_in[0])

    #set up edges list
    edges = []
    for x in range(len(read_in)):
        for y in range(len(read_in[x])):
            if(read_in[x][y] == 0):
                pass
            else:
                edges.append([x, y, read_in[x][y]])

    #make graph and run Kruskals
    g = Graph(vertices, edges)
    g.Kruskal()
main()