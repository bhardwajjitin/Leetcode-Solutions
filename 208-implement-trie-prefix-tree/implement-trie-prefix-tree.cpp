class TrieNode{
    public:
    TrieNode* arr[26];
    bool flag=false;
    
    // check if it is null
    bool check(char ch){
        return (arr[ch-'a']!=NULL);
    }
    // get the node
    TrieNode* get(char ch){
        return arr[ch-'a'];
    }
    void put(char ch,TrieNode* root){
        arr[ch-'a']=root;
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
    private:
    TrieNode* root;
    public:
    Trie(){
        root=new TrieNode();
    };

// insertion of word into the string 
    void insert(string word){
        TrieNode*temp=root;
       for(int i=0;i<word.size();i++){
        char ch=word[i];
        if(!temp->check(ch)){
            temp->put(ch,new TrieNode());
        }
        temp=temp->get(ch);
       }
      temp->setEnd();
    }
    // searching of a word in trie
    bool search(string word) {
    TrieNode*temp=root;
        for(int i=0;i<word.size();i++){
            if(!temp->check(word[i])){
                return false;
            }
            temp=temp->get(word[i]);
        }
      return temp->isEnd();
    }
    // check for the prefix
    bool startsWith(string prefix) {
        TrieNode*temp=root;
        for(int i=0;i<prefix.size();i++){
            if(!temp->check(prefix[i])){
                return false;
            }
            temp=temp->get(prefix[i]);
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