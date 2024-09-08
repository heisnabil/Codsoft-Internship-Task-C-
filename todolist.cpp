#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isCompleted;
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& taskDescription) {
        Task newTask;
        newTask.description = taskDescription;
        newTask.isCompleted = false;
        tasks.push_back(newTask);
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].isCompleted) {
                cout << " [Completed]";
            }
            cout << endl;
        }
    }

    void markTaskAsCompleted(int taskIndex) {
        if (taskIndex > 0 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].isCompleted = true;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void removeTask(int taskIndex) {
        if (taskIndex > 0 && taskIndex <= tasks.size()) {
            tasks.erase(tasks.begin() + (taskIndex - 1));
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main() {
    ToDoList myToDoList;
    bool running = true;

    while (running) {
        cout << "\n---- TO-DO LIST MANAGER ----" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";
        
        int choice;
        cin >> choice;
        cin.ignore();  // Ignore newline after input

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter task description: ";
                getline(cin, task);
                myToDoList.addTask(task);
                break;
            }
            case 2:
                myToDoList.viewTasks();
                break;
            case 3: {
                int taskNum;
                cout << "Enter task number to mark as completed: ";
                cin >> taskNum;
                myToDoList.markTaskAsCompleted(taskNum);
                break;
            }
            case 4: {
                int taskNum;
                cout << "Enter task number to remove: ";
                cin >> taskNum;
                myToDoList.removeTask(taskNum);
                break;
            }
            case 5:
                running = false;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    cout << "Exiting to-do list manager." << endl;
    return 0;
}
