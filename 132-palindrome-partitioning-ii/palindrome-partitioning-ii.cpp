class Solution {
public:
    string str;
    int n;
    bool check(int i,int j){
        while(i<j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int dp[2005];
    int f(int i){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MAX;
        for(int k=i;k<n;k++){
            if(check(i,k)==true){
                ans = min(ans,1+f(k+1));
            }
        }
        return dp[i]= ans;      
    }
    int minCut(string s) {
        str=s;
        n = s.length();
        memset(dp,-1,sizeof dp);
        return f(0)-1;
    }
};