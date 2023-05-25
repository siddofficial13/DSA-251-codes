#include <bits/stdc++.h> 
void solve(string str,vector<string> &ans, string ds,int index){
	if(index>=str.size()){
       if(ds.size()>0){
		   ans.push_back(ds);
		   
	   }
	   return;
	}
	ds.push_back(str[index]);
	solve(str,ans,ds,index+1);
	// ds.push_back(str[index]);
	ds.pop_back();
	solve(str,ans,ds,index+1);
}

vector<string> subsequences(string str){
	vector<string> ans;
	string ds="";
	int index=0;
	solve(str,ans,ds,index);
	return ans;


	// Write your code here
	
}
