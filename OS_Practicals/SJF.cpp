#include "stdafx.h"
#include "SJF.h"
#include<iostream>
#define MAX_PROCESS 100
using namespace std;

int total_burst_time;
SJF::SJF()
{
}



SJF::~SJF()
{
}

void SJF::schedule_preemtive()
{
	Process p[MAX_PROCESS];
	int n;
	puts("Enter total number of process \n");
	cin >> n;
	cout << "Enter burst time for each process \n";
	for (int i = 0; i < n; i++)
	{
		cout << "P[" << i + 1 << "]";
		cin >> p[i].burst_time;
		p[i].pid = i + 1;
		p[i].arrival_time = i;
	}
	calculate_total_burst_time(p, n);

	cout << total_burst_time;
	cout << "\n Gantt Chart\n";
	print_gantt_chart(p, n);
}


void SJF::sort_by_burst_time(Process p[], int n)
{
	Process temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (p[j].burst_time > p[j + 1].burst_time)
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}

void SJF::sort_by_pid(Process p[], int n)
{
	Process temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (p[j].pid> p[j + 1].pid)
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}

void SJF::calculate_total_burst_time(Process p[], int n)
{
	total_burst_time = 0;
	for (int i = 0; i < n; i++)
	{
		total_burst_time += p[i].burst_time;
	}
}

void SJF::print_gantt_chart(Process p[], int n)
{
	Process p_ct[MAX_PROCESS];
	copy_array(p, p_ct, n);

	int count_time = 0;
	while (count_time <= total_burst_time)
	{
		count_time++;
		if (count_time <= n)
		{
			for(int i = 0 ; i < n;i++)
			{
				if (i==count_time)
				{
					count_time++;
					for (int j = 0; j < i; j++)
					{
						if (count_time > p[j].arrival_time && p[j].burst_time != 0)
						{
							p[j].burst_time--;
							p[j].completion_time = count_time;
						}
					}
				}
			}
		}
		else
		{
			while (count_time <=total_burst_time)
			{
				sort_by_burst_time(p, n);
				for (int i = 0; i < n;i++)
				{
					sort_by_burst_time(p, n);
					if (p[i].burst_time != 0 && count_time > n)
					{
						p[i].completion_time = count_time + p[i].burst_time;
						count_time += p[i].burst_time;
						p[i].burst_time -= p[i].burst_time;
					}
				}
			}
		}
	}

	sort_by_pid(p, n);
	for (int i = 0; i < n; i++)
	{
		if (p_ct[i].pid == p[i].pid)
		{
			p[i].burst_time = p_ct[i].burst_time;
		}
	}

	cout << "Complete Gantt Chart\n";

	for (int i = 0; i < n; i++)
	{
		cout << "P[" << p[i].pid << "]\t" << p[i].burst_time << "\t" << p[i].completion_time << endl;
	}
}

void SJF::copy_array(Process p1[],Process p2[], int n)
{
	for (int i = 0; i < n; i++)
	{
		p2[i] = p1[i];
	}
}