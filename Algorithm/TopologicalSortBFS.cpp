#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long

const int N = 1e5+123;
vector<int>adj[N];
int vis[N];
int n, m;

void solve() {
    cin >> n >> m;

    while(m--) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    int inDegree[n] = {0};

    for(int i = 0; i < n; i++) {
        for(auto u: adj[i]) {
            inDegree[u]++;
        }
    }

    queue<int>qu;

    for(int i = 0; i < n; i++) {
        if(inDegree[i] == 0) {
            qu.push(i);
        }
    }

    vector<int>ans;

    while(!qu.empty()) {
        int node = qu.front();
        qu.pop();
        ans.push_back(node);

        for(auto u: adj[node]) {
            inDegree[u]--;
            if(inDegree[u] == 0) {
                qu.push(u);
            }
        }
    }

    for(auto u: ans) {
        cout << u << " ";
    } cout << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1; 
    // cin >> tc;
    for( int t = 1; t <= tc; t++ ) {
        solve();
    }
}