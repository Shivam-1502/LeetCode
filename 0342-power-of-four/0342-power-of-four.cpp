class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        int count = 0;
        while(n % 4 == 0){
            // n = n >> 1;
            // count++;
            n /= 4;
        } 

        // if(count % 2 == 0 && n == 1) return true;

        return n == 1;
    }
};