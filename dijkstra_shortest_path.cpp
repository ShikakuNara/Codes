#include<bits/stdc++.h>
using namespace std;

# define INF 0x3f3f3f3f

// iPair ==>  Integer Pair
typedef pair<int, int> iPair;

class Graph
{
    int V;    // No. of vertices
    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list< pair<int, int> > *adj;

public:
    Graph(int V);  // Constructor
    void addEdge(int u, int v, int w); // function to add an edge to graph
    void shortestPath(int s); // prints shortest path from s
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w) // adds two sided edges with their weight paired
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
void Graph::shortestPath(int src)
{
    // a priority queue to store vertices that have been visited
    priority_queue<iPair, vector <iPair> , greater<iPair> > pq;

    // Creates a vector for distances and initialize all distances as infinite (INF)
    vector<int> dist(V, INF);

    // Insert source itself in priority queue and initialize its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;

    // Looping till priority queue becomes empty (or all distances are not finalized)
    while (!pq.empty())
    {
       //The first vertex in pair is the minimum distance vertex, extract it from priority queue.
       //vertex label is stored in second  of pair (it has to be done this way to keep the vertices
       //sorted distance (distance must be first item in pair)
       int u = pq.top().second;
         pq.pop();

        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent of u.
            int v = (*i).first;
            int weight = (*i).second;

            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v)); // adding the new distance and vertex in the queue
            }
        }
    }

    // Print shortest distances stored in dist[]
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Driver program
int main()
{
    int V = 5, s=0;

    Graph g(V); //object g which represents the graph.

    g.addEdge(0, 3, 1);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 4, 1);

    g.shortestPath(s);

    return 0;
}
