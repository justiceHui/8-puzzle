//
// Created by jeounghui on 2021-06-18.
//

#ifndef PUZZLE_FENWICKTREE_H
#define PUZZLE_FENWICKTREE_H

#include <array>
#include <algorithm>

template<typename T, size_t N>
class FenwickTree{
public:
    FenwickTree(){
        std::fill(tree.begin(), tree.end(), T(0));
    }
    ~FenwickTree() = default;
    void add(int x, T v = T(1)){
        for(x++; x<N; x+=x&-x) tree[x] += v;
    }
    T get(int x){
        T ret = T(0);
        for(x++; x; x-=x&-x) ret += tree[x];
        return ret;
    }
private:
    std::array<T, N> tree;
};

#endif //PUZZLE_FENWICKTREE_H
