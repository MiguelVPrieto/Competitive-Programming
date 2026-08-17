// AtCoder Knapsack 1
// https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> items;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        items.push_back({a, b});
    }

    vector<vector<int>> dp(w+10, vector<int>(n+10));

    for (int i = 0; i <= n; i++) {
        dp[0][i] = 0;
    }

    for (int i = 0; i <= w; i++) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= n; j++) {
            if (i-items[j-1].first < 0) {
                dp[i][j] = dp[i][j-1];
                continue;
            }
            dp[i][j] = max(dp[i][j-1], dp[i-items[j-1].first][j-1] + items[j-1].second);
        }
    }

    cout << dp[w][n] << endl;
}