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
int solve(int ind,int x,int price[],int pages[]){
    if(ind==0 || x==0) return 0;
    int take = 0;
    if(x >= price[ind-1]) 
        take = pages[ind-1] + solve(ind-1,x-price[ind-1],price,pages);
    int not_take = solve(ind-1,x,price,pages);
    return max(take,not_take);
}

int main(){

    int n,x;cin>>n>>x;
    int price[n];
    int pages[n];

    rep(0,n,1) cin>>price[i];
    rep(0,n,1) cin>>pages[i];

    vector<vector<int>> dp(n+1,vector<int>(x+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++)
        {
            
            int take = (j >= price[i-1]) ?  
                (pages[i-1]%MOD + dp[i-1][j-price[i-1]]%MOD)%MOD : 0;
            int not_take =  (i==1)? 0 : dp[i-1][j]%MOD;
            dp[i][j] = max(take,not_take)%MOD;
        }
    }

    cout<<dp[n][x]<<endl;
    return 0;
}