#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    registerGen(argc, argv, 1);

    const int MINN = 10;
    const int MAXN = 15;
    const int MINM = 1;
    const int MAXM = MAXN * MAXN;
    const int SIGMA = 7;

    int n = rnd.next(MINN, MAXN);
    int sigma = rnd.next(5, SIGMA);
    int m = n * sigma;

    cout << n << " " << m << " " << sigma << endl;

    for(int u = 1;u <= n;u++) {
        for(int c = 0;c < sigma;c++) {
            int v = rnd.next(1, n);
            cout << u << " " << v << " " << c << endl;
        }
    }

    int start = rnd.next(1, n);
    int k = rnd.next(0, n);

    cout << start << endl;
    cout << k << endl;

    for(int x, i = 0;i < k;i++) {
        x = rnd.next(1, n);
    	cout << x << " ";
    }

    cout << endl;

    return 0;
}
