#include<bits/stdc++.h>

typedef pair<int,int> intpair;
#define inf 100000000;

 class Graph
  {
    int V; // number of vertices

    // adjecenc list of the adjecent nodes to a vertice paired with the weight to the corresponding path
    list< pair<int,int> > *adj ;

    // recursive function used by shortestPath function
    void shortestPath_util(int s, priority_queue pq, bool visited[], int dist[]);
   Public:
    void addEdge(int u, int v, int w); // add the edges to the graph with the corresponding weights
    void shortestPath(int s); // call the recursive function shortestPath_util
  };
    void Graph::Graph(int V) //Constructor
     {
       this-> V = V;
       list adj = new list< pair<int,int> > [V];
     }
    void Graph::addEdge(int u, int v, int w)
     {
       adj[u].push_back(make_pair(v,w)); // insert u in v's list with the weight of u<->v = w
       adj[v].push_back(make_pair(u,w)); // insert v in u's list with the weight of u<->v = w
     }
    void Graph::shortestPath_util(int s, priority_queue pq, bool visited[], int dist[])
     {
       int u,v,weight;

       //loop till the queue does not get empty 
       while(!pq.empty())
       {
          u = pq.top().second;
          pq.pop();

          //recur to all the adjecent vertices of u
          list < pair<int, int> >::iterator i;
          for(i=adj[u].begin(),i != adj[u].end(),i++)
           {
             v = (*i).first; // vertice
             weight = (*i).second; // corresponding weight of u<->v path
             if(dist[v] > dist[u] + weight)
              {
                dist[v] = dist[u] + weight; // modify distance to the smaller value
                pq.push(make_pair(dist[v], v)); // push the new pair in the queue
              }
           }
       }

       // print the shortest distances
       printf("Vertex   Distance from Source\n");
       for (int i = 0; i < V; ++i)
           printf("%d \t\t %d\n", i, dist[i]);

     }
    void Graph::shortestpath(int s)
     {
       // make a boolean arrary to keep track of which vertice has been visited
       //initialize each entry to be false ie. not visited
       bool visited = new bool[V];
       for(int i=0;i<V;i++)
        visited[i] = false;

      //priority queue to hold (distance,vertex) pair
      priority_queue < ipair, vector<ipair>, greater<ipair> > pq;

      // array to store distance of every vertex from the source vertex initialized as inf
       vector<int> dist(V, INF);
        //since distance of source is zero from source
          dist[s] = 0;

        //push (distance,vertex) pair in the prority queue
        pq.push(make_pair(0,s));

      shortestPath_util(s,pq,visited,dist);
     }
