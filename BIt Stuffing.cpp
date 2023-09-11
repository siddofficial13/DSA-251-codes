#include <bits/stdc++.h>
using namespace std;

string destuffing(string stuff){
    int n = stuff.size();
    string str="";
    int curr_count=0;
    for(int i=0;i<n;i++){
        if(stuff[i]=='0'){
            str+='0';
            curr_count=0;
        }
        else if(stuff[i]=='1'){
            str+='1';
            curr_count++;
            if(curr_count==5){
                i++;
                curr_count=0;
            }
        }
    }
    return str;
}

int main() {
    string s;
    cout<<"Enter your string"<<endl;
    cin>>s;
    int n = s.size();
    int curr_count=0;
    string str="";
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            curr_count=0;
            str+='0';
        }
        else if(s[i]=='1'){
            curr_count++;
            str+='1';
            if(curr_count==5){
                str+='0';
                curr_count=0;
            }
        }
    }
    cout<<"The bit stuffed string is"<<endl;
    cout<<str<<endl;
    string destuffed = destuffing(str);
    cout<<"The destuffed string is"<<endl;
    cout<<destuffed<<endl;

    return 0;
}
