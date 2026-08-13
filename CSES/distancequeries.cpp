// CSES Tree Algorithms - Distance Queries
// https://cses.fi/problemset/task/1135

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

vector<vector<int>> up;
vector<vector<int>> listAdj;
vector<int> depth;
void dfs(int x) {
    for (auto adj : listAdj[x]) {
        if (depth[adj] == -1) {
            up[0][adj] = x;
            depth[adj] = depth[x]+1;
            dfs(adj);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    listAdj.resize(n+10);
    up.resize(31, vector<int>(n+10, 0));
    depth.resize(n+10, -1);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        listAdj[a].push_back(b);
        listAdj[b].push_back(a);
    }

    up[0][1] = -1;
    depth[1] = 0;
    dfs(1);

    for (int i = 1; i < 31; i++) {
        for (int j = 1; j <= n; j++) {
            if (up[i-1][j] == -1) up[i][j] = -1;
            else up[i][j] = up[i-1][up[i-1][j]];
        }
    }

    while (q--) {
        int a, b, a1, b1;
        cin >> a >> b;

        if (depth[b] > depth[a]) swap(a, b);
        a1 = a;
        b1 = b;
        int diff = depth[a] - depth[b];

        for (int i = 30; i >= 0; i--) {
            if (diff&(1<<i)) {
                a = up[i][a];
            }
        }

        if (a == b) {
            cout << diff << endl;
        } else {
            for (int i = 30; i >= 0; i--) {
                if (up[i][a] != up[i][b]) {
                    a = up[i][a];
                    b = up[i][b];
                }
            }
            a = up[0][a];
            cout << (depth[b1]-depth[a]) + (depth[a1]-depth[a]) << endl;
        }
    }
}