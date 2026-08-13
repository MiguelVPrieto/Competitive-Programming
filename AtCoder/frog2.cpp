// AtCoder Frog 2
// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> stones;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        stones.push_back(x);
    }

    vector<int> dp(n+10);
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        int resp = LLONG_MAX;
        for (int j = 1; j <= k; j++) {
            if (i-j < 1) continue;
            resp = min(resp, dp[i-j]+abs(stones[i-j-1]-stones[i-1]));
        }
        dp[i] = resp;
    }

    cout << dp[n] << endl;
}