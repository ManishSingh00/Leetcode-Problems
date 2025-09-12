class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    bool maxSubstringLength(string s, int k) {
        int n = s.length();
        vector<int>first(26,-1), last(26,-1);
        for(int i=0;i<n;i++){
            if(first[s[i]-'a'] == -1) first[s[i]-'a'] = i;
            last[s[i]-'a'] = i;
        }

        vector<vector<int>>interval;

        for(int i=0;i<n;i++){ // i must be the starting point of a particular char
            if(i != first[s[i] - 'a']) continue;
            int j = last[s[i]-'a'];

            for(int k=i;k<=j;k++){ 
                j = max(j,last[s[k]-'a']); // maximizing j to the last occurence of any char present in that ineterval
            }
            
            bool flag = true;
            for(int k=i;k<=j;k++){
                if(first[s[k]-'a'] < i){ // any char present in [i...j] must not be present before i
                    flag = false;
                    break;
                }
            }

            if(flag == false) continue;
            if(i == 0 && j == n-1) continue; // condition 2

            interval.push_back({i,j});
        }


        sort(interval.begin(),interval.end(),cmp);
        int cnt = 0;
        int end_idx = -1;

        for(int i=0;i<interval.size();i++){
            if(interval[i][0] > end_idx){
                cnt++;
                end_idx = interval[i][1];
            }
        }
        cout<<cnt;



        return cnt>=k;
    }
};