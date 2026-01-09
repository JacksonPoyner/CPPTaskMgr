#include <iostream>
#include <string>
#include <vector>

int main()
{
    int userChoice;
    std::vector<Task> taskVector;
    std::cout << "Welcome to my task manager program!" << "\n"
              << "In this program you can create and complete tasks as you please." << "\n";
    std::cout << "What would you like to do?" << "\n";
    std::cout << "0. Create task" << "\n"
              << "1. List tasks" << "\n"
              << "2. Complete task" << "\n"
              << "3. Delete task" << "\n"
              << "4. Quit" << "\n";
    std::cin >> userChoice;
    if (userChoice == 0)
    {
    }
    else if (userChoice == 1)
    {
    }
    else if (userChoice == 2)
    {
    }
    else if (userChoice == 3)
    {
    }
    else if (userChoice == 4)
    {
    }
    else
    {
    }

    return 0;
}
/**
 * This is a task class that will create an object class with a name, description,
 * and a boolean that controls whether the task is complete or not.
 */
class Task
{
public:
    std::string name;
    std::string description;
    bool finishedTask = false;

    Task(std::string n, std::string d, bool f)
    {
        name = n;
        description = d;
        finishedTask = f;
    }
};

/**
 * This class will be used to create tasks, and mark tasks as complete.
 */
class TaskManager
{
public:
    // A method for creating new incomplete tasks.
    void createTask()
    {
        std::string name;
        std::string description;

        // Prompt the user to enter a new name for the task.
        std::cout << "Enter the name of the task: ";
        std::cin >> name;

        std::cout << "Enter the description of the task: ";
        std::cin >> description;

        Task task(name, description, false);
    }
    // A method for deleting tasks.
    void deleteTask()
    {
    }
};