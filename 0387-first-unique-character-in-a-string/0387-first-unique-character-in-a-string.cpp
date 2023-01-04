class Solution {
public:
    int firstUniqChar(string s) {
        map<char, pair<int, int>> mp;
        
        for(int i = 0; i < s.length(); ++i) {
            mp[s[i]].first = i;
            mp[s[i]].second++;
        }
        
        int idx = INT_MAX;
        for(auto ele: mp) {
            if (ele.second.second == 1 && ele.second.first < idx) {
                idx = ele.second.first;
            }
        }
        
        if (idx >= 0 && idx < s.length()) {
            return idx;
        }
        return -1;
    }
};