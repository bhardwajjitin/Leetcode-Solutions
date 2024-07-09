class TrieNode{
    public:
    TrieNode* arr[2];
    bool flag=false;
    
    // check if it is null
    bool check(char ch){
        return (arr[ch-'0']!=NULL);
    }
    // get the node
    TrieNode* get(char ch){
        return arr[ch-'0'];
    }
    void put(char ch,TrieNode* root){
        arr[ch-'0']=root;
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
          char ch=word[i];
          char re;
          if(ch-'0'==0){
            re='1';
          }
          else{
            re='0';
          }
          if(temp->check(re)){
            ans+="1";
            temp=temp->get(re);
          }
          else{
            ans+="0";
            temp=temp->get(ch);
          }
        }
      return temp->isEnd();
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int cnt=0;
        while(maxi!=0){
          maxi>>=1;
          cnt++;
        }
        if(cnt==0)return 0;
        Implement ts;
        for(int i=0;i<nums.size();i++){
            string word=bitset<32>(nums[i]).to_string().substr(32-cnt,32);
            ts.insert(word);
        }
        int temp=0;
        for(int i=0;i<nums.size();i++){
            string word=bitset<32>(nums[i]).to_string().substr(32-cnt,32);
            string ans="";
            ts.search(word,ans);
            int res=stoi(ans,nullptr,2);
            temp=max(temp,res);
        }
        return temp;
    }
};