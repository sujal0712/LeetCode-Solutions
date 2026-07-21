class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currentMax = nums[0];
        int currentMin = nums[0];
        int answer = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int previousMax = currentMax;
            int previousMin = currentMin;

            currentMax = max({
                nums[i],
                nums[i] * previousMax,
                nums[i] * previousMin
            });

            currentMin = min({
                nums[i],
                nums[i] * previousMax,
                nums[i] * previousMin
            });

            answer = max(answer, currentMax);
        }

        return answer;
    }
};