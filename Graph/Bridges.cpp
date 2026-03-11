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
void solve() {



    int n,m;
    cin >> n >> m;
    vector<vector<int>>adj(n + 1);
    vector<int>vis(n + 1, 0),low(n + 1, 1e9),depth(n + 1,0);
    map<pair<int,int>,int>edges;
    for (int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[{u,v}]++;
        edges[{v,u}]++;
    }

   
    set<pair<int,int>>bridges;
    function<void(int, int)> dfs = [&](int u, int p){
        vis[u] = 1;
        for (auto v : adj[u]) {
            if (v == p) continue;

            if (vis[v]) {
                low[u] = min(low[u], depth[v]);
                continue;
            }
            depth[v] = 1 + depth[u];
            dfs(v,u);
            low[u] = min(low[u],low[v]);


            if (low[v] > depth[u]) {
                // the edge between u and v is a bridge
                bridges.insert({u,v});
                bridges.insert({v,u});
            }
        }
    };
    dfs(1,-1);

    
    // removing the multi-edges  
    vector<pair<int,int>> del;
    for (auto [u,v] : bridges) {
        if (edges[{u,v}] > 1) del.push_back({u,v});
    }
    for(auto e : del) bridges.erase(e);

    
    // constructing the bridge-tree
    int id = 0;
    vector<int>ids(n + 1, -1);
    function<void(int)>dfs2 = [&](int u) {

        ids[u] = id;

        for (auto v : adj[u]) {
            if (ids[v] != -1 or bridges.count({u,v})) continue;
            dfs2(v);
        }
    };
    for (int i = 1; i <= n; i++) {

        if (ids[i] != -1) continue;
        id++;
        dfs2(i);
    }


    vector<vector<int>>adj_tree(n + 1);

    for (int u = 1; u <= n; u++) {
        for (auto v : adj[u]) {
            if (ids[u] == ids[v]) continue;
            adj_tree[ids[u]].push_back(ids[v]);
        }
    }

}

signed main() {
    fast
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // test
    solve();
}