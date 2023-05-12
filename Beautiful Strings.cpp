#include <bits/stdc++.h>
int makeBeautiful(string str) {
	int n = str.size();
	string s1="";
	string s2="";
	for(int i=0;i<n;i+=2){
		s1+='0';
		s1+='1';
		s2+='1';
		s2+='0';
	}
	int count1=0;
	int count2=0;
	for(int i=0;i<n;i++){
		if(str[i]!=s1[i])count1++;
		if(str[i]!=s2[i])count2++;
	}
	return min(count1,count2);
	// Write your code here
}
