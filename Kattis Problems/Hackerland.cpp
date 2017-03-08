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
    //cout << "Main";
    FASTER;
    int houseCount;
    int range;
    int ans = 0;
    vi housePos;
    vi housesZeroed;
    cin >> houseCount;
    cin >> range;
    
    for (int i = 0; i < houseCount; i++) {
        int house;
        cin >> house;
        housePos.push_back(house);
    }
    sort(housePos.begin(), housePos.end());
    for (int i = housePos.front(); i <= housePos.back(); i++) {
        housesZeroed.push_back(i);
    }
    for (int i = 0; i < housesZeroed.size(); i++) {
        if (find(housePos.begin(), housePos.end(), housesZeroed[i]) == housePos.end()) {
            housesZeroed[i] = 0;
        }
    }
    for (int i = 0; i < housesZeroed.size() - range; i++) {
        if (housesZeroed[i+range] != 0) {
            ans++;
            i+=range;
        }
        else {
            while (housesZeroed[i+range] == 0) {
                i++;
            }
        }
        
    }
    cout << ans;
    
    
    return 0;
}













