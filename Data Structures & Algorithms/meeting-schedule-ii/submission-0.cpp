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
        if (intervals.empty()) {
            return 0;
        }
        
        priority_queue<int, vector<int>, greater<int>> pq; // min-heap
        // priority_queue<int, std::vector<int>, std::greater<int>> pq

        sort(intervals.begin(), intervals.end(),
        [](const Interval &a, const Interval &b) {
            return a.start < b.start;
        });

        pq.push(intervals[0].end);
        //已經丟入 idx=0, 接下來要由1 開始
        for (int i = 1; i < intervals.size(); ++i) {
            if (!pq.empty() && intervals[i].start >= pq.top()) {
                //假設我會議開始時間比 目前最早會議結束時間晚
                //代表我可以重複使用這會議室，故先pop() 之後丟入新的end time
                pq.pop();
                pq.push(intervals[i].end);
            } else {
                //開始的比 目前所有會議室都還要早 
                //沒辦法只能push new end time
                pq.push(intervals[i].end);
            }

        } 

        return pq.size();
    }
};
