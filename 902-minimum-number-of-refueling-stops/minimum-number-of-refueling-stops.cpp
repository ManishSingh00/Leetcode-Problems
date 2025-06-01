class Solution {
public:
    int minRefuelStops(int tar, int fuel, vector<vector<int>>& stations) {
        int n = stations.size();
        priority_queue<int>pq;
        int covered = 0;
        int i = 0;
        int stop = 0;
        while(i<n){
            // pq.push({stations[i][1],stations[i][0]});
            fuel -= (stations[i][0]-covered);

            while(fuel<0 && pq.size()>0){
                fuel += pq.top();
                pq.pop();
                stop++;
            }
            if(fuel < 0) return -1;
            pq.push(stations[i][1]);
            covered = stations[i][0];
            i++;
        }

        int diff = tar - covered;
        fuel -= diff;
        while(fuel<0 && pq.size()>0){
            fuel += pq.top();
            pq.pop();
            stop++;
        }
        if(fuel < 0) return -1;
        return stop;
    }
};