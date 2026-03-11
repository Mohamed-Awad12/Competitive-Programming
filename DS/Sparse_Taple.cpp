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

const int N = 1e5 + 5, LOG = 18;
int a[N];


int table[N][LOG], logs[N];
int merge(int x, int y) {
    return min(x,y);
}
void build(int n){
    for(int i = 0; i < n; i++){
        table[i][0] = a[i];
    }

    for(int j = 1; j < LOG; j++){
        for(int i = 0; i + (1<<j) <= n; i++){
            table[i][j] = merge(table[i][j - 1], table[i + (1<<(j - 1))][j - 1]);
        }
    }
    logs[1] = 0;
    for(int i = 2; i <= n; i++){
        logs[i] = logs[i >> 1] + 1;
    }
}

int query(int l, int r){
    int j = logs[r - l + 1];
    return merge(table[l][j], table[r - (1<<j) + 1][j]);
}


void solve() {

}

signed main() {
    fast
    ip();

    // test
    solve();
}