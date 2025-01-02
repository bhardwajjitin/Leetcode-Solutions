class Solution {
    private:
    int check(string&str){
        int n=str.size();
        if((str[0]=='a' || str[0]=='e' || str[0]=='i' ||str[0]=='o' ||str[0]=='u') && (str[n-1]=='a' || str[n-1]=='e' || str[n-1]=='i' ||str[n-1]=='o' ||str[n-1]=='u'))return 1;
       return 0;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>prefix(n,0),ans;
        prefix[0]=check(words[0]);
        for(int index=1;index<n;index++){
            prefix[index]=check(words[index])+prefix[index-1];
        }
        for(auto it:queries){
            int start=it[0];
            int end=it[1];
            if(start!=0){
                ans.push_back(prefix[end]-prefix[start-1]);
            }
            else{
                ans.push_back(prefix[end]);
            }
        }
        return ans;
    }
};