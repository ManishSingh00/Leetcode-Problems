class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int>arr;
        for(int i=0;i<n;i++){
            if(seats[i] == 1) arr.push_back(i);
        }
        
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            if(seats[i] == 0){
                int idx = lower_bound(arr.begin(),arr.end(),i) - arr.begin();
                
                if(idx == 0){
                    ans = max(ans,arr[idx]);
                }
                else if(idx == arr.size()){
                    ans = max(ans,i-arr[arr.size()-1]);
                }
                else{
                    int temp = min(abs(arr[idx]-i),abs(arr[idx-1] - i));
                    ans = max(ans,temp);
                }
            }
        }
        return ans;
    }
};