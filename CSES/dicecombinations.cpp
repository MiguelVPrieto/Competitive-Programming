// CSES Dynamic Programming - Dice Combinations
// https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int MOD = 1e9+7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> dp(n+10, 0);

    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        int resp = 0;
        for (int j = 1; j <= 6; j++) {
            if (i-j < 1) continue;
            resp = (resp+dp[i-j])%MOD;
        }
        if (i <= 6) resp = (resp+1)%MOD;
        dp[i] = resp;
    }

    cout << dp[n] << endl;
}