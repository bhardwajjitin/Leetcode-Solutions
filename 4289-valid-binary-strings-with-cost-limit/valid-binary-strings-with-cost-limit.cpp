class Solution {
    private:
    void solve(vector<string>&ans,int n,int cost,int curr_sum,string res){
        if(res.size()>=n){
            if(curr_sum<=cost){
                ans.push_back(res);
            }
            return;
        }
        if(res.size()==0){
            res+="1";
            solve(ans,n,cost,curr_sum+res.size()-1,res);
            res.pop_back();
            res+="0";
            solve(ans,n,cost,curr_sum,res);
            res.pop_back();
        }
        else{
            if(res[res.size()-1]=='1'){
                res+="0";
                solve(ans,n,cost,curr_sum,res);
                res.pop_back();
            }
            else{
                res+="0";
                solve(ans,n,cost,curr_sum,res);
                res.pop_back();
                res+="1";
                solve(ans,n,cost,curr_sum+res.size()-1,res);
                res.pop_back();
            }
        }
    }
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string>ans;
        solve(ans,n,k,0,"");
        return ans;
    }
};