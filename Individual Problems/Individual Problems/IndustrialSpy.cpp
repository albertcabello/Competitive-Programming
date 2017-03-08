//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;

#define MEM(arr,val)memset((arr),(val), sizeof (arr))
#define PI (acos(0)*2.0)
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(v)v.begin(),v.end()
#define PB(v)push_back(v)

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll gcd(ll a,ll b){return b == 0 ? a : gcd(b,a%b);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}

/**
 * __builtin_popcount(int d) // count bits
 * __builtin_popcountll(long long d)
 * strtol(s, &end, base); // convert base number
 */
//----------------------------------------------------------------------//

vector<string> permutations;
vector<string> droppedIndices;
/*
void heapPermutations(int n, string a) {
    if ( n == 1 ) {
        permutations.push_back(a);
    }
    else {
        for (int i = 0; i < n - 1; i++) {
            heapPermutations(n-1, a);
            if ( n % 2 == 0) {
                swap(a[i], a[n - 1]);
            }
            else {
                swap(a[0], a[n - 1]);
            }
        }
        heapPermutations(n-1, a);
    }
    
} */

void permute(string a) {
    sort(a.begin(), a.end());
    do {
        if (a.substr(0,1) != "0") {
            permutations.push_back(a);
        }
    } while (next_permutation(a.begin(), a.end()));
}

void dropIndices(string a) {
    if (a.length() == 1) {
        return;
    }
    else {
        for (int i = 0; i < a.length(); i++) {
            string b = a.substr(0,i) + a.substr(i+1, a.length());
            if (find(droppedIndices.begin(), droppedIndices.end(), b) != droppedIndices.end()) {
                dropIndices(b);
                droppedIndices.push_back(b);
            }
            //dropIndices(b);
            //droppedIndices.push_back(b);
        }
    }
}

bool isPrime(int a) {
    if (a == 1 || a == 0) {
        return false;
    }
    if (a % 2 == 0 && a != 2) {
        return false;
    }
    if (a == 2) {
        return true;
    }
    for (int i = 3; i <= sqrt(a); i += 2) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}



int main(){
    
    int count;
    cin >> count;
    for (int i = 0; i < count; i++) {
        string a;
        cin >> a;
        int primeCount = 0;
        //sort(a.begin(), a.end());
        dropIndices(a);
        permute(a);
        for (int i = 0; i < droppedIndices.size(); i++) {
            //sort(droppedIndices[i].begin(), droppedIndices[i].end());
            permute(droppedIndices[i]);
        }
        for (int i = 0; i < permutations.size(); i++) {
            if (isPrime(stoi(permutations[i]))) {
                primeCount++;
            }
        }
        cout << primeCount << endl;
        primeCount = 0;
        droppedIndices.clear();
        permutations.clear();
    }
    
//    dropIndices("1234567");
//    cout << droppedIndices.size();
    return 0;
}













