#include <bits/stdc++.h>
using namespace std;
string destuffed(string s, char start, char end){
    int n = s.size();
    string str;
    for(int i=1;i<n-1;i++){
        if(s[i]==start || s[i]==end){
            str+=s[i+1];
            i++;
        }
        else{
            str+=s[i];
        }
    }
    return str;
}
string stuffed(string s, char start, char end){
    int n = s.size();
    string str;
    str+=start;
    for(int i=0;i<n;i++){
        if(s[i]==start){
            str+=start;
        }
        else if(s[i]==end){
            str+=end;
        }
        str+=s[i];
    }
    str+=end;
    return str;
}

int main() {
    string s;
    cout<<"Enter your string"<<endl;
    cin>>s;
    cout<<"Enter the starting delemiter"<<endl;
    char start;
    cin>>start;
    cout<<"Enter the ending delemiter"<<endl;
    char end;
    cin>>end;
    cout<<"The stuffed string is"<<endl;
    string stuff = stuffed(s,start,end);
    cout<<stuff<<endl;
    cout<<"The destuffed string is"<<endl;
    string destuff = destuffed(stuff,start,end);
    cout<<destuff<<endl;
    return 0;
}
