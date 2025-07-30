class Solution {
public:

    int f(int i,int curr,int maxi,int n, vector<int>& nums){
        if(i>=n){
            if(curr == maxi) return 1;
            else return 0;
        }

        int ans = f(i+1,curr,maxi,n,nums); // basically we are skipping this index
        ans += f(i+1,curr|nums[i],maxi,n,nums);

        return ans;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;

        for(int i=0;i<n;i++){
            maxi |= nums[i];
        }

        return f(0,0,maxi,n,nums);
    }
};