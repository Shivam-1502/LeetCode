class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26);
        int left = 0, maxLen = 0;
        for(int i = 0; i < s.length(); ++i){
            ++freq[s[i] - 'a'];

            while(freq[s[i] - 'a'] > 2){
                --freq[s[left++] - 'a'];
            }

            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};