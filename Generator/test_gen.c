#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../Process/process.h"

void generate_processes(int num_processes, const char *filename);
int compare_processes(const void *a, const void *b);

int main()
{
    int num_processes = 15;
    char filename[256] = "processes.txt";

    srand(time(NULL));

    generate_processes(num_processes, filename);

    return 0;
}

void generate_processes(int num_processes, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        perror("Error creating output file");
        exit(1);
    }

    fprintf(file, "#id\tarrival\truntime\tpriority\n");

    struct process *processes = malloc(num_processes * sizeof(struct process));

    int max_arrival_time = num_processes * 2;

    for (int i = 0; i < num_processes; i++)
    {
        processes[i].id = 0;

        processes[i].arrival = rand() % (max_arrival_time + 1);

        processes[i].runtime = (rand() % 20) + 1;

        processes[i].priority = rand() % 11;
    }

    qsort(processes, num_processes, sizeof(struct process), compare_processes);

    for (int i = 0; i < num_processes; i++)
    {
        processes[i].id = i + 1;
    }

    for (int i = 0; i < num_processes; i++)
    {
        fprintf(file, "%d\t%d\t%d\t%d\n",
                processes[i].id,
                processes[i].arrival,
                processes[i].runtime,
                processes[i].priority);
    }

    free(processes);
    fclose(file);
}

int compare_processes(const void *a, const void *b)
{
    struct process *proc_a = (struct process *)a;
    struct process *proc_b = (struct process *)b;

    if (proc_a->arrival != proc_b->arrival)
    {
        return proc_a->arrival - proc_b->arrival;
    }
    return 0;
}
