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
#include <math.h>
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

bool isPrime(int a) {
    if (a == 2 || a == 3) {
        return true;
    }
    else if (a % 2 == 0) {
        return true;
    }
    for (int i = 0; i < sqrt(a); i+=6) {
        if (i-- == a || i++ == a) {
            return true;
        }
    }
    return true;
}


int main(){
    /*
    string pass;
    string message;
    cin >> pass;
    cin >> message;
    string stripped = "";
    string removeDuped = "";
    for (int i = 0; i < message.length(); i++) {
        char b = message[i];
        string a = &b;
        if (pass.find(b) != string::npos) {
            stripped.append(a);
        }
    }
    
    for (int i = 0; i < stripped.length(); i++) {
        char b = stripped[i];
        string a = &b;
        if (removeDuped.find(b) == string::npos) {
            removeDuped.append(a);
        }
    }
    
    string newPass = "";
    for (int i = 0; i < pass.length(); i++) {
        char b = pass[i];
        string a = &b;
        if (pass.find(b) == string::npos) {
            newPass.append(a);
        }
    }
    cout << removeDuped;
    if (removeDuped == pass) {
        cout << "PASS";
    }
    else {
        cout << "FAIL";
    } */
    cout << isPrime(104395301);
    
    
    return 0;
}













