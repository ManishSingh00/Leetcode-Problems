class Solution {
public:
    string f(int i,int j,int n,string& s){
        while(i>=0 && j<n && s[i]==s[j]){
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            string temp = f(i,i,n,s);
            if(temp.length()>ans.length()) ans=temp;
        }

        for(int i=0;i<n;i++){
            string temp = f(i,i+1,n,s);
            if(temp.length()>ans.length()) ans=temp;
        }

        return ans;
    }
};