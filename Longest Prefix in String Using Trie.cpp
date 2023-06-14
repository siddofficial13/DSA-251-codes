#include <bits/stdc++.h>

struct Node {
  Node* links[26];
  bool flag = false;

  bool containKey(char ch) {
    return (links[ch - 'a'] != nullptr);
  }

  Node* get(char ch) {
    return links[ch - 'a'];
  }

  void setEnd() {
    flag = true;
  }

  bool isEnd() {
    return flag;
  }

  void put(char ch, Node* node) {
    links[ch - 'a'] = node;
  }
};

class Trie {
 private:
  Node* root;

 public:
  Trie() {
    root = new Node();
  }

  void insert(std::string word) {
    Node* node = root;
    for (int i = 0; i < word.size(); i++) {
      if (!node->containKey(word[i])) {
        node->put(word[i], new Node());
      }
      node = node->get(word[i]);
    }
    node->setEnd();
  }

  bool checkPrefixExists(std::string word) {
    bool f1 = true;
    Node* node = root;
    for (int i = 0; i < word.size(); i++) {
      if (node->containKey(word[i])) {
        node = node->get(word[i]);
        if (node->isEnd() == false) {
          return false;
        }
      }
    }
    return true;
  }
};

std::string completeString(int n, std::vector<std::string>& a) {
  // Write your code here.
  Trie* trie = new Trie();
  for (auto it : a) {
    trie->insert(it);
  }

  std::string longest = "";
  for (auto it : a) {
    if (trie->checkPrefixExists(it)) {
      if (it.size() > longest.size()) {
        longest = it;
      } else if (it.size() == longest.size() && it < longest) {
        longest = it;
      }
    }
  }

  if (longest == "") {
    return "None";
  }

  return longest;
}
