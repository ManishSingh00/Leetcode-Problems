class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int ans = 0;

        int i=0,j=0;
        multiset<int>st;
        while(i<n && j<n){
            st.insert(nums[j]);
            while(i<n &&  *st.rbegin() - *st.begin() > limit){
                st.erase(st.find(nums[i]));
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};