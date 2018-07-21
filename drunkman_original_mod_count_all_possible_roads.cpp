#include<bits/stdc++.h>
using namespace std;

bool dfs_Util(vector<int> Graph[], int &ct, int n, int v, int dest, bool *visited, int path[], int &u)
{
    visited[v]=true;
    path[u++]=v;

    if(v==dest)
    {
    ct++;
    /*for(int i=0;i<u;i++)
    cout<<path[i]<<" ";
    cout<<endl
    */
    visited[dest]=false;
    return true;
    }

    bool flag=0;

    for(vector<int>::iterator it=Graph[v].begin(); it!=Graph[v].end();it++)
    {
        if(!visited[*it])
        {//cout<<v<<"NOT "<<*it<<endl;
            if(dfs_Util(Graph, ct, n, *it, dest, visited, path, u))
            {
                visited[*it]=false;
                u--;
                flag=1;
          //   cout<<"going from"<<" "<<v<<endl;
            }
        }
    }

    if(flag==1)
    return true;

    return false;
}

void depth_first(vector<int> Graph[], int n, int source, int dest)
{
    bool *visited=new bool[n];
    int path[n];
    int u=0, ct=0;

    for(int i=0;i<n;i++)
    visited[i]=0;

    dfs_Util(Graph, ct, n, source, dest, visited, path, u);

    cout<<ct<<endl;
}

int main()
 {
	//code
	{
	    int n, e,s,t ;
	    cin>>n>>e>>s>>t;

	    vector<int> Graph[n];

	    for(int i=0;i<e;i++)
	    {
	        int x,y;
	        cin>>x>>y;
	        Graph[x].push_back(y);
	        Graph[y].push_back(x);
	    }

	    depth_first(Graph, n, s, t);
	}
	return 0;
}
