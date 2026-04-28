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
private:
    static bool cmp (Interval & a, Interval & b) {

        return a.start < b.start; 
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size() == 0) {
            return true;
        }
        //下一個start time 有沒有比上個end time 早? 假設有就是overlap
   
        sort(intervals.begin(), intervals.end(), cmp);

        int end = intervals[0].end;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < end) {
                return false;
            }

            end = intervals[i].end;
        }

        return true;
    }
};
