#include<bits/stdc++.h>
struct Node{
    Node * links[2];
    bool containKey(int bit){
        return (links[bit]!=NULL);
    }
    Node * get(int bit){
        return links[bit];
    }
    void put(int bit, Node * node){
        links[bit]=node;
    }

};
class Trie{
  private:
  Node * root;
  public:
  Trie(){
      root=new Node();
  } 
  public:
   void insert(int n){
       Node * node = root;
       for(int i=31;i>=0;i--){
           int bit=(n>>i)&1;
           if(!node->containKey(bit)){
               node->put(bit,new Node());
           }
           node=node->get(bit);
       }
   }
   public:
   int getmax(int num){
       Node * node = root;
       int maxNum=0;
       for(int i=31;i>=0;i--){
           int bit=(num>>i)&1;
           if(node->containKey(1-bit)){
               maxNum=maxNum | (1<<i);
               node = node->get(1-bit);
           }
           else{
            node =node->get(bit);
           }
       }
       return maxNum;
   }
};
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    // Write your code here.   
    Trie * trie= new Trie();
    for(auto it:arr1)trie->insert(it);
    int maxm=0;
    for(auto it:arr2){
        maxm=max(maxm,trie->getmax(it));
    }
    return maxm;

}
