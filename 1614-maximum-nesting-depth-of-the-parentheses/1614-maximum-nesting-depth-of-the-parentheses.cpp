class Solution {
public:
    int maxDepth(string s) {
        int curr = 0;
        int max_d = 0;

        for(char c : s){
            if(c == '('){
                curr++;
                max_d = max(max_d, curr);
            } else if(c == ')'){
                curr--;
            }
        }
        return max_d;
    }
};