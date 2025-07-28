class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre_odd(n,0);
        vector<int>pre_even(n,0);
        pre_even[0] = nums[0];
        
        for(int i=1;i<n;i++){
            if(i%2==1) pre_even[i] = pre_even[i-1];
            else pre_even[i] = pre_even[i-2] + nums[i];
        }

        if(n>1) pre_odd[1] = nums[1];
        for(int i=2;i<n;i++){
            if(i%2==0) pre_odd[i] = pre_odd[i-1];
            else pre_odd[i] = pre_odd[i-2] + nums[i];
        }

        int ans = 0;
        if(pre_odd[n-1] == pre_even[n-1]-pre_even[0]) ans++;
        for(int i=1;i<n;i++){
            int odd = pre_odd[i-1];
            int even = pre_even[i-1];

            odd += pre_even[n-1]-pre_even[i];
            even += pre_odd[n-1]-pre_odd[i];
            

            if(odd == even) ans++;
        }

        return ans;
    }
};