#define ll long long
#define pp pair<ll,int>
class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[0]<b[0];
    }
    int mostBooked(int n, vector<vector<int>>& arr) {
        int sz = arr.size();
        sort(arr.begin(),arr.end(),cmp);

        priority_queue<int,vector<int>, greater<int>>free;
        for(int i=0;i<n;i++){
            free.push(i);
        }

        priority_queue<pp,vector<pp>,greater<pp>>rooms; //<endtime,room no>

        vector<int>cnt_room(n,0);

        for(int i=0;i<sz;i++){
            int start = arr[i][0], end = arr[i][1];

            while(rooms.size()>0 && rooms.top().first<=start){
                free.push(rooms.top().second);
                rooms.pop();
            }

            int room_no;
            if(free.size()>0){
                room_no = free.top();
                free.pop();
                rooms.push({end,room_no});
                cnt_room[room_no]++;
            }
            else{
                ll end_time = rooms.top().first;
                room_no = rooms.top().second;
                rooms.pop();
                rooms.push({end_time+(end-start),room_no});
                cnt_room[room_no]++;
            }
        }

        int maxi = 0, max_idx = 0;

        for(int i=0;i<n;i++){
            if(cnt_room[i]>maxi){
                maxi = cnt_room[i];
                max_idx = i;
            }
        }

        return max_idx;

    }
};