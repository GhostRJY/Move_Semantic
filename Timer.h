#pragma once
#include<chrono>

//класс для подсчета времени
class Timer
{
private:

    //определяю type alias для большого названия
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;

    //поле начало отсчета
    std::chrono::time_point<clock_t> m_start;

public:
    //при создании задаю точку отсчета
    Timer() : m_start{ clock_t::now() } {}
    
    //задаю новую точку отсчета
    void reset() {
        m_start = clock_t::now();
    }

    //показываю результат подсчета
    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_start).count();
    }

};

