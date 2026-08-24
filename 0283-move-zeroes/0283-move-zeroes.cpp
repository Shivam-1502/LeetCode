class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int lastNZ = 0;
        
        for(int i = 0; i < n; ++i){
            if(nums[i] != 0){
                if(i != lastNZ){
                    swap(nums[i], nums[lastNZ]);
                }
                lastNZ++;
            }
        }
    }
};