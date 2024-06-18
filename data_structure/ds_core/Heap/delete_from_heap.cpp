#include <bits/stdc++.h>
using namespace std;

void insert_heap(vector<int> &v, int x) {
  v.push_back(x);

  int current_idx = v.size() - 1;

  while (current_idx != 0) {
    int parent_idx = (current_idx - 1) / 2;

    if (v[parent_idx] < v[current_idx]) {
      swap(v[parent_idx], v[current_idx]);
    } else {
      break;
    }
    current_idx = parent_idx;
  }
}

void delete_heap(vector<int> &v) {
  v[0] = v[v.size() - 1];
  v.pop_back();

  int current = 0;
  while (true) {
    int left_idx = current * 2 + 1;
    int right_idx = current * 2 + 2;
    int last_idx = v.size() - 1;

    if (left_idx <= last_idx && right_idx <= last_idx) {
      if (v[left_idx] >= v[right_idx] && v[left_idx] > v[current]) {
        swap(v[left_idx], v[current]);
        current = left_idx;
      } else if (v[right_idx] >= v[left_idx] && v[right_idx] > v[current]) {
        swap(v[right_idx], v[current]);
        current = right_idx;
      } else {
        break;
      }
    } else if (left_idx <= last_idx) {
      if (v[left_idx] > v[current]) {
        swap(v[left_idx], v[current]);
        current = left_idx;
      } else {
        break;
      }
    } else if (right_idx <= last_idx) {
      if (v[right_idx] > v[current]) {
        swap(v[right_idx], v[current]);
        current = right_idx;
      } else {
        break;
      }
    } else {
      break;
    }
  }
}

int main() {
  vector<int> v;
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    insert_heap(v, x);
  }

  delete_heap(v);

  for (int val : v)
    cout << val << " ";

  return 0;
}