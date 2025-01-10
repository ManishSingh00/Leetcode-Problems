class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        int n1=w1.size();
        int n2=w2.size();
        vector<string> ans;
        vector<int> maxFreq(26, 0);
        for (const string& word : w2) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        for (const string& word : w1) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            bool isUniversal = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal==true) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};