class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101] = {0};
        int maxFreq = 0;

        for(int num : nums){
            freq[num]++;
            if(freq[num] > maxFreq) maxFreq = freq[num];
        }

        int total = 0;
        for(int i = 0; i <= 100; i++){
            if(freq[i] == maxFreq) total += freq[i];
        }
        return total;
    }
};