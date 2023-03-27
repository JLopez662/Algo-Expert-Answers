#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<int>> taskAssignment(int k, vector<int> tasks) {
  // Write your code here.

  if(k == 0 || tasks.empty())return {{0,0}};
  

  unordered_map<int,vector<int>> tasksIndexes;

  for(int i = 0; i < tasks.size(); i++) tasksIndexes[tasks[i]].push_back(i);
  

  vector<int> ordered = tasks;

  sort(ordered.begin(), ordered.end());
  

  vector<vector<int>> taskList(k);

  int i = 0, right = ordered.size()-1;

  for(int i = 0; i < k; i++){

    taskList[i] = {tasksIndexes[ordered[i]].back(), tasksIndexes[ordered[right]].back()};

    tasksIndexes[ordered[i]].pop_back();
    tasksIndexes[ordered[right]].pop_back();

    right--;
  }

  return taskList;
}
