class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(char c : word1) freq1[c - 'a']++;
        for(char c : word2) freq2[c - 'a']++;

        for(int i = 0; i < 26; ++i){
            if((freq1[i] == 0) != (freq2[i] == 0)) return false;
        }

        vector<int> freqOfFreq1(100001, 0);
        vector<int> freqOfFreq2(100001, 0);
        
        for (int f : freq1) {
            if (f > 0) freqOfFreq1[f]++;
        }
        
        for (int f : freq2) {
            if (f > 0) freqOfFreq2[f]++;
        }

        for (int i = 1; i < freqOfFreq1.size(); i++) {
            if (freqOfFreq1[i] != freqOfFreq2[i]) return false;
        }
        
        return true;
    }
};