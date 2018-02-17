#include<iostream>
using namespace std;
int main() {
    int n, b, h, w;
    cin >> n >> b >> h >> w;
    int min = 10000000;
    while (h--) {
        int p;
        cin >> p;
        for (int i = 0; i < w; i++) {
            int num;
            cin >> num;
            if (num < n) {
                continue;
            }
            else {
                if ((n * p) < min) {
                    min = n*p;
                }
            }
        }
    }
    if (min < b) {
        cout << min << endl;
    }
    else {
        cout << "stay home" << endl;
    }
    return 0;
}

