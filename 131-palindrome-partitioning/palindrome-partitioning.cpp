class Solution {
    private:
    bool ispalind(string&s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string&s,int i,int n,vector<vector<string>>&ans,vector<string>v){
        if(i>=n){
            ans.push_back(v);
            return;
        }
        for(int j=i;j<n;j++){
            if(ispalind(s,i,j)){
                string str="";
                for(int k=i;k<=j;k++){
                    str+=s[k];
                }
                v.push_back(str);
                solve(s,j+1,n,ans,v);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        int n=s.size();
        vector<string>v;
        solve(s,0,n,ans,v);
        return ans;
    }
};