class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int,pair<int,int>>>res;
        for(int i=0;i<positions.size();i++){
          if(directions[i]=='L'){
            res.push_back({positions[i],{-1*healths[i],i}});
          }
          else{
            res.push_back({positions[i],{healths[i],i}});
          }
        }
        sort(res.begin(),res.end());
        stack<pair<int,pair<int,int>>>st;
        int n=res.size();
        vector<pair<int,int>>ans;
        for(int i=0;i<n;i++){
            int ele=res[i].second.first;
            if(st.empty()){
                st.push({res[i].first,{ele,res[i].second.second}});
            }
            else if(st.top().second.first<0){
                st.push({res[i].first,{ele,res[i].second.second}});
            }
            else if(st.top().second.first>0 && ele>0){
                st.push({res[i].first,{ele,res[i].second.second}});
                
            }
            else if(st.top().second.first>0 && ele<0){
                int temp=-1*ele;
                while(!st.empty() && st.top().second.first<temp && st.top().second.first>0){
                    st.pop();
                    temp--;
                }
                ele=-1*temp;;
                int prev=-1;
                if(!st.empty() && st.top().second.first>0)prev=st.top().second.first;
                if(!st.empty() && st.top().second.first>temp){
                  st.top().second.first-=1;
                }
                if(st.empty()){
                    st.push({res[i].first,{ele,res[i].second.second}});
                }
                else if(prev!=-1 && prev==temp){
                    st.pop();
                }
                else if(st.top().second.first<0){
                    st.push({res[i].first,{ele,res[i].second.second}});
                }
            }
        }
       while(!st.empty()){
          ans.push_back({st.top().second.second,st.top().second.first});
          st.pop();
       }
       vector<int>result;
       reverse(ans.begin(),ans.end());
       sort(ans.begin(),ans.end());
       for(auto it:ans){
        result.push_back(abs(it.second));
       }
       return result;
    }
};