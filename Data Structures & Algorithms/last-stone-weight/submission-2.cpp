class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int, vector<int>> pq;
        for(const int &stone : stones)
            pq.push(stone);
        
        while(pq.size() > 1){
            int elem1 = pq.top();
            pq.pop();
            int elem2 = pq.top();
            pq.pop();
            if(elem1 != elem2) {
                pq.push(elem1 - elem2);
            }
        }
        if(pq.size() == 1) return pq.top();
        return 0;
    }
};
