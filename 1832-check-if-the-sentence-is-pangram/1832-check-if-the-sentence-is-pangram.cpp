class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.length() < 26) return false;

        unordered_map<char, int>freqMap;

        for(char c : sentence){
            freqMap[c]++;
        }

        return freqMap.size() == 26;
    }
};