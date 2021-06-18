/******************************
Author: jhnah917(Justice_Hui)
******************************/

// https://github.com/joonion/too-much-information/tree/main/N-Puzzle_Solver

#include "puzzle/Board.h"
#include "puzzle/DijkstraSolver.h"
#include "puzzle/BFSSolver.h"

#include <iostream>
#include <string>
#include <vector>

constexpr int N = 3;

void run(const std::string &filename){
    std::cout << "testcase : " << filename << std::endl;
    Board<N> board{};
    board.input(filename);

    if(!board.isSolvable()){
        std::cout << "not solvable\n" << std::endl;
        return;
    }

    std::cout << "[[ Dijkstra Solver ]]" << std::endl;
    DijkstraSolver<N> solver1(board);
    assert(solver1.solve());

    std::cout << "[[ BFS Solver ]] " << std::endl;
    BFSSolver<N> solver2(board);
    assert(solver2.solve());

    std::cout << std::endl;
}

int main() {
    std::vector<std::string> data;
    data.emplace_back("../testcases/puzzle.8.1.in");
    data.emplace_back("../testcases/puzzle.8.2.in");
    data.emplace_back("../testcases/puzzle.8.3.in");
    data.emplace_back("../testcases/puzzle.8.4.in");
    data.emplace_back("../testcases/puzzle.8.5.in");
    for(const auto &i : data) run(i);
    return 0;
}
