#define ll long long int
class Solution {
public:
    long long maxWeight(vector<int>& arr) {
        int n = arr.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }

        int cnt = n/4;
        int odd_day = (cnt+1)/2;
        int even_day = cnt - odd_day;

        ll ans = 0;
        while(odd_day--){
            ans += pq.top();
            pq.pop();
        }
        pq.pop();
        while(even_day--){
            ans += pq.top();
            pq.pop();
            pq.pop();
        }
        return ans;
    }
};