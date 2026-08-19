// OBI 2024 Fase 2B - Nivel 2
// https://neps.academy/br/exercise/3130

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> dp(n+1);
    dp[0] = n;
    for (int i = 1; i <= n; i++) {
        string s = to_string(dp[i-1]);
        int mini = dp[i-1];
        for (int j = 0; j < s.size(); j++) {
            mini = min(mini, dp[i-1]-(s[j] - '0'));
        }
        dp[i] = mini;
        if (dp[i] == 0) {
            cout << i << endl;
            break;
        }
    }
}