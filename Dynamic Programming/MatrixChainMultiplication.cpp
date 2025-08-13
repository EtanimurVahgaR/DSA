#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
int helper( vector<int>& arr , int i , int j ,vector<vector<int>>& memo ) { 
    if ( i + 1 == j )
        return 0 ; 
    int res = INT_MAX ; 
    if ( memo[i][j] != -1) return memo[i][j] ; 

    for ( int k = i + 1 ; k < j ; k ++ ) { 
        int curr = helper(arr, i, k , memo) + helper(arr, k, j , memo) + arr[i] * arr[j] * arr[k] ; 
        res = min ( curr , res ) ; 
    }
    return memo[i][j] = res ; 
}
int MatrixChainMultiplication(vector<int> &arr) { 
    int n = arr.size() ; 
    vector<vector<int>> memo ( n + 1 ,vector<int> (n + 1  , -1 )) ; 
    return helper(arr , 0 , n-1 , memo) ; 
}

int main() {

vector<int> arr1 = {1, 2, 3, 4};
    int expected1 = 18; // (1*2*3) + (1*3*4) = 6 + 12 = 18
    int result1 = MatrixChainMultiplication(arr1);
    cout << "Test 1: Expected = " << expected1 << ", Result = " << result1 << endl;
    assert(result1 == expected1);

    // Test 2: Another case
    vector<int> arr2 = {10, 20, 30};
    int expected2 = 6000; // Only one way: 10*20*30
    int result2 = MatrixChainMultiplication(arr2);
    cout << "Test 2: Expected = " << expected2 << ", Result = " << result2 << endl;
    assert(result2 == expected2);

    // Test 3: Larger case
    vector<int> arr3 = {40, 20, 30, 10, 30};
    int expected3 = 26000;
    int result3 = MatrixChainMultiplication(arr3);
    cout << "Test 3: Expected = " << expected3 << ", Result = " << result3 << endl;
    assert(result3 == expected3);

    // Test 4: Edge case, only two matrices (no multiplication needed)
    vector<int> arr4 = {5, 10};
    int expected4 = 0;
    int result4 = MatrixChainMultiplication(arr4);
    cout << "Test 4: Expected = " << expected4 << ", Result = " << result4 << endl;
    assert(result4 == expected4);

    cout << "All tests passed!" << endl;
    return 0;
}