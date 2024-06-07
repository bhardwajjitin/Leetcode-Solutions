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
class Implement{
    private:
    TrieNode* root;
    public:
    Implement(){
        root=new TrieNode();
    };

// insertion of word into the string 
    void insert(string&word){
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
    bool search(string word,string&ans) {
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
    bool startsWith(string prefix,string&ans) {
        TrieNode*temp=root;
        for(int i=0;i<prefix.size();i++){
            if(!temp->check(prefix[i])){
                return false;
            }
            temp=temp->get(prefix[i]);
            ans+=prefix[i];
            if(temp->isEnd()){
              break;
            }
        }
        return true;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
      Implement obj;
        int m=dictionary.size();
        int n=sentence.size();
        string res="";
        for(int i=0;i<m;i++){
          string res=dictionary[i];
          obj.insert(res);
        }
        string temp="";
        for(int j=0;j<n;j++){
            if(sentence[j]==' '){
              string ans="";
              if(obj.startsWith(temp,ans)){
              res+=ans+" ";
              }
              else{
                res+=temp+" ";
              }
              temp="";
            }
            else{
              temp+=sentence[j];
            }
        }
        string ans="";
        if(obj.startsWith(temp,ans)){
          res+=ans;
        }
        else{
          res+=temp;
        }
        return res;
    }
};