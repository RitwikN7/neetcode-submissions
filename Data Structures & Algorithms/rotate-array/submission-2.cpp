class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        std::ranges::reverse(nums);
        std::ranges::reverse(nums.begin(), nums.begin() + k);
        std::ranges::reverse(nums.begin()+ k, nums.end());
    }
};