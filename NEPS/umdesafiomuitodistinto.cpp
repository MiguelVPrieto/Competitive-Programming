// OBI 2025 Fase 2 - Nivel 2
// https://neps.academy/br/exercise/3268

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int soma(int a, int x) {
    int s = 0;
    int x1 = x-a;
    s = (x1*(x1+1))/2;
    s += a*(x1+1);
    return s;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int p;
    cin >> p;
    while (p--) {
        int l, a, b;
        cin >> l >> a >> b;

        int r = 0;
        int l1 = a;
        int r1 = b;
        int res = r1;
        while (l1 <= r1) {
            int mid = (l1+r1)/2;
            if (soma(a, mid) >= l) {
                res = mid;
                r1 = mid-1;
            } else {
                l1 = mid+1;
            }
        }
        r = res-a+1;
        cout << r << endl;
    }
}