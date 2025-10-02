#define ll long long int
class Solution {
public:
    vector<string> ans;

    void f(int idx, string& s, string temp, ll curr_val, ll prev_val, int tar, int n) {
        if (idx == n) {
            if (curr_val == tar) ans.push_back(temp);
            return;
        }

        for (int i = idx; i < n; ++i) {
            if(i != idx && s[idx] == '0') break;
            string x = s.substr(idx, i - idx + 1);
            ll curr_num = stoll(x);

            if (idx == 0) {
                f(i + 1, s, x, curr_num, curr_num, tar,n);
            } else {
                // '+'
                f(i + 1, s, temp + "+" + x, curr_val + curr_num, curr_num, tar,n);
                // '-'
                f(i + 1, s, temp + "-" + x, curr_val - curr_num, -curr_num, tar,n);
                // '*'
                // prev_val is maintained only for this step
                f(i + 1, s, temp + "*" + x, curr_val - prev_val + prev_val * curr_num, prev_val * curr_num, tar,n);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        ans.clear();
        f(0, num, "", 0, 0, target, num.size());
        return ans;
    }
};
