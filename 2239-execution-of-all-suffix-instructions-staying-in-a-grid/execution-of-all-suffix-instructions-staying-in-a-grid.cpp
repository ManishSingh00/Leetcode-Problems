class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& s, string str) {
        int st_i = s[0],st_j=s[1];
        int sz = str.length();
        vector<int>ans(sz);

        for(int i=0;i<sz;i++){
            int j = i;
            int move = 0;
            int si = st_i,sj=st_j;
            while(j<sz && si>=0 && sj>=0 && si<n && sj<n){
                if(str[j]=='R') sj+=1;
                else if(str[j]=='L') sj-=1;
                else if(str[j]=='D') si+=1;
                else if(str[j]=='U') si-=1;
                j++;
                move++;
            }
            if(si==n || sj == n || si<0 || sj<0) ans[i] = move-1;
            else ans[i] = move;
        }
        return ans;
    }
};