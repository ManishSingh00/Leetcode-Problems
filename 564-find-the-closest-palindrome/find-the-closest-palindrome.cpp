#define ll long long int
class Solution {
public:
    ll convert(string str){
        int n=str.length();
        int i=0,j=n-1;
        while(i<j){
            str[j]=str[i];
            j--;
            i++;
        }
        return stoll(str);
    }

    ll left(string str){
        ll lo=0,hi=stoll(str);
        ll ans;
        while(lo<=hi){
            ll mid=lo+(hi-lo)/2;
            string temp=to_string(mid);
            ll pali=convert(temp);
            if(pali<stoll(str)){
                ans=pali;
                lo=mid+1;
            }
            else hi=mid-1;

        }
        return ans;
    }

    ll right(string str){
        ll lo=stoll(str),hi=1e18;
        ll ans;
        while(lo<=hi){
            ll mid=lo+(hi-lo)/2;
            string temp=to_string(mid);
            ll pali=convert(temp);
            if(pali>stoll(str)){
                ans=pali;
                hi=mid-1;;
            }
            else lo=mid+1;
        }
        return ans;
    }
    string nearestPalindromic(string n) {
        ll x=left(n);
        ll y=right(n);
        ll num=stoll(n);
        if(abs(x-num)<=abs(y-num)) return to_string(x);
        else return to_string(y);
    }
};