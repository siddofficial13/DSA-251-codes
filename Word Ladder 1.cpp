class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int cnt=q.front().second;
            q.pop();
            if(word==endWord){
                return cnt;
            }
            for(int i=0;i<word.size();i++){
                char ch=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,cnt+1});
                    }
                }
                word[i]=ch;
            }
        }
        return 0;
    }
};
