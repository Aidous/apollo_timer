#include <iostream>
#include "apollo_timer/timor.h"

int main() {
    const double start_timestamp = apollo::common::time::Clock::NowInSeconds();
    printf("a %f", start_timestamp);
    return 0;
}
