class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();


        vector<int>arr;

        for(int i=0;i<n;i++){
            string str = bank[i];
            int cnt = 0;
            for(int j=0;j<m;j++){
                if(str[j] == '1') cnt++;
            }
            if(cnt != 0) arr.push_back(cnt);
        }
        int ans = 0;
        for(int i=0;i<(int)arr.size()-1;i++){
            int x = arr[i];
            int y = arr[i+1];
            ans += (x*y); 
        }

        return ans;
    }
};