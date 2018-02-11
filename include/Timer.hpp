//
// Created by younes.benhoumich on 11/02/2018.
//

#pragma once

#include <thread>
#include <chrono>
#include <functional>

class Timer {
    std::thread Thread;
    bool Alive = false;
    long CallNumber = -1L;
    long repeat_count = -1L;
    std::chrono::milliseconds interval = std::chrono::milliseconds(0);
    std::function<void(void)> funct = nullptr;

    void SleepAndRun();

    void ThreadFunc();

public:
    static const long Infinite = -1L;
    Timer() {};
    Timer(std::function<void(void)> &f);
    Timer(std::function<void(void)> &f, const unsigned long &i, const long repeat = Timer::Infinite);

    void Start(bool async=true);
    void Stop();
    bool IsAlive();

    void RepeatCount(const long r);

    void SetFunction(const std::function<void(void)> &f);

    long GetLeftCount() const;

    long RepeatCount() const;

    void SetInterval(const unsigned long &i);

    unsigned long Interval() const ;

    const std::function<void(void)>& Function() const;
};
