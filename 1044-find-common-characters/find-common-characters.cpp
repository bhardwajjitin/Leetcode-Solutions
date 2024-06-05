class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<int,unordered_map<char,int>>umap;
        vector<string>ans;
        for(int i=1;i<words.size();i++){
          string temp=words[i];
          for(int j=0;j<temp.size();j++){
            char ch=temp[j];
            umap[i][ch]++;
          }
        }
        for(int i=0;i<words[0].size();i++){
            char ch=words[0][i];
            bool flag=true;
            for(int j=1;j<words.size();j++){
              if(umap[j][ch]>0){
                umap[j][ch]--;
              }
              else{
                flag=false;
              }
            }
            if(flag){
              string res;
              res+=ch;
              ans.push_back(res);
            }
        }
        return ans;
    }
};