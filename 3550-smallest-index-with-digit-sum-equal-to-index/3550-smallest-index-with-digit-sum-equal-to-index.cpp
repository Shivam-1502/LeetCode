class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int sum = 0;
            while(nums[i] > 0){
                int temp = nums[i];
                int dig = temp % 10;
                sum += dig;
                nums[i] /= 10;
            }
            if(sum == i) return i;
        }
        return -1;
    }
};