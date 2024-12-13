class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        multiset<pair<long long,long long>>ml;
        unordered_map<int,long long>umap,freq;
        vector<int>ans;
        for(int i=0;i<k;i++){
            ml.insert({0,i});
        }
        for(int i=0;i<arrival.size();i++){
            int server=i%k;
            if(umap[server]<=arrival[i]){
                ml.erase({umap[server],server});
                umap[server]=arrival[i]+load[i];
                ml.insert({umap[server],server});
                freq[server]++;
            }
            else{
                auto it=*ml.begin();
                if(it.first>arrival[i])continue;
                int mini=INT_MAX;
                int mydiff=INT_MAX;
                int myserver=-1;
                for(auto it:ml){
                    long long time=it.first;
                    long long ser=it.second;
                    if(time>arrival[i])break;
                    else{
                        if(ser<server){
                          int diff=k+ser-server;
                          if(diff<mydiff){
                            mydiff=diff;
                            myserver=ser;
                          }
                        }
                        else{
                            int diff=ser-server;
                            if(diff<mydiff){
                                mydiff=diff;
                                myserver=ser;
                            }
                        }
                    }
                }
                if(myserver!=-1){
                    freq[myserver]++;
                    ml.erase({umap[myserver],myserver});
                    umap[myserver]=arrival[i]+load[i];
                    ml.insert({umap[myserver],myserver});
                }
            }
        }
        long long maxfreq=INT_MIN;
        for(auto it:freq){
            maxfreq=max(maxfreq,it.second);
        }
        for(auto it:freq){
            // cout<<it.first<<" ->"<<it.second<<" ->"<<maxfreq<<endl;
            if(it.second==maxfreq){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};