class Solution {
public:
    //Kadane's algo
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int tempSum = 0;
        
        for(auto val: nums) {
            tempSum += val;
            if (tempSum > maxSum) {
                maxSum = tempSum;
            }
            if (tempSum < 0) {
                tempSum = 0;
            }
        }
        
        return maxSum;
    }
};