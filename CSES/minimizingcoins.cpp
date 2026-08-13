// CSES Dynamic Programming - Minimizing Coins
// https://cses.fi/problemset/task/1634

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> coins, dp(x+10, -1);
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        coins.push_back(y);
    }

    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        int resp = LLONG_MAX;
        for (int j = 0; j < n; j++) {
            if (i-coins[j] < 0) continue;
            if (dp[i-coins[j]] != -1) {
                resp = min(resp, dp[i-coins[j]]+1);
            }
        }
        if (resp == LLONG_MAX) resp = -1;
        dp[i] = resp;
    }

    cout << dp[x] << endl;
}