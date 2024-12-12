class Solution {
public:
    tuple<long long,long long,bool> getTheFirstOneFree(vector<long long>&freeAt, int neededAt){
        long long ansRoom = 200 , gotFreeAt = 0;
        for(int room = 0 ; room < freeAt.size() ; room++){
            if(freeAt[room] <= neededAt){
                ansRoom = room;
                gotFreeAt = freeAt[room];
                return {ansRoom,gotFreeAt,1};
            }
        }
        return {ansRoom,gotFreeAt,0};
    }
    
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long>freeAt(n,0);
        unordered_map<int,int>usedFrequency;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>minh;
        for(int i = 0 ; i < n ; i++)minh.push({0,i});
        sort(meetings.begin(),meetings.end());

        for(int index = 0 ; index < meetings.size() ; index++){
            long long startTime = meetings[index][0] , endTime = meetings[index][1];
            long long meetingDuration = endTime-startTime;
            auto [roomNumber,gotFreeAt,flag] = getTheFirstOneFree(freeAt,startTime);
            if(flag){
                usedFrequency[roomNumber]+=1;
                long long newFreeTime = max(meetingDuration+gotFreeAt,endTime);
                freeAt[roomNumber] = newFreeTime;
                minh.push({newFreeTime,roomNumber});
            }
            else{
                priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>newMinH;
                for(int i = 0 ; i < n ; i++)newMinH.push({freeAt[i],i});
                auto [freeNow,currentBestRoom] = newMinH.top();
                newMinH.pop();
                usedFrequency[currentBestRoom]+=1;
                long long newFreeTime = max(meetingDuration+freeNow,endTime);
                freeAt[currentBestRoom] = newFreeTime;
                minh.push({newFreeTime,currentBestRoom});
            }
        }

        int maxUsedCount = 0 , maxUsedRoom = 200;
        for(auto i : usedFrequency){
            // cout<<i.first<<" , "<<i.second<<endl;
            if(i.second >= maxUsedCount){
                maxUsedCount = i.second;
            }
        }
        // cout<<"usedMaxCount = "<<maxUsedCount<<endl;
        for(auto i : usedFrequency){
            if(maxUsedCount == i.second)maxUsedRoom = min(maxUsedRoom,i.first);
        }
        return maxUsedRoom;
    }
};