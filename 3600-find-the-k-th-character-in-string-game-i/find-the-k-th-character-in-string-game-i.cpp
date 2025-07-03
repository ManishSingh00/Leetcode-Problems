class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.length()<k){
            string temp = s;
            for(int i=0;i<temp.length();i++){
                if(temp[i]=='z') temp[i]='a';
                else temp[i] = temp[i]+1;
            }
            s = s + temp;
        }
        return s[k-1];
    }
};