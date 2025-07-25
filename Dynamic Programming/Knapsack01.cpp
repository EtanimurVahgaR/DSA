#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int knapsackRec ( int W , vector<int>& val , vector<int>& wt , int n,  vector<vector<int>>& memo) { 
    if ( n == 0 || W == 0 ) { 
        return 0 ; 
    }
    if ( memo[n][W] != -1) return memo[n][W]  ;
    int pick = 0 ; 
    
    if ( wt[n-1] <= W ) { 
        pick = val[n-1] + knapsackRec(W - wt[n-1] , val , wt , n -1 , memo) ; 
    }
    
    int notPick = knapsackRec(W , val , wt , n-1 ,memo) ; 
    return memo[n][W] =  max ( pick , notPick ) ;
}

int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size() ;
    vector<vector<int>> memo ( n +1 , vector<int> (W +1  , -1 )) ; 
    return knapsackRec ( W , val , wt , n , memo ) ; 
}
int knapsackTable(int W , vector<int> &val , vector<int> &wt) { 
    
    int n = val.size() ;
    vector<vector<int>> table ( n+1  , vector<int> ( W +1 , -1 )) ; 
    for ( int i = 0 ; i <= n ; i++ ) { 
        for ( int j = 0 ; j <= W ; j ++ ) { 
            
            if ( i ==0 || j== 0) table[i][j] = 0 ;
            else { 
                int pick = 0 ; 
                if ( wt[i-1] <= j) 
                    pick = val[i-1] + table[i-1][j-wt[i-1]] ; 
                    
                int notPick = table[i-1][j] ;
                table[i][j] = max ( pick , notPick ) ; 
            }
        }
    }
    return table[n][W] ; 
}

int knapsackTableSpaceOptimized(int W , vector<int> &val , vector<int> &wt)  { 
    int n = val.size() ;
    vector<vector<int>> table ( 2  , vector<int> ( W +1 , -1 )) ; 
    for ( int i = 0 ; i <= n ; i++ ) { 
        for ( int j = 0 ; j <= W ; j ++ ) { 
            
            if ( i == 0 || j== 0) table[i%2][j] = 0 ;
            else { 
                int pick = 0 ; 
                if ( wt[i-1] <= j) 
                    pick = val[i-1] + table[(i-1)%2][j-wt[i-1]] ; 
                    
                int notPick = table[(i-1)%2][j] ;
                table[i%2][j] = max ( pick , notPick ) ; 
            }
        }
    }
    return table[n%2][W] ; 
}

int main() {

    vector<int> val1 = {60, 100, 120};
    vector<int> wt1 = {10, 20, 30};
    int W1 = 50;
    assert(knapsack(W1, val1, wt1) == 220);
    assert(knapsackTable(W1, val1, wt1) == 220);
    assert(knapsackTableSpaceOptimized(W1, val1, wt1) == 220);
    cout<< "test " << 1 << " case passed" <<endl ; 
    
    // Test 2: Zero capacity
    
    vector<int> val2 = {10, 20, 30};
    vector<int> wt2 = {1, 1, 1};
    int W2 = 0;
    assert(knapsack(W2, val2, wt2) == 0);
    assert(knapsackTable(W2, val2, wt2) == 0);
    assert(knapsackTableSpaceOptimized(W2, val2, wt2) == 0);
    cout<< "test " << 2 << " case passed" <<endl ; 
    // Test 3: No items
    
    vector<int> val3 = {};
    vector<int> wt3 = {};
    int W3 = 10;
    assert(knapsack(W3, val3, wt3) == 0);
    assert(knapsackTable(W3, val3, wt3) == 0);
    assert(knapsackTableSpaceOptimized(W3, val3, wt3) == 0);
    cout<< "test " << 3 << " case passed" <<endl ; 
    // Test 4: All items too heavy
    
    vector<int> val4 = {10, 20, 30};
    vector<int> wt4 = {11, 12, 13};
    int W4 = 10;
    assert(knapsack(W4, val4, wt4) == 0);
    assert(knapsackTable(W4, val4, wt4) == 0);
    assert(knapsackTableSpaceOptimized(W4, val4, wt4) == 0);
    cout<< "test " << 4 << " case passed" <<endl ; 
    // Test 5: Single item fits
    
    vector<int> val5 = {100};
    vector<int> wt5 = {5};
    int W5 = 5;
    assert(knapsack(W5, val5, wt5) == 100);
    assert(knapsackTable(W5, val5, wt5) == 100);
    assert(knapsackTableSpaceOptimized(W5, val5, wt5) == 100);
    cout<< "test " << 5 << " case passed" <<endl ; 
    // Test 6: Multiple items, only some fit
    
    vector<int> val6 = {10, 40, 30, 50};
    vector<int> wt6 = {5, 4, 6, 3};
    int W6 = 10;
    assert(knapsack(W6, val6, wt6) == 90);
    assert(knapsackTable(W6, val6, wt6) == 90);
    assert(knapsackTableSpaceOptimized(W6, val6, wt6) == 90);
    cout<< "test " << 6 << " case passed" <<endl ; 
    // Test 7: Large capacity, all items fit
    
    vector<int> val7 = {10, 20, 30};
    vector<int> wt7 = {1, 2, 3};
    int W7 = 10;
    assert(knapsack(W7, val7, wt7) == 60);
    assert(knapsackTable(W7, val7, wt7) == 60);
    assert(knapsackTableSpaceOptimized(W7, val7, wt7) == 60);
    cout<< "test " << 7 << " case passed" <<endl ; 
    // Test 8: Duplicate weights and values
    
    vector<int> val8 = {10, 10, 10};
    vector<int> wt8 = {5, 5, 5};
    int W8 = 10;
    assert(knapsack(W8, val8, wt8) == 20);
    assert(knapsackTable(W8, val8, wt8) == 20);
    assert(knapsackTableSpaceOptimized(W8, val8, wt8) == 20);
    cout<< "test " << 8 << " case passed" <<endl ; 
    // Test 9: Edge case, capacity just enough for one item
    
    vector<int> val9 = {15, 25, 50};
    vector<int> wt9 = {10, 20, 30};
    int W9 = 30;
    assert(knapsack(W9, val9, wt9) == 50);
    assert(knapsackTable(W9, val9, wt9) == 50);
    assert(knapsackTableSpaceOptimized(W9, val9, wt9) == 50);
    cout<< "test " << 9 << " case passed" <<endl ; 
    // Test 10: Large values and weights
    
    vector<int> val10 = {1000, 2000, 3000};
    vector<int> wt10 = {100, 200, 300};
    int W10 = 500;
    assert(knapsack(W10, val10, wt10) == 5000);
    assert(knapsackTable(W10, val10, wt10) == 5000);
    assert(knapsackTableSpaceOptimized(W10, val10, wt10) == 5000);
    cout<< "test " << 10 << " case passed" <<endl ; 
    return 0;
}