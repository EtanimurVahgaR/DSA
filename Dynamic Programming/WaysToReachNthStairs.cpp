#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()

int countWaysHelper ( int n , vector<int>& memo ) { 
    if ( n == 0 ) return 1 ; 
    if ( n == -1 ) return 0 ; 
    if ( memo[n] != -1) return memo[n] ; 
    memo[n] = countWaysHelper(n-1 , memo) + countWaysHelper(n-2 , memo) ; 
    return (memo[n]) ; 
    
}
int countWays(int n) {
    // your code here
    vector<int> memo ( n+1 , -1 ) ;
    memo[0] = 0 ; 
    memo[1] = 1 ; 
    
    return  countWaysHelper( n , memo ) ;
    
}

int main() {
    vector<int> expected = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    for (int n = 0; n <= 10; ++n) {
        int result = countWays(n);
        cout << "countWays(" << n << ") = " << result << endl;
        assert(result == expected[n]);
    }
    cout << "All test cases passed!" << endl;

    return 0;
}