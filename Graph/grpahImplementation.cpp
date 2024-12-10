#include<iostream>
#include<vector>
#include<list>

using namespace std;

//Function to implement the Undirected Graph using Adjacency List
vector< list<int> > implementingGraph(int nodes, vector< vector<int> >& edges){
    //Creating Adjacecy List 
    vector< list<int> > graph(nodes);

    //Traversing through the vector of edges
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];    //Start Node of the edge
        int v = edges[i][1];    //End Node of the edge

        //Adding connection from 'u' to 'v'
        graph[u].push_back(v);
        //Adding connection from 'v' to 'u'
        graph[v].push_back(u);
    }

    //Returning the constructed Graph
    return graph;
} 