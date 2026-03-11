#include <bits/stdc++.h>
#define test int tttt=0;cin>>tttt;while(tttt--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define ll long long
#define ld long double
#define int ll
using namespace std;



void ip(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
vector<vector<int>>adj;
vector<int>dp, sz, res;
void dfs1(int u, int p = 0) {

    sz[u] = 1;
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs1(v,u);
        dp[u] += dp[v] + sz[v];
        sz[u] += sz[v];
    }
}

void dfs2(int u, int p = 0) {

    res[u] = dp[u];
    for (auto v : adj[u]) {
        if (v == p) continue;
        dp[u] -= dp[v] + sz[v];
        sz[u] -= sz[v];
        dp[v] += dp[u] + sz[u];
        sz[v] += sz[u];
        dfs2(v,u);
        dp[v] -= dp[u] + sz[u];
        sz[v] -= sz[u];
        dp[u] += dp[v] + sz[v];
        sz[u] += sz[v];

    }
}
void solve() {

    int n; cin >> n;
    adj.assign(n + 1, {});
    dp.assign(n + 1, 0);
    sz.assign(n + 1, 0);
    res.assign(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1);
    dfs2(1);
    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
}
signed main() {
    fast
    ip();

    // test
    solve();
}
