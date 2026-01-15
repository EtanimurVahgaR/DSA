#include <bits/stdc++.h>
#include <iostream>

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

void multiplyMat(vector<vector<int>>& a , vector<vector<int>>& b ) { 
    vector<vector<int>> res(2,vector<int>(2) ) ;
    res[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    res[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    res[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    res[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];

    a[0][0] = res[0][0];
    a[1][0] = res[1][0];
    a[0][1] = res[0][1];
    a[1][1] = res[1][1];
}

vector<vector<int>> power(vector<vector<int>>& m , int expo) { 
    vector<vector<int>> res = {{1,0}, {0,1}} ;
    while ( expo ) { 
        if ( expo & 1 )
            multiplyMat(res , m) ; 
        multiplyMat(m , m ) ; 
        expo >>= 1 ;  
    }
    return res ; 
}
int countWaysMatrixExpo( int  n ) { 
    if ( n == 0 || n == 1) return 1 ; 

    vector<vector<int>> m = {{1,1} , {1,0}} ; 
    vector<vector<int>> initialMatrix = {{1,1} , {1,0}} ; 
    vector<vector<int>> res = power(m , n -1 ); 
    multiplyMat(res , initialMatrix);
    return res[0][0] ; 
}

int main() {
    vector<int> expected = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    for (int n = 0; n <= 10; ++n) {
        int result = countWaysMatrixExpo(n);
        cout << "countWays(" << n << ") = " << result << endl;
        assert(result == expected[n]);
    }
    cout << "All test cases passed!" << endl;

    return 0;
}