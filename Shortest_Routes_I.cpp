#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define rep(a,b,c) for(int i=a;i<b;i=i+c) 
#define rrep(a,b,c) for(int i=a;i>=b;i=i-c)
#define yes() cout<<"YES"<<endl;
#define no() cout<<"NO"<<endl;
#define pii pair<int,int> 
#define pb push_back
const int MOD = 1000000007;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(m,vector<int>(3));
    rep(0,m,1){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
    vector<vector<pii>> adj(n+1);
    rep(0,m,1){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].pb({v,wt});
    }

    vector<int> dis(n+1,LLONG_MAX);
    dis[1] = 0;
    priority_queue<pii,vector<pii>, greater<pii>> pq;
    pq.push({0,1}); 
    while(!pq.empty()){
        auto [cur_dis,node] = pq.top();
        pq.pop();
        if(cur_dis > dis[node]) continue;
        for(auto [neib,wt] : adj[node]){
            if(dis[node] + wt < dis[neib]){
                dis[neib] = (dis[node] + wt) ;
                pq.push({dis[neib],neib});
            }
        }
    }
    rep(1,n+1,1) cout<<dis[i]<<" ";
}

signed main(){
    solve();
    return 0;
}
