class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        map<pair<int,int>,bool>mp;
        vector<int>cnt(n);
        for(int i=0;i<roads.size();i++){
            int a=roads[i][0];
            int b=roads[i][1];
            cnt[a]++;
            cnt[b]++;
            mp[{min(a,b),max(a,b)}]=true;
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(mp[{min(i,j),max(i,j)}]==true){
                    maxi=max(maxi,cnt[i]+cnt[j]-1);
                }
                else{
                    maxi=max(maxi,cnt[i]+cnt[j]);
                }
            }
        }
        return maxi;
    }
};