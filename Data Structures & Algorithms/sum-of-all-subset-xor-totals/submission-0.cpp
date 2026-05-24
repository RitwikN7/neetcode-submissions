class Solution {
private:
    int total{};
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> subset{};
        dfs(0, 0, nums, subset);
        return total;
    }

    void dfs(int i, int xorr, vector<int>& nums, vector<int>& subset)
    {
        if (i == nums.size())
            return;

        subset.push_back(nums[i]);
        int new_xorr = xorr ^ nums[i];
        total += new_xorr;
        dfs(i + 1, new_xorr, nums, subset);
        subset.pop_back();
        dfs(i + 1, xorr, nums, subset);
    }
};