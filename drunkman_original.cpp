/*
Input

    The first line of the input contains a single integer T — the number of test cases in this input. Then follow T descriptions of individual test cases.
    The first line of the input contains four integers n, m, s and t — the number of intersections and the number of roads in the city, the index of the intersection where the bar is located and the index of the intersection where the drunk man's house is, respectively.
    The ith of the following m lines contains two integers ui and vi — indices of the junctions connected by the ith road.

Output

    If there is no strategy for him to reach home definitely, output -1 in a new line.
    Otherwise, print how many minutes the drunk man needs to get home in the worst possible scenario if he always behaves optimally in the Step 1 of every minute.

Constraints

    1 ≤ T ≤ 100000
    3 ≤ n, m ≤ 300000
    1 ≤ s, t ≤ n
    s ≠ t
    1 ≤ ui, vi ≤ n
    ui ≠ vi
    It is guaranteed that it is possible to get from any junction to any other junction moving along the roads, each junction has at least two incident roads and no two roads connect the same pair of junctions.
    It is guaranteed that both the total number of intersections and the total number of roads over all test cases in one input file won't exceed 1000000
    */

    // we try a DFS algorithm here 
    
    #include<iostream>   
    #include<list>       
    using namespace std; 
                         
        class Graph      
        {                
            int V;    // No. of vertices               
            list<int> *adj;   // Pointer to an array containing adjacency lists 
            void DFSUtil(int v, bool visited[],int t); //A function used by DFS 
        public:          
            Graph(int V);   // Constructor   
            void addEdge(int v, int w);   // function to add an edge to graph   
            void DFS(int t);    // prints DFS traversal of the complete graph   
        };
        Graph::Graph(int V)
        {
            this->V = V;
            adj = new list<int>[V];
        }
         
        void Graph::addEdge(int v, int w)
        {
            adj[v].push_back(w); // Add w to v’s list.
        }
         
        void Graph::DFSUtil(int v, bool visited[],int t)
        {
            // Mark the current node as visited and print it
            visited[v] = true;
            cout<<v<<" ";
            if(v==t)
             {
               cout<<"found";
             }
         
            // Recur for all the vertices adjacent to this vertex
            list<int>::iterator i;
            for(i = adj[v].begin(); i != adj[v].end(); ++i)
                if(!visited[*i])
                    DFSUtil(*i, visited,t);
        }
         
        // The function to do DFS traversal. It uses recursive DFSUtil()
        void Graph::DFS(int t)
        {
            // Mark all the vertices as not visited
            bool *visited = new bool[V];
            for (int i = 0; i < V; i++)
                visited[i] = false;
         
            // Call the recursive helper function to print DFS traversal 
            // starting from all vertices one by one 
            for (int i = 0; i < V; i++)
                if (visited[i] == false)
                    DFSUtil(i, visited,t);
        }
         
        int main()
        {
            int s,t;
            scanf("%d %d",&s,&t);  
            // Create a graph
            Graph g(4);
            g.addEdge(0, 1);
            g.addEdge(0, 2);
            g.addEdge(1, 2);
            g.addEdge(2, 0);
            g.addEdge(2, 3);
            g.addEdge(3, 3);
            
            g.DFS(t); //starting search
         
            return 0;
        }
