class Solution {
public:
    int f(int mid,vector<int>& arr,int n){
        int cnt_store = 0;
        for (int q : arr) {
            // ceil(q / mid) = (q + mid - 1) / mid
            cnt_store += ceil(double(q)/mid);
        }
        return cnt_store;
    }
    int minimizedMaximum(int n, vector<int>& arr) {
        int sz = arr.size();
        int lo = 1;
        int hi = *max_element(arr.begin(),arr.end());

        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(f(mid,arr,n)<=n) hi = mid;
            else lo = mid+1;
        }
        return lo;
    }
};