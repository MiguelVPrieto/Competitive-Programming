// Codeforces Mortal Kombat Tower
// https://codeforces.com/problemset/problem/1418/C

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n == 0) {
            cout << 0 << endl;
            continue;
        }

        vector<int> boss;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            boss.push_back(x);
        }
        vector<vector<int>> dp(n, vector<int>(2, 1e5*2));

        dp[0][0] = boss[0];

        if (n >= 2) {
            dp[1][0] = dp[0][0] + boss[1];
            dp[1][1] = dp[0][0];
        }

        for (int i = 2; i < n; i++) {
            dp[i][0] = min(boss[i] + dp[i-1][1], boss[i] + boss[i-1] + dp[i-2][1]);
            dp[i][1] = min(dp[i-1][0], dp[i-2][0]);
        }

        cout << min(dp[n-1][0], dp[n-1][1]) << endl;
    }
}