# define ll long long int
class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;
        map<pair<int,int> ,int>mp;

        for(int r =4;r<=n-3;r++){
            int q = r-2;

            for(int p=0;p<=q-2;p++){
                int _gcd = gcd(nums[p],nums[q]);
                int x = nums[p]/_gcd;
                int y = nums[q]/_gcd;
                mp[{x,y}]++;
            }

            for(int s = r+2;s<n;s++){
                int _gcd = gcd(nums[s],nums[r]);
                int x = nums[s]/_gcd;
                int y = nums[r]/_gcd;
                ans += mp[{x,y}]; 
            }
            
        }

        return ans;
    }
};