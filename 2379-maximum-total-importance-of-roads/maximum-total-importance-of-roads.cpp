class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>temp(n);
        for(int i=0;i<roads.size();i++){
            int a=roads[i][0],b=roads[i][1];
            temp[a]++;
            temp[b]++;
        }

        sort(temp.rbegin(),temp.rend());
        long long ans=0;
        int mul=n;
        for(int i=0;i<n;i++){
            ans+=(1LL*temp[i]*mul);
            mul--;
        }
        return ans;
    }
};