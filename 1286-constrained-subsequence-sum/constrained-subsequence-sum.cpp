class Solution {
public:
    // dp will take O(n*k)
    // this is optimized approach using priority queue which takes O(n*logK);
    // one more approach is there using deque, which takes O(n), i have not implemeted 
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(n);

        priority_queue<pair<int,int>>pq;
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            while(pq.size()>0 && pq.top().second < i-k) pq.pop();

            dp[i] = nums[i];
            if(pq.size()>0){
                dp[i] = max(dp[i],dp[i]+pq.top().first);
            }

            pq.push({dp[i],i});

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};