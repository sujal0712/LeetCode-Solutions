class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum =0;
        int minlen = INT_MAX;
        int right =0;
        for (int left=0; left < nums.size(); left++){
            while (sum < target && right < nums.size()){
                sum = sum + nums[right];
                right++;
            }
                if (sum >= target ){
                    int current_len = right- left ;
                    minlen = min(current_len, minlen);
                }
                sum = sum - nums[left];
        }
        return minlen == INT_MAX ? 0: minlen;
        
    }
};