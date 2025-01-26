#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
const int N = 1e5;
int parent[N], Rank[N];

void Initialize() {
    for(int i = 0; i < N; i++) {
        parent[i] = i;
    }
}

int findPar(int node) {
    if(parent[node] == node)
        return node;

    return parent[node] = findPar(parent[node]);
}

void Union(int node1, int node2) {
    int x = findPar(node1);
    int y = findPar(node2);

    if(x == y) return;

    if(Rank[x] > Rank[y]) {
        parent[y] = x;
    } else if(Rank[y] > Rank[x]) {
        parent[x] = y;
    } else {
        parent[y] = x;
        Rank[x]++;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    Initialize();

    while(m--) {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    int cnt = 0;

    for(int i = 0; i < n; i++) {
        if(parent[i] == i)
            cnt++;
    }

    cout << cnt << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1; 
    // cin >> tc;
    for( int t = 1; t <= tc; t++ ) {
        solve();
    }
}