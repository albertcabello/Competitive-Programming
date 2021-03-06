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
    string a1;
    string a2;
    string a3;
    string b1;
    string b2;
    string b3;
    cin >> a1;
    cin >> a2;
    cin >> a3;
    cin >> b1;
    cin >> b2;
    cin >> b3;
    
    int ascore;
    int bscore;
    
    if (stoi(a1) > stoi(b1)) {
        ascore++;
    }
    else if (stoi(a1) < stoi(b1)) {
        bscore++;
    }
    
    if (stoi(a2) > stoi(b2)) {
        ascore++;
    }
    else if (stoi(a2) < stoi(b2)) {
        bscore++;
    }
    if (stoi(a3) > stoi(b3)) {
        ascore++;
    }
    else if (stoi(a3) < stoi(b3)) {
        bscore++;
    }
    cout << ascore << " " << bscore << endl;
    
    return 0;
}
