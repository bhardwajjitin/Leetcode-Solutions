class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) {
        unordered_map<string,int>umap;
        string temp;
        for(int i=0;i<p.size();i++){
          if((p[i]>='a' && p[i]<='z' ) || (p[i]>='A' && p[i]<='Z')){
           temp+=tolower(p[i]);
          }
          else{
            umap[temp]++;
            temp="";
          }
            
        }
        umap[temp]++;
        string ans;
        int mini=0;
        for(auto it:umap){
          bool flag=true;
           for(auto temp:banned){
            if(it.first==temp)flag=false;
           }
           if(flag){
            if(it.second>mini && it.first!=""){
              mini=it.second;
              ans=it.first;
            }
           }
        }
        return ans;
    }
};