class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        string a = "";
        string b = "";
        string c = "";
        string d = "";
        for(int i=0;i<n;i+=2){
            a += s1[i];
            b += s1[i+1];
            c += s2[i];
            d += s2[i+1];
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        sort(d.begin(),d.end());

        if(a == c && b == d) return true;
        else return false; 
    }
};