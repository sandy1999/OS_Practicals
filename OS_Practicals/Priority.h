#pragma once
class Priority
{
	struct process
	{
		int pid;
		int burst_time;
		int waiting_time;
		int completion_time = 0;
		int arrival_time;
		int priority;
	};

	typedef	process Process;
public:
	Priority();
	void sort_by_priority(Process p[], int n);
	void non_preemtive_scheduling();
	void calculate_total_burst_time(Process p[], int n);
	void compute_completion_time(Process p[], int n);
	void print_process_table(Process p[], int n);
};

