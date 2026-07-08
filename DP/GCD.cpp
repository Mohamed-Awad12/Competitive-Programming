int n; cin >> n;
    vector<int> arr(n);
    vector<int> freq(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        freq[arr[i]]++;
    }


    vector<int> dp(n + 1);
    for (int i = n; i >= 1; --i) {

        int cnt = 0;
        for (int j = i; j <= n; j += i) {
            cnt += freq[j];
        }

        dp[i] = cnt * (cnt - 1) / 2;

        for (int j = 2 * i; j <= n; j += i) {
            dp[i] -= dp[j];
        }
    }