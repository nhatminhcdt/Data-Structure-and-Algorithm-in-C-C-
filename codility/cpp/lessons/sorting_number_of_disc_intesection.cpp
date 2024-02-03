/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/6-sorting/number_of_disc_intersections/)
 * 
 * We draw N discs on a plane.
 *  The discs are numbered from 0 to N ? 1.
 *  An array A of N non-negative integers, specifying the radiuses of the discs, is given.
 *  The J-th disc is drawn with its center at (J, 0) and radius A[J].
 * 
 * We say that the J-th disc and K-th disc intersect if J �� K and the J-th and K-th discs have at least one common point (assuming that the discs contain their borders).
 * The figure below shows discs drawn for N = 6 and A as follows:
 *   A[0] = 1
 *   A[1] = 5
 *   A[2] = 2
 *   A[3] = 1
 *   A[4] = 4
 *   A[5] = 0
 * There are eleven (unordered) pairs of discs that intersect, namely:
 *  discs 1 and 4 intersect, and both intersect with all the other discs;
 *  disc 2 also intersects with discs 0 and 3.
 * 
 * Write a function:
 *  int solution(vector<int> &A);
 * that, given an array A describing N discs as explained above, returns the number of (unordered) pairs of intersecting discs.
 * The function should return ?1 if the number of intersecting pairs exceeds 10,000,000.
 * 
 * Given array A shown above, the function should return 11, as explained above.
 * @note assumptions:
 *  - N is an integer within the range [0..100,000];
 *  - each element of array A is an integer within the range [0..2,147,483,647].
 * 
*/

#include <algorithm>
int solution(vector<int> &A) {
  if (A.empty()) return 0;
  int N = A.size();
  vector<int> S(N, 0);
  vector<int> E(N, 0);
  vector<int> CS(N, 0);
  vector<int> CE(N, 0);

  for (int i = 0; i < N; ++i) {
    // Set the start and end points of the discs from 0 to N-1
    S[i] = (i <= A[i]) ? 0 : i - A[i];
    E[i] = (i + A[i] >= N) ? N - 1 : i + A[i];

    CS[S[i]]++;
    CE[E[i]]++;
  }
  // Calculate the cumulative sums of the start and end points
  vector<int> CCS(A.size(), 0);
  vector<int> CCE(A.size(), 0);
  CCS[0] = CS[0];
  CCE[0] = CE[0];
  for (int i = 1; i < N; ++i) {
    CCS[i] = CCS[i - 1] + CS[i];
    CCE[i] = CCE[i - 1] + CE[i];
  }

  int s = 0;
  for (int i = 0; i < N; ++i) {
    // (CCS[i] - CCE[i-1] + CS[i]) * CS[i]: Intersections of disks centered at pos i with other disks
    // CS[i] * (CS[i] - 1) / 2: Intersections of disks centered at pos i with each other mutual intersection
    s += (CCS[i] - CCE[i-1] - CS[i]) * CS[i] + CS[i] * (CS[i] - 1) / 2;
    if (s > 10000000) return -1;
  }

  return s;
}