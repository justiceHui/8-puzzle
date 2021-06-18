//
// Created by jeounghui on 2021-06-18.
//

#ifndef PUZZLE_DIJKSTRASOLVER_H
#define PUZZLE_DIJKSTRASOLVER_H

#include "puzzle/Board.h"
#include "custom_set.h"
#include "TimeLogger.h"
#include <queue>
#include <vector>
#include <utility>
#include <functional>

template<size_t N>
class DijkstraSolver{
public:
    DijkstraSolver() = default;
    explicit DijkstraSolver(const Board<N> &board) : initialState(board) {}
    ~DijkstraSolver() = default;
    void init(){ initialState.input(); }
    bool solve() const;
private:
    Board<N> initialState;
    static constexpr int di[] = {0, 0, 1, -1};
    static constexpr int dj[] = {1, -1, 0, 0};
};

template<size_t N>
bool DijkstraSolver<N>::solve() const {
    TimeLogger logger;
    if(!initialState.isSolvable()) return false;

    using pq_node = std::pair<int64_t, Board<N>>;
    std::priority_queue<pq_node, std::vector<pq_node>, std::greater<>> pq;
    __gnu_pbds::gp_hash_table<int64_t, int, my_hash> dst({},{},{},{}, {1 << 18});

    pq.emplace(0, initialState);
    dst[initialState.hash()] = 0;

    int ans = -1;

    while(pq.size()){
        auto [cst, now] = pq.top(); pq.pop();
        if(now.isFinished()){
            ans = cst;
            break;
        }
        if(cst != dst[now.hash()]) continue;
        auto [i,j] = now.findZeroPosition();
        for(int k=0; k<4; k++){
            int ii = i + di[k], jj = j + dj[k];
            if(ii < 0 || ii >= N || jj < 0 || jj >= N) continue;
            now.swap(i, j, ii, jj);
            int64_t nxtHash = now.hash();
            if(dst.find(nxtHash) == dst.end() || dst[nxtHash] > cst + 1){
                dst[nxtHash] = cst + 1;
                pq.emplace(cst + 1, now);
            }
            now.swap(i, j, ii, jj);
        }
    }

    std::cout << "move : " << ans << std::endl;
    return true;
}

#endif //PUZZLE_DIJKSTRASOLVER_H
