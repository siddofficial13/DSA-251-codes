class Solution {
public:
    string commonPrefix(string &str1, string &str2){
        int n=min(str1.size(),str2.size());
        string result="";
        for(int i=0;i<n;i++){
            if(str1[i]!=str2[i]){
                break;
            }
            result+=str1[i];
        }
        return result;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string prefix=strs[0];
        for(int i=1;i<strs.size();i++){
            prefix=commonPrefix(prefix,strs[i]);
        }
        return prefix;
    }
};
