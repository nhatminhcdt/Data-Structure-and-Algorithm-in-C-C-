/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_semiprimes/)
 * 
 * A prime is a positive integer X that has exactly two distinct divisors: 1 and X. The first few prime integers are 2, 3, 5, 7, 11 and 13.
 * A semiprime is a natural number that is the product of two (not necessarily distinct) prime numbers. The first few semiprimes are 4, 6, 9, 10, 14, 15, 21, 22, 25, 26.
 * You are given two non-empty arrays P and Q, each consisting of M integers. These arrays represent queries about the number of semiprimes within specified ranges.
 * Query K requires you to find the number of semiprimes within the range (P[K], Q[K]), where 1 ? P[K] ? Q[K] ? N.
 * 
 * @example Consider an integer N = 26 and arrays P, Q such that:
 *     P[0] = 1    Q[0] = 26
 *     P[1] = 4    Q[1] = 10
 *     P[2] = 16   Q[2] = 20
 * The number of semiprimes within each of these ranges is as follows:
 * (1, 26) is 10,
 * (4, 10) is 4,
 * (16, 20) is 0.
 * 
 * Write a function:
 *  vector<int> solution(int N, vector<int> &P, vector<int> &Q);
 * that, given an integer N and two non-empty arrays P and Q consisting of M integers, returns an array consisting of M elements specifying the consecutive answers to all the queries.
 * 
 * @example Given an integer N = 26 and arrays P, Q such that:
 *     P[0] = 1    Q[0] = 26
 *     P[1] = 4    Q[1] = 10
 *     P[2] = 16   Q[2] = 20
 * the function should return the values [10, 4, 0], as explained above.
 * 
 * Write an efficient algorithm for the following assumptions:
 *  - N is an integer within the range [1..50,000];
 *  - M is an integer within the range [1..30,000];
 *  - each element of arrays P and Q is an integer within the range [1..N];
 *  - P[i] ? Q[i].
 * 
*/

enum {
  kNot_prime = 0,
  kPrime = 1,
};


enum {
  kNot_semiprime = 0,
  kSemi_prime = 1,
};


vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
  vector<int> primes(N + 1, kPrime);

  primes[0] = primes[1] = kNot_prime;

  // Find the primes in the range [2, N]
  for (int i = 2; i * i <= N; i++) {
    if (primes[i] == kPrime) {
      int k = i * i;
      while (k <= N) {
        primes[k] = 0;
        k += i;
      }
    }
  }

  // Find the semiprimes in the range [2, N]
  vector<int> all_semiprimes(N + 1, kNot_semiprime);
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      if (primes[i] * primes[j] == 1 && i * j <= N) all_semiprimes[i * j] = kSemi_prime;
      if (i * j > N) break;
    }
  }

  int kInput_size = P.size();
  // Calculate the cumulative sum of semiprimes in the range [P, Q]
  vector<int> semiprimes(kInput_size, kNot_semiprime);
  vector<int> semiprimes_cum(N+1, 0);
  int sum = 0;

  for (int i = 0; i < N + 1; i++) {
    sum += all_semiprimes[i];
    semiprimes_cum[i] = sum;
  }

  for (int i = 0; i < kInput_size; i++) {
    semiprimes[i] = semiprimes_cum[Q[i]] - semiprimes_cum[P[i] - 1];
  }

  return semiprimes;
}
