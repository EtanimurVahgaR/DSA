#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()




int MCTRTHelper(vector<int>& cost ,int onstep , vector<int>& memo) { 
    if ( onstep == 0 ) return cost[0] ; 
    if ( onstep == 1 ) return cost[1] ; 
    if ( memo[onstep] != -1) return memo[onstep] ; 
    return  memo[onstep] =  min ( MCTRTHelper (cost , onstep - 1 , memo) ,MCTRTHelper(cost , onstep -2 ,memo)) + cost[onstep] ;
}
int MinimumCostToReachTop(vector<int>& cost) {
    // Write your code here
    int n = cost.size() ; 
    vector<int> memo ( n + 1 , -1 ) ;
    return min(MCTRTHelper(cost, n-1 , memo) , MCTRTHelper(cost , n-2 , memo)) ; 
}

int MinimumCostToReachTopTable(vector<int>&cost) { 
    int n = cost.size();
    vector<int> table(n, 0);
    table[0] = cost[0];
    table[1] = cost[1];

    for (int i = 2; i < n; i++) {
        table[i] = min(table[i - 1], table[i - 2]) + cost[i];
    }
    return min(table[n - 1], table[n - 2]);
}
int MinimumCostToReachTopTableSpaceOptimized(vector<int>&cost) { 
    int n = cost.size();
    if (n == 1) return cost[0] ; 
    int prev1 = cost[1] ; int prev2 = cost[0]; 
    int curr = 0 ;
    for (int i = 2; i < n; i++) {
        curr = min(prev1, prev2) + cost[i];
        prev2 = prev1 ; 
        prev1 = curr ;
    }
    return min(prev2 , prev1);
}

int main() {
    vector<int> cost1 = {10, 15, 20};
    // Expected output: 15 (10->15->top or 15->top)
    cout << "Test 1: ";
    cout << MinimumCostToReachTop(cost1) << endl;
    cout << MinimumCostToReachTopTable(cost1) << endl;
    cout << MinimumCostToReachTopTableSpaceOptimized(cost1) << endl;
    
    // Test case 2: Another example
    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    // Expected output: 6
    cout << "Test 2: ";
    cout << MinimumCostToReachTop(cost2) << endl;
    cout << MinimumCostToReachTopTable(cost2) << endl;
    cout << MinimumCostToReachTopTableSpaceOptimized(cost2) << endl;
    
    // Test case 3: Single step
    vector<int> cost3 = {5};
    // Expected output: 5
    cout << "Test 3: ";
    cout << MinimumCostToReachTop(cost3) << endl;
    cout << MinimumCostToReachTopTable(cost3) << endl;
    cout << MinimumCostToReachTopTableSpaceOptimized(cost3) << endl;
    
    // Test case 4: Two steps
    vector<int> cost4 = {2, 3};
    // Expected output: 2 (start at step 0)
    cout << "Test 4: ";
    cout << MinimumCostToReachTop(cost4) << endl;
    cout << MinimumCostToReachTopTable(cost4) << endl;
    cout << MinimumCostToReachTopTableSpaceOptimized(cost4) << endl;
    
    // Test case 5: All zeros
    vector<int> cost5 = {0, 0, 0, 0};
    // Expected output: 0
    cout << "Test 5: ";
    cout << MinimumCostToReachTop(cost5) << endl;
    cout << MinimumCostToReachTopTable(cost5) << endl;
    cout << MinimumCostToReachTopTableSpaceOptimized(cost5) << endl;
    

    return 0;
}