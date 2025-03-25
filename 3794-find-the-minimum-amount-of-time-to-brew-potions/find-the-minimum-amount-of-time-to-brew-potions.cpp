class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size(),m=mana.size();

        vector<long long>done_time(n,0);
        for(int j=0;j<m;j++){
            long long last_end_time=0;
            for(int i=0;i<n;i++){
                long long start_time=max(done_time[i],last_end_time);
                last_end_time=done_time[i] = start_time+skill[i]*mana[j];
            }
            for(int i=n-1;i>=1;i--){
                done_time[i-1] = done_time[i] - skill[i]*mana[j];
            }
        }

        return done_time[n-1];
    }
};