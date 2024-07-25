#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define rep(a,b,c) for(int i=a;i<b;i=i+c) 
#define rrep(a,b,c) for(int i=a;i>=b;i=i-c)
#define vi(n) vector<int> v(n,0)
#define yes() cout<<"YES"<<endl;
#define no() cout<<"NO"<<endl;
#define pii pair<int,int> 
#define pb push_back
void dijkstra(int src,vector<pii> adj[],vector<int>& dis){
    dis[src] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        auto [cur_dis,node] = pq.top();
        pq.pop();
        if(cur_dis > dis[node]) continue;
        for(auto [v,w] : adj[node]){
            if(dis[v] > w + dis[node])
            {
                dis[v] = w +dis[node];
                pq.push({dis[v],v});
            }
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<pii> adj1[n+1];
    vector<pii> adj2[n+1];
    vector<vector<int>> edges(m,vector<int>(3));
    rep(0,m,1){
        int u,v,w;
        cin>>u>>v>>w;
        adj1[u].pb({v,w});
        adj2[v].pb({u,w});
        edges[i] = {u,v,w};
    }
    vector<int> dis1(n+1,LLONG_MAX);
    vector<int> dis2(n+1,LLONG_MAX);
    dijkstra(1,adj1,dis1);
    dijkstra(n,adj2,dis2);

    int ans = LLONG_MAX;
    rep(0,m,1){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        if (dis1[u] != LLONG_MAX && dis2[v] != LLONG_MAX) {
            int path = dis1[u] + dis2[v] + w / 2;
            ans = min(ans, path);
        }
    }

    cout<<ans<<endl;
}

signed main(){

    int t;t=1;
    while(t--){
        solve();
    }
    return 0;
}