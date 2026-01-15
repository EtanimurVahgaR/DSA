#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()

bool toggle(bool &value) {
    value = !value;
    return value ; 
}

int helper(vector<int>& arr , int k , int i ,bool hasStock ) { 
    // this function returns the value of the profit till the index it has covered 
        // 1 ≤ arr.size() ≤ 103
        // 1 ≤ k ≤ 200
        // 1 ≤ arr[i] ≤ 103

    int n = arr.size() ; 
    if ( n == 1 ) return 0 ;
    if (k == 0 || i == n) return 0;
    // int profit = 0 ; 
    int doesntIgnore ;
    if ( hasStock ) { 
        // sell 
        doesntIgnore = helper( arr , k-1 , i + 1 ,  !hasStock ) + arr[i] ; 
    }else { 
        // buy
        doesntIgnore =  helper( arr , k , i + 1 , !hasStock ) - arr[i]; 
    }
    // ignore 
    int ignore = helper( arr, k , i + 1 , hasStock  );
    return max ( doesntIgnore , ignore) ; 

}

int StockBuyAndSell(vector<int>& arr , int k) { 
    return helper( arr, k,0,false) ; 
}

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
    // memo[i][k][hasStock] = max profit starting at day i, with k transactions left, and stock held/not held
    vector<vector<vector<int>>> memo(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
    return helperMemo(arr, k, 0, 0, memo);
    }

int main() {
    // Test 1: Simple increasing prices, k = 1
    cout<<"starting test case " << 1 << endl ; 
    vector<int> prices1 = {1, 2, 3, 4, 5};
    assert(StockBuyAndSell(prices1, 1) == 4);
    assert(StockBuyAndSellMemo(prices1, 1) == 4);
    cout<<"ending test case " << 1 << endl ; 

    // Test 2: Simple decreasing prices, k = 2
    cout<<"starting test case " << 2 << endl ; 
    vector<int> prices2 = {5, 4, 3, 2, 1};
    assert(StockBuyAndSell(prices2, 2) == 0);
    assert(StockBuyAndSellMemo(prices2, 2) == 0);
    cout<<"ending test case " << 2 << endl ; 

    // Test 3: Prices with peaks and valleys, k = 2
    cout<<"starting test case " << 3 << endl ; 
    vector<int> prices3 = {3, 2, 6, 5, 0, 3};
    assert(StockBuyAndSell(prices3, 2) == 7);
    assert(StockBuyAndSellMemo(prices3, 2) == 7);
    cout<<"ending test case " << 3 << endl ; 

    // Test 4: Only one price, k = 1
    cout<<"starting test case " << 4 << endl ; 
    vector<int> prices4 = {10};
    assert(StockBuyAndSell(prices4, 1) == 0);
    assert(StockBuyAndSellMemo(prices4, 1) == 0);
    cout<<"ending test case " << 4 << endl ; 

    // Test 5: k = 0 (no transactions allowed)
    cout<<"starting test case " << 5 << endl ; 
    vector<int> prices5 = {1, 2, 3, 4, 5};
    assert(StockBuyAndSell(prices5, 0) == 0);
    assert(StockBuyAndSellMemo(prices5, 0) == 0);
    cout<<"ending test case " << 5 << endl ; 

    // Test 6: k greater than possible transactions
    cout<<"starting test case " << 6 << endl ; 
    vector<int> prices6 = {2, 4, 1};
    assert(StockBuyAndSell(prices6, 10) == 2);
    assert(StockBuyAndSellMemo(prices6, 10) == 2);
    cout<<"ending test case " << 6 << endl ; 

    // Test 7: Empty prices
    cout<<"starting test case " << 7 << endl ; 
    vector<int> prices7 = {};
    assert(StockBuyAndSell(prices7, 2) == 0);
    assert(StockBuyAndSellMemo(prices7, 2) == 0);
    cout<<"ending test case " << 7 << endl ; 


    return 0;
}