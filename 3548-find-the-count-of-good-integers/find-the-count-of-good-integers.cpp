#define ll long long int
class Solution {
public:
    vector<string> f(int n){
        vector<string>ans;
        if (n == 1) {
            for (char d = '1'; d <= '9'; d++) {
                string s(1, d);
                ans.push_back(s);
            }
            return ans;
        }
        int len=n/2;
        int start=pow(10,len-1);
        int end=pow(10,len)-1;
        
        bool is_odd=n%2!=0;
        for(int i=start;i<=end;i++){
            string temp=to_string(i);
            if(is_odd==true){ // we have to add one midddle digit
                for(char mid='0';mid<='9';mid++){
                    string str=temp+mid;
                    reverse(temp.begin(),temp.end());
                    str=str+temp;
                    reverse(temp.begin(),temp.end()); // again reversing for new string
                    ans.push_back(str);
                }
            }
            else{
                string str=temp;
                reverse(str.begin(),str.end());
                ans.push_back(temp+str);
            }
        }
        return ans;    
    }   

    // vector<ll> factorial;
    // factorial.push_back(1);
    // ll fact(int n) {
    //     while ((int)factorial.size() <= n) {
    //         factorial.push_back(factorial.back() * factorial.size());
    //     }
    //     return factorial[n];
    // }
      ll fact(int n){
        if(n==1) return 1;
        return n*fact(n-1);
    }

    long long countGoodIntegers(int n, int k) {
        vector<string> palindrome = f(n);
        ll ans=0;
        set<vector<int>> seen;  // to store unique digit frequency
        for (string& p : palindrome) {
            ll num = stoll(p);
            if (num % k != 0) continue;
            
            vector<int> freq(10, 0);
            for (char ch : p) freq[ch - '0']++;
            
            if (seen.count(freq)!=0) continue; 
            seen.insert(freq);
            
            int tot_digit=n;
            int num_val=fact(tot_digit);
            for(int i=0;i<10;i++){
                if(freq[i]>1) num_val/=fact(freq[i]);
            }
            if(freq[0]==0) ans+=num_val;
            else{
                int num_val_new=fact(tot_digit-1);
                for(int i=0;i<10;i++){
                    if(i==0) freq[0]--;
                    if(freq[i]>1) num_val_new/=fact(freq[i]);
                }
                ans+=(num_val-num_val_new);
            }
        }
        return ans;
    }
};