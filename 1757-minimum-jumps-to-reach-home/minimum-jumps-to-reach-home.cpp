#define ll long long int
class Solution {
public:
    unordered_set<int>st;
    int dp[10005][2];
    int f(int curr,bool back,int tar,int a,int b){
        if(curr==tar) return 0;
        if(curr<0 || curr>10001 || st.count(curr)!=0) return 1e9;
        if(dp[curr][back]!=-1) return dp[curr][back];

        // ll ans=INT_MAX;
        // moving right
        dp[curr][back]=1+f(curr+a,false,tar,a,b);

        // moving left
        if(back==false){
            dp[curr][back] = min(dp[curr][back],1+f(curr-b,true,tar,a,b));
        }

        return dp[curr][back];
    }
    int minimumJumps(vector<int>& arr, int a, int b, int x) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            st.insert(arr[i]);
        }
        memset(dp,-1,sizeof(dp));
        ll ans=f(0,false,x,a,b);
        cout<<ans<<endl;
        if(ans>1e9) return -1;
        return ans;
    }
};