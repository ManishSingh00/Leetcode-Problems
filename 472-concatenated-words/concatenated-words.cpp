class Solution {
public:
    unordered_set<string>st;
    unordered_map<string,bool>mp;
    bool f(string& word){
        if(mp.count(word)!=0) return mp[word];
        int m = word.size();

        for(int i=0;i<m;i++){
            string front = word.substr(0,i);
            string back = word.substr(i);

            if(st.count(front)!=0){
                if(st.count(back)!=0){
                    return mp[word] = true;
                }
                else if(f(back) ==  true){
                    return mp[word] = true;
                }
            }
        }
        return mp[word] = false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        st = unordered_set<string>(words.begin(),words.end());
        vector<string>ans;
        int n = words.size();
        for(int i=0;i<n;i++){
            if(f(words[i]) == true){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};