class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp1,mp2;
        for(auto x:nums) mp1[x]++;

        for(int i=0;i<n-1;i++){
            mp1[nums[i]]--;
            mp2[nums[i]]++;
            if(mp2[nums[i]]>((i+1)/2) && mp1[nums[i]]>((n-i-1)/2)) return i;
        }
        return -1;
        

    }
};