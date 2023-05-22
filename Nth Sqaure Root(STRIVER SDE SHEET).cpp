int NthRoot(int n, int m) {
    // 'ans' variable stores the 
    // nth root of m
    int ans = -1;
    
    // 's' and 'e' are the lower and upper
    // bounds of our search space
    int s = 1, e = m;
    
    while (s <= e) {
        int mid = (s + e) / 2;
        
        // 'x' stores the value of 
        // mid ^ n
        long long x = 1;
        
        // Iterating from '1' from 'n'
        // to get 'mid ^ n'
        for (int i = 1; i <= n; ++i) {
            x *= mid;
            
            // If 'x' is greater than 'm'
            // it's better to stop the loop
            // as obviously, multiplying 
            // x, further with 'mid' will increase it
            // more.
            if (x > 1LL * m) {
                break;
            }
        }
        // If 'x' becomes 'm', we have found the answer
        if (x == 1LL * m) {
            ans = mid;
            break;
        }
        // If 'x' is greater than 'm',
        // we should shift our search space
        // to lower integer values, otherwise higher.
        if (x > m) {
            e = mid - 1;
        } else
            s = mid + 1;
    }
    return ans;
}



//
#include <bits/stdc++.h>
using namespace std;
double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}

void getNthRoot(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-7; 
    
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(multiply(mid, n) < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
    
    cout <<n<<"th root of "<<m<<" is "<<low<<endl; 
    
}
int main() {
	int n=3, m=27; 
	getNthRoot(n, m); 
	return 0;
}
