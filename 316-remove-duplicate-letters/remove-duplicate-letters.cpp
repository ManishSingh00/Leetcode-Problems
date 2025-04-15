class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.length();
        vector<int>freq(26);
        vector<bool>seen(26);

        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        string ans="";
        for(int i=0;i<n;i++){
            freq[s[i]-'a']--;
            if(seen[s[i]-'a'] == true) continue;

            while(ans.length()>0 && s[i]<ans.back() && freq[ans.back()-'a']>0){
                seen[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            seen[s[i]-'a']=true;
        }

        return ans;

    }
};