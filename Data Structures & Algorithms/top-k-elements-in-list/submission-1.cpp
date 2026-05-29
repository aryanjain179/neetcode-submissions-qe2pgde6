class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1️⃣ Count frequencies
        // unordered_map<int, int> freq;
        // for (int num : nums) {
        //     freq[num]++;
        // }

        // // 2️⃣ Min-heap to keep top K frequent elements
        // // Heap stores pairs: (frequency, number)
        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // for (auto& [num, count] : freq) {
        //     pq.push({count, num});
        //     if (pq.size() > k) pq.pop(); // remove smallest frequency if heap > K
        // }

        // // 3️⃣ Extract the numbers from the heap
        // vector<int> result;
        // while (!pq.empty()) {
        //     result.push_back(pq.top().second);
        //     pq.pop();
        // }
        // return result; // contains top K frequent elements (order doesn’t matter)

        unordered_map<int, int> freq;
        for (int num : nums){
            freq[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (auto& [num, count] : freq){
            pq.push({count, num});
            if (pq.size() > k){
                pq.pop();
            }
        }

        vector<int> result;
        while (!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
