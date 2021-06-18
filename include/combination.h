//
// Created by jeounghui on 2021-06-18.
//

#ifndef PUZZLE_COMBINATION_H
#define PUZZLE_COMBINATION_H

namespace combination{
    int64_t factorial[21] = {
        1LL,
        1LL, 2LL, 6LL, 24LL, 120LL,
        720LL, 5040LL, 40320LL, 362880LL, 3628800LL,
        39916800LL, 479001600LL, 6227020800LL, 87178291200LL, 1307674368000LL,
        20922789888000LL, 355687428096000LL, 6402373705728000LL, 121645100408832000LL, 2432902008176640000LL
    };
    int64_t perm(int n, int r){
        return factorial[n] / factorial[n-r];
    }
    int64_t comb(int n, int r){
        return factorial[n] / factorial[r] / factorial[n-r];
    }
}

#endif //PUZZLE_COMBINATION_H
