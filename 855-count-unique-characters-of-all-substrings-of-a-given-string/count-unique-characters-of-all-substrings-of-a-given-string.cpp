#define ll long long int
class Solution {
public:
    int uniqueLetterString(string s) {
        ll n = s.length();
        int ans = 0;

        for(char ch='A';ch<='Z';ch++){
            vector<int>temp;
            temp.push_back(-1);
            for(int i=0;i<n;i++){
                if(s[i]==ch){
                    temp.push_back(i);
                }
            }
            temp.push_back(n);
            int cnt = 0;
            for(int j=1;j<temp.size()-1;j++){
                cnt += (temp[j] - temp[j-1])*(temp[j+1]-temp[j]);  // left*right  contribution 
            }
            ans += cnt;
        }

        return ans;
    }
};