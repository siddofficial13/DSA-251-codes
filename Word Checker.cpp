#include<bits/stdc++.h>
struct Trie {
	Trie* child[26];
	bool isEnd;

	Trie(){
		for (int i = 0; i < 26; i++){
			child[i] = NULL;
		}
		isEnd = false;
	}
};

// Function to insert string, 'STR' in the 'Trie'.
void insert(Trie* root, string &str){
    int i = 0;

	while(i < str.length()){
        // Index of current character in 'Trie'.
        int index = str[i] - 'a';

        // Current character is not present.
		if (root->child[index] == NULL){
            // Create a new node for the current character.
			root->child[index] = new Trie();
		}
		root = root->child[index];
        i++;
	}

    // Mark the end of the string.
	root->isEnd = true;
}

// Function to find suggested correct spellings.
void findSuggestions(Trie* root, string possibleAnswer, vector<string> &res){
    // String 'possibleAnswer' is present as a complete string.
	if (root->isEnd == true){
		res.push_back(possibleAnswer);
        return;
	}

	for (int i = 0; i < 26; i++){
        // Character is present in the 'Trie'.
    	if (root->child[i] != NULL){  
            // Append the character to the 'possibleAnswer'.
        	possibleAnswer.push_back(i + 'a');

			findSuggestions(root->child[i], possibleAnswer, res);

            // Pop the last appended character.
			possibleAnswer.pop_back();
		}
	}
}

vector<string> spellChecker(vector<string> &dictionary, string &query){
    // Creating root node of 'Trie'.
    Trie* root = new Trie();

	for (int i = 0; i < dictionary.size(); i++){
		insert(root, dictionary[i]);
	}

    vector<string> result;

    for (int i = 0; i < query.length(); i++){
        // Index of current character in 'Trie'.
        int index = query[i] - 'a';

        // Current character is not present in the 'Trie'.
    	if (root->child[index] == NULL){
            // The substring of string 'query' before the current character is the longest prefix to be searched in 'dictionary'.
            string prefixQuery = query.substr(0, i);

			findSuggestions(root, prefixQuery, result);
            return result;
		}
		root = root->child[index];
	}
	
    // The string 'query' is present in the 'Trie'.
    if (root->isEnd == true){
		return result;
	}
	
    // Find suggested correct spellings for 'query' with prefix as whole string.
    findSuggestions(root, query, result);
    return result;
}
