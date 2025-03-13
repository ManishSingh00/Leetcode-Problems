class Solution {
public:
    bool f(int mid,int n, vector<vector<int>>& q,vector<int>& nums){
        vector<int>diff(n+1);
        for(int i=0;i<mid;i++){
            int l=q[i][0];
            int r=q[i][1];
            int val=q[i][2];
            diff[l] += val;
            diff[r+1] -= val;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=diff[i];
            if(sum<nums[i]) return false; 
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        int m = q.size();
        int lo=0;
        int hi=m;
        int mid;
        if(f(m,n,q,nums)==false) return -1;
        while(lo<=hi){
            mid=(lo+hi)/2;
            if(f(mid,n,q,nums)==true){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return lo;
    }
};