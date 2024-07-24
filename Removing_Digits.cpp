#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll solve(ll N)
{
    vector<ll> dp(N + 1, 1e9);

    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        ll temp = i;
        while (temp) {
            ll d = temp % 10;
            dp[i] = min(dp[i], 1 + dp[i - d]);
            temp /= 10;
        }
    }
    return dp[N];
}

int main()
{
    // Sample Input
    ll N ;cin>>N;

    cout << solve(N);
}
