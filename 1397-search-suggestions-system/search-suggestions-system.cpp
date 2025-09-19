class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& arr, string word) {
        int n = arr.size();
        int m = word.length();
        sort(arr.begin(),arr.end());
        vector<vector<string>>ans;

        for(int i=0;i<m;i++){
            string tar = word.substr(0,i+1);
            int  cnt = 0;
            // cout<<"hello"<<endl;
            vector<string>st;
            for(int j=0;j<n;j++){
                string temp = arr[j];
                if(temp.length() >= tar.length()){
                    // cout<<"hello2"<<endl;
                    if(temp.substr(0,i+1) == tar && cnt < 3){
                        cnt++;
                        st.push_back(temp);
                    }
                }
                // cout<<"hello3"<<endl;
            }
            ans.push_back(st);
        }

        return ans;
    }
};