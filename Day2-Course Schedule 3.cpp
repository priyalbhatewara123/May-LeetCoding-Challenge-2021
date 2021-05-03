/*
Problem link : https://leetcode.com/problems/course-schedule-iii/
*/

class Solution {
public:
    static bool cmp(vector<int> v1 , vector<int> v2) {
        return v1[1] < v2[1];
    }

    int scheduleCourse(vector<vector<int>>& courses) {

        //sort the vector(courses) in non-decreasing order of last day
        sort(courses.begin(), courses.end(), cmp);

        //we will use priority queue (max heap) to store duration of courses taken in decreasing order
        priority_queue<int> pq;
        int current_time = 0;

        for (auto c : courses) {

            //if taking the current course dosen't exceed the deadline.
            if (current_time + c[0] <= c[1]) {
                pq.push(c[0]);
                current_time += c[0];
            }

            //if taking current course exceeds deadline
            else {
                //if pq is not empty then we can remove highest duration course and add the current course
                if (!pq.empty() and pq.top() > c[0]) {
                    int top = pq.top();
                    pq.pop();
                    current_time -= top;
                    pq.push(c[0]);
                    current_time += c[0] ;
                }
            }
        }

        return pq.size();
    }
};