class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // unordered_set<int> numsSet;
        // for (int num : nums){
        //     numsSet.insert(num);
        // }
        // int maxLen = 0;
        // for (int num: numsSet){
        //     if (!numsSet.count(num-1)){
        //         int tempLen = 1;
        //         int tempNum = num;
        //         tempNum++;
        //         while (numsSet.count(tempNum)){
        //             tempLen++;
        //             tempNum++;
        //         }
        //         maxLen = max(maxLen,tempLen);
        //     }
        // }
        // return maxLen;

        unordered_set<int> numsSet;
        for (int num: nums){
            numsSet.insert(num);
        }
        int maxLen = 0;
        for (int num: numsSet){
            if (!numsSet.count(num-1)){
                int tempLen = 1;
                int tempNum = num;
                tempNum++;
                while (numsSet.count(tempNum)){
                    tempLen++;
                    tempNum++;
                }
                maxLen = max(maxLen, tempLen);
            }
        }
        return maxLen;
    }
};
