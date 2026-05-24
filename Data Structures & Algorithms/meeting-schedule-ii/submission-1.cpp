/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> sweep;
        for (const auto& intv : intervals)
        {
            sweep[intv.start]++;
            sweep[intv.end]--;
        }
        int prev = 0;
        int res = 0;
        for (auto& elem : sweep)
        {
            prev += elem.second;
            res = max(prev, res);
        }
        return res;
    }
};
