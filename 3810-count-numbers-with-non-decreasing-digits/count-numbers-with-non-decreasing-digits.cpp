#define ll long long int
#define mod 1000000007
class Solution {
public:
    vector<int> convert(string num, int b) {
        vector<int> digits;
        while(num != "0"){
            int carry=0;
            string q="";

            for (char ch:num) {
                int cur=carry * 10 + (ch - '0');
                int quot=cur / b;
                carry=cur % b;

                if (!(q.empty() && quot==0))
                    q += (char)(quot + '0');
            }
            digits.push_back(carry);
            num = (q.empty() ? "0" : q);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
    ll dp[505][2][2][15];
    ll f(int pos,bool tight,bool leadingzero,int prev,vector<int>& num,int b){
        if(pos==num.size()) return leadingzero==true?0:1;
        if(dp[pos][tight][leadingzero][prev]!=-1) return dp[pos][tight][leadingzero][prev];

        ll ans=0;
        int ub=(tight==0)?b-1:num[pos];
        for(int dig=0;dig<=ub;dig++){
            bool new_tight=tight&&(dig==ub);
            if(leadingzero==true){
                if(dig==0) ans += f(pos+1,new_tight,true,10,num,b);
                else ans += f(pos+1,new_tight,false,dig,num,b);
            }
            else{
            if(prev!=10 && dig-prev>=0) ans += f(pos+1,new_tight,false,dig,num,b);
            }
        }
        return dp[pos][tight][leadingzero][prev]=ans;
    }
    int countNumbers(string l, string r, int b) {
        vector<int>arr_l=convert(l,b);
        vector<int>arr_r=convert(r,b);

        memset(dp,-1,sizeof dp);
        ll x=f(0,true,true,10,arr_r,b);
        
        memset(dp,-1,sizeof dp);
        ll y=f(0,true,true,10,arr_l,b);

        bool flag=true;
        for(int i=1;i<arr_l.size();i++){
            if(arr_l[i-1]>arr_l[i]) flag=false;
        }

        return (x-y+(flag==true?1:0)+mod)%mod; 
    }
};