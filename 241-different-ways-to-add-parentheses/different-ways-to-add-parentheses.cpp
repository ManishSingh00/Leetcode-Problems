class Solution {
public:
    unordered_map<string,vector<int>>dp;
    vector<int> f(string& s,int n){
        // base case
        bool flag = true;
        for(char c : s){
            if(c == '+' || c == '-' || c == '*'){
                flag = false;
                break;
            }
        }
        if(flag == true){
            return {stoi(s)}; // if no operator is found it means it is number itself
        }

        // memoization
        if(dp.count(s) != 0) return dp[s];

        vector<int>res;
        for(int i=0;i<n;i++){
            if(isdigit(s[i]) == 0){
                string left = s.substr(0,i);
                string right = s.substr(i+1);

                vector<int> left_ans = f(left,left.length());
                vector<int>right_ans = f(right,right.length());

                for(auto x:left_ans){
                    for(auto y:right_ans){
                        if(s[i] == '+') res.push_back(x+y);
                        else if(s[i] == '-') res.push_back(x-y);
                        else if(s[i] == '*') res.push_back(x*y);
                    }
                }

            }
        }
        return dp[s] = res;
    }
    vector<int> diffWaysToCompute(string expression) {
        return f(expression,expression.length());
    }
};