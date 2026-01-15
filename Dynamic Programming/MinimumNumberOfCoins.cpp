#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()

int helper( vector<int>& coins , int sum , int index , vector<vector<int>>& memo ) { 
    // [25, 10, 5], sum = 30 ( expects 2 )
    if ( sum == 0 ) return 0  ;
    if ( index == coins.size() ) return 1e9 ; 
    if ( memo[index][sum] != -1 ) return memo[index][sum] ; 
    int pick = 1e9 ; 
    if ( sum - coins[index] >= 0 )  {  
        pick = 1 + helper(coins , sum - coins[index] , index  , memo ) ; 
    }
    int notPick = helper(coins , sum , index + 1 ,memo ) ; 
    return memo[index][sum] =  min ( pick , notPick ) ;
}   

int MinimumNumberOfCoins(vector<int> coins , int sum) { 
    vector<vector<int>> memo ( coins.size() + 1 , vector<int> (sum + 1 , -1)) ; 
    int res = helper( coins , sum , 0  ,memo)  ; 
    return ( res >= 1e9 )?(-1):(res); 
    
}
int MinimumNumberOfCoinsTable(vector<int> coins , int sum) { 
    int n=coins.size(); 
    if ( n == 0 ) return -1 ; 
    vector<vector<int>> table ( n +1 , vector<int> (sum +1 ,INT_MAX )) ; 

    for (int i = 0; i <= n; i++) {
        table[i][0] = 0;
    }

    for (int j = 1; j <= sum; j++) {
        if (j % coins[0] == 0)
            table[1][j] = j / coins[0];
    }

    for ( int i = 2 ; i <= n ; i++ ) { 
        for ( int j = 1 ; j <= sum ; j ++) { 
            int pick  = INT_MAX ;
            if ( j - coins[i-1] >= 0 ) { 
                pick = table[i][j-coins[i-1]] ; 
                if ( pick != INT_MAX ) pick ++ ; 
            }
            int notPick = table[i-1][j] ; 
            table[i][j] = min ( pick , notPick ) ;
        }
    }
    // return table[n][sum] ;
    return table[n][sum] == INT_MAX ? -1 : table[n][sum];
 
}

int main() {
    {
        std::vector<int> coins = {25, 10, 5};
        int sum = 30;
        int result = MinimumNumberOfCoins(coins, sum);
        int result2 = MinimumNumberOfCoinsTable(coins, sum);
        assert(result == 2); // 25 + 5
        assert(result2 == 2); // 25 + 5
    }

    // Test 2: No solution possible
    {
        std::vector<int> coins = {7, 3};
        int sum = 5;
        int result = MinimumNumberOfCoins(coins, sum);
        int result2 = MinimumNumberOfCoinsTable(coins, sum);
        assert(result == -1); // Not possible
        assert(result2 == -1); // Not possible
    }

    // Test 3: Single coin equals sum
    {
        std::vector<int> coins = {1, 2, 5};
        int sum = 5;
        int result = MinimumNumberOfCoins(coins, sum);
        int result2 = MinimumNumberOfCoinsTable(coins, sum);
        assert(result == 1); // 5
        assert(result2 == 1); // 5
    }

    // Test 4: Multiple coins, greedy fails, DP works
    {
        std::vector<int> coins = {1, 3, 4};
        int sum = 6;
        int result = MinimumNumberOfCoins(coins, sum);
        int result2 = MinimumNumberOfCoinsTable(coins, sum);
        assert(result == 2); // 3+3 or 4+2*1
        assert(result2 == 2); // 3+3 or 4+2*1
    }

    // Test 5: Large sum, small coins
    {
        std::vector<int> coins = {1, 2, 5};
        int sum = 11;
        int result = MinimumNumberOfCoins(coins, sum);
        int result2 = MinimumNumberOfCoinsTable(coins, sum);
        assert(result == 3); // 5+5+1
        assert(result2 == 3); // 5+5+1
    }

    // Test 6: Zero sum
    {
        std::vector<int> coins = {2, 3, 7};
        int sum = 0;
        int result = MinimumNumberOfCoins(coins, sum);
        int result2 = MinimumNumberOfCoinsTable(coins, sum);
        assert(result == 0); // No coins needed
        assert(result2 == 0); // No coins needed
    }

    // Test 7: Only one coin type, exact division
    {
        std::vector<int> coins = {4};
        int sum = 12;
        int result = MinimumNumberOfCoins(coins, sum);
        int result2 = MinimumNumberOfCoinsTable(coins, sum);
        assert(result == 3); // 4+4+4
        assert(result2 == 3); // 4+4+4
    }

    // Test 8: Only one coin type, not possible
    {
        std::vector<int> coins = {4};
        int sum = 10;
        int result = MinimumNumberOfCoins(coins, sum);
        int result2 = MinimumNumberOfCoinsTable(coins, sum);
        assert(result == -1); // Not possible
        assert(result2 == -1); // Not possible
    }

    // Test 9: Empty coins vector
    {
        std::vector<int> coins = {};
        int sum = 10;
        int result = MinimumNumberOfCoins(coins, sum);
        int result2 = MinimumNumberOfCoinsTable(coins, sum);
        assert(result == -1); // Not possible
        assert(result2 == -1); // Not possible
    }

    // Test 10: Large coin, small sum
    {
        std::vector<int> coins = {100} ;
        int sum = 1;
        int result = MinimumNumberOfCoins(coins, sum);
        int result2 = MinimumNumberOfCoinsTable(coins, sum);
        assert(result == -1); // Not possible
        assert(result2 == -1); // Not possible
    }
    cout<<"All test cases passed " ;
    return 0;
}