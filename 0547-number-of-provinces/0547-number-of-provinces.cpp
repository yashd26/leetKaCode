class Solution {
public:
    vector<int> vec;
    
    int find(int x) {
        if (vec[x] == -1) {
            return x;
        }
        
        vec[x] = find(vec[x]);
        return vec[x];
    }
    
    void join(int i, int j) {
        int a = find(i);
        int b = find(j);
        
        if (a == b) {
            return;
        }
        
        vec[a] = b;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0; 
        
        for(int i = 0; i < isConnected.size(); ++i) {
            vec.push_back(-1);
        }
        
        for(int i = 0; i < isConnected.size(); ++i) {
            for(int j = 0; j < isConnected[i].size(); ++j) {
                if (isConnected[i][j] && i != j) {
                    join(i, j);
                }
            }
        }
        
        for(int i = 0; i < vec.size(); i++) {
            if(vec[i] == -1) {
                cnt++;
            }
        }
        
        return cnt;
    }
};