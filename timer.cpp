#include <iostream>
#include <thread> 
#include <chrono>
#include "Timer.h"

using namespace std;

void wait_for_a_few_seconds(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}

int main() {
    Timer timer;

    cout << "Starting timer..." << endl;
    timer.start();

    wait_for_a_few_seconds(5);

    timer.stop();
    cout << "Stopping timer..." << endl;

    int elapsed = timer.elapsed();
    cout << "Elapsed time: " << elapsed << " seconds" << endl;

    return 0;
}
