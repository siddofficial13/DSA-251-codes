long long compute_hash(string const &s, int len) {
    const int p = 31;
    const int m = 1e9 + 7;
    long long hash_value = 0;
    long long p_pow = 1;
    for (int i = 0; i < len; i++) {
        hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

vector<int> stringMatch(string &str, string &pat) {
    vector<int> ans;
    long long hash_pattern = compute_hash(pat, pat.size());
    int n = str.size();
    int m = pat.size();
    int i = 0;
    while (i <= n - m) {
        string temp = str.substr(i, m);
        long long hash_text = compute_hash(temp, m);
        if (hash_text == hash_pattern) {
            ans.push_back(i);
        }
        i++;
    }
    return ans;
}
