class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(),events.end());

        priority_queue<int ,vector<int>, greater<>>pq;
        int day = 0;
        int ans = 0;
        int i = 0;
        
        while(i<n || pq.size()>0){
            if(pq.empty()) day = events[i][0];

            while(i<n && events[i][0] <= day){
                pq.push(events[i][1]);
                i++;
            }

            pq.pop();
            ans++;
            day++;

            while(pq.size()>0 && pq.top() < day) pq.pop();
            
        }
        return ans;
    }
};