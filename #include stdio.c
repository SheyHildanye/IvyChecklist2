a#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of tasks
#define MAX_TASKS 100

// Structure to represent a task
struct Task {
    char description[100];
    int completed;
};

// Global array to store tasks
struct Task tasks[MAX_TASKS];
int numTasks = 0;

// Function to add a new task
void addTask() {
    if (numTasks >= MAX_TASKS) {
        printf("Task list is full. Cannot add more tasks.\n");
        return;
    }

    printf("Enter task description: ");
    scanf(" %[^\n]", tasks[numTasks].description);
    tasks[numTasks].completed = 0;
    numTasks++;
}

// Function to mark a task as completed
void markCompleted() {
    int taskIndex;
    printf("Enter the task number to mark as completed (1-%d): ", numTasks);
    scanf("%d", &taskIndex);

    if (taskIndex >= 1 && taskIndex <= numTasks) {
        tasks[taskIndex - 1].completed = 1;
        printf("Task marked as completed!\n");
    } else {
        printf("Invalid task number.\n");
    }
}

// Function to display all tasks
void viewTasks() {
    printf("Task List:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("%d. %s [%s]\n", i + 1, tasks[i].description,
               tasks[i].completed ? "Completed" : "Not Completed");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- To-Do List ---\n");
        printf("1. Add Task\n");
        printf("2. Mark Task as Completed\n");
        printf("3. View Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                markCompleted();
                break;
            case 3:
                viewTasks();
                break;
            case 4:
                printf("Exiting. Have a productive day!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
