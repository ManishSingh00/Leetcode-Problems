class Solution {
public:
    bool canBeValid(string s, string l) {
        int n  =s.length();
        stack<int>open,star;
        if(n%2!=0) return false;

        for(int i=0;i<n;i++){
            if(l[i]=='0'){
                star.push(i);
            }
            else if(s[i]=='('){
                open.push(i);
            }
            else if(s[i]==')'){
                if(open.size()>0){
                    open.pop();
                }
                else if(star.size()>0){
                    star.pop();
                }
                else{
                    return false;
                }
            }
        }
        cout<<"hello";
        while(open.size()>0 && star.size()>0 && open.top()<star.top()){
            open.pop();
            star.pop();
        }
        if(open.size()>0) return false;
        return true;
        
    }
};