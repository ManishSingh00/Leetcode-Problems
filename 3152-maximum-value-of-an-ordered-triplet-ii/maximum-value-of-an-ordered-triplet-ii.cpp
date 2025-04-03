class Solution {
    typedef long long int ll;
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n); // store max_element from left
        vector<int>right(n); // store max_ele from left
        left[0]=nums[0];
        right[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],nums[i]);
        }
        for(int j=n-2;j>=0;j--){
            right[j]=max(right[j+1],nums[j]);
        }
        ll ans=0;
        for(int i=1;i<n-1;i++){
            ans = max(ans,(ll)(left[i-1]-nums[i])*(ll)right[i+1]);
        }
        return ans;
    }
};