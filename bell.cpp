#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u, v, w;
};

void bellman(vector<edge> arr, int s, int v, int e){
    vector<int> dist(v, INT_MAX);
    dist[s] = 0;
    for(int i = 0; i < v; i++){
        for(int j = 0; j < e; j++){
            int s = arr[j].u;
            int e = arr[j].v;
            int wt = arr[j].w;

            if(dist[s] != INT_MAX && dist[s] + wt < dist[e]){
                dist[e] = dist[s] + wt;
            }
        }
    }

    for(int j = 0; j < e; j++){
            int s = arr[j].u;
            int e = arr[j].v;
            int wt = arr[j].w;

            if(dist[s] != INT_MAX && dist[s] + wt < dist[e]){
                cout<<"Negative cycle exists.."<<endl;
                return;
            }
        }

        for(int i = 0; i < v; i++){
            cout<<s<<" -> "<<i<<" : "<<dist[i]<<endl;
        }
    
}

int main(){

    int v, e;
    cout<<"enter v : ";
    cin>>v;
    cout<<"enter e : ";
    cin>>e;
    vector<edge> arr(e);
    cout<<"enter edges (u v w)"<<endl;
    for(int i = 0; i < e; i++){
        cin>>arr[i].u>>arr[i].v>>arr[i].w;
    }

    int s;
    cout<<"enter source : ";
    cin>>s;

    bellman(arr, s, v, e);

    return 0;
}
