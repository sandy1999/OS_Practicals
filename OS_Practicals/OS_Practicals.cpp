// OS_Practicals.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FCFS.h"
#include "SJF.h"
#include<iostream>
using namespace std;
int main()
{
	//FCFS fcfs;
	SJF sjf;
	sjf.schedule_preemtive();
	//fcfs.showBurstAndArrivalTimes();
    return 0;
}

