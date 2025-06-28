class Solution {
public:
    static bool cmp(string& a,string& b){
        if(a.length()!=b.length()){
            return a.length()<b.length();
        }
        return a<b; 
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),cmp);
        for(auto x:nums) cout<<x<<" ";
        return nums[n-k];
        
    }
};