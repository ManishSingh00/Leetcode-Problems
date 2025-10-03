class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<pair<int,int>>st;
        
        int res = 0, sign = 1;
        int i = 0;
        while(i<n){
            if(s[i] == ' '){
                i++;
                continue;
            }
            if(s[i] == '('){
                st.push({res,sign});
                res = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                int prev_res = st.top().first;
                int prev_sign = st.top().second;
                st.pop();
                res = prev_res + prev_sign*res;
            }
            else if(s[i] == '+' || s[i] == '-'){
                if(s[i] == '+') sign = 1;
                if(s[i] == '-') sign = -1;
            }
            else{// any  number
                int j = i;
                while(j<n && s[j]-'0' >= 0 && s[j]-'0' <= 9) j++;
                string temp = s.substr(i,j-i);
                int num = stoi(temp);
                res = res + (sign*num);
                i = j;
                continue;
            }
            i++;
        }
        return res;
    }
};