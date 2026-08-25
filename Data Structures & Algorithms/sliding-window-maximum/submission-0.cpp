class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int n = nums.size();
        
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            while (!q.empty() && q.back() < nums[i]) {
                q.pop_back();
            }

            q.push_back(nums[i]);
        }

        ans.push_back(q.front());

        int left = 0;
        for (int i = k; i < n; i++) {
            if (nums[left] == q.front()) {
                q.pop_front();
            }
            left++;

            while (!q.empty() && q.back() < nums[i]) {
                q.pop_back();
            }

            q.push_back(nums[i]);
            ans.push_back(q.front());
        }

        return ans;
    }
};
