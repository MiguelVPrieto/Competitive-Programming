// AtCoder Frog 1
// https://atcoder.jp/contests/dp/tasks/dp_a

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> stones;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        stones.push_back(x);
    }

    vector<int> dp(n+10, -1);
    dp[1] = 0;
    dp[2] = abs(stones[0]-stones[1]);
    for (int i = 3; i <= n; i++) {
        dp[i] = min(dp[i-2] + abs(stones[i-3]-stones[i-1]), dp[i-1] + abs(stones[i-2]-stones[i-1]));
    }

    cout << dp[n] << endl;
}