class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size()==1) return fruits.size();

        int n =fruits.size();
        int i=0;
        int j=0;
        int ans=INT_MIN;
        unordered_map<int,int> mp;
        while(j<n){
            mp[fruits[j]]++;
            if(mp.size()<2){
                j++;
            }
            if(mp.size()==2){
                ans=max(ans,j-i+1);
                j++;
            }
            else if(mp.size()>2){
                while(mp.size()>2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0){
                        mp.erase(fruits[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        if(mp.size()==1){
            auto it=mp.begin();
            return it->second;
        }
        return ans;

    }
};
