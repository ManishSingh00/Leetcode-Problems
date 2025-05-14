class Solution {
public:
    bool count(int x , vector<int>& nums,int k){
        int n = nums.size();
        int i = 0,j = 1;
        int cnt = 0;
        while(i<n){
            while(j<n && nums[j]-nums[i]<=x){
                j++;
                cnt++;
                if(cnt == k) return true;
            }
            i++;
            j=i+1;
        }
        return false;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int lo=0;
        int hi=nums[n-1]-nums[0];

        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(count(mid,nums,k)==true){
                hi = mid - 1;
            }
            else lo = mid + 1;
        }

        return lo;
    }
};