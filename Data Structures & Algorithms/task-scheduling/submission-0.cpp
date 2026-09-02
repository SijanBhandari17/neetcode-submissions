class Solution {
   public:
   int leastInterval(vector<char> &tasks, int n) {

  unordered_map<char, int> task_count;
  for (const char &a : tasks) {
    task_count[a]++;
  }
  priority_queue<pair<int, char>> pq;
  for (const auto &[task, count] : task_count) {
    cout << "task: " << task << " count: " << count << endl;
    pq.push({count, task});
  }

  int cycles = 0;

  priority_queue<pair<int, pair<int, char>>, vector<pair<int, pair<int, char>>>,
                 greater<pair<int, pair<int, char>>>>
      cooldown_heap;

  while ((!pq.empty() || !cooldown_heap.empty())) {
    if (!pq.empty()) {
      auto task = pq.top();
      task.first--;
      if (task.first != 0) {
        cooldown_heap.push({cycles + n + 1, task});
      }
      pq.pop();
    }

    cycles++;

    while (!cooldown_heap.empty() && cooldown_heap.top().first <= cycles) {
      auto cooldown_task = cooldown_heap.top();
      pq.push(cooldown_task.second);
      cooldown_heap.pop();
    }
  }
  return cycles;
}

};
