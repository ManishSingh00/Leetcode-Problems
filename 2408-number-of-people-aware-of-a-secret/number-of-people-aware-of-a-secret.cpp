#define mod 1000000007
#define ll long long int
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
       queue<pair<int,int>>q; //{day_learned, people_cnt}
       q.push({1,1});
       int day = 1;

       while(q.size()>0 && day<=n){
            int sz = q.size();
            ll cnt = 0;
            for(int i=0;i<sz;i++){
                auto node = q.front();
                int day_learned = node.first;
                int person_cnt = node.second;
                q.pop();

                if(day_learned + forget > day){
                    if(day_learned + delay <= day){
                        cnt = (cnt + person_cnt)%mod;
                    }
                    q.push(node);
                }

            }
            if(cnt > 0){
                q.push({day,(int)cnt});
            }
            day++;
       }
        ll ans = 0;
        while(q.size()>0){
            ans = (ans + q.front().second)%mod;
            q.pop();
        }

        return (int)ans;

    }
};