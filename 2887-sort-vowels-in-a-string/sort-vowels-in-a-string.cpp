class Solution {
public:
    string sortVowels(string s) {
        string temp="";
        int n = s.length();
        unordered_set<char>st{'A','E','I','O','U','a','e','i','o','u'};
        for(int i=0;i<n;i++){
            if(st.count(s[i]) != 0){
                temp.push_back(s[i]);
            }
        }

        sort(temp.begin(),temp.end());
        int idx = 0;

        for(int i=0;i<n;i++){
            if(st.count(s[i]) == 0) continue;
            else{
                s[i] = temp[idx];
                idx++;
            }
        }
        return s;
    }
};