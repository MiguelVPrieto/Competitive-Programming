// AtCoder Stones
// https://atcoder.jp/contests/abc270/tasks/abc270_d

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
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        stones.push_back(x);
    }

    vector<vector<int>> dp(n+10, vector<int>(2, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (i-stones[j] < 0) continue;
            dp[i][0] = max((i-stones[j] - dp[i-stones[j]][1]) + stones[j], dp[i][0]);
            dp[i][1] = max((i-stones[j] - dp[i-stones[j]][0]) + stones[j], dp[i][1]);
        }
    }

    cout << max(dp[n][0], (n-dp[n][1])) << endl;
}