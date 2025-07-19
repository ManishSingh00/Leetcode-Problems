class Solution {
public:
    vector<string> removeSubfolders(vector<string>& str) {
        int n = str.size();
        sort(str.begin(),str.end());
        unordered_map<string,bool>mp;
        vector<string>ans;

        for(int i=0;i<n;i++){
            string temp = str[i];
            int j = 0;

            string temp2 = "";
            while(j<temp.length()){
                if(temp[j]=='/' && mp.count(temp2)) break;
                temp2+=temp[j];
                j++;
            }
            if(j==temp.length()){
                ans.push_back(str[i]);
                mp[temp2]=1;
            }
        }

        return ans;
    }
};