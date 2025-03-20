#include <stdio.h>

struct Process {
    int id, bt, priority, wt, tat, ct, rem_bt, at;  // Added arrival time (at)
};

// Function to find waiting time for non-preemptive priority scheduling
void findWaitingTimeNonPreemptive(struct Process p[], int n) {
    p[0].wt = 0;
    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }
}

// Function to find waiting time for preemptive priority scheduling with arrival time
void findWaitingTimePreemptive(struct Process p[], int n) {
    int completed = 0, t = 0; // Time starts at 0
    int check[n]; // Keeps track of whether a process is completed
    for (int i = 0; i < n; i++) {
        check[i] = 0;  // 0 means the process has not been completed
        p[i].rem_bt = p[i].bt;  // Initialize remaining burst time for preemptive scheduling
    }

    while (completed < n) {
        int max_priority = 9999, idx = -1;

        // Find process with highest priority that has arrived and not completed
        for (int i = 0; i < n; i++) {
            // Check if process has arrived and has remaining burst time
            if (check[i] == 0 && p[i].rem_bt > 0 && p[i].at <= t && p[i].priority < max_priority) {
                max_priority = p[i].priority;
                idx = i;
            }
        }

        if (idx != -1) {
            // Process the selected process
            p[idx].rem_bt--;  // Decrease the remaining burst time of the selected process
            t++;  // Increment time
            if (p[idx].rem_bt == 0) {
                check[idx] = 1;  // Mark the process as completed
                completed++;  // Increment the completed process count
                p[idx].ct = t;  // Completion time is the current time
                p[idx].wt = p[idx].ct - p[idx].bt - p[idx].at;  // Waiting time = Completion time - Burst time - Arrival time
            }
        } else {
            t++;  // If no process is ready to execute, increment time (idle CPU)
        }
    }
}

// Function to calculate turnaround time for each process
void findTurnAroundTime(struct Process p[], int n) {
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;  // Turnaround time = Completion time - Arrival time
    }
}

// Function to print the result
void printResults(struct Process p[], int n) {
    float totalWT = 0, totalTAT = 0, totalCT = 0;
    printf("\nProcess\tBT\tPriority\tAT\tWT\tTAT\tCT\n");
    for (int i = 0; i < n; i++) {
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
        totalCT += p[i].ct;
        printf("P%d\t%d\t%d\t\t%d\t%d\t%d\t%d\n", p[i].id, p[i].bt, p[i].priority, p[i].at, p[i].wt, p[i].tat, p[i].ct);
    }
    printf("\nAverage WT = %.2f\n", totalWT / n);
    printf("Average TAT = %.2f\n", totalTAT / n);
    printf("Average CT = %.2f\n", totalCT / n);
}

// Function to sort processes by priority (used for non-preemptive scheduling)
void sortByPriority(struct Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].priority > p[j].priority) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}



int main() {
    int n, choice;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];

    // Input burst time, priority, and arrival time for each process
    for (int i = 0; i < n; i++) {
        printf("Enter BT, Priority & Arrival Time for P%d: ", i + 1);
        p[i].id = i + 1;
        scanf("%d %d %d", &p[i].bt, &p[i].priority, &p[i].at);
    }

    printf("\nChoose scheduling algorithm:\n");
    printf("1. Non-Preemptive Priority Scheduling\n");
    printf("2. Preemptive Priority Scheduling\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        sortByPriority(p, n);  // Sort processes by priority for non-preemptive scheduling
        findWaitingTimeNonPreemptive(p, n);
        for (int i = 0; i < n; i++) {
            p[i].ct = p[i].wt + p[i].bt + p[i].at;  // Completion time = Waiting time + Burst time + Arrival time
        }
    } else if (choice == 2) {
        findWaitingTimePreemptive(p, n);
    } else {
        printf("Invalid choice!\n");
        return 0;
    }

    findTurnAroundTime(p, n);
    printResults(p, n);

    return 0;
}