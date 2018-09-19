#include "testlib.h"

int main(int argc, char* argv[]) {
    
    registerValidation(argc, argv);

/*
n m sigma
<e_1, e_2, ..., e_m>
s
k
<t_1, ..., t_k>
*/  

    const int MINN = 1;
    const int MAXN = 200;
    const int MINM = 1;
    const int MAXM = MAXN * MAXN;
    const int SIGMA = 100;

    int n = inf.readInt(MINN, MAXN);
    inf.readSpace();
    int m = inf.readInt(MINM, MAXM);
    inf.readSpace();
    int sigma = inf.readInt(1, SIGMA);
    inf.readEoln();

    for(int u, v, c, i = 0;i < m;i++) {
        u = inf.readInt(1, n);
        inf.readSpace();
        v = inf.readInt(1, n);
        inf.readSpace();
        c = inf.readInt(0, sigma - 1);
        inf.readEoln();
    }

    int start = inf.readInt(1, n);
    inf.readEoln();
    int k = inf.readInt(0, n);
    inf.readEoln();

    for(int x, i = 0;i < k;i++) {
        x = inf.readInt(1, n);
        inf.readSpace();
    }

    inf.readEoln();
    inf.readEof();

    return 0;
}
