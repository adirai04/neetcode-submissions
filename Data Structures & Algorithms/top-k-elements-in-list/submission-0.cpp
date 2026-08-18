class Solution {
    typedef pair<int, int> P;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<P, vector<P>, greater<P>> minHeap;
        unordered_map<int, int> mpp;

        for (int num : nums) {
            mpp[num]++;
        }

        for (auto it : mpp) {
            int num  = it.first;
            int freq = it.second;

            minHeap.push({freq, num});

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> ans;
        while (!minHeap.empty()) {
            int num = minHeap.top().second;
            minHeap.pop();

            ans.push_back(num);
        }

        return ans;

    }
};
