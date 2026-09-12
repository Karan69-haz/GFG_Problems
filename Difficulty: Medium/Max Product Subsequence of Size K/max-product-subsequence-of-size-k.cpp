class Solution {
public:

// Memoization
pair<int, int> maxProductMemo(int i, int k, vector<int>& arr, vector<vector<pair<int, int>>>& dp) {
    // Base Case
    if (k == 0) {
        return {1, 1};
    }
    if (i >= arr.size() || arr.size() - i < k) {
        return {INT_MAX, INT_MIN};
    }
    if (dp[i][k].second != INT_MIN) {
        return dp[i][k];
    }

    // Include
    auto [inMin, inMax] = maxProductMemo(i+1, k-1, arr, dp);
    // Exclude
    auto [exMin, exMax] = maxProductMemo(i+1, k, arr, dp);

    inMin *= arr[i];
    inMax *= arr[i];

    int mini = min(exMin, min(inMin, inMax));
    int maxi = max(exMax, max(inMin, inMax));

    return dp[i][k] = {mini, maxi};
}

// Tabulation
int maxProductTab(vector<int>& arr, int k) {
    const int size = arr.size();
    vector<vector<pair<int, int>>> dp(size+1, vector<pair<int, int>>(k+1, {INT_MAX, INT_MIN}));

    // Known values
    for (int i = 0; i <= size; i++) {
        dp[i][0] = {1, 1};
    }

    // Bottom-UP
    for (int i = size-1; i >= 0; i--) {
        for (int j = k; j > 0; j--) {
            // Check mini value
            if (dp[i+1][j-1].second == INT_MIN) {
                continue;
            }

            // Include
            auto [inMin, inMax] = dp[i+1][j-1];
            // Exclude
            auto [exMin, exMax] = dp[i+1][j];

            inMin *= arr[i];
            inMax *= arr[i];

            int mini = min(exMin, min(inMin, inMax));
            int maxi = max(exMax, max(inMin, inMax));

            dp[i][j] = {mini, maxi};
        }
    }

    return dp[0][k].second;
}

// Tabulation SO
int maxProductTabSO(vector<int>& arr, int k) {
    const int size = arr.size();
    vector<pair<int, int>> curr(k+1, {INT_MAX, INT_MIN});
    vector<pair<int, int>> next(k+1, {INT_MAX, INT_MIN});

    // Known values
    curr[0] = {1, 1};
    next[0] = {1, 1};

    // Bottom-UP
    for (int i = size-1; i >= 0; i--) {
        for (int j = k; j > 0; j--) {
            // Check mini value
            if (next[j-1].second == INT_MIN) {
                continue;
            }

            // Include
            auto [inMin, inMax] = next[j-1];
            // Exclude
            auto [exMin, exMax] = next[j];

            inMin *= arr[i];
            inMax *= arr[i];

            int mini = min(exMin, min(inMin, inMax));
            int maxi = max(exMax, max(inMin, inMax));

            curr[j] = {mini, maxi};
        }

        // Updation
        swap(curr, next);
    }

    return next[k].second;
}

int maxProduct(vector<int>& arr, int k) {
    // Memoization
    // const int size = arr.size();
    // vector<vector<pair<int, int>>> dp(size, vector<pair<int, int>>(k+1, {INT_MAX, INT_MIN}));
    // return maxProductMemo(0, k, arr, dp).second;

    // Tabulation
    // return maxProductTab(arr, k);

    // Tabulation SO
    return maxProductTabSO(arr, k);
}

};
