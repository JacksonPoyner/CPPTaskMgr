#include <iostream>
#include <string>

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

    void completeTask(Task task)
    {
        task(name, description, true);
    }
};