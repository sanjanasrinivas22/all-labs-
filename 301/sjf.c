#include <stdio.h>
#include <limits.h>


void nonPreemptiveSJF(int n, int arrivalTime[], int burstTime[]) {
    int completed = 0, currentTime = 0;
    int remainingTime[n], completionTime[n], waitingTime[n], turnaroundTime[n];
    for (int i = 0; i < n; i++) {
        remainingTime[i] = burstTime[i];
    }

    while (completed != n) {
        int minIndex = -1;
        int minBurst = INT_MAX;
       
        for (int i = 0; i < n; i++) {
            if (arrivalTime[i] <= currentTime && remainingTime[i] > 0 && burstTime[i] < minBurst) {
                minBurst = burstTime[i];
                minIndex = i;
            }
        }
       
        if (minIndex == -1) {
            currentTime++;
            continue;
        }

        currentTime += burstTime[minIndex];
        completionTime[minIndex] = currentTime;
        remainingTime[minIndex] = 0;
        turnaroundTime[minIndex] = completionTime[minIndex] - arrivalTime[minIndex];
        waitingTime[minIndex] = turnaroundTime[minIndex] - burstTime[minIndex];
        completed++;
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, arrivalTime[i], burstTime[i], completionTime[i], turnaroundTime[i], waitingTime[i]);
    }
}


void preemptiveSJF(int n, int arrivalTime[], int burstTime[]) {
    int completed = 0, currentTime = 0;
    int remainingTime[n], completionTime[n], waitingTime[n], turnaroundTime[n];
    for (int i = 0; i < n; i++) {
        remainingTime[i] = burstTime[i];
    }

    while (completed != n) {
        int minIndex = -1;
        int minRemainingTime = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (arrivalTime[i] <= currentTime && remainingTime[i] > 0 && remainingTime[i] < minRemainingTime) {
                minRemainingTime = remainingTime[i];
                minIndex = i;
            }
        }

        if (minIndex == -1) {
            currentTime++;
            continue;
        }

        remainingTime[minIndex]--;
        currentTime++;
       
        if (remainingTime[minIndex] == 0) {
            completionTime[minIndex] = currentTime;
            turnaroundTime[minIndex] = completionTime[minIndex] - arrivalTime[minIndex];
            waitingTime[minIndex] = turnaroundTime[minIndex] - burstTime[minIndex];
            completed++;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, arrivalTime[i], burstTime[i], completionTime[i], turnaroundTime[i], waitingTime[i]);
    }
}

int main() {
    int n, choice;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int arrivalTime[n], burstTime[n];

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &arrivalTime[i], &burstTime[i]);
    }

    printf("Choose Scheduling Algorithm:\n1. Non-Preemptive SJF\n2. Preemptive SJF (SRTF)\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        nonPreemptiveSJF(n, arrivalTime, burstTime);
    } else {
        preemptiveSJF(n, arrivalTime, burstTime);
    }

    return 0;
}