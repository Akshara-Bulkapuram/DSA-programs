#include <bits/stdc++.h>
#include <vector>
using namespace std;
#include <list>

class Graph{
    int V;
    vector <list<int>> adj;
    public:
    Graph(int V);
    void BFS(int s, vector <bool> v);
    void addEdge(int v, int w);
    bool dfs_cycle(int s,int parent,vector <bool> v);
    bool isCyclic();

};
 Graph::Graph(int V){
    this->V=V;
    adj.resize(V);

 }

 void Graph::BFS(int s,vector <bool> visited){

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
 bool Graph::dfs_cycle(int s,int parent, vector<bool>v){
    v[s]=true;
    cout<<"visiting "<<s<<endl;
    for(auto x: adj[s]){
        if(!v[x]){
            return dfs_cycle(x,s,v);
        }
        else{
            if(x!=parent){
                cout<<"cycle at "<<s<<" --- "<<x<<endl;
                return true;
            }
        }
    }
    return false;

 }


 void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
 }


bool Graph :: isCyclic(){
    vector<bool> visited(V,false);

    for (int u = 0; u < V; u++) {
 
 
        if (!visited[u])
            if (dfs_cycle(u, -1,visited))
                return true;
    }
    return false;
}

// Driver code
int main()
{
    // Create a graph given in the above diagram
    int V=5;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    vector<bool>visited;
    visited.resize(V,false);
    bool k=g.dfs_cycle(2,2,visited);
    if(k){
        cout<<"cycle exists!"<<endl;
    }
    else{
        cout<<"no cycle!"<<endl;
    }
    cout<<"-------------------------------------"<<endl;
    Graph g1(5);
    
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic() ? cout << "Graph contains cycle\n"
                  : cout << "Graph doesn't contain cycle\n";
    cout<<"-------------------------------------"<<endl;

 
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCyclic() ? cout << "Graph contains cycle\n"
                  : cout << "Graph doesn't contain cycle\n";


 
    return 0;
}
