// CSES Graph Algorithms - Course Schedule
// https://cses.fi/problemset/task/1679

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> indegree(n, 0), toposort;
    vector<vector<int>> conec(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        conec[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int atual = q.front();
        q.pop();

        toposort.push_back(atual+1);
        for (auto adj : conec[atual]) {
            indegree[adj]--;
            if (indegree[adj] == 0) q.push(adj);
        }
    }

    if (toposort.size() != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << toposort[i] << " ";
    }
    cout << endl;
}