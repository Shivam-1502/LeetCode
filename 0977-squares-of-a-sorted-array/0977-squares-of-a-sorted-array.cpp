class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        vector<int> ans(n);
        int k = n - 1;
        while(l <= r){
            int leftsq = nums[l]*nums[l];
            int rightsq = nums[r]*nums[r];

            if(leftsq > rightsq){
                ans[k] = leftsq;
                l++;
            } else {
                ans[k] = rightsq;
                r--;
            }
            k--;
        }
        return ans;
    }
};