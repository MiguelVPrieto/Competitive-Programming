// OBI 2025 Fase 2 - Nivel 2
// https://neps.academy/br/exercise/3267

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int gotas[n][m], gotas2[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> gotas[i][j];
            gotas2[i][j] = gotas[i][j];
        }
    }

    // gotas[i][j]%2 == 0
    // (i+j)%2 == 0 ^
    int add1 = 0;
    if (gotas[0][0]%2 == 1) {
        gotas[0][0]++;
        add1++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i != 0) {
                if ((gotas[i][j]+gotas[i-1][j])%2 == 0) {
                    if (gotas[i][j]%2 == 1 && (i+j)%2 == 0) {
                        gotas[i][j]++;
                        add1++;
                    } else if (gotas[i][j]%2 == 0 && (i+j)%2 == 1) {
                        gotas[i][j]++;
                        add1++;
                    }
                }
            }
            if (j != 0 ) {
                if ((gotas[i][j]+gotas[i][j-1])%2 == 0) {
                    if (gotas[i][j]%2 == 1 && (i+j)%2 == 0) {
                        gotas[i][j]++;
                        add1++;
                    } else if (gotas[i][j]%2 == 0 && (i+j)%2 == 1) {
                        gotas[i][j]++;
                        add1++;
                    }
                }
            }
        }
    }

    // gotas2[i][j]%2 == 1
    // (i+j)%2 == 0 ^
    int add2 = 0;
    if (gotas2[0][0]%2 == 0) {
        gotas2[0][0]++;
        add2++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i != 0) {
                if ((gotas2[i][j]+gotas2[i-1][j])%2 == 0) {
                    if (gotas2[i][j]%2 == 1 && (i+j)%2 == 1) {
                        gotas2[i][j]++;
                        add2++;
                    } else if (gotas2[i][j]%2 == 0 && (i+j)%2 == 0) {
                        gotas2[i][j]++;
                        add2++;
                    }
                }
            }

            if (j != 0) {
                if ((gotas2[i][j]+gotas2[i][j-1])%2 == 0) {
                    if (gotas2[i][j]%2 == 1 && (i+j)%2 == 1) {
                        gotas2[i][j]++;
                        add2++;
                    } else if (gotas2[i][j]%2 == 0 && (i+j)%2 == 0) {
                        gotas2[i][j]++;
                        add2++;
                    }
                }
            }
        }
    }

    if (add1 < add2) {
        cout << add1 << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << gotas[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << add2 << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << gotas2[i][j] << " ";
            }
            cout << endl;
        }
    }
}