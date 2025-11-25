class Solution {
public:
    string findLongestWord(string s, vector<string>& dict) {
        int n = s.length();

        vector<vector<int>>nxt_pos(n+1,vector<int>(26,-1));
        for(int i=n-1;i>=0;i--){
            nxt_pos[i] = nxt_pos[i+1];
            if(s[i] >= 'a' && s[i] <= 'z'){
                nxt_pos[i][s[i] - 'a'] = i;
            }
        }


        string best = "";
        for(auto& w:dict){
            bool ok = true;
            int pos = 0;

            for(int i=0;i<w.length();i++){
                if(w[i] < 'a' && w[i] > 'z'){
                    ok = false;
                    break;
                }
                int nxt = nxt_pos[pos][w[i]-'a'];

                if(nxt == -1){
                    ok = false;
                    break;
                }
                pos = nxt + 1;
            }
            if(ok == true){
                if(w.length() > best.length()) best = w;
                else if (w.length() == best.length()){
                    if(w < best) best = w;
                }
            }
        }

        return (best.size() == 0 ? "" : best);
    }
};