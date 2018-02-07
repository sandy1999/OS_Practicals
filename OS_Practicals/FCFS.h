#pragma once
class FCFS
{
public:
	FCFS();
	~FCFS();
	float getBurstAverage(int p1,int p2, int p3);
	int showBurstTimes();
	int showBurstAndArrivalTimes();
	int showArrivalTimes(int p1, int p2, int p3);
};
