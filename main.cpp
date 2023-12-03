#include <iostream>
#include <vector>
#include <string>
#include <fstream>


class ToDoList {
private:
    std::vector<std::string> tasks;
    std::string filename = "tasks.txt"; // File to store tasks


public:
 void loadTasks() {
        std::ifstream file(filename);
        std::string task;
        while (getline(file, task)) {
            if (!task.empty()) {
                tasks.push_back(task);
            }
        }
        file.close();
    }

    void saveTasks() const {
        std::ofstream file(filename);
        for (const auto& task : tasks) {
            file << task << std::endl;
        }
        file.close();
    }
    void addTask(const std::string& task) {
        tasks.push_back(task);
    }

    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
        }
    }

    void showTasks() const {
        for (int i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i] << std::endl;
        }
    }
};

int main() {
    ToDoList myList;
    std::string input;
    int choice;
    myList.loadTasks();

    while (true) {
        std::cout << "\nTo-Do List\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Remove Task\n";
        std::cout << "3. Show Tasks\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter a task: ";
                std::cin >> input;
                myList.addTask(input);
                myList.saveTasks();
                break;
            case 2:
                std::cout << "Enter task number to remove: ";
                std::cin >> choice;
                myList.removeTask(choice - 1);
                myList.saveTasks();
                break;
            case 3:
                myList.showTasks();
                break;
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
