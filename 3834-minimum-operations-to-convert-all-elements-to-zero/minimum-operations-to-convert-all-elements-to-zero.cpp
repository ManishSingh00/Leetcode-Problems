class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                while(st.size()!=0) st.pop();
            }
            else{
                while(st.size()>0 && st.top()>nums[i]) st.pop();
                if(st.size()==0 || st.top()<nums[i]){
                    st.push(nums[i]);
                    ans++;
                }
            }
        }
        return ans;
    }
};