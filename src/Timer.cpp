//
// Created by younes.benhoumich on 11/02/2018.
//
#include "Timer.hpp"

void Timer::SleepAndRun() {
    std::this_thread::sleep_for(interval);
    if(Alive){
        Function()();
    }
}

void Timer::ThreadFunc() {
    if(CallNumber == Infinite){
        while(Alive){
            SleepAndRun();
        }
    } else{
        while (repeat_count--){
            SleepAndRun();
        }
    }
}

Timer::Timer(std::function<void(void)> &f): funct(f) {

}

Timer::Timer(std::function<void(void)> &f,
             const unsigned long &i, const long repeat): funct(f),
                                                         interval(std::chrono::milliseconds(i)),
                                                         CallNumber(repeat) {

}

void Timer::Start(bool async) {
    if(IsAlive()){
        return;
    }
    Alive = true;
    repeat_count = CallNumber;
    if(async){
        Thread = std::thread(ThreadFunc, this);
    } else{
        this->ThreadFunc();
    }
}

void Timer::Stop(){
    Alive = false;
    Thread.join();
}

bool Timer::IsAlive() {
    return Alive;
}

void Timer::RepeatCount(const long r) {
    if(Alive){
        return;
    }
    CallNumber = r;
}

void Timer::SetFunction(const std::function<void(void)> &f) {
    funct = f;
}

long Timer::GetLeftCount() const {
    return repeat_count;
}

long Timer::RepeatCount() const {
    return CallNumber;
}

void Timer::SetInterval(const unsigned long &i) {
    if(Alive){
        return;
    }
    interval = std::chrono::milliseconds(i);
}

unsigned long Timer::Interval() const {
    return interval.count();
}

const std::function<void(void)>& Timer::Function() const {
    return funct;
}