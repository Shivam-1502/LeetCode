class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;   // stores repeat numbers
        stack<string> saved;    // stores string built before '['
        string current = "";    // string being built right now
        int k = 0;              // number being parsed right now

        for (char c : s) {
            if (isdigit(c)) {
                // Build multi-digit numbers: "12[a]" → k = 1*10+2 = 12
                k = k * 10 + (c - '0');

            } else if (c == '[') {
                // Save state and reset for inner content
                counts.push(k);
                saved.push(current);
                current = "";
                k = 0;

            } else if (c == ']') {
                // Repeat current string, append to what was saved
                int repeat = counts.top(); counts.pop();
                string prev = saved.top();  saved.pop();
                string repeated = "";
                for (int i = 0; i < repeat; i++)
                    repeated += current;
                current = prev + repeated;

            } else {
                // Regular character — just append
                current += c;
            }
        }

        return current;
    }
};