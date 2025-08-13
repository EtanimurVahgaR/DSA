#include <bits/stdc++.h>
#include <iostream>
#include <cassert>
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()

int helper( string& digits , int i) { 
    int n = digits.size() ; 
    // base case
    if ( i >= n) return 1 ; 

    int ways= 0 ; 

    // one digit decoding : checking if the single digit is not 0 
    if ( digits[i] != '0' ) { 
        ways += helper(digits, i + 1 ) ;
    }

    // 2 digit decoding : checking if the 2 digits combine to form a valid number
    if (( i + 1 < n ) && ((digits[i] == '1' && digits[i + 1] <= '9') ||
                          (digits[i] == '2' && digits[i + 1] <= '6'))) 
    { 
        ways+= helper(digits, i + 2 ) ;
    }
    return ways ;

}

int TotalDecoding(string & digits ) { 
    return helper( digits, 0 ) ;
}
int TotalDecodingtabulation(string &digits) {
    int n = digits.length() ; 
    vector<int> dp ( n + 1 , 0 ) ; 

    dp[n] = 1 ; 

    for ( int i = n -1 ; i >=0 ; i-- ) { 
        if ( digits[i] != '0') { 
            dp[i] += dp[i + 1] ;
        }

        if ((i + 1 < n) && 
            ((digits[i] == '1' && digits[i+1] <= '9') ||
            (digits[i] == '2' && digits[i+1] <= '6')))   
        {
            dp[i] += dp[i + 2] ; 
        }
    }
    return dp[0] ; 
}

int TotalDecodingOptimnized(string& digits) { 
    int n = digits.length () ;
    int current =0 ; 
    int next = 1 ; 
    int nextToNext = 0; 

    if ( n == 0 ) return 1 ;
    

    for ( int i = n -1 ; i >=0 ; i --) { 
        current = 0 ; 
        if ( digits[i] != '0') { 
            current += next ;
        }

        if ((i + 1 < n) && 
            ((digits[i] == '1' && digits[i+1] <= '9') ||
            (digits[i] == '2' && digits[i+1] <= '6')))   
        {
            current += nextToNext ; 
        }
        nextToNext = next ;
        next = current ;

    }
    return current ; 
}
int main() {
    {
        string digits = "12";
        int result = TotalDecoding(digits);
        int result2 = TotalDecodingtabulation(digits);
        int result3 = TotalDecodingOptimnized(digits);
        int expected = 2;
        cout << "digits: \"" << digits << "\", result: " << result << ", expected: " << expected << endl;
        cout << "Tabulation : " << "digits: \"" << digits << "\", result: " << result2 << ", expected: " << expected << endl;
        cout << "Optimized : " << "digits: \"" << digits << "\", result: " << result3 << ", expected: " << expected << endl;
        cout << endl ; 
        assert(result == expected);
        assert(result2 == expected);
        assert(result3 == expected);
    }
    {   
        string digits = "226";
        int result = TotalDecoding(digits);
        int result2 = TotalDecodingtabulation(digits);
        int result3 = TotalDecodingOptimnized(digits);
        int expected = 3;
        cout << "digits: \"" << digits << "\", result: " << result << ", expected: " << expected << endl;
        cout << "Tabulation : " << "digits: \"" << digits << "\", result: " << result2 << ", expected: " << expected << endl;
        cout << "Optimized : " << "digits: \"" << digits << "\", result: " << result3 << ", expected: " << expected << endl;
        cout << endl ; 
        assert(result == expected);
        assert(result2 == expected);
        assert(result3 == expected);
    }
    {
        string digits = "0";
        int result = TotalDecoding(digits);
        int result2 = TotalDecodingtabulation(digits);
        int result3 = TotalDecodingOptimnized(digits);
        int expected = 0;
        cout << "digits: \"" << digits << "\", result: " << result << ", expected: " << expected << endl;
        cout << "Tabulation : " << "digits: \"" << digits << "\", result: " << result2 << ", expected: " << expected << endl;
        cout << "Optimized : " << "digits: \"" << digits << "\", result: " << result3 << ", expected: " << expected << endl;
        cout << endl ; 
        assert(result == expected);
        assert(result2 == expected);
        assert(result3 == expected);
    }
    {
        string digits = "10";
        int result = TotalDecoding(digits);
        int result2 = TotalDecodingtabulation(digits);
        int result3 = TotalDecodingOptimnized(digits);
        int expected = 1;
        cout << "digits: \"" << digits << "\", result: " << result << ", expected: " << expected << endl;
        cout << "Tabulation : " << "digits: \"" << digits << "\", result: " << result2 << ", expected: " << expected << endl;
        cout << "Optimized : " << "digits: \"" << digits << "\", result: " << result3 << ", expected: " << expected << endl;
        cout << endl ; 
        assert(result == expected);
        assert(result2 == expected);
        assert(result3 == expected);
    }
    {
        string digits = "27";
        int result = TotalDecoding(digits);
        int result2 = TotalDecodingtabulation(digits);
        int result3 = TotalDecodingOptimnized(digits);
        int expected = 1;
        cout << "digits: \"" << digits << "\", result: " << result << ", expected: " << expected << endl;
        cout << "Tabulation : " << "digits: \"" << digits << "\", result: " << result2 << ", expected: " << expected << endl;
        cout << "Optimized : " << "digits: \"" << digits << "\", result: " << result3 << ", expected: " << expected << endl;
        cout << endl ; 
        assert(result == expected);
        assert(result2 == expected);
        assert(result3 == expected);
    }
    {
        string digits = "";
        int result = TotalDecoding(digits);
        int result2 = TotalDecodingtabulation(digits);
        int result3 = TotalDecodingOptimnized(digits);
        int expected = 1;
        cout << "digits: \"" << digits << "\", result: " << result << ", expected: " << expected << endl;
        cout << "Tabulation : " << "digits: \"" << digits << "\", result: " << result2 << ", expected: " << expected << endl;
        cout << "Optimized : " << "digits: \"" << digits << "\", result: " << result3 << ", expected: " << expected << endl;
        cout << endl ; 
        assert(result == expected);
        assert(result2 == expected);
        assert(result3 == expected);
    }
    cout << "All test cases passed!\n";
    return 0;
}