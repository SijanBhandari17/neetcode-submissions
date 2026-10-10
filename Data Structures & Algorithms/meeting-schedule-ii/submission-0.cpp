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

        vector<pair<int,int>> rooms;
        priority_queue< int ,vector<int>, greater<int> > pq;

        sort(intervals.begin(),intervals.end(),[](const Interval &a, const Interval &b){
            return a.start < b.start;
        });

        for(const Interval &interval: intervals){
            if(!pq.empty() && pq.top() <= interval.start){
                pq.pop();
            }
            pq.push(interval.end);

        }
        return pq.size();

        
    }
};
