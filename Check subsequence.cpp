#include <bits/stdc++.h> 
bool isSubSequence(string str1, string str2) {
    // Write your code here.
    int n1 = str1.size();
    int n2 = str2.size();
    int i=0;
    int j=0;
    int count=0;
    while(i<n1 && j<n2){
        if(str1[i]==str2[j]){
            i++;
            j++;
            count++;
        }
        else{
            j++;
        }
    }
    return (count==n1);
}
