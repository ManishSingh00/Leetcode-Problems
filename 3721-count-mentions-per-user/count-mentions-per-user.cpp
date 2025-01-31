class Solution {
public:
    static bool cmp(vector<string>& a,vector<string>& b){
        string s1=a[1];
        string s2=b[1];
        if(stoi(s1) == stoi(s2)) return a[0] == "OFFLINE";
        return (stoi(s1) < stoi(s2));
    }
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        sort(events.begin(),events.end(),cmp);
        int m=events.size();
        unordered_set<int>online;
        queue<pair<int,int>>q;

        for(int i = 0; i < n; i++){
            online.insert(i);
        }

        vector<int>ans(n);
        for(auto v : events){
            int t = stoi(v[1]);
            while(q.size()>0 && q.front().first<=t){
                online.insert(q.front().second);
                q.pop();
            }
            if(v[0]=="MESSAGE"){
                if(v[2]=="ALL"){
                    for(int i=0;i<n;i++){
                        ans[i]++;
                    }
                    continue;
                }
                if(v[2]=="HERE"){
                    for(auto i:online){
                        ans[i]++;
                    }
                    continue;
                }
                stringstream ss(v[2]);
                string temp;
                while(ss>>temp){
                    int id=stoi(temp.substr(2));
                    ans[id]++;
                }
            }
            else{ // v[0]=='OFFLINE
                int id=stoi(v[2]);
                online.erase(id);
                q.push({60+t,id});
            }

        }
        return ans;


    }
};