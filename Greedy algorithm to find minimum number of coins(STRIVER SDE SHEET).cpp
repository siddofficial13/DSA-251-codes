#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    int coins[] ={1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n=9;
    int count=0;
    for(int i=n-1;i>=0;i--){
        int temp=0;
        while(amount>=coins[i]){
            amount-=coins[i];
            temp++;
        }
        count+=temp;
    }
    return count;
}
//Striver Code
#include<bits/stdc++.h>


using namespace std;
int main() {
  int V = 49;
  vector < int > ans;
  int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  int n = 9;
  for (int i = n - 1; i >= 0; i--) {
    while (V >= coins[i]) {
      V -= coins[i];
      ans.push_back(coins[i]);
    }
  }
  cout<<"The minimum number of coins is "<<ans.size()<<endl;
  cout<<"The coins are "<<endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
