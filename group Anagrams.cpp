#include <bits/stdc++.h> 
long long compute_hash(string const &s){
    const int p =31;
    const int m = 1e9+9;
    long long hash_value = 0;
    long long p_pow=1;
    for(char c: s){
        hash_value = (hash_value+(c-'a'+1)*p_pow)%m;
        p_pow = (p_pow*p)%m;
    }
    return hash_value;
}
vector<vector<string>> getGroupedAnagrams(vector<string> &inputStr, int n)
{
    // Write your code here.
    vector<pair<long long,string>>hashes(n);
    for(int i=0;i<n;i++){
        string temp=inputStr[i];
        sort(temp.begin(),temp.end());
        hashes[i] = {compute_hash(temp),inputStr[i]};
    }
    sort(hashes.begin(),hashes.end());
    vector<vector<string>>groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    return groups;

}
