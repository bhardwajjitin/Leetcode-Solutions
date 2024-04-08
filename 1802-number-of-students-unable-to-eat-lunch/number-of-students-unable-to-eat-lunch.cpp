class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // using queue space
        // queue<int>q;
        // for(auto it:students){
        //     q.push(it);
        // }
        // int cnt=0;
        // while(true){
        //     if(sandwiches[0]!=q.front()){
        //         int top=q.front();
        //         q.pop();
        //         q.push(top);
        //         cnt++;
        //     }
        //     else{
        //         q.pop();
        //         sandwiches.erase(sandwiches.begin()+0);
        //         cnt=0;
        //     }
        //     if(cnt==q.size())break;
        // }
        // return cnt;
        // without queue
        int cnt=0;
        while(true){
            if(sandwiches[0]!=students[0]){
                int top=students[0];
                students.erase(students.begin()+0);
                students.push_back(top);
                cnt++;
            }
            else{
                students.erase(students.begin()+0);
                sandwiches.erase(sandwiches.begin()+0);
                cnt=0;
            }
            if(cnt==students.size())break;
        }
        return cnt;
    }
};