class Solution {
#define ll long long
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int> prev(n), next(n);
        stack<int> s;

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i]) s.pop();
            prev[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            next[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ll left = i - prev[i];
            ll right = next[i] - i;
            ans = (ans + (arr[i] * left % mod) * right % mod) % mod;
        }

        return (int)ans;
    }
};
