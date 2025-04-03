class Solution {
public:
typedef long long int ll;
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n); // store max_element from left
        vector<int>right(n); // store max_ele from left
        left[0]=nums[0];
        right[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            left[i]=min(left[i-1],nums[i]);
        }
        for(int j=n-2;j>=0;j--){
            right[j]=min(right[j+1],nums[j]);
        }
        int ans=1e9;
        for(int i=1;i<n-1;i++){
            if(nums[i]<=left[i-1] || nums[i]<=right[i+1]) continue;
            ans= min(ans,left[i-1]+nums[i]+right[i+1]);
        }
        if(ans==1e9) return -1;
        else return ans;
    }
};