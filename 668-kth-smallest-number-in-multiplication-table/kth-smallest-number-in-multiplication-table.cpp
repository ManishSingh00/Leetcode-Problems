class Solution {
public:
    int count(int m,int n,int x){
        int ans=0;
        for(int i=1;i<=m;i++){
            ans += min(n,x/i);
        }
        return ans;
    }
    int findKthNumber(int m, int n, int k) {
        int lo = 1;
        int hi = m*n;
        int ans;
        while(lo<=hi){
            int mid = lo + (hi-lo) / 2;
            if(count(m,n,mid) < k){
                lo = mid  + 1;
            }
            else{
                ans = mid;
                hi=mid-1;
            }
        }
        return ans;
    }
};