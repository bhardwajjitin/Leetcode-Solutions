class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>>grid(26,vector<int>(26,10000001));
        for(int i=0;i<original.size();i++){
           char ch=original[i];
           char ch1=changed[i];
           int dis=cost[i];
           if(grid[ch-'a'][ch1-'a']>dis){
            grid[ch-'a'][ch1-'a']=dis;
           }
        }
        for(char via='a';via<='z';via++){
          for(char i='a';i<='z';i++){
            for(char j='a';j<='z';j++){
              if(grid[i-'a'][via-'a']!=10000001 && grid[via-'a'][j-'a']!=10000001 && (grid[i-'a'][j-'a']> grid[i-'a'][via-'a']+grid[via-'a'][j-'a'])){
                grid[i-'a'][j-'a']=grid[i-'a'][via-'a']+grid[via-'a'][j-'a'];
              }
            }
          }
        }
        long long ans=0;
        for(int i=0;i<source.size();i++){
          char ch=source[i];
          char ch1=target[i];
          if(ch==ch1)continue;
          else{
            if(grid[ch-'a'][ch1-'a']!=10000001)ans+=grid[ch-'a'][ch1-'a'];
            else 
             return -1;
          }
        }
        return ans;
    }
};