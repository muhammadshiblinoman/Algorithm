#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int>adj[N];
int path[N];

void dfs(int node, int par = -1) {
    path[node] = par;

    for(auto child: adj[node]) {
        if(child == par) continue;
        dfs(child, node);
    }
}

vector<int> findPath(int v) {
    vector<int>ans;

    while(v != -1) {
        ans.push_back(v);
        v = path[v];
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    int a, b;
    cin >> a >> b;

    vector<int>fr = findPath(a);
    vector<int>se = findPath(b);

    int m = min(fr.size(), se.size());

    int ans = -1;

    for(int i = 0; i < m; i++) {
        if(fr[i] == se[i]) {
            ans = fr[i];
        } else {
            break;
        }
    }

    cout << ans << '\n';
    return 0;
}
