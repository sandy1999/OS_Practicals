#include "stdafx.h"
#include "FCFS.h"
#include <iostream>
using namespace std;

FCFS::FCFS()
{
}


FCFS::~FCFS()
{
}

float FCFS::getBurstAverage(int p1, int p2, int p3)
{
	int sum_of_process = 0 + p1 * 2 + p2;
	float average_time = (float)sum_of_process / 3;
	return average_time;
}

int FCFS::showBurstTimes()
{
	int process[3];
	cout << "Enter the time of process in respective order";
	for (int i = 0; i < 3; i++)
	{
		cin >> process[i];
	}
	cout << "FCFS of process in order P2,P1,P3 are " << getBurstAverage(process[1], process[0], process[2]) << "ms" << endl;
	cout << "FCFS of process in order P3,P2,P1 are " << getBurstAverage(process[2], process[1], process[0]) << "ms" << endl;
	cout << "FCFS of process in order P1,P2,P3 are " << getBurstAverage(process[0], process[1], process[2]) << "ms" << endl;
	cout << "FCFS of process in order P3,P1,P2 are " << getBurstAverage(process[2], process[0], process[1]) << "ms" << endl;
	return 0;
}
