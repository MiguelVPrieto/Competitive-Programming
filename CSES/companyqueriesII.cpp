// CSES Tree Algorithms - Company Queries II
// https://cses.fi/problemset/task/1688

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> up(31, vector<int>(n+10));
    vector<vector<int>> listAdj(n+10);
    vector<int> depth(n+10, -1);
    up[0][1] = -1;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        up[0][i] = x;
        listAdj[x].push_back(i);
    }

    for (int i = 1; i < 31; i++) {
        for (int j = 1; j <= n; j++) {
            if (up[i-1][j] == -1) up[i][j] = -1;
            else up[i][j] = up[i-1][up[i-1][j]];
        }
    }

    queue<int> q1;
    q1.push(1);
    depth[1] = 0;
    while (!q1.empty()) {
        int atual = q1.front();
        q1.pop();

        for (auto adj : listAdj[atual]) {
            if (depth[adj] == -1) {
                depth[adj] = depth[atual]+1;
                q1.push(adj);
            }
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        if (depth[b] > depth[a]) swap(a, b);
        int diff = depth[a] - depth[b];
        for (int i = 30; i >= 0; i--) {
            if (diff&(1<<i)) {
                a = up[i][a];
            }
        }

        if (a == b) {
            cout << a << endl;
        } else {
            for (int i = 30; i >= 0; i--) {
                if (up[i][a] != up[i][b]) {
                    a = up[i][a];
                    b = up[i][b];
                }
            }
            cout << up[0][a] << endl;
        }
    }
}