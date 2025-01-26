#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+123;
int parent[N];
int Rank[N];

void Initialize(int node) {
    for(int i = 0; i <= node; i++)
        parent[i] = i;
}

int findParent(int node) {
    if(node == parent[node])
        return node;

    return parent[node] = findParent(parent[node]);
}

void Union(int node1, int node2) {
    int ulp_u = findParent(node1);
    int ulp_v = findParent(node2);

    if(ulp_u == ulp_v) return;

    if(Rank[ulp_u] > Rank[ulp_v]) {
        parent[ulp_v] = ulp_u;
    } else if(Rank[ulp_u] < Rank[ulp_v]) {
        parent[ulp_u] = ulp_v;
    } else {
        parent[ulp_v] = ulp_u;
        Rank[ulp_u]++;
    }
}

int main() {
    int node, edge;
    cin >> node >> edge;

    Initialize(node);

    for(int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;

        Union(u, v);
    }

    int q;
    cin >> q;

    while(q--) {
        int node1, node2;
        cin >> node1 >> node2;

        cout << parent[node1] << " " <<parent[node2] << ' ';

        if(parent[node1] == parent[node2]) {
            cout << "SAME\n";
        } else {
            cout << "NOT SAME\n";
        }
    }
}