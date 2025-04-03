/*
University Amerike
Author: Sebastian Arias
Practice: 20
Date: 04/03/25
Description: Create a menu about 5 differents task list that the user can create, eliminate, visualize and leave the programm
*/

#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 5;
string tasks[MAX_TASKS];
int taskCount = 0;

void showMenu();
void addTask();
void deleteTask();
void showTasks();

//This will begin the programm, this will tell the user to select an option, add, delete, show or leave the programm
int main() {
    char option;
    do {
        showMenu();
        cout << "Select an option: ";
        cin >> option;
        cin.ignore();
        
        switch (option) {
            case '1': addTask(); break;
            case '2': deleteTask(); break;
            case '3': showTasks(); break;
            case '4': cout << "Exiting the program...\n"; break;
            default: cout << "Invalid option. Please try again.\n"; break;
        }
        if (option != '4') {
            cout << "Press Enter to return to the menu...";
            cin.get();
        }
    } while (option != '4');
    
    return 0;
}
//This option will show what the user will see and think what to do first
void showMenu() {
    cout << "\n--- TASK MENU ---\n";
    cout << "1. Add task\n";
    cout << "2. Delete task\n";
    cout << "3. View tasks\n";
    cout << "4. Exit\n";
}

//This option will add more task, and if the user surpasses the limit, the programm will tell him that he cant add more task
void addTask() {
    if (taskCount >= MAX_TASKS) {
        cout << "Cannot add more tasks. Limit reached.\n";
        return;
    }
    cout << "Enter the task: ";
    getline(cin, tasks[taskCount]);
    taskCount++;
    cout << "Task added successfully.\n";
}

//This option will delete the task that the user want to eliminate
void deleteTask() {
    if (taskCount == 0) {
        cout << "No tasks to delete.\n";
        return;
    }
    showTasks();
    int index;
    cout << "Enter the number of the task to delete: ";
    cin >> index;
    cin.ignore();
    
    if (index < 1 || index > taskCount) {
        cout << "Invalid number.\n";
        return;
    }
    
    for (int i = index - 1; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    taskCount--;
    cout << "Task deleted successfully.\n";
}
//This option will show how many task the user have
void showTasks() {
    if (taskCount == 0) {
        cout << "No tasks to show.\n";
        return;
    }
    cout << "\nTask list:\n";
    for (int i = 0; i < taskCount; i++) {
        cout << i + 1 << ". " << tasks[i] << "\n";
    }
}

