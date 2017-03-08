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
#include <map>
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

vector<char> mergeVec(vector<char> a, vector<char> b) {
    vector<char> ans;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '0') {
            a[i] = b[i];
        }
    }
    
    
    return a;
}


int main(){
    
    int group1Size;
    int group2Size;
    cin >> group1Size;
    cin >> group2Size;
    string group1;
    cin >> group1;
    string group2;
    cin >> group2;
    
    int time;
    cin >> time;
    
    
    reverse(group1.begin(), group1.end());
    string combo = group1+group2;
    //cout << combo;
    
    map<char, bool> myMap;
    for (int i = 0; i < group1Size; i++) {
        myMap.emplace(group1[i], true);
    }
    for (int i = 0; i < group2Size; i++) {
        myMap.emplace(group2[i], false);
    }
    
    if (combo.size() == 2) {
        swap(combo[0], combo[1]);
        cout << combo;
        
    }
    else {
        for (int i = 0; i < time; i++) {
            for (int j = 0; j < combo.length() - 1; j++) {
                if (myMap.find(combo[j])->second ^ myMap.find(combo[j+1])->second) {
                    //cout << combo[j] << " " << combo[j+1] << " swapped" << endl;
                    if (j >= combo.length()) {
                        break;
                    }
                    swap(combo[j], combo[j+1]);
                    j++;
                    
                
                }
                
            }
        }
        cout << combo << endl;
    }
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
