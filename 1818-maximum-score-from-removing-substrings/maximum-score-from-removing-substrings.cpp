class Solution {
public:
    int f(string &s, string t, int cost){
        stack<char>st;
        int cnt = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(st.size()>0 && st.top() == t[0] && s[i] == t[1]){
                st.pop();
                cnt += cost;

            }
            else st.push(s[i]);
        }

        string temp = "";
        while(st.size()>0){
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        s = temp;

        return cnt;
    }
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        
        int ans = 0;
        if(x>=y){
            ans += f(s,"ab",x);
            ans += f(s,"ba",y);
        }
        else if(x<y){
            ans += f(s,"ba",y);
            ans += f(s,"ab",x);
        }
        return ans;
    }
};