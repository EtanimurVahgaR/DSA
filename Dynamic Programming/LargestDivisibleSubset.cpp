#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Return the largest subset such that for every pair (a, b) in the subset:
// a % b == 0 or
// b % a == 0
// If there are multiple solutions, return any of them.
// 
// Example 1
// Input
// nums = [1,2,3]
// Output
// [1,2] or [1,3]


// Explanation
// [1,3] is also valid, but [1,2] is one of the largest subsets.
#define pb push_back
#define all(x) (x).begin(), (x).end()
class LengthOfLargestDivisible { 
    public:
    // practice / revision 1 : 
    // int LLDS_tabulation(vector<int>& nums) { 
    //     sort ( nums.begin() , nums.end() ) ; 
    //     int n = nums.size() ;
    //     if ( n == 0 ) return 0 ; 
    //     vector<int> dp ( n , 1) ; 
    //     int ans = 1 ; 
    //     for ( int i = 1 ; i < n ; i++ ) { 
    //         for ( int j = 0 ; j < i ; j ++) { 
    //             if ( nums[i] % nums[j] == 0 ) { 
    //                 dp[i] = max ( dp[i] , dp[j] + 1 )  ;
    //             }
    //         }
    //         ans = max ( ans , dp[i] ) ; 
    //     }
    //     return ans ;
    // }
    int LLDS_tabulation( vector<int>&nums ) { 

        int n = nums.size() ;  
        sort (nums.begin() ,nums.end() ) ; 
        vector<int> dp ( n , 1 ) ; 
        int maxi =  1 ; 
        for ( int i = 0 ; i < n  ; i ++ ) { 
            for ( int j = 0 ; j < i ; j++ ) { 
                if ( nums[i] % nums[j] == 0 ) { 
                    dp[i] = max ( dp [i] , dp [j] + 1 ) ; 
                }
            }
            maxi = max ( maxi , dp[i]) ; 
        }
        return maxi ; 
    }
};


int main() {
    LengthOfLargestDivisible solver;
    vector<vector<int>> test_cases = {
        {1, 2, 3},
        {1, 2, 4, 8},
        {3, 5, 10, 20, 21},
        {1},
        {2, 3, 4, 9, 8}
    };
    vector<int> expected = {2, 4, 3, 1, 3};
    for (int i = 0; i < 5; ++i) {
        cout << "Test " << (i+1) << ": [";
        for (size_t j = 0; j < test_cases[i].size(); ++j) {
            cout << test_cases[i][j];
            if (j + 1 != test_cases[i].size()) cout << ", ";
        }
        cout << "]... ";
        vector<int> arr = test_cases[i];
        assert(solver.LLDS_tabulation(arr) == expected[i]);
        cout << "Passed!" << endl;
    }
    return 0;
}