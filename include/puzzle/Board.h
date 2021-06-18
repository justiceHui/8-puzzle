//
// Created by jeounghui on 2021-06-18.
//

#ifndef PUZZLE_BOARD_H
#define PUZZLE_BOARD_H

#include "FenwickTree.h"
#include "combination.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <array>
#include <utility>
#include <bitset>
#include <algorithm>
#include <cassert>

template<size_t N>
class Board{
public:
    Board() = default;
    ~Board() = default;
    void input();
    void input(const std::string &filename);
    void swap(int r1, int c1, int r2, int c2);
    [[nodiscard]] bool isFinished() const;
    [[nodiscard]] bool isSolvable() const;
    [[nodiscard]] int64_t hash() const;
    [[nodiscard]] std::pair<int, int> findZeroPosition() const;
    bool operator < (const Board &board) const {
        return a < board.a;
    }
    bool operator == (const Board &board) const {
        return a == board.a;
    }
private:
    std::array<std::array<int, N>, N> a;
    [[nodiscard]] int inversionCount() const;
};

template<size_t N>
void Board<N>::input(){
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) std::cin >> a[i][j];
}

template<size_t N>
void Board<N>::input(const std::string &filename){
    std::ifstream in(filename);
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) in >> a[i][j];
}

template<size_t N>
void Board<N>::swap(int r1, int c1, int r2, int c2){
    std::swap(a[r1][c1], a[r2][c2]);
}

template<size_t N>
bool Board<N>::isFinished() const {
    for(int i=0, k=1; i<N; i++) for(int j=0; j<N; j++, k++) {
        if(i+1 == N && j+1 == N){
            if(a[i][j] != 0) return false;
        }
        else{
            if(a[i][j] != k) return false;
        }
    }
    return true;
}

template<>
bool Board<3>::isSolvable() const {
    int inversion = inversionCount();
    return ~inversion & 1;
}

template<>
bool Board<4>::isSolvable() const {
    int inversion = inversionCount();
    int pos = 4 - findZeroPosition().first;
    return (inversion ^ pos) & 1;
}

template<size_t N>
int64_t Board<N>::hash() const {
    std::bitset<N*N> check;
    int64_t ret = 1;
    for(int i=0, p=0; i<N; i++) for(int j=0; j<N; j++, p++){
        check[a[i][j]] = true;
        for(int k=0; k<a[i][j]; k++){
            if(check[k]) continue;
            ret += combination::factorial[N*N-p-1];
        }
    }
    return ret;
}

template<size_t N>
int Board<N>::inversionCount() const {
    int ret = 0;
    FenwickTree<int, N*N+3> tree;
    for(int i=N-1; i>=0; i--) for(int j=N-1; j>=0; j--) {
        if(a[i][j]) ret += tree.get(a[i][j]), tree.add(a[i][j]);
    }
    return ret;
}

template<size_t N>
std::pair<int, int> Board<N>::findZeroPosition() const {
    for(int i=0; i<4; i++) for(int j=0; j<4; j++){
        if(!a[i][j]) return {i, j};
    }
    assert(false);
}


#endif //PUZZLE_BOARD_H
