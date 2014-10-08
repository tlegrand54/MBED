#include "sonar.h"

Sonar::Sonar(PinName input, Timer& t) :
    interrupt(input),
    time(t),
    pulseStartTime(0),
    range(0) {
    interrupt.rise(this, &Sonar::pulseStart);
    interrupt.fall(this, &Sonar::pulseStop);
}

int Sonar::read() {
    return range;
}

Sonar::operator int() {
    return read();
}

void Sonar::pulseStart() {
    pulseStartTime = time.read_us();
}

void Sonar::pulseStop() {
    int endTime = time.read_us();
    if (endTime < pulseStartTime) return; // Escape if there's been a roll over
    range = (endTime - pulseStartTime) / 58; // 58uS per CM
}