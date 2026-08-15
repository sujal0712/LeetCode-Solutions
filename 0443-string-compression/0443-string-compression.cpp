class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int index = 0;
        while (i < chars.size()) {
            char current = chars[i];
            int count = 0;
            while (i < chars.size() && current == chars[i]) {
                count++;
                i++;
            }
            chars[index] = current;
            index++;
            if (count > 1) {
                string st = to_string(count);
                for (char c : st) {
                    chars[index] = c;
                    index++;
                }
            }
        }
        return index;
    }
};