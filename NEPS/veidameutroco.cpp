// Neps Academy Véi, Dá Meu Troco!
// https://neps.academy/br/exercise/308

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> dp(m+10, 0), moedas;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        moedas.push_back(x);
    }

    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            if (i-moedas[j] < 0) continue;
            if (dp[i-moedas[j]]) {
                dp[i] = 1;
                break;
            }
        }
    }

    if (dp[m]) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }
}