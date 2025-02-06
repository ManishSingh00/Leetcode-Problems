class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }

      for(auto it:mp){
        int pair=it.second;
        cnt += (2*pair) * (2*(pair-1));
      }
        return  cnt;


    }
};