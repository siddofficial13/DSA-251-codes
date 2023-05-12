#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string reverseStringWordWise(string s)
{
     vector<string> res;
        string str = "";
        int n = s.size();
        for(int i = n-1 ; i >= 0 ; i--) {
            if(s[i] != ' ') str += s[i];
            else {
                reverse(str.begin(), str.end());
                res.push_back(str);
                str = "";
            }
        }        
        string ans = "";
        for(int i = 0 ; i < res.size() ; i++) {
            ans += res[i];
            ans += ' ';
        }        
        if(str.size() != 0) {
            reverse(str.begin(), str.end());
            ans += str;
        }

        string st = "";
        int ind1 = 0;
        while(ans[ind1] == ' '){
            ind1++;
        }
        
        int ind2 = ans.length()-1;
        while(ans[ind2] == ' '){
            ind2--;
        }
        
        for(int i = ind1 ; i <= ind2 ; i++) st += ans[i];
        
      
        
        string finl = "";
        int j = 0;

        string final_ans = "";
        for(int i = 0 ; i < st.size() ; i++) {
            if(st[i] != ' ') {
                final_ans += st[i];
            }
            else{
                while(st[i] == ' ') i++;
                final_ans += ' ';
                i--;
            }
        }
        return final_ans;
    //Write your code here
}

int main()
{
    string s;
    getline(cin, s);
    string ans = reverseStringWordWise(s);
    cout << ans << endl;
}
