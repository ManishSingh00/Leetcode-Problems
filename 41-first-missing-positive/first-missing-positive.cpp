class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<n && nums[i]<=0) i++;

        int exp = 1;
        while(i<n && nums[i]==exp){
            int j =i+1;
            while(j<n && nums[j]==nums[j-1]) j++;
            i=j;
            exp++;
        }
        return exp;
    }
};