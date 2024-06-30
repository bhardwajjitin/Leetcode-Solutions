class Trie{
  private:
  Trie*arr[26];
  bool flag=false;
  public:
  bool contains(char ch){
    return arr[ch-'a']!=NULL;
  }
  void put(char ch,Trie*node){
    arr[ch-'a']=node;
  }
  Trie*get(char ch){
    return arr[ch-'a'];
  }
  void setEnd(){
    flag=true;
  }
  bool isEnd(){
    return flag;
  }
};
class TrieNode{
  private:
  Trie*root=new Trie();
  public:
  void insert(string word){
    Trie*temp=root;
    for(int i=0;i<word.size();i++){
      if(!temp->contains(word[i])){
        temp->put(word[i],new Trie());
      }
      temp=temp->get(word[i]);
    }
    temp->setEnd();
  }
  bool checkpre(string word){
    Trie*temp=root;
    for(int i=0;i<word.size();i++){
      temp=temp->get(word[i]);
      if(!temp->isEnd()){
          return false;
      }
    }
    return true;
  }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
      TrieNode ts;
        for(int i=0;i<words.size();i++){
          string res=words[i];
          ts.insert(res);
        }
        string ans="";
        for(int i=0;i<words.size();i++){
           if(ts.checkpre(words[i])){
              if(ans.length()<words[i].length()){
                ans=words[i];
              }
              else if(ans.length()==words[i].length() && ans>words[i]){
                ans=words[i];
              }
           }
        }
        return ans;
    }
};