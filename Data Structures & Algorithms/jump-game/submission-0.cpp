class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int fur = 0;
        int cur = 0;
        while (cur < n && fur < n - 1)
        {
            if (fur < cur)
                return false;
            fur = max(fur, cur + nums[cur]);
            cur++;
        }
        return true;
    }
};
