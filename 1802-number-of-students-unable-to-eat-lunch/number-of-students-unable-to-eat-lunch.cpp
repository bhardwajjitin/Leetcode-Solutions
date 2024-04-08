class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        for(auto it:students){
            q.push(it);
        }
        int cnt=0;
        while(true){
            if(sandwiches[0]!=q.front()){
                int top=q.front();
                q.pop();
                q.push(top);
                cnt++;
            }
            else{
                q.pop();
                sandwiches.erase(sandwiches.begin()+0);
                cnt=0;
            }
            if(cnt==q.size())break;
        }
        return cnt;
    }
};