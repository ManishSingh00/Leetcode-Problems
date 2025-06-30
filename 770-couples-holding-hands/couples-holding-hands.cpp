class Solution {
public:
    int minSwapsCouples(vector<int>& rows) {
        int n = rows.size();
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            mp[rows[i]]=i;
        }

        int cnt = 0;
        for(int i=0;i<n;i+=2){
            int curr = rows[i];
            int nxt = curr^1;

            if(nxt!=rows[i+1]){
                int correct_pos = mp[nxt];
                int temp = rows[i+1];
                swap(rows[i+1],rows[correct_pos]);
                mp[nxt] = i+1;
                mp[temp] = correct_pos;
                cnt++;
            }
        }
        return cnt;
    }
};