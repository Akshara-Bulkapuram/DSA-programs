#include <bits/stdc++.h>
#include <vector>
using namespace std;
#include <list>

class Graph{
    int V;
    vector <list<int>> adj;
    public:
    Graph(int V);
    void BFS(int s);
    void addEdge(int v, int w);
    void DFS_it(int s);

};
 Graph::Graph(int V){
    this->V=V;
    adj.resize(V);
 }

 void Graph::BFS(int s){
    vector <bool> visited;
    visited.resize(V,false);
    list <int> queue;
    queue.push_back(s);
    visited[s]=true;
    while(!queue.empty()){
        s=queue.front();
        cout<<"visiting "<<s<<endl;
        queue.pop_front();
        for(auto x: adj[s]){
            if(!visited[x]){
            visited[x]=true;
            queue.push_back(x);

            }
        }
    }


 }

    




 void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
 }

// Driver code
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n";
    g.DFS_it(2);
 
    return 0;
}
