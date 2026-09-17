class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = n + 1;

        vector<int> best(n, INF); 
        int ans = INF;
        int curr_sum = 0, left = 0;

        for (int right = 0; right < n; right++) {
            curr_sum += arr[right];

            while (curr_sum > target)
                curr_sum -= arr[left++];

            if (curr_sum == target) {
                int len = right - left + 1;

                if (left > 0 && best[left - 1] < INF){
                    ans = min(ans, len + best[left - 1]);
                }
                best[right] = min((right > 0 ? best[right - 1] : INF), len);
            } else {
                best[right] = (right > 0 ? best[right - 1] : INF);
            }
        }

        return ans >= INF ? -1 : ans;
    }
};