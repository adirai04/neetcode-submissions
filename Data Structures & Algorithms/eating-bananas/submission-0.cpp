class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN;
        for (int pile : piles) {
            high = max(high, pile);
        }

        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    bool possible(vector<int> &piles, int speed, int h) {
        long timeReq = 0;
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] <= speed) {
                timeReq++;
            } else {
                timeReq += ceil((double) piles[i] / speed);
            }
        }

        return timeReq <= h;
    }
};