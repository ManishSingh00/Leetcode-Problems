class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        int maxLen = 0;

        int maxi = *max_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i] == maxi){
                len++;
                if(len>maxLen) maxLen = len;
            }
            else{
                len = 0;
            }
        }

        return maxLen;




    }
};