class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,int>>pq;
        if(a>0) pq.push({a,0});
        if(b>0) pq.push({b,1});
        if(c>0) pq.push({c,2});

        string ans="";
        int last = -1;
        while(pq.size()>0){
            auto[cnt,letter] = pq.top();
            pq.pop();

            if(letter == last){ 
                if(pq.size() ==0 ) break;
                auto[cnt2,letter2] = pq.top();
                pq.pop();

                ans += ('a' + letter2);
                last = letter2;
                cnt2--;
                if(cnt2>0) pq.push({cnt2,letter2});
                pq.push({cnt,letter});
            }

            else{
                if(cnt >=2){
                    ans += ('a' + letter);
                    ans += ('a' + letter);
                    cnt -= 2;
                    last = letter;
                    if(cnt >0) pq.push({cnt,letter});
                }
                else if(cnt == 1){
                    ans += ('a' + letter);
                    last = letter;
                }
            }
        }

        return ans;
    }
};