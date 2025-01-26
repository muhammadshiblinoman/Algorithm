#include <bits/stdc++.h>
#define int long long

#define inff 100000000000000
using namespace std;

const int mx=1e7+11;
vector<pair<int,int>>adj[mx];
vector<int>ans[mx];
int dist[mx];
 
void dijkstra(int s,int n){
    for(int i=1;i<=n;i++) dist[i]=inff;
    dist[s]=0;   
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,s});
    while(!pq.empty()){
        int u=pq.top().second;
        int curD=pq.top().first;
        pq.pop();
        if(dist[u]<curD) continue; 
 
        for(auto p:adj[u]){
            int v=p.first;
            int w=p.second;
            if(curD+w<dist[v]){
                dist[v]=curD+w;
                pq.push({dist[v],v});
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m; cin>>n>>m;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        //adj[v].push_back({u,w});   
    }
    dijkstra(1,n);
    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
    cout<<'\n';
}