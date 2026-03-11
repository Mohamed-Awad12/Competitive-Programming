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
const int N = 3e5+5,Z = 0, M = 1e6+5;
int a[N];


struct Node {

    int val = 1e9;

} neutral;

struct segtree {


    vector<Node>seg;
    int sz;
    segtree(int n) : seg(4 * n) {sz = n;}
    static Node merge(Node a, Node b) {
        Node res;
        res.val = min(a.val , b.val);
        return res;
    }

    Node single(int val) {
        Node res;
        res= {val};
        return res;
    }

    void build(int node, int start, int end){
        if(start == end){
            seg[node] = single(a[start]);
            return;
        }

        int mid = (start + end) >> 1;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);

         seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {

        if (idx < start or idx > end) return;
        if (start == end) {
            seg[node].val = val ;
            return;
        }
        int mid = (start + end) >> 1;
        update(node * 2,start,mid,idx,val);
        update(node * 2 + 1,mid + 1,end,idx,val);
        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }
    void update(int idx, int val) {
        update(1,0,sz-1,idx,val);
    }



    Node query(int node, int start, int end,int l, int r) {
        if (start > r or l > end) return neutral;

        if (start >= l and r >= end) return seg[node];
        int mid = (start + end) >> 1;

        auto left =  query(node * 2,start,mid,l,r);
        auto right = query(node * 2 + 1,mid + 1,end,l,r);
         return merge(left,right);
    }
    Node query(int l, int r) {
        return query(1,0,sz-1,l,r);
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
