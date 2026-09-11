class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans = 0;
        int n = digits.size();
        int count[10] = {0};

        for(int d : digits) count[d]++;

        for(int num = 100; num <= 999; num += 2){
            int temp = num;
            int tempCount[10] = {0};

            for(int i = 0; i < 3; ++i){
                int digit = temp % 10;
                tempCount[digit]++;
                temp /= 10;
            }

            bool psbl = true;
            for(int d = 0; d <= 9; ++d){
                if(tempCount[d] > count[d]){
                    psbl = false;
                    break;
                }
            }
            if(psbl) ans++;
        }
        return ans;
    }
};