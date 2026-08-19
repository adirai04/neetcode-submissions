class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);

        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int x = maxHeap.top();
            maxHeap.pop();

            minHeap.push(x);
        }

        int n1 = maxHeap.size();
        int n2 = minHeap.size();

        int diff = abs(n1 - n2);
        if (diff > 1) {
            if (n1 > n2) {
                int x = maxHeap.top();
                maxHeap.pop();

                minHeap.push(x);
            } else {
                int x = minHeap.top();
                minHeap.pop();

                maxHeap.push(x);
            }
        }
    }
    
    double findMedian() {
        int m = maxHeap.size();
        int n = minHeap.size();

        if (m == n) {
            int x1 = maxHeap.top();
            int x2 = minHeap.top();

            return (double) (x1 + x2) / 2;
        } else {
            if (m > n) return maxHeap.top();
            else return minHeap.top();
        }
    }
};
