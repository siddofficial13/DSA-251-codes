class Solution {
public:
    string reverseWords(string s) {
   stack<string> st;
        int lo = 0;
        int hi = s.size() - 1;
        string word = "";
        
        // Find the starting and ending indices of the non-space characters
        while (lo < s.size() && s[lo] == ' ') {
            lo++;
        }
        
        while (hi >= 0 && s[hi] == ' ') {
            hi--;
        }
        
        int i = hi;
        while (i >= lo) {
            if (s[i] == ' ') {
                i--;
            } else {
                string temp = "";
                while (i >= lo && s[i] != ' ') {
                    temp += s[i];
                    i--;
                }
                reverse(temp.begin(), temp.end());
                word += temp;
                word += ' ';
            }
        }
        
        if (!word.empty()) {
            word.pop_back(); // Remove the trailing space
        }
        
        return word;
    }
    
};
