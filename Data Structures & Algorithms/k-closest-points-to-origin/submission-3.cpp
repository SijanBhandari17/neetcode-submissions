class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, vector<int>>> distance;
        for (auto p : points) {
            distance.push_back({calculateDistance(p), p});
        }
        int left = 0;
        int right = distance.size() - 1;

        while (left <= right) {
            int pivotIndex = partition(left, right, distance);

            if (pivotIndex == k - 1) {
                break;
            } else if (pivotIndex > k - 1) {
                right = pivotIndex - 1;
            } else {
                left = pivotIndex + 1;
            }
        }

        vector<vector<int>> output;

        for (int i = 0; i < k; i++) {
            output.push_back(distance[i].second);
        }

        return output;
    }

        int partition(int low, int high, vector<pair<int, vector<int>>>& distance) {
            int pivot = distance[high].first;
            int i = low;

            for (int j = low; j < high; j++) {
                if (distance[j].first <= pivot) {
                    swap(distance[i], distance[j]);
                    i++;
                }
            }

            swap(distance[i], distance[high]);

            return i;
    }
    int calculateDistance(vector<int> p) { return p[0] * p[0] + p[1] * p[1]; }
};
