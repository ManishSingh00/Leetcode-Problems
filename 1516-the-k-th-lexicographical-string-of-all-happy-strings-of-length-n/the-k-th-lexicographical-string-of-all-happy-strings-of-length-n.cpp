class Solution {
public:
    vector<string>str;
    void f(int j,int n,string temp){
        if(j==n){
            str.push_back(temp);
            return;
        }
        for(int i=0;i<3;i++){
            char ch='a'+i;
            if(temp.size()==0){
                temp.push_back(ch);
                f(j+1,n,temp);
                temp.pop_back();
            }
            if(temp.size()>=1 && temp[temp.size()-1]!= ch){
                temp.push_back(ch);
                f(j+1,n,temp);
                temp.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        string temp;
        f(0,n,temp);
        int sz=str.size();
        sort(str.begin(),str.end());
        if(sz<k) return "";
        else return str[k-1];
    }
};