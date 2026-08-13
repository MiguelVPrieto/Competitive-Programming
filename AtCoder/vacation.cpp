// AtCoder Vacation
// https://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> days(n+10, vector<int>(3));
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        days[i][0] = a;
        days[i][1] = b;
        days[i][2] = c;
    }

    vector<vector<int>> dp(n+10, vector<int>(3, 0));
    dp[1][0] = days[1][0];
    dp[1][1] = days[1][1];
    dp[1][2] = days[1][2];

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            int resp = 0;
            resp = max(dp[i-1][(j+1)%3]+days[i][j], dp[i-1][(j+2)%3]+days[i][j]);
            dp[i][j] = resp;
        }
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}