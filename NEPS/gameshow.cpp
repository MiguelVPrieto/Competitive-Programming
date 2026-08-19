// OBI 2024 Fase 2B - Nivel 2
// https://neps.academy/br/exercise/3127

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int a = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'E') {
            a = a*2;
        } else {
            a = a*2+1;
        }
    }
    cout << a << endl;
}