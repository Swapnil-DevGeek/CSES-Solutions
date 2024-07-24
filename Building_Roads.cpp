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

class DSU{
    public:
    vector<int> parent,size;
        DSU(int n) {
            parent.resize(n+1);
            size.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
                size[i] = 1;
            }

        }
        int findUpar(int u){
            if(u == parent[u])
                return u;
            return parent[u] = findUpar(parent[u]);
        }
        void unionBySize(int x,int y){
            int ulp_x = findUpar(x);
            int ulp_y = findUpar(y);
            if(ulp_x==ulp_y) return;
            if(size[ulp_x] < size[ulp_y]){
                parent[ulp_x] = ulp_y;
                size[ulp_y] += size[ulp_x];
            }
            else{
                parent[ulp_y] = ulp_x;
                size[ulp_x] += size[ulp_y];
            }
        }
};

void solve(){
    int n,m;
    cin>>n>>m;
    vector<pii> arr(m);
    rep(0,m,1){
        cin>>arr[i].first>>arr[i].second;
    }

    DSU dsu(n);
    rep(0,m,1){
        int x = arr[i].first;
        int y = arr[i].second;
        dsu.unionBySize(x,y);
    }
    int k = 0;
    vector<pii> roads;
    int upar;
    vector<int> parent = dsu.parent;
    for(int i=1;i<=n;i++){
        if(parent[i]==i){
            upar = i;
            break;
        }
    }
    rep(1,n+1,1){
        if(parent[i]==i and i!=upar){
            k++;
            roads.pb({upar,i});
        }
    }
    cout<<k<<endl;
    for(auto x:roads) cout<<x.first<<" "<<x.second<<endl;
}

int main(){

    int t;t=1;
    while(t--){
        solve();
    }
    return 0;
}