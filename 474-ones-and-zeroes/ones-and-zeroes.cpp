class Solution {
public:
    int dp[601][101][101];
    int f(int i,int m,int n, vector<pair<int,int>>& cnt,int cnt_m,int cnt_n){
        if(i==cnt.size()) return 0;
        if(dp[i][cnt_m][cnt_n]!=-1) return dp[i][cnt_m][cnt_n];

        int ans = f(i+1,m,n,cnt,cnt_m,cnt_n);
        if(cnt_m + cnt[i].first <= m && cnt_n + cnt[i].second <=n){
            ans = max(ans , 1 + f(i+1,m,n,cnt,cnt_m + cnt[i].first, cnt_n + cnt[i].second));
        }

        return dp[i][cnt_m][cnt_n] = ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();

        vector<pair<int,int>>cnt(sz);
        for(int i=0;i<sz;i++){
            string s = strs[i];
            int z=0,one=0;
            for(int j=0;j<s.length();j++){
                if(s[j]=='1') one++;
                else z++;
            }
            cnt[i]={z,one};
        }

        memset(dp,-1,sizeof dp);
        return f(0,m,n,cnt,0,0);

    }
};