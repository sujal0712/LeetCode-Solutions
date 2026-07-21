class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int current_max = nums[0];
        int current_min= nums[0];
        int answer = nums[0];
        for (int i=1; i<nums.size(); i++){
             int previous_max = current_max;
             int previous_min = current_min;
             current_max = max({nums[i], nums[i]*previous_max,nums[i]*previous_min});
             current_min = min({nums[i], nums[i]*previous_max,nums[i]*previous_min});
             answer = max(answer, current_max);
        }
        return answer;
    }
};