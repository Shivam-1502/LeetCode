class Solution {
public:
    int gcd(int a, int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        int minNum = nums[0];
        int maxNum = nums[0];

        for(int num : nums){
            if(num < minNum) minNum = num;
            if(num > maxNum) maxNum = num;
        }

        return gcd(minNum, maxNum);
    }
};