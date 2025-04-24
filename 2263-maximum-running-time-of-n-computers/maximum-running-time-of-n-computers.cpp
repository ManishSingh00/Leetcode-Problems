#define ll long long int
class Solution {
public:

    ll f(ll mid,ll n,vector<int>& arr){
        ll time = 0;
        for(auto x : arr){
            time += min((ll)x,mid);
            if(time >= (n*mid)){
                return true;
            }
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& arr) {
       ll sum = 0;
       for(auto x : arr) sum += x;
       ll lo = 0, hi = sum/n;
       ll ans = 0; 
       while(lo <= hi){
        ll mid = lo + (hi-lo) / 2;
        if(f(mid,n,arr) == true){
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
       }

       return ans;

    }
};