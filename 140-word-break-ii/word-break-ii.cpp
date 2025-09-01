class Solution {
public:
    unordered_set<string>st;
    unordered_map<int,vector<string>> dp;

    vector<string> f(int i,string& s){
        vector<string>ans;

        if(i == s.length()){
            ans.push_back("");
            return ans;
        }
        
        if(dp.count(i) != 0) return dp[i];

        for(int j=i+1;j<=s.length();j++){
            string front = s.substr(i,j-i);
            if(st.count(front) == 0) continue;
            vector<string> rem = f(j,s);

            for(auto str:rem){
                if(str == ""){
                    ans.push_back(front);
                }
                else{
                    ans.push_back(front+" "+str);
                }
            }
        }
        return dp[i] = ans;
    }
    vector<string> wordBreak(string s, vector<string>& dict) {
        st = unordered_set<string>(dict.begin(),dict.end());
        return f(0,s);
    }
};