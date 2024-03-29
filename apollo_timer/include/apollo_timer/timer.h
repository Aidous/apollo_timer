/**
 * Copyright (c) 2019, Chao Wang
 *  All rights reserved.
 *    Files: timer.h
 *      Created by aidous on 19-8-6.
 *        Email: aidous.mr.w@gmail.com
 */

#ifndef UNTITLED4_TIMER_H
#define UNTITLED4_TIMER_H

/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef CYBER_TIME_TIME_H_
#define CYBER_TIME_TIME_H_

#include <limits>
#include <string>

#include "duration.h"

namespace apollo {
    namespace cyber {

        class Time {
        public:
            static const Time MAX;
            static const Time MIN;
            Time() {}
            explicit Time(uint64_t nanoseconds);
            explicit Time(int nanoseconds);
            explicit Time(double seconds);
            Time(uint32_t seconds, uint32_t nanoseconds);
            Time(const Time& other);
            Time& operator=(const Time& other);
            ~Time() {}

            static Time Now();
            static Time MonoTime();
            static void SleepUntil(const Time& time);

            double ToSecond() const;
            uint64_t ToNanosecond() const;
            std::string ToString() const;
            bool IsZero() const;

            Duration operator-(const Time& rhs) const;
            Time operator+(const Duration& rhs) const;
            Time operator-(const Duration& rhs) const;
            Time& operator+=(const Duration& rhs);
            Time& operator-=(const Duration& rhs);
            bool operator==(const Time& rhs) const;
            bool operator!=(const Time& rhs) const;
            bool operator>(const Time& rhs) const;
            bool operator<(const Time& rhs) const;
            bool operator>=(const Time& rhs) const;
            bool operator<=(const Time& rhs) const;

        private:
            uint64_t nanoseconds_ = 0;
        };

        std::ostream& operator<<(std::ostream& os, const Time& rhs);

    }  // namespace cyber
}  // namespace apollo

#endif  // CYBER_TIME_TIME_H_


#endif //UNTITLED4_TIMER_H
