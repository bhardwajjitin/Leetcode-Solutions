class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int>st;
        vector<int>answer;
        for(int i=0;i<nums.size();i++){
            st.push(nums[i]);
            while(st.size()>=2){
                int first=st.top();
                st.pop();
                int second=st.top();
                if(gcd(first,second)>1){
                    st.pop();
                    st.push(lcm(first,second));
                }
                else{
                    st.push(first);
                    break;
                }
            }
        }
        while(!st.empty()){
            answer.push_back(st.top());
            st.pop();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};