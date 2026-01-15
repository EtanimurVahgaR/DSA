#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob_memo = 1 + 3 = 4.

class HouseRobber {
private:
    int rob_r (vector<int>& nums , int i ,unordered_map<int,int>&memo ) { 
        int n = nums.size() ;  
        if ( i > n- 1 ) return 0  ; 
        if ( memo.find(i) != memo.end() )return memo[i] ;
        return memo[i] = max ( nums[i] + rob_r(nums , i + 2 , memo) ,rob_r(nums, i + 1 ,memo ) )  ; 
    }
public:
    int rob_memo(vector<int>& nums) { 
        int n = nums.size() ; 
        unordered_map <int , int > memo ; 
        return rob_r( nums, 0 , memo) ; 
    }

    int rob_tabulation ( vector<int> & nums ) { 
        int n = nums.size() ;
        vector<int> dp ( n , 0 ) ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            dp[i] = nums[i] ; 
        }
        for ( int i = 0 ; i < n ; i ++ ) { 
            // pick
            for ( int j = 0 ; j < )
        }
    }


};

int main() {
    vector<pair<vector<int>, int>> tests = {
        {{1,2,3,1}, 4},      // Rob 1 and 3
        {{2,7,9,3,1}, 12},   // Rob 2, 9, 1
        {{2,1,1,2}, 4},      // Rob 2 and 2
        {{0}, 0},            // Only one house, 0
        {{5,1,1,5}, 10}      // Rob 5 and 5
    };
    for (size_t i = 0; i < tests.size(); ++i) {
        cout << "Test " << (i+1) << ": [";
        for (size_t j = 0; j < tests[i].first.size(); ++j) {
            cout << tests[i].first[j];
            if (j + 1 != tests[i].first.size()) cout << ", ";
        }
        cout << "]... ";
        HouseRobber solver;
        vector<int> arr = tests[i].first;
        assert(solver.rob_memo(arr) == tests[i].second);
        cout << "Passed!" << endl;
    }
    return 0;
}