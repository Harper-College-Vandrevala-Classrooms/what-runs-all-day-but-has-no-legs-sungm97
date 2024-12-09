#pragma once

#include <chrono>
#include <stdexcept>

using namespace std;

class Timer {
private:
    chrono::time_point<chrono::steady_clock> startTime;
    chrono::time_point<chrono::steady_clock> endTime;
    bool running = false;
    bool started = false;

public:
    Timer() : running(false), started(false) {}

    void start() {
        if (!running) {
            startTime = chrono::steady_clock::now();
            running = true;
            started = true;
        }
    }

    void stop() {
        if (running) {
            endTime = chrono::steady_clock::now();
            running = false;
        }
    }

    int elapsed() const {
        if (!started) {
            return 0;
        } else if (running) {
            auto current = chrono::steady_clock::now();
            return chrono::duration_cast<chrono::seconds>(current - startTime).count();
        } else {
            return chrono::duration_cast<chrono::seconds>(endTime - startTime).count();
        }
    }
};

