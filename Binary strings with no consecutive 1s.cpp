vector<string> generateString(int k) {

    if (k == 0) return {};

    if (k == 1){
        return {"0","1"};
    }
    
    vector<string> v = generateString(k-1);
    vector<string> ans;
    for (auto x : v){
        string temp = x + "0";
        ans.push_back(temp);

        if (x.back() == '0'){
            string temp1 = x + "1";
            ans.push_back(temp1);
        }   
    }

    return ans;
}
