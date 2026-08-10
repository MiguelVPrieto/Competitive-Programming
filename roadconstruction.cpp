// CSES Graph Algorithms - Road Construction
// https://cses.fi/problemset/task/1676

#include <bits/stdc++.h>
using namespace std;

int n, m;
int cc;
int maxpeso = 1;
vector<int> pai, peso;

int find(int x) {
    if (pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if (x==y) return;

    if (peso[x] > peso[y]) swap(x, y);
    pai[x] = y;
    peso[y] += peso[x];
    cc--;
    maxpeso = max(maxpeso, peso[y]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cc = n;
    pai.resize(n);
    peso.resize(n, 1);
    for (int i = 0; i < n; i++) {
        pai[i] = i;
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        join(a, b);
        cout << cc << " " << maxpeso << endl;
    }
}