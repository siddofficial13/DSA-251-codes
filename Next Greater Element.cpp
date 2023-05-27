//Not A Circular Array
#include <bits/stdc++.h>

vector<int> nextGreater(vector<int> &arr, int n) {

// Write your code here

stack<int>s;

 

s.push(-1);

for(int i=n-1; i>=0; i--){

int curr=arr[i];

while(!s.empty() && s.top()<=curr){

s.pop();

}

if(s.empty()){

arr[i]=-1;

}

else{

arr[i]=s.top();

}

s.push(curr);

}

return arr;

}

//Circular Array Approach
#include<bits/stdc++.h>

using namespace std;
class Solution {
  public:
    vector < int > nextGreaterElements(vector < int > & nums) {
      int n = nums.size();
      vector < int > nge(n, -1);
      stack < int > st;
      for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
          st.pop();
        }

        if (i < n) {
          if (!st.empty()) nge[i] = st.top();
        }
        st.push(nums[i % n]);
      }
      return nge;
    }
};
int main() {
  Solution obj;
  vector < int > v {5,7,1,2,6,0};
  vector < int > res = obj.nextGreaterElements(v);
  cout << "The next greater elements are" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
}
