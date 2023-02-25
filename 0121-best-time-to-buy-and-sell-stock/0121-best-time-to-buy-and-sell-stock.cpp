class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int idxStart = 0;
        int idxEnd = 1;
        int maxDiff = 0;
        
        while(idxEnd < prices.size()) {
            if (prices[idxEnd] < prices[idxStart]) {
                idxStart = idxEnd;
                idxEnd = idxStart + 1;
            }
            else {
                if (prices[idxEnd] - prices[idxStart] > maxDiff) {
                    maxDiff = prices[idxEnd] - prices[idxStart];
                }
                idxEnd += 1;
            }
        }
        
        return maxDiff;
    }
};