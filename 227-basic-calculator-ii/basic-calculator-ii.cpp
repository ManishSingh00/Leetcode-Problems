class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int>st;
        char opr = '+';
        int i = 0;
        while(i<n){
            if(s[i] == ' '){
                i++;
                continue;
            }
            if(isdigit(s[i]) == 0){ // if any operator is found
                opr = s[i];
            }
            else{
                int j = i;
                while(j<n && s[j]-'0' >= 0 && s[j]-'0' <= 9) j++;
                string temp = s.substr(i,j-i);
                int num = stoi(temp);
                if(opr == '+'){
                    st.push(num);
                }
                else if(opr == '-'){
                    st.push(-num);
                }
                else if(opr == '*'){
                    int val = st.top();
                    st.pop();
                    st.push(num*val);
                }
                else{
                    int val = st.top();
                    st.pop();
                    st.push(val/num);
                }
                i = j;
                continue;
            }
            i++;
        } 
        int res = 0;
        while(st.size()>0){
            res += (st.top());
            st.pop();
        }
        return res;
    }
};