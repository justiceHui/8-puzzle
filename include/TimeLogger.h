//
// Created by jeounghui on 2021-06-18.
//

#ifndef PUZZLE_TIMELOGGER_H
#define PUZZLE_TIMELOGGER_H

#include <iostream>
#include <chrono>

class TimeLogger{
public:
    TimeLogger(){ start = getTime(); }
    ~TimeLogger(){ end = getTime(); std::cout << "time : " << getDuration() << " ms" << std::endl; }
private:
    std::chrono::system_clock::time_point start, end;
    std::chrono::system_clock::time_point getTime(){
        return std::chrono::system_clock::now();
    }
    unsigned getDuration(){
        return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    }
};

#endif //PUZZLE_TIMELOGGER_H
