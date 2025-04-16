#define ll long long int
class Solution {
public:
    ll reverse(ll num,int sz){
        ll res=0;
        bool flag=true;
        if(sz%2!=0){
            flag=false;
        }
        while(num>0){
            if(flag==false){
                flag=true;
                num=num/10;
                continue;
            }
            res = res*10 + num%10;
            num=num/10;
        }
        return res;
    }
    vector<long long> kthPalindrome(vector<int>& queries, int n) {
        ll start=pow(10,(n+1)/2 - 1);
        ll end=pow(10,(n+1)/2)-1;
        vector<ll>ans;
        ll mul=pow(10,n/2);
        for(auto q:queries){
           ll num = start + (q - 1);
            if (num <= end) {
                ll palindrome = num * mul + reverse(num, n);
                ans.push_back(palindrome);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};