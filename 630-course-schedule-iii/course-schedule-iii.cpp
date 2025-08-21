class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){return a[1]<b[1];}
    int scheduleCourse(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        int n = arr.size();
        priority_queue<int>pq;

        int day = 0;
        for(int i=0;i<n;i++){
            day += arr[i][0];
            pq.push(arr[i][0]);

            if(day > arr[i][1]){
                day -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};