# OS-Scheduler-Simulation

This project provides a comprehensive Operating Systems process scheduling and memory management simulator built in C. It includes the simulation of different scheduling algorithms, a system clock, inter-process communication (IPC), and buddy-system memory allocation.

## Features

- **Process Scheduling Algorithms:**
  - Shortest Job First (SJF)
  - Pre-emptive Highest Priority First (PHPF)
  - Round Robin (RR)
- **Memory Management:**
  - Dynamic memory allocation using the Buddy System algorithm up to a limit of 1024 bytes.
- **Inter-Process Communication (IPC):**
  - Utilizes Message Queues, Shared Memory, and Signals to coordinate synchronization between the Process Generator, Clock, Scheduler, and individual processes.
- **Performance Evaluation:**
  - Logs scheduling events and memory allocations.
  - Generates detailed performance metrics including CPU utilization, Turnaround Time (TA), Weighted Turnaround Time (WTA), and waiting time.

## Project Structure

- **`Process Generator/`**: Reads `processes.txt`, asks the user for the preferred scheduling algorithm, and dispatches processes to the Scheduler via Message Queues at their specified arrival times.
- **`Scheduler/`**: The core component that receives processes, allocates memory for them via the Buddy System, and schedules them for execution based on the selected algorithm using signals (`SIGSTOP`, `SIGCONT`, `SIGKILL`).
- **`Clock/`**: Emulates a synchronized system clock using shared memory.
- **`Process/`**: Represents an executing process. It loops to simulate CPU burst time synchronized with the system clock.
- **`Test Generator/`**: A utility program that generates random processes and outputs them to `processes.txt` to serve as test cases.
- **`headers.h`**: Common structs and IPC key configurations.
- **`Makefile`**: Compilation commands.

## Getting Started

### Prerequisites

Ensure you have a C compiler (`gcc`) and `make` installed on your Linux-based system.

### Compilation

Build all components using the provided Makefile:

```bash
make build
```

To clean the compiled binaries and outputs:

```bash
make clean
```

### Execution

1. **Generate Test Data (Optional):**

   Run the test generator to create a set of randomized processes:
   ```bash
   ./test_generator.out
   ```
   *You'll be prompted to enter the number of processes to generate.*

2. **Run the Simulation:**

   Start the process generator which initializes the simulation:
   ```bash
   make run
   # OR
   ./process_generator.out
   ```

   The program will prompt you to select a scheduling algorithm:
   - `1`: SJF
   - `2`: Pre-emptive HPF
   - `3`: Round Robin *(will ask for a time quantum)*

### Outputs

After simulation completes, the following files are produced for analysis:
- **`scheduler.log`**: Traces the process states (started, stopped, resumed, finished).
- **`mem.log`**: Traces memory allocation and deallocation for processes.
- **`scheduler.perf`**: Summarizes CPU Utilization, Average WTA, Average Waiting Time, and Standard Deviation of WTA.
