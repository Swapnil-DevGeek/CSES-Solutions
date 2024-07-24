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

int solve(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
    if(i==s1.length()or j==s2.length())
        return max(s1.length()-i,s2.length()-j);    

    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]) return dp[i][j] = solve(i+1,j+1,s1,s2,dp);

    return dp[i][j] =1 + min({solve(i+1,j+1,s1,s2,dp),solve(i+1,j,s1,s2,dp),solve(i,j+1,s1,s2,dp)});
}

int main(){

    string s1,s2;
    cin>>s1>>s2;

    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int ans = solve(0,0,s1,s2,dp);
    cout<<ans;
    return 0;
}