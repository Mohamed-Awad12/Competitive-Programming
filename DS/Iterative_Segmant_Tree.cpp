struct Node {
    int val = -1e18;
};

Node neutral;
struct segtree {
    vector<Node> tree;
    int start, end;
    int n;

    segtree(int l = 0, int r = 0) : start(l), end(r) {
        int len = end - start + 1;
        n = 1;
        while (n < len) n <<= 1;
        tree.assign(2 * n, neutral);
    }

    Node pushup(Node a, Node b) {
        Node ret;
        ret.val = max(a.val, b.val);
        return ret;
    }

    void build(vector<int>& a) {
        fill(tree.begin(), tree.end(), neutral);

        for (int i = start; i <= end; i++) {
            int pos = i - start;

            if (0 <= i && i < sz(a)) {
                tree[n + pos].val = a[i];
            } else {
                tree[n + pos] = neutral;
            }
        }

        for (int i = n - 1; i >= 1; i--) {
            tree[i] = pushup(tree[i << 1], tree[i << 1 | 1]);
        }
    }

    void update(int idx, int val) {
        if (idx < start || idx > end)
            return;

        int pos = idx - start + n;
        tree[pos].val = val;

        pos >>= 1;

        while (pos) {
            tree[pos] = pushup(tree[pos << 1], tree[pos << 1 | 1]);
            pos >>= 1;
        }
    }

    Node query(int l, int r) {
        if (l > r)
            return neutral;

        l = max(l, start);
        r = min(r, end);

        if (l > r)
            return neutral;

        l = l - start + n;
        r = r - start + n;

        Node left_ans = neutral;
        Node right_ans = neutral;

        while (l <= r) {
            if (l & 1) {
                left_ans = pushup(left_ans, tree[l]);
                l++;
            }

            if (!(r & 1)) {
                right_ans = pushup(tree[r], right_ans);
                r--;
            }

            l >>= 1;
            r >>= 1;
        }

        return pushup(left_ans, right_ans);
    }
};