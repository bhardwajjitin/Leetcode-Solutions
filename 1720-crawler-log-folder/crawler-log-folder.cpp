class Solution {
public:
    int minOperations(vector<string>& logs) {
        int curr=0;
        for(int i=0;i<logs.size();i++){
          string word=logs[i];
          if(word=="../"){
              if(curr==0)continue;
              else curr--;
          }
          else if(word=="./")continue;
          else{
            curr++;
          }
        }
        return curr;
    }
};