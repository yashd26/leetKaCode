class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        
        for(int i = 0; i < students.size(); ++i) {
            q.push(students[i]);
        }
        
        int idx = 0, rotate = 0;
        while(q.size() && rotate < q.size()) {
            if (q.front() == sandwiches[idx]) {
                q.pop();
                idx++;
                rotate = 0;
            }
            else {
                int val = q.front();
                q.pop();
                q.push(val);
                rotate++;
            }
        }
        
        return q.size();
    }
};