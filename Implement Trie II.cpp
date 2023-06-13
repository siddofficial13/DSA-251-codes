#include <bits/stdc++.h> 
struct Node {
    Node * links[26];
    int countEndWith=0;
    int countPrefix=0;
    bool flag=false;
    bool containKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
    void put(char ch, Node * node){
        links[ch -'a'] = node;
    }
    void increaseEnd(){
        countEndWith++;
    }
    void increasePrefix(){
        countPrefix++;
    }
    void deleteEnd(){
        countEndWith--;
    }
    void reducePrefix(){
        countPrefix--;
    }
    int getEnd(){
        return countEndWith;
    }
    int getPrefix(){
        return countPrefix;
    }
};
class Trie{
    private:
    Node * root;
    public:

    Trie(){
        root=new Node();
        // Write your code here.
    }

    void insert(string &word){
        Node * node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
        // Write your code here.
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node * node = root;
        for(int i=0;i<word.size();i++){
            if(node->containKey(word[i])){
                node = node->get(word[i]);
            }
            else{
               return 0; 
            }
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node * node = root;
        for(int i=0;i<word.size();i++){
            if(node->containKey(word[i])){
                node = node->get(word[i]);
            }
            else{
               return 0; 
            }
        }
        return node->getPrefix();

    }

    void erase(string &word){
        // Write your code here.
        Node * node = root;
        for(int i=0;i<word.size();i++){
            if(node -> containKey(word[i])){
                node=node->get(word[i]);
                node->reducePrefix();
            }
            else{
                return;
            }
        }
        node->deleteEnd();
    }
};
