#include <bits/stdc++.h>
#define test int tttt=0;cin>>tttt;while(tttt--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define ll long long
#define ld long double
#define int ll
#define sz(s) (int)(s).size()
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast,unroll-loops")


void ip(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
class  DSU {
public:
    vector<int> root;
    vector<int> sz;
    DSU(int n) {
        root.assign(n + 1, 0);
        sz.assign(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            root[i] = i;
        }
    }

    int getRoot(int node) {
        if (root[node] == node) return node;
        return root[node] = getRoot(root[node]);
    }

    void unionSets(int u, int v) {
        u = getRoot(u);
        v = getRoot(v);
        if (u == v) return;
        if (sz[u] > sz[v]) swap(u, v);
        root[u] = v;
        sz[v] += sz[u];
    }

    bool sameSet(int u, int v) {
        return getRoot(u) == getRoot(v);
    }

    int largestSet() {
        return *max_element(sz.begin(), sz.end());
    }

    int smallestSet() {
        return *min_element(sz.begin(), sz.end());
    }
    size_t sizeOfRoot() {
        return root.size();
    }

};
void solve() {
}

signed main() {
    fast
    ip();

    // test
    solve();
}
