#define ll long long int
class Solution {
public:
    long long appealSum(string s) {
        ll n = s.length();
        ll tot_cnt  = 1LL*(n*(n+1))/2;
        ll cnt = 0;
        for(char ch = 'a';ch<='z';ch++){
            ll temp_cnt = 0; 
            for(int i =0;i<n;i++){
                if(s[i]==ch) continue;
                else{
                    ll cnt = 0;
                    while(i<n && s[i]!=ch){
                        cnt++;
                        i++;
                    }
                    temp_cnt += (cnt*(cnt+1))/2;
                }
            }
            cnt += (tot_cnt - temp_cnt);
        }
        return cnt;
    }
};