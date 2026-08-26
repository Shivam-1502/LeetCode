class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int ops = 0;

        for(int num : nums){
            int comp = k - num;
            if(count[comp] > 0){
                ops++;
                count[comp]--;
            } else{
                count[num]++;
            }
        }
        return ops;
    }
};