// class Solution {
// public:
//     long long maximumPoints(vector<int>& enemy, int current) {
//         long long sum=0;
//         priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
//         priority_queue<pair<long long,int>>pq1;
//         int n=enemy.size();
//         unordered_map<long long,int>umap;
//         for(int i=0;i<n;i++){
//             pq.push({enemy[i],i});
//             pq1.push({enemy[i],i});
//         }
//         long long maxi=0;
//         if(current<pq.top().first)return 0;
//         while(true){
//             while(pq.size()!=0 && current>=pq.top().first && umap.find(pq.top().second)==umap.end()){
//                 long long temp=current/pq.top().first;
//                 current-=(pq.top().first*temp);
//                 maxi+=temp;
//             }
//             while(pq.size()!=0 && umap.find(pq.top().second)!=umap.end()){
//                 pq.pop();
//             }
//             if(pq.size()!=0 && current<pq.top().first && maxi!=0){
//                 auto it=pq1.top();
//                 umap[it.second]++;
//                 current+=it.first;
//                 pq1.pop();
//             }
//             if(pq.size()==0)return maxi;
//         }
//         return maxi;
//     }
// };
class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long c=0;
        int n=enemyEnergies.size();
        sort(enemyEnergies.begin(),enemyEnergies.end());
        int s=0,e=n-1;
        while(s<=e){
            while(currentEnergy >= enemyEnergies[s]){
              long long temp=currentEnergy/enemyEnergies[s];
                currentEnergy-=((long long)enemyEnergies[s]*temp);
                c+=temp;
            }
            if(c==0) return 0;
            if(currentEnergy < enemyEnergies[s]){
                currentEnergy+= enemyEnergies[e];
                e--;
            }
        }
        return c;
    }
};