//#include "stdafx.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

const vector<int>* fibon_seq(int size) {
    const int max_size = 1024;
    static vector<int> elems;
    if (size <= 0 || size > max_size) {
        cerr << "Error";
        return 0;
    }
    for (int ix = elems.size(); ix < size; ++ix) {
        if (ix == 0 || ix == 1)
            elems.push_back(1);
        else elems.push_back(elems[ix - 1] + elems[ix - 2]);
    }
    return &elems;
}

void display(const vector<int>* vec, ostream &os = cout) {
    if (!vec)
        cerr << "null vector";
    for (int i = 0; i < (vec)->size(); ++i)
        os << (*vec)[i] << " ";
    os << endl;
}

bool fibon_elem(int pos, int &elem, const vector<int>* (*seq_ptr)(int)) {
    const vector<int> *pseq = seq_ptr(pos);
    if (!pseq){
        elem = 0; return false;
    }
    elem = (*pseq)[pos - 1];
    return true;
}

int main()
{
    const vector<int>* (*(*seq_array)[1])(int);
    (*seq_array)[0] = fibon_seq;
    const vector<int>* (*seq_ptr)(int);
    int seq_index = 0;
    seq_ptr = (*seq_array)[0];//This is the line with error.
    int a;
    fibon_elem(12, a, seq_ptr);//This is the line with error.
    getchar();
    return 0;
}
