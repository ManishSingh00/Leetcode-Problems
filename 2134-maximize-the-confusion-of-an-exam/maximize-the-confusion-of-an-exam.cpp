class Solution {
public:
    int f(string &str,char ch,int k){
        int left = 0, right = 0, n = str.length();
        while (right < n) {
            if(str[right]==ch) right++;
            else if (str[right] != ch) {
                k--;
                right++;
            }
            if (k < 0) {
                if (str[left] != ch) k++;
                left++;
            }
        }
        return right - left;
    }
    int maxConsecutiveAnswers(string str, int k) {
        return max(f(str,'T',k),f(str,'F',k));
    }
};