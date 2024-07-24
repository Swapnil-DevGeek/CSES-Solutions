#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define rep(a,b,c) for(int i=a;i<b;i=i+c) 
#define rrep(a,b,c) for(int i=a;i>=b;i=i-c)
#define vi vector<ll> 
#define yes() cout<<"YES"<<endl;
#define no() cout<<"NO"<<endl;
#define pii pair<ll,ll> 
#define pb push_back

const int MOD = 1e9 + 7;  

int main() {
    int n; cin >> n;
    vector<int> dp(n+1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6 and i-j>=0;j++){
            dp[i] = (dp[i]+ dp[i-j])%MOD;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}