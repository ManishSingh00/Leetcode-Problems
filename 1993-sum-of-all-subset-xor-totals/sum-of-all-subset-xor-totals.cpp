class Solution {
public:
    int f(vector<int>& nums,int idx,int curr){
        if(idx==nums.size()){
            return curr;
        }
        int take=f(nums,idx+1,curr^nums[idx]);
        int not_take=f(nums,idx+1,curr);
        return take+not_take;
    }
    int subsetXORSum(vector<int>& nums) {
        return f(nums,0,0);
    }
};