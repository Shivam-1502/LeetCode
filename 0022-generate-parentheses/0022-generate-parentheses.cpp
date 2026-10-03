class Solution {
public:

    void backtrack(vector<string>& arr, string curr, int open, int close, int max){
        if(curr.size() == max*2){
            arr.push_back(curr);
            return;
        }

        if(open < max){
            backtrack(arr, curr + "(", open + 1, close, max);
        }
        if(close < open){
            backtrack(arr, curr + ")", open, close + 1, max);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);

        return ans;
    }
};