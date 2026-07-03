// mask contributes to its superset
void forward(vector<int> &dp) {
    for (int cnt = 0; cnt < N; ++cnt) {
        for (int mask = 0; mask < (1<<N); ++mask) {
            if(mask & (1 << cnt))
                dp[mask] += dp[mask ^ (1<<cnt)];
            if (dp[mask] >= M) dp[mask] -= M;
        }
    }
}

// remove mask contribution to its superset
void forwardMinus(vector<int> &dp) {
    for (int cnt = 0; cnt < N; ++cnt) {
        for (int mask = 0; mask < (1<<N); ++mask) {
            if(mask & (1 << cnt))
                dp[mask] -= dp[mask ^ (1<<cnt)];
            if (dp[mask] < 0) dp[mask] += M;
        }
    }
}

// mask contributes on its subsets
void backward(vector<int> &dp) {
    for (int cnt = 0; cnt < N; ++cnt) {
        for (int mask = (1<<N) - 1; ~mask; --mask) {
            if(mask & (1 << cnt))
                dp[mask ^ (1<<cnt)] += dp[mask];
            if (dp[mask ^ (1<<cnt)] >= M) dp[mask ^ (1<<cnt)]  -= M;

        }
    }
}

// remove mask contribution on its subsets
void backwardMinus(vector<int> &dp) {
    for (int cnt = 0; cnt < N; ++cnt) {
        for (int mask = (1<<N) - 1; ~mask; --mask) {
            if(mask & (1 << cnt))
                dp[mask ^ (1<<cnt)] -= dp[mask];
            if (dp[mask ^ (1<<cnt)] < 0) dp[mask ^ (1<<cnt)] += M;
        }
    }
}