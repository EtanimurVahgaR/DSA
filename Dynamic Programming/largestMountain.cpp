#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()

int largestMountain(vector<int> arr) { 
    if ( arr.size() < 3 ) return 0 ;
        int n = arr.size() ;
        int ans = 0 ; 
        int up = 0 ; int down = 0 ; 
        for ( int i= 1 ; i < n ; i++ ) { 
            if ( (down > 0 && arr[i-1] < arr[i]) || arr[i-1] == arr[i]){ 
                up = down = 0 ; 
            }

            if ( arr[i-1] < arr[i] ) { 
                up ++ ; 
            }else if ( arr[i-1] > arr[i]) { 
                down ++ ; 
            }

            if ( up > 0 && down > 0) { 
                ans= max ( ans, up + down + 1) ; 
            }
        }
        return ans ; 
}

int main() {
    vector<pair<vector<int>, int>> tests = {
        {{2,1,4,7,3,2,5}, 5}, // mountain: 1,4,7,3,2
        {{2,2,2}, 0},         // no mountain
        {{0,2,0,2,1,2,3,4,4,1}, 3}, // mountain: 1,2,3,4,4,1 (but plateau, so max is 3,4,4,1 is not valid)
        {{1,2,3,4,5}, 0},     // strictly increasing
        {{5,4,3,2,1}, 0}      // strictly decreasing
    };
    for (size_t i = 0; i < tests.size(); ++i) {
        cout << "Test " << (i+1) << ": [";
        for (size_t j = 0; j < tests[i].first.size(); ++j) {
            cout << tests[i].first[j];
            if (j + 1 != tests[i].first.size()) cout << ", ";
        }
        cout << "]... ";
        assert(largestMountain(tests[i].first) == tests[i].second);
        cout << "Passed!" << endl;
    }
    return 0;
}