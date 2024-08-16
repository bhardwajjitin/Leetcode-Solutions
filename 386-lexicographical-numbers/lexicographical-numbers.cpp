class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>res;
        for(int i=1;i<=n;i++){
            string temp=to_string(i);
            res.push_back(temp);
        }
        sort(res.begin(),res.end());
        vector<int>arr;
        for(auto it:res){
            int temp=stoi(it);
            arr.push_back(temp);
        }
        return arr;
    }
};