class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int>q;
        unordered_map<int,int>closed;
        for(auto it:initialBoxes){
            if(status[it]==1){
                q.push(it);
            }
            else{
                closed[it]++;
            }
        }
        int totalcand=0;
        while(!q.empty()){
            int box=q.front();
            q.pop();
            totalcand+=candies[box];
            for(auto it:containedBoxes[box]){
                if(status[it]==1){
                    q.push(it);
                }
                else{
                    closed[it]++;
                }
            }
            for(auto temp:keys[box]){
                if(closed.find(temp)!=closed.end()){
                    closed.erase(temp);
                    q.push(temp);
                }
                else{
                    status[temp]=1;
                }
            }
        }
        return totalcand;
    }
};