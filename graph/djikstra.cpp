#include <iostream>
#include <vector>
using namespace std;

#define V 9

void print_solution(vector <int> d){
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << d[i] << endl;
}

int min_dist(vector <int> dist,vector <bool> sptset ){
    int min= INT_MAX;
    int min_idx;
    for(int i=0;i<V;i++){
        if(!sptset[i]){
            if(dist[i]<=min){
                min=dist[i];
                min_idx=i;
            }
        }
    }
    return min_idx;
}

void djikstra(int graph[V][V], int s){
    vector <bool> sptset(V,false);
    vector <int> dist (V,INT_MAX);
    dist[s]=0;
    for(int i=0;i<V;i++){
        int u= min_dist(dist,sptset);//gets the min distance node index
        sptset[u]=true;
   
        for(int j=0;j<V;j++){
            if(graph[u][j]!=0){
                if(!sptset[j] && dist[j]!=INT_MAX){
                   dist[j]=min(dist[u]+graph[u][j],dist[j]);
                }
                else if(dist[j]==INT_MAX){
                    dist[j]=dist[u]+graph[u][j];
                }
                
            }

        }



    }
    print_solution(dist);
}

int main()
{
 
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    // Function call
    djikstra(graph, 0);
 
    return 0;
}
