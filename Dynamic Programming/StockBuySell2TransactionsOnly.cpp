#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()

// Imported functions from StockBuyAndSell.cpp
int helperMemo(vector<int>& arr, int k, int i, bool hasStock, vector<vector<vector<int>>> &memo) {
    int n = arr.size();
    if (k == 0 || i == n) return 0;

    if (memo[i][k][hasStock] != -1) return memo[i][k][hasStock];

    int profit = 0;
    int doesntIgnore ;
    if (hasStock) {
        // Sell or skip
        doesntIgnore = arr[i] + helperMemo(arr, k - 1, i + 1, 0, memo);
    } else {
        doesntIgnore = -arr[i] + helperMemo(arr, k, i + 1, 1, memo);
    }
    int ignore = helperMemo(arr, k, i + 1, hasStock , memo);
    profit = max (doesntIgnore , ignore );
    return memo[i][k][hasStock] = profit;
}

int StockBuyAndSellMemo(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<vector<int>>> memo(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
    return helperMemo(arr, k, 0, 0, memo);
}

int maxProfOne ( vector<int>& prices, int idx ) { 
    int minSoFar = prices[idx] , res = 0 ; 
    for ( int i= idx  +  1 ; i < prices.size() ; i ++ )  {
        minSoFar = min( minSoFar , prices[i] ) ;
        res = max(res , prices[i] - minSoFar ) ;
    }
    return res ;
}

int StockBuySell2TransactionsOnly(vector<int>&  prices) { 
    int n = prices.size() ; 
    int minSoFar = prices[0] ; int res = 0 ; 
    for ( int i = 1 ; i < n ; i++ ) { 
        if ( prices[i] > minSoFar ) { 
            int curr = prices[i] - minSoFar + maxProfOne( prices , i ) ; 
            res = max ( curr , res ) ; 
        }else { 
            minSoFar = prices[i] ; 
        }
    }
    return res ; 
}
int StockBuySell2TransactionsOnlyPostFix ( vector<int>& prices ) { 
    int n = prices.size() ; 
    int minSoFar = prices[0] ; 
    vector<int> profit ( n , 0 ) ; 
    int maxPrice = prices[n-1 ] ;
    for (int i = n-2 ; i>= 0 ; i--) { 
        maxPrice = max(maxPrice , prices[i]) ; 
        profit[i] = max(profit[i + 1] , maxPrice - prices[i]) ; 
    }
    int minPrice = prices[0] ; int res = 0  ; 
    for ( int i = 1 ; i < n ; i ++ ) { 
        minPrice = min ( minPrice , prices[i]) ; 
        res = max ( res , profit[i] + prices[i] - minPrice) ; 
    }
    return res ; 
}
int main() {
    // Test case 1: Normal case with clear profit opportunities
    vector<int> prices1 = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << "Test 1 - prices: [3,3,5,0,0,3,1,4]" << endl;
    cout << "Max profit (2 transactions): " << StockBuySell2TransactionsOnly(prices1) << endl;
    cout << "Max profit (postfix): " << StockBuySell2TransactionsOnlyPostFix(prices1) << endl;
    cout << "Max profit (memo k=2): " << StockBuyAndSellMemo(prices1, 2) << endl;
    cout << "Expected: 6" << endl << endl;

    // Test case 2: Simple increasing array
    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Test 2 - prices: [1,2,3,4,5]" << endl;
    cout << "Max profit: " << StockBuySell2TransactionsOnly(prices2) << endl;
    cout << "Max profit: " << StockBuySell2TransactionsOnlyPostFix(prices2) << endl;
    cout << "Max profit (memo k=2): " << StockBuyAndSellMemo(prices2, 2) << endl;
    cout << "Expected: 4" << endl << endl;

    // Test case 3: Decreasing array (no profit possible)
    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "Test 3 - prices: [7,6,4,3,1]" << endl;
    cout << "Max profit: " << StockBuySell2TransactionsOnly(prices3) << endl;
    cout << "Max profit: " << StockBuySell2TransactionsOnlyPostFix(prices3) << endl;
    cout << "Max profit (memo k=2): " << StockBuyAndSellMemo(prices3, 2) << endl;
    cout << "Expected: 0 (no profit possible)" << endl << endl;

    // Test case 4: Single element
    vector<int> prices4 = {5};
    cout << "Test 4 - prices: [5]" << endl;
    cout << "Max profit: " << StockBuySell2TransactionsOnly(prices4) << endl;
    cout << "Max profit: " << StockBuySell2TransactionsOnlyPostFix(prices4) << endl;
    cout << "Max profit (memo k=2): " << StockBuyAndSellMemo(prices4, 2) << endl;
    cout << "Expected: 0 (cannot make transaction)" << endl << endl;

    // Test case 5: Two elements
    vector<int> prices5 = {1, 5};
    cout << "Test 5 - prices: [1,5]" << endl;
    cout << "Max profit: " << StockBuySell2TransactionsOnly(prices5) << endl;
    cout << "Max profit: " << StockBuySell2TransactionsOnlyPostFix(prices5) << endl;
    cout << "Max profit (memo k=2): " << StockBuyAndSellMemo(prices5, 2) << endl;
    cout << "Expected: 4 (buy at 1, sell at 5)" << endl << endl;

    return 0;
}