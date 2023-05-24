#include <bits/stdc++.h> 
//Base Approach
//    void subsets(vector < int > & nums, int index, vector < int > ds, set < vector < int >> & res) {
//       if (index == nums.size()) {
//         sort(ds.begin(), ds.end());
//         res.insert(ds);
//         return;
//       }
//       ds.push_back(nums[index]);
//       subsets(nums, index + 1, ds, res);
//       ds.pop_back();
//       subsets(nums, index + 1, ds, res);
//     }
//optimal approach
void subsets(int ind, vector < int > & nums, vector < int > & ds, vector < vector < int >> & ans) {
         ans.push_back(ds);
         for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);
            subsets(i + 1, nums, ds, ans);
            ds.pop_back();
         }
      }

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>>ans;
    // set<vector<int>>s;
    vector<int>ds;
    sort(arr.begin(),arr.end());
    subsets(0,arr,ds,ans);
    // for(auto it =s.begin(); it!=s.end();it++){
    //     ans.push_back(*it);
    // }
    return ans;
}
