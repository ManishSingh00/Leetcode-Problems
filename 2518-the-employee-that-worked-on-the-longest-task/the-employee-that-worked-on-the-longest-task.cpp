class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int m = logs.size();

        int min_id = logs[0][0];
        int max_time = logs[0][1];

        for(int i=1;i<m;i++){
            int time = logs[i][1] - logs[i-1][1];
            if(time>max_time){
                max_time = time; 
                min_id = logs[i][0];
            }
            else if(time == max_time){
                min_id = min(min_id,logs[i][0]);
            }
        }
        return min_id;
    }
};