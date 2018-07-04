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
    
#include<stdc++.h>

using namespace std;

int* Input(int n,int m) //inputting variable no. of junctions,no. of roads
{
  //dynamically allocating array: road i connected to junctions u_i and v_i
  int* start=NULL;
  int* array = new int[m*2];            <-delete afterwards
  start=array
   for(int i=0;i<2*m;i++)
    {
      std::cin>>*array;                 <-check i guess its wrong
      array++;
    }
  return start
}
int navigate()
{
  int n,m,s,t;
  std::cin>>n>>m>>s>>t;
  int* start=Input(n,m);
  
}
