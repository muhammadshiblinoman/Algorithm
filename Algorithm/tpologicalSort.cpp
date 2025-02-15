#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long

const int N = 1e5+123;
vector<int>adj[N];
int vis[N];
int n, m;

void dfs(int node, stack<int>&st) {
    vis[node] = 1;
    for(auto u: adj[node]) {
        if(!vis[u]) {
            dfs(u, st);
        }
    }

    st.push(node);
}

void solve() {
    cin >> n >> m;

    while(m--) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    stack<int>st;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, st);
        }
    }

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
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