class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>umap;
        int maxi=0;
        for(int i=0;i<s.size();i++){
            umap[s[i]]++;
        }
        for(auto it:umap){
          if(it.second%2!=0)
          maxi=max(maxi,it.second);
        }
        int len=0;
        bool flag=false;
        for(auto it:umap){
          if(it.second%2==0){
            len+=it.second;
          }
          else if(it.second==maxi && !flag){
              len+=it.second;
              flag=true;
          }
          else{
            len+=it.second-1;
          }
        }
        return len;
    }
};