#include <iostream>
#include <vector>
using namespace std;

// [Naive Approach]Brute Force Matrix Transposition
// O(n^2) Time and O(n^2) Space
vector<vector<int>> transpose(vector<vector<int>> &mat) {

  int n = mat.size();

  vector<vector<int>> tMat(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

      tMat[j][i] = mat[i][j];
    }
  }

  return tMat;
}

int main() {
  vector<vector<int>> mat = {
      {1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4}};

  vector<vector<int>> res = transpose(mat);

  for (auto &row : res) {
    for (auto &elem : row) {
      cout << elem << " ";
    }
    cout << "\n";
  }

  return 0;
}

// // [Expected Approach]Using constant space for Square Matrix
// // O(n^2) Time and O(1) Space
// #include <iostream>
// #include <vector>
// using namespace std;

// vector<vector<int>> transpose(vector<vector<int>> &mat) {
//   int n = mat.size();

//   for (int i = 0; i < n; i++) {
//     for (int j = i + 1; j < n; j++) {

//       swap(mat[i][j], mat[j][i]);
//     }
//   }

//   return mat;
// }

// int main() {

//   vector<vector<int>> mat = {
//       {1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4}};

//   vector<vector<int>> res = transpose(mat);

//   for (const auto &row : res) {
//     for (int elem : row) {
//       cout << elem << " ";
//     }
//     cout << endl;
//   }

//   return 0;
// }