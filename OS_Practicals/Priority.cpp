#include "stdafx.h"
#include "Priority.h"
#include <iostream>
#define MAX_PROCESS 100

using namespace std;

Priority::Priority()
{
}

void Priority::sort_by_priority(Process p[], int n)
{
	Process temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (p[j].priority < p[j + 1].priority)
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}

void Priority::non_preemtive_scheduling()
{	
	int n;
	Process p[MAX_PROCESS];
	cout << "Enter number of process";
	cin >> n;
	cout << "Enter burst time and priority for each process \n";
	for (int i = 0; i < n; i++)
	{
		cout << "P[" << i + 1 << "]";
		cin >> p[i].burst_time;
		p[i].pid = i + 1;
		p[i].arrival_time = i;
		cout << "Priority";
		cin >> p[i].priority;
	}

	compute_completion_time(p, n);
	print_process_table(p, n);
}

void Priority::compute_completion_time(Process p[], int n) 
{
	int count_time = 0;
	sort_by_priority(p, n);
	for (int i = 0 ; i < n; i++)
	{
		p[i].completion_time = count_time + p[i].burst_time;
		count_time += p[i].burst_time;
	}
}

void Priority::print_process_table(Process p[], int n)
{
	cout << "Process id" << "\t Priority" << "\t Burst Time" << "\t Completion Time" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "P[" << p[i].pid << "]\t\t" << p[i].priority << "\t\t" << p[i].burst_time << "\t\t" << p[i].completion_time << endl;
	}
}