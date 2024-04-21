class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int n=asteroids.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int ele=asteroids[i];
            if(st.empty()){
                st.push(ele);
            }
            else if(st.top()<0){
                st.push(ele);
            }
            else if(st.top()>0 && ele>0){
                st.push(ele);
            }
            else if(st.top()>0 && ele<0){
                int temp=-1*ele;
                while(!st.empty() && st.top()<temp && st.top()>0){
                    st.pop();
                }
                if(st.empty()){
                    st.push(ele);
                }
                else if(st.top()==temp){
                    st.pop();
                    
                }
                else if(st.top()<0){
                    st.push(ele);
                }
               
            }
        }
       while(!st.empty()){
          ans.push_back(st.top());
          st.pop();
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};