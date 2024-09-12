class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int>umap;
        for(auto it:allowed){
            umap[it]++;
        }
        int cnt=0;
        for(auto it:words){
            string temp=it;
            bool flag=true;
            for(int i=0;i<temp.size();i++){
                if(umap.find(temp[i])==umap.end()){
                    flag=false;
                    break;
                }
            }
            if(flag){
                cnt++;
            }
        }
        return cnt;
    }
};