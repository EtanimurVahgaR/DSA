#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()

// Length of longest increasing subsequence : 
// Given an integer array nums, return the length of the longest strictly increasing subsequence.

 

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4

class Lenght_of_longest_increasing_subsequence { 
    private : 
    int _LLIS_recrsive(vector<int> & nums , int ind , int prev_ind , int n ) { 
        if ( ind == n ) return 0 ; 
        // not choosing
        int len = 0 + _LLIS_recrsive(nums , ind + 1 , prev_ind , n ) ; 

        if ( prev_ind == -1 || nums[ind] > nums[prev_ind] ) { 
            len = max ( len , 1 + _LLIS_recrsive ( nums , ind + 1 , ind , n) ) ; 
        }
        return len ; 
    } 
    int _LLIS_memoized(vector<int> & nums , int ind , int prev_ind , int n , vector<int> &dp  ) { 
        if ( ind == n ) return 0 ; 
        if (dp[ind] != -1 ) return dp[ind] ; 
        int len = 0 + _LLIS_recrsive(nums , ind + 1 , prev_ind , n ) ; 

        if ( prev_ind == -1 || nums[ind] > nums[prev_ind] ) { 
            len = max ( len , 1 + _LLIS_recrsive ( nums , ind + 1 , ind , n) ) ; 
        }
        return dp[ind] = len ; 
    } 
    public : 
    int LLIS_recursive(vector<int> nums) {
        int n = nums.size() ; 
        return _LLIS_recrsive( nums , 0 , -1 , n ) ; 
    } 
    int LLIS_memoized( vector<int> nums) { 
        int n = nums.size() ;  
        vector<int> dp ( n+1 , -1 ) ; 
        return _LLIS_memoized(nums, 0 , -1 , n , dp ) ; 
    }
    int LLIS_tabulation( vector<int> nums ) { 
        int n = nums.size() ;
        if ( n == 0 ) return 0 ; 
        vector<int> dp ( n , 1) ; 
        int ans = 1 ; 
        for ( int i = 1 ; i < n ; i++ ) { 
            for ( int j = 0 ; j < i ; j ++) { 
                if ( nums[i] > nums[j] ) { 
                    dp[i] = max ( dp[i] , dp[j] + 1 )  ;
                }
            }
            ans = max ( ans , dp[i] ) ; 
        }
        return ans ;
    }
    int LLIS_space_optimized(vector<int> nums) {
        // BINARY SEARCH SOLUTION

        // vector<int> tails;
        // for (int x : nums) {
        //     auto it = lower_bound(tails.begin(), tails.end(), x);
        //     if (it == tails.end())
        //         tails.push_back(x);
        //     else
        //         *it = x;
        // }
        // return tails.size(); 
        vector<int> ans;  
        int n = nums.size() ; 
        for ( int i  =0 ; i < n ; i++ ) { 
            int j = lower_bound ( ans.begin() , ans.end() , nums[i]) - ans.begin() ; 
            if ( j == ans.size() ) { 
                ans.push_back(nums[i]) ;
            }else { 
                ans[j] = nums[i] ; 
            }
        }
        return ans.size() ;     
    }

};
    

int main() {
    Lenght_of_longest_increasing_subsequence solver;
    vector<vector<int>> test_cases = {
        {10, 9, 2, 5, 3, 7, 101, 18},
        {0, 1, 0, 3, 2, 3},
        {7, 7, 7, 7, 7},
        {},
        {1, 2, 3, 4, 5}
    };
    vector<int> expected = {4, 4, 1, 0, 5};
    vector<string> method_names = {"recursion", "memoization", "tabulation", "space optimized"};
    vector<function<int(vector<int>)>> methods = {
        [&](vector<int> arr) { return solver.LLIS_recursive(arr); },
        [&](vector<int> arr) { return solver.LLIS_memoized(arr); },
        [&](vector<int> arr) { return solver.LLIS_tabulation(arr); },
        [&](vector<int> arr) { return solver.LLIS_space_optimized(arr); }
    };
    for (size_t m = 0; m < methods.size(); ++m) {
        cout << method_names[m] << " :\n";
        for (size_t i = 0; i < test_cases.size(); ++i) {
            cout << "Test " << (i+1) << ": [";
            for (size_t j = 0; j < test_cases[i].size(); ++j) {
                cout << test_cases[i][j];
                if (j + 1 != test_cases[i].size()) cout << ", ";
            }
            cout << "]... ";
            vector<int> arr = test_cases[i];
            assert(methods[m](arr) == expected[i]);
            cout << "Passed!" << endl;
        }
    }
    cout << "All LLIS_recursive tests passed." << endl;
    return 0;
}