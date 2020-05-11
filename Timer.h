#ifndef TIMER_H
#define TIMER_H

class Timer {
private:
	int time_per_tick;
	int open_time;
	int close_time;
	int actual_time;
public:
	Timer(int _time_per_tick, int _open_time, int _close_time);

	int getTimePerTick();
	int getOpenTime();
	int getCloseTime();
	int getActualTime();

	void setTimePerTick(int _time_per_tick);
	void getOpenTime(int _open_time);
	void getCloseTime(int _close_time);
};

#endif