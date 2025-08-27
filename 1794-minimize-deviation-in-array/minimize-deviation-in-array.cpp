class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();

        priority_queue<int>pq;
        int ans = INT_MAX;
        int mini = INT_MAX;

        for(int i=0;i<n;i++){
            if(nums[i]%2 == 1){
                pq.push(nums[i]*2);
                mini = min(mini,nums[i]*2);
            }
            else {
                pq.push(nums[i]);
                mini = min(mini,nums[i]);
            }
        }
        while(pq.top()%2 == 0){
            int maxi = pq.top();
            pq.pop();
            ans = min(ans,maxi-mini);

            maxi = maxi/2;
            mini = min(mini,maxi);
            pq.push(maxi);
        }

        ans = min(ans, pq.top()-mini);

        return ans;
    }
};