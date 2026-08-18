class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthestJump = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > farthestJump) return false;

            farthestJump = max(farthestJump, i + nums[i]);
        }

        return true;
    }
};
