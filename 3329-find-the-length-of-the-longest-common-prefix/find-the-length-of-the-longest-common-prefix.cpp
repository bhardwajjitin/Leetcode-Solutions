class Trie{
    private:
    Trie*arr[10];
    bool flag=false;
public:
// check function
bool check(char r){
    return arr[r-'0']!=NULL;
}
// get function
Trie* get(char r){
    return arr[r-'0'];
}
//put function
void put(char r,Trie*node){
    arr[r-'0']=node;
}
// is end function
bool isEnd(){
    return flag;
}
// setEnd function
void setEnd(){
    flag=true;
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
        }
        temp->setEnd();
    }
    int search(string res){
        Trie*temp=root;
        int cnt=0;
        for(int i=0;i<res.size();i++){
            char ch=res[i];
            if(!temp->check(ch))return cnt;
            temp=temp->get(ch);
            cnt++;
        }
        return cnt;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        for(int i=0;i<arr2.size();i++){
            int word=arr2[i];
            string r=to_string(word);
            insert(r);
        }
        int ans=0;
        for(int i=0;i<arr1.size();i++){
            int res=arr1[i];
            string word=to_string(res);
            int temp=search(word);
            ans=max(ans,temp);
        }
        return ans;
    }
};