class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int i=0;
        int j=skill.size()-1;
        long long product=(long long)skill[i]*(long long)skill[j];
        long long sum=skill[i++]+skill[j--];
        while(i<=j){
           if(skill[i]+skill[j]!=sum)return -1;
           else{
            product+=(long long)skill[i]*(long long)skill[j];
           }
           i++;
           j--;
        }
        return product;
    }
};