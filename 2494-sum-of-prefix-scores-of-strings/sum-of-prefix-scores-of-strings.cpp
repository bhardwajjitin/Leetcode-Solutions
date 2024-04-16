// class Trie{
// private:
//     Trie* arr[26];
//     int cntpre=0;

// public:
// bool check(char ch){
//     return arr[ch-'a']!=NULL;
// }
// Trie*get(char ch){
//     return arr[ch-'a'];
// }
// void put(char ch,Trie*temp){
//     arr[ch-'a']=temp;
//     cntpre++;
// }
// void incpre(){
//     cntpre++;
// }
// int getpre(){
//     return cntpre;
// }
// };
class TrieNode {
    public:
    TrieNode* children[26];
    int count=0;
};
class Solution {
    // private:
    // Trie*root;
    // public:
    // Solution(){
    //     root=new Trie();
    // }
    // void insert(string word){
    //     Trie*temp=root;
    //     for(int i=0;i<word.size();i++){
    //         char ch=word[i];
    //         if(!temp->check(ch)){
    //             temp->put(ch,new Trie());
             
    //         }
    //         else{
    //             temp->incpre();
    //         }
    //            cout<<ch<<" "<<temp->getpre()<<endl;
    //         temp=temp->get(ch);
    //     }
    // }
    // int getsum(string word){
    //     Trie*temp=root;
    //     int sum=0;
    //     for(int i=0;i<word.size();i++){
    //         char ch=word[i];
    //         sum+=temp->getpre();
    //         temp=temp->get(ch);
    //     }
    //     return sum;
    // }
    public:
    void insert(TrieNode* root, string s) {
        TrieNode* currNode = root;
        for(int i=0; i<s.size(); i++) {
            char c = s[i];
            if(currNode->children[c-'a'] == NULL) currNode->children[c-'a'] = new TrieNode();
            currNode = currNode->children[c-'a'];
            currNode->count++;
        }
    }
    int getCount(TrieNode* root, string s) {
        TrieNode* currNode = root;
        int ans = 0;
        for(int i=0; i<s.size(); i++) {
            char c = s[i];
            if(currNode->children[c-'a'] == NULL) return ans;
            currNode = currNode->children[c-'a'];
            ans += currNode->count;
        }
        return ans;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
       for(int i=0;i<words.size();i++){
        string res=words[i];
        insert(root, res);
       } 
    //    int temp=getsum(words[0]);
    //    int temp1=getsum(words[1]);
    //    int temp2=getsum(words[2]);
       vector<int>ans;
       for(int i=0;i<words.size();i++){
           int temp=getCount(root, words[i]);
           ans.push_back(temp);
       }
       return ans;
    }
};