#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define rep(a,b,c) for(int i=a;i<b;i=i+c) 
#define rrep(a,b,c) for(int i=a;i>=b;i=i-c)
#define pii pair<int,int> 
#define pb push_back

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> edges(m, vector<int>(3));
    rep(0, m, 1) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    vector<vector<int>> dis(n + 1, vector<int>(n + 1, LLONG_MAX));
    
    // Set distance from a node to itself to 0
    rep(1, n + 1, 1) {
        dis[i][i] = 0;
    }
    
    // Initialize distances based on the edges
    rep(0, m, 1) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        dis[u][v] = min(dis[u][v], wt);
        dis[v][u] = min(dis[v][u], wt);
    }

    // Floyd-Warshall algorithm
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][k] < LLONG_MAX && dis[k][j] < LLONG_MAX) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }

    // Process queries
    vector<pii> queries(q);
    rep(0, q, 1) {
        cin >> queries[i].first >> queries[i].second;
    }
    rep(0, q, 1) {
        int u = queries[i].first;
        int v = queries[i].second;
        if (dis[u][v] == LLONG_MAX) cout << -1 << endl;
        else cout << dis[u][v] << endl;
    }
}

signed main() {
    solve();
    return 0;
}
