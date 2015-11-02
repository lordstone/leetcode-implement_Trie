class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        count = 0;
        for(int i = 0; i < 26; i ++)
            children[i] = NULL;
    }
    TrieNode *children[26];
    int count;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        if(word.length() == 0) return;
        int ptr = 0;
        TrieNode *cur = root;
        while (ptr < word.length()){
            if(cur -> children[word[ptr] - 'a']  == NULL)
                cur -> children[word[ptr] - 'a'] = new TrieNode();
            cur = cur -> children[word[ptr++] - 'a'];
        }//end while
        cur -> count ++;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        if(word.length() == 0) return false;
        int ptr = 0;
        TrieNode * cur = root;
        while(ptr < word.length()){
            if(cur -> children[word[ptr] - 'a']  == NULL) return false;
            cur = cur -> children[word[ptr++] - 'a'];
        }//end while
        if(cur -> count > 0) return true;
        else return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if(prefix.length() == 0) return true;
        int ptr = 0;
        TrieNode * cur = root;
        while(ptr < prefix.length()){
            if(cur -> children[prefix[ptr] - 'a']  == NULL) return false;
            cur = cur -> children[prefix[ptr++] - 'a'];
        }//end while
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
