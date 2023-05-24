string kthPermutation(int n, int k) {
    // Write your code here.
    int f=1;
    vector<int>v;
    for(int i=1;i<n;i++){
        f=f*i;
        v.push_back(i);
    }
    v.push_back(n);
    string ans="";
    k--;
    while(true){
        ans= ans + to_string(v[k/f]);
        v.erase(v.begin()+(k/f));
        if(v.size()==0){
            break;
        }
        k=k%f;
        f=f/v.size();
    }
    return ans;
}
