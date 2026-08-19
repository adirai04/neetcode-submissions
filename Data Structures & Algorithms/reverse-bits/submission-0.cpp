class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int exp = 31;
        int num = 0;
        while (n > 0) {
            int dgt = n & 1;
            num += dgt * pow(2, exp);
            exp--;

            n = n >> 1;
        }

        return num;
    }
};
