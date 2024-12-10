#include<iostream>
#include<vector>
#include<list>

using namespace std;

//Function for Depth First Traversal (DFS) of the Graph
void DFSTraversal(vector< list<int> > &graph, vector<bool>& visited, int node){
    
    cout<< node <<" ";      //Printing the Current Node
    visited[node] = true;   //Marking the Current Node as Visited

    //Exploring the neighbours of the Current Node
    for(auto neighbour : graph[node]){
        //If neighbour is not visited, recursively perform DFS
        if(!visited[neighbour]){
            DFSTraversal(graph,visited,neighbour);
        }
    }
}