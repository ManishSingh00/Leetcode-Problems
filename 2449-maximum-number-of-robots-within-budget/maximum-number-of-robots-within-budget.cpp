#define ll long long int
class Solution {
public:
    ll f(ll k,vector<int>& charge,vector<int>& cost){
        ll mini = LLONG_MAX;
        priority_queue<pair<int,int>>pq;
        ll sum = 0;
        for(int i=0;i<k;i++){
            pq.push({charge[i],i});
            sum += cost[i];
        }
        mini = min(mini,pq.top().first + k*sum);

        for(int i=k;i<charge.size();i++){
            pq.push({charge[i],i});
            sum = sum + cost[i] - cost[i-k];

            while(pq.size()>0 && pq.top().second < i-k+1) pq.pop();
            mini = min(mini,pq.top().first + k*sum);
        }
        return mini;

    }
    int maximumRobots(vector<int>& charge, vector<int>& cost, long long budget) {
        int n = charge.size();
        ll lo = 1;
        ll hi = n;
        while(lo <= hi){
            ll mid = lo + (hi-lo)/2;

            if(f(mid,charge,cost)<=budget){
                lo=mid+1;
                // ans = mid;
            }
            else hi = mid-1;
        }
        return lo-1;

    }
};