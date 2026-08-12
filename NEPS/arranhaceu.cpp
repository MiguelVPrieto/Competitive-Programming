// OBI Fase 3 Nivel 2 2017
// https://neps.academy/br/exercise/43

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, q;
vector<int> p;
vector<int> bit;

void update(int id, int x) {
    while (id <= n) {
        bit[id] += x;
        id += id&-id;
    }
}

int soma(int id) {
    int resp = 0;

    while (id > 0) {
        resp += bit[id];
        id -= id&-id;
    }
    return resp;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    p.resize(n+10);
    bit.resize(n+10);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        p[i] = x;
        update(i, x);
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int a, b;
            cin >> a >> b;
            int dif = b-p[a];
            update(a, dif);
            p[a] = b;
        } else {
            int a;
            cin >> a;
            cout << soma(a) << '\n';
        }
    }
}