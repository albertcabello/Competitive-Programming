//
//  Hackerland.cpp
//  Feb11 Contest Individual
//
//  Created by Alberto Cabello on 2/11/17.
//  Copyright © 2017 Alberto Cabello. All rights reserved.
//

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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



int main(){
    string pass = "ABC";
    string message = "HAPPYBIRTHDAYCASEY";
    for (int i = 0; i < message.length(); i++) {
//        cout << "Loop";
        char a = message[i];
        string b = &a;
        //cout << pass.find(b);
        if (pass.find(b) != string::npos) {
            cout << "In if";
            char first = pass[0];
            if (&first == b) {
                cout << pass.substr(1) << endl;
                pass = pass.substr(1);
            }
            else {
                cout << "FAIL";
                return 0;
            }
            
        }
    }
    if (pass == "") {
        cout << "PASS";
    }
    else {
        cout << "FAIL";
    }
    
    
    return 0;
}












