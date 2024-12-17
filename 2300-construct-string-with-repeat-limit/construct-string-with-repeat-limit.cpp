class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int>frequency;
        string answer="";
        for(auto it:s){
            frequency[it]++;
        }
        priority_queue<char>largechar;
        for(auto temp:frequency){
            largechar.push(temp.first);
        }
        while(!largechar.empty()){
            char first=largechar.top();
            largechar.pop();
            while(frequency[first]!=0){
                int times=min(repeatLimit,frequency[first]);
                while(times--){
                    answer+=first;
                    frequency[first]--;
                }
                if(frequency[first]!=0 && !largechar.empty()){
                   char second=largechar.top();
                   answer+=second;
                   frequency[second]--;
                   if(frequency[second]==0){
                       largechar.pop();
                   }
                }
                else{
                    break;
                }
            }
        }
        return answer;
    }
};