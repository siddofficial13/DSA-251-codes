class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        double ans=0.0;
        while(s[i]==' ' && i<n){
            i++;
        }
        bool positive = s[i] == '+';
        bool negative = s[i] == '-';
        positive == true ? i++ : i;
        negative == true ? i++ : i;
        while(i<n && s[i]<='9' && s[i]>='0'){
           ans=ans*10 + (s[i]-'0');
           i++;
        }
        if(negative){
            ans=-ans;
        }
        if(ans>INT_MAX){
            ans=INT_MAX;
        }
        if(ans<INT_MIN){
            ans=INT_MIN;
        }
        return int(ans);
    }
};
