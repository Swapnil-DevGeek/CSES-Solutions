#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define rep(a,b,c) for(int i=a;i<b;i=i+c) 
#define rrep(a,b,c) for(int i=a;i>=b;i=i-c)
#define vi(n) vector<ll> v(n,0)
#define yes() cout<<"YES"<<endl;
#define no() cout<<"NO"<<endl;
#define pii pair<int,int> 
#define pb push_back

void fun(int node,vector<int>& vis,vector<int> adj[],vector<int> &ans,bool &fl){
    int col= ans[node];
    for(auto &it : adj[node]){
        if(!vis[it]){
            vis[it]=1;
            ans[it] = col==1 ? 2: 1;
            fun(it,vis,adj,ans,fl);
        }
        else{
            if(ans[it]==col)
                fl = false;
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<pii> edges(m);
    rep(0,m,1)
        cin>>edges[i].first>>edges[i].second;
    vector<int> ans(n+1);
    vector<int> adj[n+1];
    rep(0,m,1){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> vis(n+1,0);
    rep(1,n+1,1){
        if(!vis[i]){
            vis[i] = 1;
            ans[i] = 1;
            bool fl = true;
            fun(i,vis,adj,ans,fl);
            if(!fl){
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
    }
    rep(1,n+1,1) cout<<ans[i]<<" ";
}

int main(){

    int t;t=1;
    while(t--){
        solve();
    }
    return 0;
}