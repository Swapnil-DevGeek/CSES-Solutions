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
const int MOD = 1000000007;
int rec(int ind,int sum,vector<vector<int>>& dp){
    if(ind==0) return 0;
    if(sum==0) return 1;
    if(dp[ind][sum]!=-1) return dp[ind][sum];
    int take=0,not_take=0;
    if(sum >= ind) take= rec(ind-1,sum-ind,dp);
    not_take=rec(ind-1,sum,dp);
    return dp[ind][sum] = (take + not_take)%MOD;
}
void solve(){
    int n;cin>>n;
    int tot = (n*(n+1))/2;
    if(tot%2){
        cout<<0;
        return;
    }
    int sum = tot/2;
    vector<int> arr(n);
    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
    cout<<rec(n,sum,dp);
}

int main(){

    int t;t=1;
    while(t--){
        solve();
    }
    return 0;
}