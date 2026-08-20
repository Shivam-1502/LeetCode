class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1;
        vector<int> arr2;
        
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int i = 2; i < n; i++){
            int p = arr1.size();
            int q = arr2.size();

            if(arr1[p-1] > arr2[q-1]){
                arr1.push_back(nums[i]);
            } else{
                arr2.push_back(nums[i]);
            }
        }

        vector<int> res;
        for(int i = 0; i < arr1.size(); i++){
            res.push_back(arr1[i]);
        }

        for(int i = 0; i < arr2.size(); i++){
            res.push_back(arr2[i]);
        }

        return res;
    }
};