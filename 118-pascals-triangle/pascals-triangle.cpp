class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>res={1};
        if(numRows==1)return {{1}};
        ans.push_back(res);
        numRows--;
        while(numRows--){
            vector<int>temp;
            temp.push_back(res[0]);
            if(res.size()>=2){
            for(int i=1;i<res.size();i++){
                int sum=res[i]+res[i-1];
                temp.push_back(sum);
            }
            }
            temp.push_back(res[res.size()-1]);
            ans.push_back(temp);
            res=temp;
        }
        return ans;
    }
};