class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq1;
        vector<int>ans;
        for(int i=0;i<servers.size();i++){
            pq.push({servers[i],i});
        }
        int arrivaltime=0;
        for(int i=0;i<tasks.size();i++){
            arrivaltime=max(arrivaltime,i);
            if(!pq1.empty() &&  arrivaltime< get<0>(pq1.top()) && pq.empty()){
                arrivaltime=get<0>(pq1.top());
            }
            while(!pq1.empty() && arrivaltime>=get<0>(pq1.top())){
                int server=get<2>(pq1.top());
                int weight=get<1>(pq1.top());
                pq.push({weight,server});
                pq1.pop();
            }
            int totaltime=arrivaltime+tasks[i];
            ans.push_back(pq.top().second);
            pq1.push({totaltime,pq.top().first,pq.top().second});
            pq.pop();
        }
        return ans;
    }
};