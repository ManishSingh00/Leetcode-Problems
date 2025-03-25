#define ll long long int
class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        int n = queries.size();
        ll final_ans=0;
        ll mx=0;
        for(int i=0;i<n;i++){
            ll l=queries[i][0],r=queries[i][1];
            int x;
            ll sum=0;
            for(x=0;x<=16;x++){
                if(l>=pow(4,x) && r<=pow(4,x+1)-1) sum = sum + (r-l+1)*(x+1);
                else if(l>=pow(4,x)){
                    ll cnt=pow(4,x+1) - l;
                    if(cnt<0) continue;
                    sum = sum + cnt*(x+1);
                    l+=cnt;
                }
                else{
                    mx=x;
                    break;
                } 
            }
            // cout<<sum<<" "<<mx<<endl;
            if(mx>sum-mx) final_ans += mx;
            // else return ceil(sum/2);
            else if(sum%2==0) final_ans += sum/2;
            else final_ans += (sum/2 + 1);
            // cout<<final_ans<<endl;
        }
        return final_ans;
    }
};