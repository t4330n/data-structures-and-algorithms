#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// // [Naive Approach] Using Extra Space
// // O(n^2) Time and O(n^2) Space
// void rotateMatrix(vector<vector<int>> &mat) {
//   int n = mat.size();
//   vector<vector<int>> res(n, vector<int>(n));

//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n; j++) {
//       res[n - j - 1][i] = mat[i][j];
//     }
//   }

//   mat = res;
// }

// int main() {
//   vector<vector<int>> mat = {
//       {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

//   rotateMatrix(mat);

//   for (auto &row : mat) {
//     for (int x : row) {
//       cout << x << ' ';
//     }
//     cout << endl;
//   }

//   return 0;
// }

// // [Expected Approach 1] Forming Cycles
// // O(n2) Time and O(1) Space
// void rotateMatrix(vector<vector<int>> &mat) {
//   int n = mat.size();

//   for (int i = 0; i < n / 2; i++) {
//     for (int j = i; j < n - i - 1; j++) {

//       int temp = mat[i][j];
//       mat[i][j] = mat[j][n - 1 - i];
//       mat[j][n - 1 - i] = mat[n - 1 - i][n - 1 - j];
//       mat[n - 1 - i][n - 1 - j] = mat[n - 1 - j][i];
//       mat[n - 1 - j][i] = temp;
//     }
//   }
// }

// int main() {
//   vector<vector<int>> mat = {
//       {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
//   rotateMatrix(mat);
//   for (auto &row : mat) {
//     for (int x : row) {
//       cout << x << ' ';
//     }
//     cout << endl;
//   }

//   return 0;
// }

// [Expected Approach 2] Reversing Rows and Transposing
// O(n2) Time and O(1) Space
#include <iostream>

using namespace std;

void rotateMatrix(vector<vector<int>> &mat) {
  int n = mat.size();

  for (int i = 0; i < n; i++)
    reverse(mat[i].begin(), mat[i].end());

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++)
      swap(mat[i][j], mat[j][i]);
  }
}

int main() {
  vector<vector<int>> mat = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  rotateMatrix(mat);
  for (auto &row : mat) {
    for (int x : row) {
      cout << x << ' ';
    }
    cout << endl;
  }

  return 0;
}