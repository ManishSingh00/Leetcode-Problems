class Solution {
public:
    string f(int n){
        string s = "";
        while(n>0){
            int rem = n%2;
            s += (rem+'0');
            n = n/2;
        }
        return s;
    }
    int minBitFlips(int start, int goal) {
        string st = f(start);
        string endd = f(goal);

        // cout<<st<<" "<<endd<<endl;

        int st_size = start !=0 ? floor(log2(start))+1 : 0;
        int end_size = goal !=0 ? floor(log2(goal)) + 1 :0;


        if(end_size > st_size){
            int diff = end_size - st_size;
            while(diff--){
                st += '0';
            }
        }
        else if(st_size > end_size){
            int diff = st_size - end_size;
            while(diff--){
                endd += '0';
            }
        }
        reverse(st.begin(),st.end());
        reverse(endd.begin(),endd.end());

        int n = st.length();
        int i = n-1;

        int ans = 0;
        while(i>=0){
            if(st[i] != endd[i]){
                ans++;
            }
            i--;
        }

        return ans;
    }
};