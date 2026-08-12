// CSES Range Queries - Range Updates and Sums
// https://cses.fi/problemset/task/1735/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n, q;
vector<int> nums;

class Node {
public:
    int soma = 0;
    int lazy1 = -1;
    int lazy2 = -1;

    Node operator + (Node a) {
        Node resp;
        resp.soma = soma+a.soma;
        return resp;
    }
};

vector<Node> tree;

void build(int node, int l, int r) {
    if (l==r) {
        tree[node].soma = nums[l];
        return;
    }
    int mid = (l+r)/2;

    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    tree[node] = tree[2*node] + tree[2*node+1];
}

void propagar(int node, int l, int r) {
    if (tree[node].lazy1 == -1 && tree[node].lazy2 == -1) return;

    if (tree[node].lazy2 != -1) {
        tree[node].soma = tree[node].lazy2*(r-l+1);
    }
    if (tree[node].lazy1 != -1) {
        tree[node].soma += tree[node].lazy1*(r-l+1);
    }

    if (l!=r) {
        if (tree[node].lazy2 != -1) {
            tree[2*node].lazy2 = tree[node].lazy2;
            tree[2*node].lazy1 = -1;
            tree[2*node+1].lazy2 = tree[node].lazy2;
            tree[2*node+1].lazy1 = -1;
        }
        if (tree[node].lazy1 != -1) {
            if (tree[2*node].lazy1 == -1) tree[2*node].lazy1++;
            if (tree[2*node+1].lazy1 == -1) tree[2*node+1].lazy1++;
            tree[2*node].lazy1 += tree[node].lazy1;
            tree[2*node+1].lazy1 += tree[node].lazy1;
        }
    }

    tree[node].lazy1 = -1;
    tree[node].lazy2 = -1;
}

void update(int node, int l, int r, int p, int q, int t, int x) {
    propagar(node, l, r);
    if (r<p || l>q) return;
    if (p<=l && r<=q) {
        if (t == 1) {
            if (tree[node].lazy1 == -1) tree[node].lazy1++;
            tree[node].lazy1 += x;
        } else {
            tree[node].lazy1 = -1;
            tree[node].lazy2 = x;
        }
        propagar(node, l, r);
        return;
    }
    int mid = (l+r)/2;

    update(2*node, l, mid, p, q, t, x);
    update(2*node+1, mid+1, r, p, q, t, x);

    tree[node] = tree[2*node] + tree[2*node+1];
}

void query(int node, int l, int r, int p, int q, Node &resp) {
    propagar(node, l, r);
    if (r<p || l>q) return;
    if (p<=l && r<=q) {
        resp = resp + tree[node];
        return;
    }
    int mid = (l+r)/2;

    query(2*node, l, mid, p, q, resp);
    query(2*node+1, mid+1, r, p, q, resp);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    nums.resize(n+10);
    tree.resize(4*n+1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    build(1, 1, n);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b, x;
            cin >> a >> b >> x;
            update(1, 1, n, a, b, t, x);
        } else if (t == 2) {
            int a, b, x;
            cin >> a >> b >> x;
            update(1, 1, n, a, b, t, x);
        } else {
            int a, b;
            cin >> a >> b;
            Node resp;
            query(1, 1, n, a, b, resp);
            cout << resp.soma << endl;
        }
    }
}