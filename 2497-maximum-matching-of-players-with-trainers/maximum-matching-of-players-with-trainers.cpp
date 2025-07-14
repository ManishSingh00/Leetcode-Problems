class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        int n = p.size();
        int m = t.size();

        sort(p.begin(),p.end());
        sort(t.begin(),t.end());

        int i=0,j=0;
        int ans = 0;
        while(i<n && j<m){
            if(p[i]<=t[j]){
                i++;
                j++;
                ans++;
            }
            else if(t[j]<p[i]) j++;
        }

        return ans;
    }
};