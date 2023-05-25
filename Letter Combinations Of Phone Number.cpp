#include<bits/stdc++.h>

void solve(string &s,vector<string>&ans,string &ds,string str[],int index){
	if(index==s.size()){
		ans.push_back(ds);
		return;
	}
	int digit=s[index]-'0';
	for(int i=0;i<str[digit].size();i++){
       ds.push_back(str[digit][i]);
	   solve(s,ans,ds,str,index+1);
	   ds.pop_back();
	}
}

vector<string> combinations(string s){
	
	string str[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	vector<string>ans;
	string ds="";
	solve(s,ans,ds,str,0);
	return ans;
	// Write your code here
	
}
