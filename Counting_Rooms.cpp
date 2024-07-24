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

void dfs(int i,int j,vector<vector<char>>& grid){
    grid[i][j]='#';
    int n = grid.size();
    int m = grid[0].size();
    if(i>0 && grid[i-1][j]=='.') dfs(i-1,j,grid);
    if(i<n-1 && grid[i+1][j]=='.') dfs(i+1,j,grid);
    if(j>0 && grid[i][j-1]=='.') dfs(i,j-1,grid);
    if(j<m-1 && grid[i][j+1]=='.') dfs(i,j+1,grid);
    return;  
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.'){
                dfs(i,j,grid);
                ans++;
            }
        }
    }   
    cout<<ans;
}

int main(){

    int t;t=1;
    while(t--){
        solve();
    }
    return 0;
}
