class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<double,double>>>pq;
        for(int i=0;i<classes.size();i++){
            double numo=classes[i][0];
            double deno=classes[i][1];
            double rat1=(double)numo/(double)deno;
            double rat2=(double)(numo+1)/(double)(deno+1);
            double ratio=rat2-rat1;
            pq.push({ratio,{numo,deno}});
        }
        while(extraStudents--){
            int deno=pq.top().second.second;
            int numo=pq.top().second.first;
            numo++;
            deno++;
            pq.pop();
            double rat1=(double)numo/(double)deno;
            double rat2=(double)(numo+1)/(double)(deno+1);
            double ratio=rat2-rat1;
            pq.push({ratio,{numo,deno}});
        }
        double ans=0;
        while(!pq.empty()){
            int deno=pq.top().second.second;
            int numo=pq.top().second.first;
            double res=(double)numo/(double)deno;
            ans+=res;
            pq.pop();
        }
        return ans/classes.size();
    }
};