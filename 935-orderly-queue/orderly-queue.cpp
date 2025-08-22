class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.length();
        if(k==1){
            string t = s+s;
            string ans = s;
            int i = 0;
            while(i+n <= 2*n){
                string temp = t.substr(i,n);
                if(temp < ans){
                    ans = temp;
                }
                i++;
            }

            return ans;
        }
        else {
            sort(s.begin(),s.end());
        }

        return s;
    }
};