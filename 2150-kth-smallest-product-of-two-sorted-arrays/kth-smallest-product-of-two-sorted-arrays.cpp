#define ll long long int
class Solution {
public:
    ll floor_(ll a, ll b){
        if(b==0) return 1e18;
        ll x = a/b;
        if((a^b) < 0 && a%b != 0) x--;
        return x;
    }

    ll ceil_(ll a,ll b){
        if(b==0) return 1e18;
        ll x  = a/b;
        if((a^b)>0 && a%b!=0) x++;
        return x; 
    }
        ll count_pair(ll mid,vector<int>& nums1,vector<int>& nums2){
        int n = nums1.size(), m= nums2.size();
        ll cnt = 0;
        for(int i=0;i<n;i++){
            if(nums1[i]>0){
                ll val = floor_(mid,nums1[i]);
                cnt += upper_bound(nums2.begin(),nums2.end(),val) - nums2.begin();
            }
            else if(nums1[i]<0){
                ll val = ceil_(mid,nums1[i]);
                cnt += nums2.end() - lower_bound(nums2.begin(),nums2.end(),val);
            }
            else{
                if(mid>=0) cnt += m;
            }
        }

        return cnt;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n = nums1.size();
        int m = nums2.size();
        // ll lo = min(nums1[0]*nums2[0] , nums1[0]*nums2[m-1]);
        // ll hi = max(nums1[n-1]*nums2[0],nums1[n-1]*nums2[m-1]);
        ll lo = -1e10, hi=1e10;

        while(lo<hi){
            ll mid = lo + (hi-lo)/2;

            if(count_pair(mid,nums1,nums2) < k) lo = mid+1;
            else hi  = mid;
        }

        return lo;
    }
};