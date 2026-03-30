class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<vector<int>> heap;
        vector<int> output;
        for (int i = 0; i < nums.size(); i++) {
            heap.push({nums[i], i});
            if (i >= k - 1) {
                while (heap.top()[1] <= i - k) {
                    heap.pop();
                }
                output.push_back(heap.top()[0]);
            }
        }
        return output;
    }
};
