class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>left;
        unordered_set<int>right;

        sort(nums.rbegin(),nums.rend());
        for(int i=0;i<n;i++){
            right.insert(nums[i]);
        }


        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }

        int ans = -1;

        for(int i=0;i<n;i++){
            right.erase(nums[i]);
            int x = sum-nums[i];
            if(x%2!=0){
                left.insert(nums[i]);
                continue;
            }
            int chk = x/2;
            if(right.count(chk)!=0 || left.count(chk)!=0){
                return nums[i];
            }
            left.insert(nums[i]);
        }

        return -1;
    }
};