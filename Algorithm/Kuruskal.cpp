#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
const int N = 1e5;
int vis[N];

void solve() {
    int n, m;
    cin >> n >> m;

    priority_queue<pair<int,pair<int,int>>> pq;
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        pq.push({-w, {u, v}});
    }

    vector<pair<int,int>>ans;
    int sum = 0;
    int i = 0;

    while(!pq.empty() && i <= n) {
        int w = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        if(vis[u] && vis[v]) {
            continue;
        }

        ans.push_back({u, v});
        vis[u] = 1, vis[v] = 1;
        sum += abs(w);
        i++;
    }

    cout << "MINIMUM SPANING TREE = " << sum << '\n'; 
    for(auto u: ans) {
        cout << u.first << " " <<  u.second << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1; 
    // cin >> tc;
    for( int t = 1; t <= tc; t++ ) {
        solve();
    }
}