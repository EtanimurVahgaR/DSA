#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()

    bool helper( vector<int>& arr , int i , int sum , int target , vector<vector<int>>& memo)  { 
        int n = arr.size()  ; 
        if ( i >= n || sum > target ) return false ;
        if ( memo[i][sum] != -1 ) return memo[i][sum] ; 
        if ( sum == target ) return true ;
        bool pick = helper ( arr ,  i + 1 , sum + arr[i] , target ,memo ) ; 
        bool notPick = helper( arr , i + 1 , sum , target , memo ) ; 
        return memo[i][sum] = ( pick || notPick ) ; 
    }   
    bool PartionIntoSameSumSubset(vector<int>& arr) {
        // code here
        int sum = 0 ; 
        int n = arr.size() ; 
        if ( n == 1 ) return false ; 
        else if ( n == 0 ) return true ; 
        for ( int i = 0 ; i < n ; i ++ ) 
            sum += arr[i] ; 
        if ( sum % 2 == 1) return false ; 
        int target = sum / 2 ;
        vector<vector<int>> memo ( n + 1 , vector<int> ( target + 1 ,  -1)) ; 
        return helper ( arr , 0 , 0 ,target , memo ); 
        
    }

    bool PartionIntoSameSumSubsetTab( vector<int>& arr){ 
        int n = arr.size() ; 
        if ( n == 0 ) return true ; 
        else if ( n == 1 ) return false ; 
        int sum = 0 ;
        for ( int i = 0 ; i < n ; i ++ ) { sum += arr[i] ;}
        int target = sum / 2 ;
        if ( sum % 2 == 1 )return false; 

        vector<vector<bool>> table ( n + 1, vector<bool> ( target + 1 , false)) ; 
        for (int i = 0; i <= n ; i++)
        {
            table[i][0] = true ; 
        }
        
        for ( int i = 1 ; i <= n ; i ++ ) { 
            for ( int j = 1 ; j <= target ; j ++ ) { 
                if ( j >=  arr[i-1]) { 
                    // pick 
                    table[i][j] = table[i-1][j - arr[i-1]] || table[i-1][j] ; 
                }else{ 
                    // not pick
                    table[i][j] = table[i-1][j] ; 
                }
            }
        } 
        return table[n][target];
    }
     bool PartionIntoSameSumSubsetSpaceOptimized( vector<int>& arr){ 
        int n = arr.size() ; 
        if ( n == 0 ) return true ; 
        else if ( n == 1 ) return false ; 
        int sum = 0 ;
        for ( int i = 0 ; i < n ; i ++ ) { sum += arr[i] ;}
        int target = sum / 2 ;
        if ( sum % 2 == 1 )return false; 

        vector<vector<bool>> table ( 2 , vector<bool> ( target + 1 , false)) ; 
        for (int i = 0; i <= n ; i++)
        {
            table[i%2][0] = true ; 
        }
        
        for ( int i = 1 ; i <= n ; i ++ ) { 
            for ( int j = 1 ; j <= target ; j ++ ) { 
                if ( j >=  arr[i-1]) { 
                    // pick 
                    table[i%2][j] = table[(i-1)%2][j - arr[i-1]] || table[(i-1)%2][j] ; 
                }else{ 
                    // not pick
                    table[i%2][j] = table[(i-1)%2][j] ; 
                }
            }
        } 
        return table[n%2][target];
    }
int main() {

    vector<int> arr1 = {1, 5, 11, 5};
    cout<< "starting test case " << 1 <<endl ; 
    assert(PartionIntoSameSumSubset(arr1) == true);
    assert(PartionIntoSameSumSubsetTab(arr1) == true);
    assert(PartionIntoSameSumSubsetSpaceOptimized(arr1) == true);
    cout<< "ending test case " << 1 <<endl ; 

    // Test case 2: Cannot be partitioned into two subsets with equal sum
    vector<int> arr2 = {1, 2, 3, 5};
    cout<< "starting test case " << 2 <<endl ; 
    assert(PartionIntoSameSumSubset(arr2) == false);
    assert(PartionIntoSameSumSubsetTab(arr2) == false);
    assert(PartionIntoSameSumSubsetSpaceOptimized(arr2) == false);
    cout<< "ending test case " << 2 <<endl ; 

    // Test case 3: Empty array
    vector<int> arr3 = {};
    cout<< "starting test case " << 3 <<endl ; 
    assert(PartionIntoSameSumSubset(arr3) == true);
    assert(PartionIntoSameSumSubsetTab(arr3) == true);
    assert(PartionIntoSameSumSubsetSpaceOptimized(arr3) == true);
    cout<< "ending test case " << 3 <<endl ; 

    // Test case 4: Single element
    vector<int> arr4 = {2};
    cout<< "starting test case " << 4 <<endl ; 
    assert(PartionIntoSameSumSubset(arr4) == false);
    assert(PartionIntoSameSumSubsetTab(arr4) == false);
    assert(PartionIntoSameSumSubsetSpaceOptimized(arr4) == false);
    cout<< "ending test case " << 4 <<endl ; 

    // Test case 5: All elements are the same
    vector<int> arr5 = {2, 2, 2, 2};
    cout<< "starting test case " << 5 <<endl ; 
    assert(PartionIntoSameSumSubset(arr5) == true);
    assert(PartionIntoSameSumSubsetTab(arr5) == true);
    assert(PartionIntoSameSumSubsetSpaceOptimized(arr5) == true);
    cout<< "ending test case " << 5 <<endl ; 

    // Test case 6: Large numbers
    vector<int> arr6 = {100, 100, 100, 100, 100, 100};
    cout<< "starting test case " << 6 <<endl ; 
    assert(PartionIntoSameSumSubset(arr6) == true);
    assert(PartionIntoSameSumSubsetTab(arr6) == true);
    assert(PartionIntoSameSumSubsetSpaceOptimized(arr6) == true);
    cout<< "ending test case " << 6 <<endl ; 

    // Test case 7: Odd total sum
    vector<int> arr7 = {1, 2, 3};
    cout<< "starting test case " << 7 <<endl ; 
    assert(PartionIntoSameSumSubset(arr7) == true);
    assert(PartionIntoSameSumSubsetTab(arr7) == true);
    assert(PartionIntoSameSumSubsetSpaceOptimized(arr7) == true);
    cout<< "ending test case " << 7 <<endl ; 

    cout<< "test cases passed" ;
    return 0;
}