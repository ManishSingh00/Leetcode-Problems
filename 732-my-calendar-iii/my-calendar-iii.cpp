class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    map<int,int>mp;
    int maxi = 0;
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;

        int curr = 0;
        for(auto x:mp){
            curr += x.second;
            maxi = max(maxi,curr);
        }

        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */