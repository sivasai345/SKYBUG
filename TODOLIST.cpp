#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    std::string description;
    bool completed;
};

// Function prototypes
void addTask(std::vector<Task> &tasks, const std::string &description);
void viewTasks(const std::vector<Task> &tasks);
void markTaskAsCompleted(std::vector<Task> &tasks, const std::string &description);
void removeTask(std::vector<Task> &tasks, const std::string &description);

int main() {
    std::vector<Task> tasks;

    char choice;
    do {
        std::cout << "\n==== ToDo List Manager ====\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                std::string taskDescription;
                std::cout << "Enter task description: ";
                std::cin.ignore(); // Clear the newline character from the buffer
                std::getline(std::cin, taskDescription);
                addTask(tasks, taskDescription);
                break;
            }
            case '2':
                viewTasks(tasks);
                break;
            case '3': {
                std::string taskDescription;
                std::cout << "Enter task description to mark as completed: ";
                std::cin.ignore();
                std::getline(std::cin, taskDescription);
                markTaskAsCompleted(tasks, taskDescription);
                break;
            }
            case '4': {
                std::string taskDescription;
                std::cout << "Enter task description to remove: ";
                std::cin.ignore();
                std::getline(std::cin, taskDescription);
                removeTask(tasks, taskDescription);
                break;
            }
            case '5':
                std::cout << "Quitting the ToDo List Manager. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != '5');

    return 0;
}

void addTask(std::vector<Task> &tasks, const std::string &description) {
    Task newTask{description, false};
    tasks.push_back(newTask);
    std::cout << "Task added: " << description << "\n";
}

void viewTasks(const std::vector<Task> &tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
    } else {
        std::cout << "\n==== Task List ====\n";
        for (const auto &task : tasks) {
            std::cout << "- " << task.description << " [" << (task.completed ? "Completed" : "Pending") << "]\n";
        }
    }
}

void markTaskAsCompleted(std::vector<Task> &tasks, const std::string &description) {
    auto it = std::find_if(tasks.begin(), tasks.end(),
                           [&description](const Task &task) { return task.description == description; });

    if (it != tasks.end()) {
        it->completed = true;
        std::cout << "Task marked as completed: " << description << "\n";
    } else {
        std::cout << "Task not found.\n";
    }
}

void removeTask(std::vector<Task> &tasks, const std::string &description) {
    auto it = std::remove_if(tasks.begin(), tasks.end(),
                             [&description](const Task &task) { return task.description == description; });

    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        std::cout << "Task removed: " << description << "\n";
    } else {
        std::cout << "Task not found.\n";
    }
}
