#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll solve(ll N, ll X, vector<ll>& coins)
{ 
    ll dp[X + 1] = {};

    dp[0] = 1;

    for (int i = 1; i <= X; i++) {
        for (int j = 0; j < N; j++) {
            
            if (coins[j] > i)
                continue;
            dp[i] = (dp[i] + dp[i - coins[j]]) % mod;
        }
    }
    
    return dp[X];
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<ll> coins(n);
    for(int i=0;i<n;i++)cin>>coins[i];

    cout << solve(n, x, coins) << "\n";
}
