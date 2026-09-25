class Solution {
    set<string> result;

    void dfs(string exp) {
        int j = exp.find('}');
        if (j == string::npos) {
            result.insert(exp);
            return;
        }

        int i = exp.rfind('{', j);

        string before = exp.substr(0, i);
        string after  = exp.substr(j + 1);
        string inner  = exp.substr(i + 1, j - i - 1);

        stringstream ss(inner);
        string token;
        while (getline(ss, token, ',')) {
            dfs(before + token + after);
        }
    }

public:
    vector<string> braceExpansionII(string expression) {
        dfs(expression);
        return vector<string>(result.begin(), result.end());
    }
};