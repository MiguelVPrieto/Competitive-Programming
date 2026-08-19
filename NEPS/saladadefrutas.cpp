// OBI 2024 Fase 2B - Nivel 2
// https://neps.academy/br/exercise/3128

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r;
    cin >> r >> n;

    vector<pair<int, int>> feira1, feira;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        feira1.push_back({a, b});
    }
    sort(feira1.begin(), feira1.end());
    int lastt = -1;
    for (int i = 0; i < n; i++) {
        if (feira1[i].first != lastt) {
            lastt = feira1[i].first;
            feira.push_back(feira1[i]);
        }
    }

    n = feira.size();

    vector<vector<int>> dp(n+1, vector<int>(r+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= r; j++) {
            if (j-feira[i-1].second < 0) {
                dp[i][j] = dp[i-1][j];
                continue;
            }
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-feira[i-1].second]+1);
        }
    }

    cout << dp[n][r] << endl;
}