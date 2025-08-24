#define ll long long int
#define mod 1000000007
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i=0, j=0;
        ll sum1= 0,sum2 = 0;
        ll final_ans = 0;

        while(i<n && j <m){
            if(nums1[i]<nums2[j]){
                sum1 += nums1[i];
                i++;
            }
            else if(nums1[i]>nums2[j]){
                sum2 += nums2[j];
                j++;
            }
            else{
                final_ans += max(sum1,sum2) +nums1[i];
                i++;
                j++;
                sum1 = 0;
                sum2 = 0;
            }
        }
        while(i<n){
            sum1 += nums1[i];
            i++;
        }
        while(j<m) {
            sum2 += nums2[j];
            j++;
        }

        final_ans += max(sum1,sum2);

        return final_ans%mod;
    }
};