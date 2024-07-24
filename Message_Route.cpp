#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define rep(a,b,c) for(int i=a;i<b;i=i+c) 
#define rrep(a,b,c) for(int i=a;i>=b;i=i-c)
#define vi(n) vector<ll> v(n,0)
#define yes() cout<<"YES"<<endl;
#define no() cout<<"NO"<<endl;
#define pii pair<ll,ll> 
#define pb push_back

void solve(){
    int n,m;
    cin>>n>>m;
    vector<pii> arr(m);
    rep(0,m,1)
        cin>>arr[i].first>>arr[i].second;
    
    vector<int> adj[n+1];
    rep(0,m,1){
        int u=arr[i].first,v=arr[i].second;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    vector<int> vis(n+1,0);
    vector<int> dist(n+1,1e9);
    vector<int> par(n+1);
    vis[1]=1;dist[1]=0;par[1]=-1;
    pq.push({0,1,-1});

    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        int cur_dis= top[0];
        int node = top[1];
        for(int &u : adj[node]){
            if(vis[u]) continue;
            vis[u]=1;
            dist[u]=cur_dis+1;
            par[u]=node;
            pq.push({dist[u],u,par[u]});
        }
    }
    if(!vis[n]){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    cout<<dist[n]+1<<endl;
    vector<int> path;
    int cur=n;
    while(cur!=-1){
        path.pb(cur);
        cur = par[cur];
    }
    reverse(path.begin(),path.end());
    rep(0,path.size(),1)
        cout<<path[i]<<" ";
}

int main(){

    int t;t=1;
    while(t--){
        solve();
    }
    return 0;
}