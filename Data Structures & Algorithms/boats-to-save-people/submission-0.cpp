class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0;
        int right = people.size() - 1;
        int boats = 0;
        while (left <= right)
        {
            int cap = limit - people[right];
            right--;
            if (people[right] <= cap)
                right--;
            else if (people[left] <= cap)
                left++;

            boats++;
        }
        return boats;
    }
};