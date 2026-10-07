class Solution {
public:

    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;
        
        q.push(s);
        visited.insert(s);
        
        while (!q.empty()) {
            string current = q.front();
            q.pop();
            
            if (isValid(current)) {
                result.push_back(current);
            }
            if (!result.empty()) continue;
            
            for (int i = 0; i < current.length(); i++) {
                if (current[i] != '(' && current[i] != ')') continue;                
                string nextString = current.substr(0, i) + current.substr(i + 1);
                
                if (visited.find(nextString) == visited.end()) {
                    visited.insert(nextString);
                    q.push(nextString);
                }
            }
        }
        
        return result;
    }
};