/*Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Note:
1. Here you need to consider that you need to print BFS path starting from vertex 0 only. 
2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
3. E is the number of edges present in graph G.
4. Take graph input in the adjacency matrix.
5. Handle for Disconnected Graphs as well*/

/*Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains space separated two integers, that denote that there exists an edge between vertex a and b.
*/
//Example
/*
Sample Input :
4 4
0 1
0 3
1 2
2 3
Sample Output :
0 1 3 2
*/

//Code:-

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void print(int **edge,int V, bool *visit,int start)
{
    queue<int>q;
    q.push(start);
    visit[start]=true;

    while(!q.empty())
    {
        for(int i=0;i<V;i++)
        {
            if(edge[start][i]==1 && visit[i]==false)
            {
               q.push(i);
               visit[i]=true; 
            }
        }
        cout<<start<<" ";
        q.pop();
        start=q.front();
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    int **edge= new int*[V];
    for(int i=0;i<V;i++)
    {
        edge[i]=new int[V];
        for(int j=0;j<V;j++)
        {
            edge[i][j]=0;
        }
    }
    for(int i=0;i<E;i++)
    {
        int s,f;
        cin>>s>>f;
        edge[s][f]=1;
        edge[f][s]=1;
    }


    bool *visit=new bool[V];
    for(int i=0;i<V;i++)
        visit[i]=false;

    print(edge,V,visit,0);




  return 0;
}
