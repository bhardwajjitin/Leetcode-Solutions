class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,int>deads;
        for(auto it:deadends){
            deads[it]++;
        }
        set<string>already;
        string start="0000";
        queue<pair<int,string>>myqueue;
        myqueue.push({0,start});
        already.insert(start);
        
        while(!myqueue.empty()){
            auto top=myqueue.front();
            myqueue.pop();
               string current=top.second;
            int moves=top.first;
            if(deads.find(current)!=deads.end())continue;
         
           
            if(current==target)return moves;
            string original=current;
            for(int index=0;index<4;index++){
                char currentchar=current[index];
                int currentval=currentchar-'0'+1+10;
                int prevval=currentchar-'0'-1+10;
                currentval%=10;
                prevval%=10;
                char changed=currentval+'0';
                current[index]=changed;
                if(already.find(current)==already.end()){
                    myqueue.push({moves+1,current});
                    already.insert(current);
                }
                changed=prevval+'0';
                current[index]=changed;
                if(already.find(current)==already.end()){
                    myqueue.push({moves+1,current});
                    already.insert(current);
                }
                current=original;
            }
        }
        return -1;
    }
};