#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve(vector<int>& arr, int k) {
    vector<int> ans;
    for (int i = 0; i < arr.size() - k + 1; i++) {
        priority_queue<int> maxHeap;
        for (int j = i; j < i + k; j++) {
            maxHeap.push(arr[j]);
        }
        ans.push_back(maxHeap.top());
    }
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;
}

void optimalSolution(vector<int>& arr, int k) {
    priority_queue<pair<int, int>> maxHeap;
    vector<int> ans;

    for (int i = 0; i < k; i++) {
        maxHeap.push({arr[i], i});
    }
    ans.push_back(maxHeap.top().first);

    for (int i = k; i < arr.size(); i++) {
        maxHeap.push({arr[i], i});
        while (maxHeap.top().second <= i - k) {
            maxHeap.pop();
        }
        ans.push_back(maxHeap.top().first);
    }
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr;
    int num;
    while (cin >> num) {
        arr.push_back(num);
        if (cin.get() == '\n') break;
    }
    int k;
    cin >> k;
    solve(arr, k);
    optimalSolution(arr, k);
    return 0;
}


//optimised-o(n)-solutions-code by ritik

#include<bits/stdc++.h>

using namespace std;

vector < int > maxSlidingWindow(vector < int > & nums, int k) {
  deque < int > dq;
  vector < int > ans;
  for (int i = 0; i < nums.size(); i++) {
    if (!dq.empty() && dq.front() == i - k) dq.pop_front();

    while (!dq.empty() && nums[dq.back()] < nums[i])
      dq.pop_back();

    dq.push_back(i);
    if (i >= k - 1) ans.push_back(nums[dq.front()]);
  }
  return ans;
}
int main() {
  int i, j, n, k = 3, x;
  vector < int > arr {4,0,-1,3,5,3,6,8};
  vector < int > ans;
  ans = maxSlidingWindow(arr, k);
  cout << "Maximum element in every " << k << " window " << endl;
  for (i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  return 0;
}
