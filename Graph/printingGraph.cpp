#include<iostream>
#include<vector>
#include<list>

using namespace std;

//Function for Printing the Adjacency List representing the Undirected Graph
void GraphPrinting(vector< list<int> > &Graph){
    //Traversing through nodes of the Adjacency List
    for(int node = 0; node < Graph.size(); node++){
        cout<<node<<": ";   //Printing Current Node

        //Traversing through the neighbours of the Node
        for(auto neighbour : Graph[node]){
            cout<<neighbour<<" ";   //Printing Neighbours of the Current Node
        }

        cout<<endl;
    }
}