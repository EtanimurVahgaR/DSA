#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()

int helper( vector<int>& arr , int index ,vector<int>& memo ){
    if ( memo[index] != -1) return memo[index] ;   
    int n = arr.size() ; 
    if ( index >= n-1 ) return 0 ; // reached end destination no need to jump

    int res = INT_MAX ; 
    
    for ( int j = index + 1 ; j <= arr[index] + index ; j ++ ) { 
        int val = helper(arr,  j , memo ) ; 
        if( val != INT_MAX ) { 
            memo[index] = res = min (val+1 ,res ) ; 
        }
    }
    return res ; 

}

int MinimumNumberOfJumps(vector<int>& arr) { 
    // return jumps ? 
    vector<int> memo ( arr.size()  , - 1)  ;
    int ans = helper(arr, 0 , memo ) ;
    if (ans == INT_MAX) { 
        return -1 ; 
    }
    return ans ;
}

int MinimumNumberOfJumpsTabulation ( vector<int>& arr ) { 
    int n = arr.size() ; 
    if ( n <= 1 ) return 0 ; 
    if ( arr[0] == 0 ) return -1 ;  
    
    vector<int> table ( n , INT_MAX) ;
    table[0] = 0 ;  
    for ( int i = 0 ; i < n ; i ++ ) {
        if (table[i] == INT_MAX )return -1 ; 
        for (int j = i+1 ; j <= arr[i] +  i && j < n  ; j++) {
            table[j] = min ( table[j] , table[i] + 1 ) ; 
        }
    }

    return ( table[n-1] == INT_MAX )? ( -1 ): (table[n-1]) ; 
}



int main() {
    vector<int> arr1 = {2, 3, 1, 1, 4};
    // cout<<"hoping for "<< 2 <<endl;
    assert(MinimumNumberOfJumps(arr1) == 2);
    assert(MinimumNumberOfJumpsTabulation(arr1) == 2);

    vector<int> arr2 = {1, 1, 1, 1};
    // cout<<"hoping for "<< 3<<endl;
    assert(MinimumNumberOfJumps(arr2) == 3);
    assert(MinimumNumberOfJumpsTabulation(arr2) == 3);

    vector<int> arr3 = {0};
    // cout<<"hoping for "<< 0<<endl;
    assert(MinimumNumberOfJumps(arr3) == 0);
    assert(MinimumNumberOfJumpsTabulation(arr3) == 0);

    vector<int> arr4 = {0, 2, 3};
    // cout<<"hoping for "<< 1<<endl;
    assert(MinimumNumberOfJumps(arr4) == -1);
    assert(MinimumNumberOfJumpsTabulation(arr4) == -1);

    vector<int> arr5 = {1, 0, 0, 0};
    // cout<<"hoping for "<< 1<<endl;
    assert(MinimumNumberOfJumps(arr5) == -1);
    assert(MinimumNumberOfJumpsTabulation(arr5) == -1);

    cout<< "all test cases passed" ; 
    return 0;
}