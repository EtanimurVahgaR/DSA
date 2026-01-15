#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()

int helper (  vector<int>& coins , int sum , int index , vector<vector<int>>& memo)  
{ 
    int n = coins.size() ; 
    if ( sum == 0 ) return 1 ; 
    if ( index == n ) return 0 ; 
    if ( memo[index][sum] != -1 ) return memo[index][sum] ; 
    int res = 0 ; 

    if ( sum - coins[index] >= 0 ) { 
        res += helper(coins , sum-coins[index] , index , memo ) ;
    }
    
    return memo[index][sum] = ( res  + helper(coins ,sum , index + 1 ,memo ) ) ;

}

int CoinChangeCountWays(vector<int> coins , int sum) { 
    vector<vector<int>> memo ( coins.size()+1 , vector<int> ( sum+1 , -1 )  ) ; 
    return helper(coins , sum , 0 , memo ) ; 
}
int CoinChangeCountWaysTable(vector<int> coins , int sum) { 
    int n = coins.size() ; 
    vector<vector<int>> table ( n+1 , vector<int> ( sum+1 , 0 )  ) ; 
    table[0][0] = 1 ;   
    // int res = 0 ;
    for ( int i = 1 ; i <= n ; i++ ) { 
        for ( int j = 0 ;  j <= sum ; j ++ ) { 
            if ( j - coins[i-1] >= 0 ) { 
                table[i][j] += table[i][j-coins[i-1]];
            }
            table[i][j] += table[i-1][j] ; 
        }
    }
    return table[n][sum] ; 
}
int CoinChangeCountWaysTableSpaceOptimized(vector<int> coins , int sum) { 
    int n = coins.size() ; 
    vector<int> table ( sum + 1) ; 
    table[0] = 1 ;   
    // int res = 0 ;
    for ( int i = 0 ; i < n ; i++ ) { 
        for ( int j = coins[i] ;  j <= sum ; j ++ ) { 
                table[j] += table[j-coins[i]];
        }
    }
    return table[sum] ; 
}


int main() {
    vector<int> coins1 = {1, 2, 3};
    int sum1 = 4;
    assert(CoinChangeCountWays(coins1, sum1) == 4);
    assert(CoinChangeCountWaysTable(coins1, sum1) == 4);
    assert(CoinChangeCountWaysTableSpaceOptimized(coins1, sum1) == 4);
    cout << "Passed test case 1" << endl;

    vector<int> coins2 = {2, 5, 3, 6};
    int sum2 = 10;
    assert(CoinChangeCountWays(coins2, sum2) == 5);
    assert(CoinChangeCountWaysTable(coins2, sum2) == 5);
    assert(CoinChangeCountWaysTableSpaceOptimized(coins2, sum2) == 5);
    cout << "Passed test case 2" << endl;

    vector<int> coins3 = {1};
    int sum3 = 0;
    assert(CoinChangeCountWays(coins3, sum3) == 1);
    assert(CoinChangeCountWaysTable(coins3, sum3) == 1);
    assert(CoinChangeCountWaysTableSpaceOptimized(coins3, sum3) == 1);
    cout << "Passed test case 3" << endl;

    vector<int> coins4 = {2, 5};
    int sum4 = 3;
    assert(CoinChangeCountWays(coins4, sum4) == 0);
    assert(CoinChangeCountWaysTable(coins4, sum4) == 0);
    assert(CoinChangeCountWaysTableSpaceOptimized(coins4, sum4) == 0);
    cout << "Passed test case 4" << endl;

    return 0;
}