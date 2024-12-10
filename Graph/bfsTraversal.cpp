#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

//Function for Breadth First Traversal (BFS) of the Graph
void BFSTraversal(vector< list<int> >& graph, vector<bool> &visited, int node){
    //Initializing queue
    queue<int> q;

    //Starting BFS from given node
    q.push(node);
    visited[node] = true;   //Marking given Node is Visited


    //Performing BFS Process until the queue 'q' is not empty
    while(!q.empty()){
        //Accessing the front node
        int frontNode = q.front();
        q.pop();    //Removing node from the queue

        cout<<frontNode<<" ";   //Printing the Current Node

        //Exploring the all neighbours of the Current Node
        for(auto neighbour : graph[frontNode]){
            //If neighbour is not visited, mark it as visited and push it in the queue.
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}