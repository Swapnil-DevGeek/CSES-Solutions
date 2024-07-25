#include<bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int i=a;i<b;i=i+c) 
#define pii pair<int,int> 
#define pb push_back

bool dfs(int node, int p, vector<int> adj[], vector<int>& vis, vector<int>& par, int &sp, int &ep) {
    vis[node] = 1;
    par[node] = p;
    for (auto it : adj[node]) {
        if (it == p) continue;
        if (vis[it]) {
            sp = it;
            ep = node;
            return true;
        }
        if (!vis[it]) {
            if (dfs(it, node, adj, vis, par, sp, ep))
                return true;
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> edges(m);
    rep(0, m, 1)
        cin >> edges[i].first >> edges[i].second;
    vector<int> adj[n + 1];
    rep(0, m, 1) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int sp = -1, ep = -1;
    vector<int> vis(n + 1, 0);
    vector<int> par(n + 1, -1);
    bool is_cycle = false;
    rep(1, n + 1, 1) {
        if (!vis[i]) {
            if (dfs(i, -1, adj, vis, par, sp, ep)) {
                is_cycle = true;
                break;
            }
        }
    }

    if (!is_cycle) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> ans;
    ans.pb(ep);
    int cur = ep;
    while (cur != sp) {
        ans.pb(par[cur]);
        cur = par[cur];
    }
    reverse(ans.begin(), ans.end()); 
    ans.pb(sp);  
    cout << ans.size() << endl;
    for (auto &n : ans) cout << n << " ";
    cout << endl;
}

int main() {
    int t; t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
