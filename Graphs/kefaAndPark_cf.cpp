// Link : https://codeforces.com/problemset/problem/580/C
#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    int n,m;
    cin>>n>>m;
    
    std::vector<int> cats(n+1);
    
    for(int i=1;i<=n;i++)
    {
        cin>>cats[i];
    }
    
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }   
    
    int c = 0;
    if(cats[1]==1)
        c = 1;
    
    int cnt = 0;
    std::queue<pair<int,int>> q;
    q.push({1,c});
    vector<int> vis(n+1,0);
    vis[1]= 1;
    
    while(!q.empty()){
        auto fr = q.front();
        q.pop();
        int node = fr.first;
        int ct = fr.second;
        if(ct > m) continue;
        bool added = false;
        for(auto& it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                added = true;
                if(cats[it]==1){
                    q.push({it,ct+1});
                }
                else{
                    q.push({it,0});
                }
            }
        }
        if(!added){
            cnt++;
        }
    }
    
    cout<<cnt<<endl;
    return 0;
}
