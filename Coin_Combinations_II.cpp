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

int main(){

    int n,x;cin>>n>>x;
    vector<int> v(n);
    rep(0,n,1) cin>>v[i];
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));

    for(int i=0;i<=n;i++) dp[i][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            int take  = 0;
            if(j >= v[i-1]) take = dp[i][j-v[i-1]];
            int not_take = dp[i-1][j];
            dp[i][j] = (take + not_take)%(1000000007);
        }
    }

    cout<<dp[n][x];
    return 0;
}