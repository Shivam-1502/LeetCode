class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int open = 0;
        for(char c : s){
            if(c == '('){
                if(open != 0){
                    res += "(";
                }
                open++;
            }
            if(c == ')'){
                if(open != 1) {
                    res += ")";
                }
                open--;
            }        
        }
        return res;
    }
};