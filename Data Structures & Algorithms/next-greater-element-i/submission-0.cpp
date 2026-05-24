class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         vector<int> res(nums1.size(), -1);
         unordered_map<int, int> nIdx;
         for (int i = 0; i < nums1.size(); i++)
            nIdx[nums1[i]] = i;

        stack<int> stk;
        for (int n : nums2)
        {
            while (!stk.empty() && n > stk.top())
            {
                int val = stk.top();
                stk.pop();
                res[nIdx[val]] = n;
            }
            if (nIdx.find(n) != nIdx.end())
                stk.push(n);
        }
        return res;
    }
};