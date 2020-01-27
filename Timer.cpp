//
//  Timer.cpp
//  SORT
//
//  Created by Kainalu Estrella on 9/25/19.
//  Copyright © 2019 Kainalu Estrella. All rights reserved.
//

#include "Timer.hpp"



void Timer::Start()
{
    start = std::chrono::high_resolution_clock::now();
}

void Timer::End()
{
    end = std::chrono::high_resolution_clock::now();
}

unsigned Timer::DurationInNanoSeconds()
{
    using namespace std::chrono;
    duration<double> time_span = duration_cast<duration<double>>(end - start);
    
    return static_cast<unsigned>(time_span.count() * 1000000000);
}

unsigned Timer::DurationInMicroSeconds()
{
    using namespace std::chrono;
    duration<double> time_span = duration_cast<duration<double>>(end - start);
    
    return static_cast<unsigned>(time_span.count() * 1000000);
}

unsigned Timer::DurationInMilliSeconds()
{
    using namespace std::chrono;
    duration<double> time_span = duration_cast<duration<double>>(end - start);
    
    return static_cast<unsigned>(time_span.count() * 1000);
}
