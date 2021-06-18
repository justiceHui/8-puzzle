//
// Created by jeounghui on 2021-06-18.
//

#ifndef PUZZLE_BFSSOLVER_H
#define PUZZLE_BFSSOLVER_H

#include "puzzle/Board.h"
#include "custom_set.h"
#include "TimeLogger.h"

#include <queue>
#include <vector>
#include <utility>
#include <functional>

template<size_t N>
class BFSSolver{
public:
    BFSSolver() = default;
    explicit BFSSolver(const Board<N> &board) : initialState(board) {}
    ~BFSSolver() = default;
    void init(){ initialState.input(); }
    bool solve() const;
private:
    Board<N> initialState;
    static constexpr int di[] = {0, 0, 1, -1};
    static constexpr int dj[] = {1, -1, 0, 0};
};

template<size_t N>
bool BFSSolver<N>::solve() const {
    TimeLogger logger;
    if(!initialState.isSolvable()) return false;

    std::queue<Board<N>> que;
    __gnu_pbds::gp_hash_table<int64_t, int, my_hash> dst({},{},{},{}, {1 << 16});

    que.push(initialState);
    dst[initialState.hash()] = 0;

    int ans = -1;

    while(que.size()){
        auto now = que.front(); que.pop();
        int cst = dst[now.hash()];
        if(now.isFinished()){
            ans = cst;
            break;
        }
        auto [i,j] = now.findZeroPosition();
        for(int k=0; k<4; k++){
            int ii = i + di[k], jj = j + dj[k];
            if(ii < 0 || ii >= N || jj < 0 || jj >= N) continue;
            now.swap(i, j, ii, jj);
            int64_t nxtHash = now.hash();
            if(dst.find(nxtHash) == dst.end()){
                dst[nxtHash] = cst + 1;
                que.push(now);
            }
            now.swap(i, j, ii, jj);
        }
    }

    std::cout << "move : " << ans << std::endl;
    return true;
}

#endif //PUZZLE_BFSSOLVER_H