#include <bits/stdc++.h>
#define ll long long int
#define INF 1000000000
using namespace std;

ll solve(ll N, ll X, vector<ll>& coins)
{
    vector<ll> dp(X + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= X; i++) {
        for (int j = 0; j < N; j++) {
            if (coins[j] > i || dp[i - coins[j]] == INF)
                continue;
            dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }
    if (dp[X] != INF)
        return dp[X];

    return -1;
}

int main()
{
    ll N , X ; cin>>N>>X;
    vector<ll> coins(N);
    for(ll i=0;i<N;i++) cin>>coins[i];
    
    cout << solve(N, X, coins) << "\n";
}
