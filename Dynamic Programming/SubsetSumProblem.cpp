#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()

bool helperWithoutMemo(vector<int> &arr , int target , int i ) { 
    int n = arr.size() ; 
    // if ( n == 1 && arr[0] == target)  { 

    //     return true ; 
    // }
    if ( i > n ) return false ;
    if ( target == 0 ) return true ;     
    bool pick = false ; 
    if (i < n-1 ) pick = helperWithoutMemo ( arr , target - arr[i] , i + 1 ,)   ; 
    int notPick = helperWithoutMemo( arr , target , i + 1 ) ; 
    if ( pick || notPick ) return true; 
    return false ;
}
bool helper(vector<int> &arr , int target , int i , vector<vector<int>>& memo) { 
    int n = arr.size() ; 
    // if ( n == 1 && arr[0] == target)  { 

    //     return true ; 
    // }
    if ( i > n ) return false ;
    if ( target == 0 ) return true ; 

    if ( memo[i][target] != -1 ) return memo[i][target] ; 
    bool pick = false ; 
    if (i < n-1 ) pick = helper ( arr , target - arr[i] , i + 1 ,memo )   ; 
    int notPick = helper( arr , target , i + 1 ,memo) ; 
    if ( pick || notPick ) return  memo[i][target]  =  true; 
    return  memo[i][target] = false ;
}
bool SubsetSumProblem(vector<int> &arr , int target) { 
    int n = arr.size() ; 
    vector<vector<int>> memo ( n + 1 , vector<int> ( target + 1 , -1)) ; 
    return helper( arr , target , 0 , memo ) ;
}
bool SubsetSumProblemTab(vector<int>& arr , int target) { 
    int n = arr.size() ; 
    vector<vector<bool>> table ( n + 1 ,  vector<bool> ( target + 1 , false)) ;
    for (int i = 0; i <= n ; i++){
        table[i][0] = true ; 
    }

    for (int i = 1 ; i <= n ; i++){
        for ( int j  = 1 ; j  <= target ; j++ ) { 
            if ( j < arr[i] ) { 
                table[i][j] = table[i-1][j] ; 
            }else{ 
                table[i][j] = table[i][j-arr[i]] || table[i-1][j-arr[i]] ; // not picking and picking in that order  
            }
        }
    }
    return table[n][target] ; 
    
}
bool SubsetSumProblemBest(vector<int>& arr , int target) { 
    int n = arr.size() ; 
    vector<vector<bool>> table ( 2 ,  vector<bool> ( target + 1 , false)) ;
    for (int i = 0; i <= 1 ; i++){
        table[i][0] = true ; 
    }

    for (int i = 1 ; i <= n ; i++){
        for ( int j  = 1 ; j  <= target ; j++ ) { 
            if ( j < arr[i] ) { 
                table[i%2][j] = table[(i-1)%2][j] ; 
            }else{ 
                table[i%2][j] = table[(i-1)%2][j] || table[(i-1)%2][j-arr[i]] ; // not picking and picking in that order  
            }
        }
    }
    return table[n%2][target] ; 
    
}

int main() {

    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 9;
    assert(SubsetSumProblem(arr, target) && "Test failed: Subset with sum 9 should exist.");
    assert(SubsetSumProblemTab(arr, target) && "Test failed: Subset with sum 9 should exist. ( TABULATION )");
    assert(SubsetSumProblemBest(arr, target) && "Test failed: Subset with sum 9 should exist. ( TABULATION )");
    cout<< "test case passed" ; 
    return 0;
}