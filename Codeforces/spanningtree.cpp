// Codeforces - Spanning Tree
// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/E

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
vector<int> pai, peso;
vector<pair<int, pair<int, int>>> edges;
int cost = 0;

int find(int x) {
    if (pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void juntar(int a, int b) {
    a = find(a);
    b = find(b);

    if (a==b) return;
    if (peso[a] > peso[b]) swap(a, b);
    pai[a] = b;
    peso[b] += peso[a];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    peso.resize(n, 1);
    pai.resize(n);
    for (int i = 0; i < n; i++) {
        pai[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges.push_back({c, {a, b}});
    }
    sort(edges.begin(), edges.end());

    for (int i = 0; i < m; i++) {
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if (find(a) == find(b)) continue;
        cost += edges[i].first;
        juntar(a, b);
    }

    cout << cost << endl;
}