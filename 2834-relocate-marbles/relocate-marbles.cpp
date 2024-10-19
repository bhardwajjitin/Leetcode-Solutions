class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        for(int i=0;i<moveFrom.size();i++){
            int start=moveFrom[i];
            int end=moveTo[i];
            st.erase(start);
            st.insert(end);
        }
        vector<int>answer;
        for(auto it:st){
            answer.push_back(it);
        }
        return answer;
    }
};