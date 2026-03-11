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

const int N = 5e5 + 5, LOG = 30;
vector<vector<pair<int,int>>> adj;
int up[N][LOG], lvl[N],cost_Max[N][LOG], cost_min[N][LOG];
int merge(int a, int b, bool mx) {
    return mx? max(a,b) : min(a,b);

}
void dfs(int u, int p){
    for(int j = 1; j < LOG; j++){
        up[u][j] = up[up[u][j - 1]][j - 1];
        cost_Max[u][j] = merge(cost_Max[u][j - 1], cost_Max[up[u][j - 1]][j - 1],1);
        cost_min[u][j] = merge(cost_min[u][j - 1], cost_min[up[u][j - 1]][j - 1],0);
    }

    for(auto [v,c] : adj[u]){
        if(v == p) continue;
        up[v][0] = u;
        cost_Max[v][0] = c;
        cost_min[v][0] = c;

        lvl[v] = lvl[u] + 1;
        dfs(v, u);
    }
}

int getKthParent(int u, int k){
    for(int j = LOG - 1; j >= 0; j--){
        if((k >> j) & 1){
            u = up[u][j];
        }
    }
    return u;
}

int lca(int u, int v) {
    if(lvl[u] < lvl[v]) swap(u, v);
    u = getKthParent(u, lvl[u] - lvl[v]);
    if(u == v) return u;
    for(int j = LOG - 1; j >= 0; j--){
        if(up[u][j] != up[v][j]){
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}
int dis(int u, int v){
    int ans = lvl[u] + lvl[v] - 2 * lvl[lca(u, v)];
    return ans;
}

int get_cost(int u, int k,bool mx) {
    int mx_c = 0, mn_c = 1e9;
    int uu = u;
    for(int j = LOG - 1; j >= 0; j--){
        if((k >> j) & 1){
            mx_c = merge(mx_c, cost_Max[u][j],1);
            u = up[u][j];
        }
    }
    for(int j = LOG - 1; j >= 0; j--){
        if((k >> j) & 1){
            mn_c = merge(mn_c, cost_min[uu][j],0);
            uu = up[uu][j];
        }
    }
    return (mx? mx_c : mn_c);
}
array<int,2> query(int a, int b) {

    int lc = lca(a,b);
    return {
        merge(get_cost(a, lvl[a] - lvl[lc],1), get_cost(b, lvl[b] - lvl[lc],1),1),
        merge(get_cost(a, lvl[a] - lvl[lc],0), get_cost(b, lvl[b] - lvl[lc],0),0)
    };
}
void solve() {
}

signed main() {
    fast
    ip();

    // test
    solve();
}
