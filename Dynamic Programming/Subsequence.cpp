#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()

int LisEndingAtIndex ( vector<int>& arr , int index ) {
    if ( index == 0 ) return 1 ; 

    int count = 1 ;
    for ( int prev = 0 ; prev < index ; prev ++ ) { 
        if (arr[prev] < arr[index] ) { 
            count = max( count,  LisEndingAtIndex(arr , prev) + 1) ;
        }
    }
    return count ; 
}
int Lis(vector<int>& arr) { 
    int n = arr.size() ; 
    int res = 1 ; 
    for ( int i = 1 ; i < n ; i ++) { 
        res = max ( res ,  LisEndingAtIndex(arr , i)) ;
    }
    return res ;
}

// with memoization
int LisEndingAtIndexMemo ( vector<int> &arr , int index , vector<int>& memo) { 
    if ( index == 0 ) return 1 ; 
    // checks if the value was computed earlier 
    if(memo[index] != -1) return memo[index] ; 

    int count = 1 ;
    for ( int prev = 0 ; prev < index ; prev ++ ) { 
        if ( arr[prev] < arr[index] ) { 
            count = max ( count , LisEndingAtIndexMemo(arr, prev , memo) + 1) ; 
        }
    }
    memo[index] = count ; 
    return memo[index] ;
}
int LisMemo ( vector<int>& arr ) { 
    int n = arr.size() ; 
    vector<int> memo(n , -1) ;
    int res = 1 ;
    for ( int i = 1 ; i < n ; i ++) { 
        res = max(res , LisEndingAtIndexMemo(arr,i,memo)) ; 
    }
    return res ; 
}


int LisTabulation ( vector<int> & arr) { 
    int n = arr.size() ; 
    vector<int> table( n , 1 ) ; 
    
    for ( int i = 1 ; i < n ; i++) { 
        for ( int prev = 0 ; prev < i ; prev ++) { 
            if ( arr[i] > arr[prev] && table[i] < table[prev] + 1) { 
                table[i] = table[prev] + 1; 
            }
        }
    }
    return *max_element(table.begin() , table.end()) ; 
}

int main() {
    // vector<int> arr = { 10, 22, 9, 33, 21, 50, 41, 60 };
    // cout << Lis(arr);
    // return 0;

    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    int expected = 4; // LIS is {2, 3, 7, 101}
    int result = Lis(arr);
    int result2 = LisMemo(arr);
    int result3 = LisTabulation(arr);
    cout << "Lis without memo       : " << result << endl ;
    cout << "Lis with memo          : " << result2 << endl ;
    cout << "Lis with tabulation    : " << result3 << endl ;
    cout << "Expected solution : " << 4 <<  endl ; 
    return 0;   
}