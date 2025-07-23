class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
         unordered_set<string>st;
        for (string word : startWords) {
            sort(word.begin(), word.end());
            st.insert(word);
        }

        int cnt = 0;
        for (string word : targetWords) {
            sort(word.begin(), word.end());

            for (int i = 0; i < word.size(); ++i) {
                string temp = word;
                temp.erase(i, 1);
                if (st.count(temp)) {
                    cnt++;
                    break;
                }
            }
        }

        return cnt;
    }
};