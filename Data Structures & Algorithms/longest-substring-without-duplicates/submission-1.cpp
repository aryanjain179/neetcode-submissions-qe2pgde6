 class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // if (s.empty()) return 0;

        // int l = 0;
        // int r = 0;
        // unordered_set<char> seen;
        // int maxLen = 0;
        // int temp = 0;

        // while (r < s.length()) {
        //     if (seen.count(s[r]) != 0) {
        //         // Duplicate found, shrink window from left
        //         while (s[l] != s[r]) {
        //             seen.erase(s[l]);
        //             l++;
        //             temp--;
        //         }
        //         // Remove the duplicate itself and move right
        //         seen.erase(s[l]);
        //         l++;
        //         temp--;
        //     }
        //     // Add new character
        //     seen.insert(s[r]);
        //     r++;
        //     temp++;
        //     maxLen = max(maxLen, temp);
        // }

        // return maxLen;

        int l = 0;
        int r = 0;
        unordered_set<char> seen;
        int maxLen = 0;
        int temp = 0;

        while (r < s.length()){
            if (seen.count(s[r]) != 0){
                while (s[l] != s[r]){
                    seen.erase(s[l]);
                    l++;
                    temp--;
                }
                seen.erase(s[l]);
                l++;
                temp--;
            }
            seen.insert(s[r]);
            temp++;
            maxLen = max(maxLen, r-l+1);
            r++;
        }

        return maxLen;
    }
};