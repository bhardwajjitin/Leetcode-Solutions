class Trie{
public:
    Trie* arr[26];
    int cntpre=0;

bool check(char ch){
    return arr[ch-'a']!=NULL;
}
Trie*get(char ch){
    return arr[ch-'a'];
}
void put(char ch,Trie*temp){
    arr[ch-'a']=temp;
}
void incpre(){
    cntpre++;
}
int getpre(){
    return cntpre;
}
};
class Solution {
    private:
    Trie*root;
    public:
    Solution(){
        root=new Trie();
    }
    void insert(string word){
        Trie*temp=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(!temp->check(ch)){
                temp->put(ch,new Trie());
            }
            temp=temp->get(ch);
            temp->incpre();
        }
    }
    int getsum(string word){
        Trie*temp=root;
        int sum=0;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
              if(!temp->check(ch))return sum;
              temp=temp->get(ch);
              sum+=temp->getpre();
        }
        return sum;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
       for(int i=0;i<words.size();i++){
        string res=words[i];
        insert(res);
       } 
       vector<int>ans;
       for(int i=0;i<words.size();i++){
           int temp=getsum(words[i]);
           ans.push_back(temp);
       }
       return ans;
    }
};