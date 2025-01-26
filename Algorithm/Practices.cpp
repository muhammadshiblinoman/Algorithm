// DFS
/*vector<vector<int>> adj; // graph represented as an adjacency list
int n; // number of vertices
vector<bool> visited;
void dfs(int v) {
//Process v here…
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
}*/

// BFS
/*vector<vector<int>> adj;  // adjacency list representation
int n; // number of nodes
int s; // source vertex
queue<int> q;
vector<bool> used(n);
vector<int> d(n), p(n);
q.push(s);
used[s] = true;
p[s] = -1;
while (!q.empty()) {
    int v = q.front();
//Process v here…
    q.pop();
    for (int u : adj[v]) {
        if (!used[u]) {
            used[u] = true;
            q.push(u);
            d[u] = d[v] + 1;
            p[u] = v;
        }
    }
}
// To see shortest path(less edge)
if (!used[u])
{
    cout << "No path!";
}
else
{
    vector<int> path;
    for (int v = u; v != -1; v = p[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    cout << "Path: ";
    for (int v : path)
        cout << v << " ";
}*/

// Dijkstra
/*void dijkstra(vector<vector<pair<ll, ll>>> &adj, vector<ll> &dis, vector<ll> &pre, ll start)
{
    ll n = adj.size();  // adj[from].push_back({to,weight});
    dis.assign(n, INF); // distance from start
    pre.assign(n, -1);  // store predecessor
    dis[start] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        pair<ll, ll> top = pq.top();
        pq.pop();
        if (dis[top.second] < top.first)
            continue;
        for (auto i : adj[top.second])
        {
            ll to = i.first;
            ll len = i.second;
            if (dis[to] > top.first + len)
            {
                dis[to] = top.first + len;
                pq.push({dis[to], to});
                pre[to] = top.second;
            }
        }
    }
}*/