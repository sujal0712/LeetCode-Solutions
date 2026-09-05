class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxfreq = 0;
        int left = 0;
        int answer = 0;

        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'A']++;

            maxfreq = max(maxfreq, count[s[right] - 'A']);

            while ((right - left + 1) - maxfreq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            int current_len = right - left + 1;
            answer = max(answer, current_len);
        }

        return answer;
    }
};