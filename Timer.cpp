#include "Timer.h"

Timer::Timer(int _time_per_tick, int _open_time, int _close_time) {
	time_per_tick = _time_per_tick;
	open_time = _open_time;
	close_time = _close_time;
	actual_time = open_time;

	bank = new Bank(10);
}

int Timer::getTimePerTick() {
	return time_per_tick;
}
int Timer::getOpenTime() {
	return open_time;
}
int Timer::getCloseTime() {
	return close_time;
}
int Timer::getActualTime() {
	return actual_time;
}

void Timer::setTimePerTick(int _time_per_tick) {
	time_per_tick = _time_per_tick;
}
void Timer::getOpenTime(int _open_time) {
	open_time = _open_time;
}
void Timer::getCloseTime(int _close_time) {
	close_time = _close_time;
}