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
    int n;cin>>n;
    vi(n);
    rep(0,n,1) cin>>v[i];
    vector<int> lis;
    lis.pb(v[0]);
    rep(1,n,1){
        if(v[i] > lis.back()){
            lis.pb(v[i]);
        }
        else{
            int ind= lower_bound(lis.begin(),lis.end(),v[i])-lis.begin();
            lis[ind]=v[i];
        }
    }
    cout<<lis.size()<<endl;
}

int main(){

    int t;t=1;
    while(t--){
        solve();
    }
    return 0;
}