#include<bits/stdc++.h>
using namespace std;

class Graph
{
  int V; // number of vertices
  list<int> *adj;//pointer to the adjecency list
  //recursive function to print the paths after storing it appropriately in the array paths
  void print_path_util(int u,int s,int t, int path_index,int path[],bool visited[]);
 public:
   Graph(int V); // constructor;
  void addEdge(int u,int v); // add edges in the adjecency list
  void print_path(int s,int t); // call print_paths_util
};
Graph::Graph(int V)
 {
   this->V=V;
   adj = new list<int> [V];
 }
 void Graph::addEdge(int u,int v)
  {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  void Graph::print_path_util(int u,int s,int t, int path_index,int path[],bool visited[])
  {
    visited[u] = true; //since vertex u is visited
    path[path_index] = u; //enter u in the path
    path_index++; // increment the path index

    //incase current vertex is the destination then print the current path
    if(u==t)
     {
       // printig the current path
       for(int i = 0; i<path_index; i++)
        printf(" %d ",path[i]);
        printf("\n");
     }
     else //if current vertex is not the destination then recur to the adjecent vetices
      {
        list<int>::iterator i;
        for(i = adj[u].begin(); i != adj[u].end(); i++)
         if(!visited[*i])
          print_path_util(*i,s,t,path_index,path,visited);
      }

      visited[u] = false; //set the current vertice as not visited
      path_index--; //decrement the path_index to go to the current vertice to change it in the next call

  }
  void Graph::print_path(int s,int t)
  {
    //boolean array of visited vertices and initialise each one as not visited(ie. false)
    bool* visited = new bool [V];
    for(int i=0;i<V;i++)
     visited[i] = false;

     //array containing the current path
    int* path = new int [V];
    int path_index = 0; //current path index is will be zero and source will be added in the first call to 0
    print_path_util(s,s,t,path_index,path,visited);
  }
  // Main
  int main()
  {
      int V,m,s,t;// number of vertices, number of roads, source, destination
              scanf("%d %d %d %d",&V,&m,&s,&t);
              // Create a graph
              Graph g(V);  // g is object of the user defined class Graphs
              while(m)
              {
                int u,v;
                scanf("%d %d",&u,&v);
                g.addEdge(u, v);
                g.addEdge(v, u);
                m=m-1;
              }
      cout << "Following are all different paths from " <<s<< " to " <<t<< endl;
      g.print_path(s, t);

      return 0;
  }
