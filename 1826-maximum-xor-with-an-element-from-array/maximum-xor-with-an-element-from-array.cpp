class TrieNode{
    public:
    TrieNode* arr[2];
    bool flag=false;
    
    // check if it is null
    bool check(int ch){
        return (arr[ch]!=NULL);
    }
    // get the node
    TrieNode* get(int ch){
        return arr[ch];
    }
    void put(int ch,TrieNode* root){
        arr[ch]=root;
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

// insertion of number into the string 
    void insert(int num){
        TrieNode*temp=root;
       for(int i=31;i>=0;i--){
       int bit=(num>>i)&1;
        if(!temp->check(bit)){
            temp->put(bit,new TrieNode());
        }
        temp=temp->get(bit);
       }
      temp->setEnd();
    }
    // searching of a number in trie
    int search(int num) {
    TrieNode*temp=root;
    int res=0;
        for(int i=31;i>=0;i--){
          int bit = (num>>i)&1;
          if(temp->check(!bit)){
            res=res|(1<<i);
            temp=temp->get(!bit);
          }
          else if(temp->check(bit)){
            temp=temp->get(bit);
          }
          else{
            return -1;
          }
        }
      return res;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        int m=queries.size();
        vector<int>ans(m);
        vector<pair<int,pair<int,int>>>arr;

        for(int i=0;i<m;i++){
          int first=queries[i][0];
          int second=queries[i][1];
          arr.push_back({second,{first,i}});
        }
      
        sort(arr.begin(),arr.end());
        Implement ts;
        int j=0;
        for(int i=0;i<m;i++){
          int number=arr[i].second.first;
          int val=arr[i].first;
          int ind=arr[i].second.second;
          while(j<nums.size()){
          if(nums[j]<=val){
            ts.insert(nums[j]);
          }
          else{
            int res=ts.search(number);
            ans[ind]=res;
            break;
          }
          j++;
          }
          if(j==nums.size()){
            int res=ts.search(number);
            ans[ind]=res;
          }
        }
        return ans;
    }
};