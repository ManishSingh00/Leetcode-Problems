class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        set<int>st;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            int val = nums[i];

            if(st.count(val-k)==0){
                st.insert(val-k);
                continue;
            }

            int lo = val-k;
            int hi= val+k;
            int ans=INT_MAX;
           while(lo<=hi){
                int mid = (lo+hi)/2;
                if(st.count(mid)==0){
                    hi = mid-1;
                    ans = mid;
                }
                else lo = mid+1;
            }
            if(ans <= val+k && st.count(ans)==0) st.insert(ans);
        }
        return st.size();
    }
};