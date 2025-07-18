#define ll long long int
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int sz = nums.size();
        int n = sz/3;

        vector<ll>left(sz,0);
        vector<ll>right(sz,0);

        priority_queue<int>pq;
        ll sum = 0;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
            sum += nums[i];
        }

        left[n-1] = sum;
        for(int i=n;i<2*n;i++){
            sum += nums[i];
            pq.push(nums[i]);
            sum -= pq.top();
            pq.pop();
            left[i] = sum;
        }

        priority_queue<int,vector<int>,greater<int>>pqq;
        sum = 0;
        for(int i=sz-1;i>=2*n;i--){
            pqq.push(nums[i]);
            sum += nums[i];
        }

        right[2*n] = sum;
        for(int i=2*n-1;i>=n;i--){
            sum += nums[i];
            pqq.push(nums[i]);
            sum -= pqq.top();
            pqq.pop();
            right[i] = sum;

        }

        ll ans = 1e10;
        for(int i=n-1;i<2*n;i++){
            ans = min(ans,left[i]-right[i+1]);
        }


        return ans;
    }
};