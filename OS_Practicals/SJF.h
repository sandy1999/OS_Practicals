#pragma once
class SJF
{
	struct process
	{
		int pid;
		int burst_time;
		int waiting_time;
		int completion_time=0;
		int arrival_time;
	};

	typedef	process Process;
public:
	SJF();
	~SJF();
	void sort_by_burst_time(Process p[], int n);
	void sort_by_pid(Process p[], int n);
	void schedule_preemtive();
	void print_gantt_chart(Process p[], int n);
	void calculate_total_burst_time(Process p[], int n);
	void copy_array(Process p1[],Process p2[], int n);
};

