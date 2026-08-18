class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =0;
        int maxlength = 0;
        unordered_set<char> seen;
        for (int right =0; right<s.length(); right++){
            while (seen.count(s[right])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            maxlength = max(maxlength, right-left+1);
        }
        return maxlength;
    }
};