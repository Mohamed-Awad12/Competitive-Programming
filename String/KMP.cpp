vector<int> prefix_function(const string& s) {
    int n = s.size();
    vector<int> pi(n);

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        }

        pi[i] = j;
    }

    return pi;
}

vector<int> kmp(const string& text, const string& pattern) {
    string s = pattern + '#' + text;
    vector<int> pi = prefix_function(s);

    vector<int> occurrences;
    int m = pattern.size();

    for (int i = m + 1; i < (int)s.size(); i++) {
        if (pi[i] == m) {
            int pos = i - 2 * m;
            occurrences.push_back(pos);
        }
    }

    return occurrences;
}