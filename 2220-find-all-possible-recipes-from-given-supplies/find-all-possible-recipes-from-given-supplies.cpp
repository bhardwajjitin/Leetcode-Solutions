class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>>umap;
        unordered_map<string,int>freq;
        for(int i=0;i<recipes.size();i++){
            string rec=recipes[i];
            for(int j=0;j<ingredients[i].size();j++){
                string ing=ingredients[i][j];
                umap[ing].push_back(rec);
            }
            freq[rec]=ingredients[i].size();
        }
        vector<string>ans;
        queue<string>q;
        for(auto it:supplies){
            q.push(it);
        }
        while(!q.empty()){
            string top=q.front();
            q.pop();
            for(auto temp:umap[top]){
                freq[temp]--;
                if(freq[temp]==0){
                    q.push(temp);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};