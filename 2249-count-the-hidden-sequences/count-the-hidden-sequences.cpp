class Solution {
public:
    int numberOfArrays(vector<int>& arr, int lower, int upper) {
        int n = arr.size();
        long long mini = 0;
        long long maxi = 0;
        long long sum=0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            mini = min(mini, sum);
            maxi = max(maxi, sum);
        }

        return max(0LL,(upper - lower + 1) - (maxi - mini));
    }
};