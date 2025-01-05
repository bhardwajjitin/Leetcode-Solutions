class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        unordered_map<int,int>umap;
        for(int i=0;i<shifts.size();i++){
            int start=shifts[i][0];
            int end=shifts[i][1];
            int dir=shifts[i][2];
            if(dir==0){
                umap[start]+=-1;
                umap[end+1]+=1;
            }
            else{
                umap[start]+=1;
                umap[end+1]+=-1;
            }
        }
        s[0] = ((s[0]-'a')+(umap[0]% 26)+26) % 26 + 'a';
        for(int i=1;i<s.size();i++){
            umap[i]+=umap[i-1];
            int shift = umap[i];
            s[i] = ((s[i]-'a')+(shift%26)+26) % 26 + 'a';
        }
        return s;
    }
};