class TrieNode {
public:
    map<char, TrieNode*> children;
    bool EOW;

    TrieNode() {
        this->EOW = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        this->root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = this->root;

        for (int i=0; i<word.size(); i++){
            if (curr->children.find(word[i]) == curr->children.end()) {
                curr->children[word[i]] = new TrieNode();
            }
            curr = curr->children[word[i]];
        }

        curr->EOW = true;
    }
    
    bool search(string word) {
        TrieNode* curr = this->root;

        for (int i=0; i<word.size(); i++){
            if (curr->children.find(word[i]) == curr->children.end()) {
                return false;
            }
            curr = curr->children[word[i]];
        }

        return curr->EOW;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = this->root;

        for (int i=0; i<prefix.size(); i++){
            if (curr->children.find(prefix[i]) == curr->children.end()) {
                return false;
            }
            curr = curr->children[prefix[i]];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
