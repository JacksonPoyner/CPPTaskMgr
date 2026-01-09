#include <iostream>
#include <string>
#include <vector>

int main() {
  TaskManager taskManager;
  int userChoice;
  std::vector<Task> tasks;
  std::cout
      << "Welcome to my task manager program!" << "\n"
      << "In this program you can create and complete tasks as you please."
      << "\n";
  while (true) {
    std::cout << "What would you like to do?" << "\n";
    std::cout << "0. Create task." << "\n"
              << "1. List tasks." << "\n"
              << "2. Mark a task as complete or incomplete." << "\n"
              << "3. Delete task." << "\n"
              << "4. Quit." << "\n";
    std::cin >> userChoice;

    // Create a new task and add it to the existing vector.
    if (userChoice == 0) {
      Task task = taskManager.createTask();
      tasks.push_back(task);

    } else if (userChoice == 1) {
      int listChoice;

      while (true) {
        std::cout << "How would you like your list to be sorted?" << "\n";
        std::cout << "0. No sort." << "\n"
                  << "1. Incomplete tasks." << "\n"
                  << "2. Complete tasks." << "\n"
                  << "3. Nevermind." << "\n";
        std::cin >> listChoice;

        if (listChoice == 0) {
          std::cout << "Tasks: " << std::endl;

          for (const Task& task : tasks) {
            std::cout << task.name << " " << task.description << " "
                      << " Task complete? " << task.finishedTask << std::endl;
          }

        } else if (listChoice == 1) {
          std::cout << "Incomplete tasks: " << std::endl;

          for (const Task& task : tasks) {
            if (task.finishedTask == false) {
              std::cout << task.name << " " << task.description << " "
                        << " Task complete? " << task.finishedTask << std::endl;
            };
          };
        } else if (listChoice == 2) {
          std::cout << "Complete tasks: " << std::endl;

          for (const Task& task : tasks) {
            if (task.finishedTask == true) {
              std::cout << task.name << " " << task.description << " "
                        << " Task complete? " << task.finishedTask << std::endl;
            };
          };
        } else if (listChoice == 3) {
          std::cout << "Exiting task viewer." << "\n";
          break;
        } else {
          std::cout << "Please input a valid choice." << "\n";
        }
      };

    } else if (userChoice == 2) {
      int taskChoice;
      std::cout << "Tasks: " << std::endl;

      for (const Task& task : tasks) {
        std::cout << task.name << " " << task.description << " "
                  << " Task complete? " << task.finishedTask << std::endl;
      }
      std::cout << "Select a task that you would like to mark as complete or "
                   "incomplete: "
                << "\n";
      std::cin >> taskChoice;
      if (taskChoice < 0 || taskChoice >= tasks.size() - 1) {
        std::cout << "Please select a task that is contained in the list."
                  << "\n";
      } else {
        Task currentTask = tasks.at(taskChoice);
        // If the task is incomplete lets set it to complete.
        if (currentTask.finishedTask == false) {
          currentTask.finishedTask = true;
          std::cout << currentTask.name << " is has been set to complete."
                    << "\n";
          // If the task is complete lets set it to incomplete.
        } else {
          currentTask.finishedTask = false;
          std::cout << currentTask.name << " is has been set to incomplete."
                    << "\n";
        }
      }

    } else if (userChoice == 3) {
    } else if (userChoice == 4) {
      std::cout << "Exiting program." << "\n";
      break;
    } else {
      std::cout << "Please input a valid choice." << "\n";
    }
  };

  return 0;
}
/**
 * This is a task class that will create an object class with a name,
 * description.
 */
class Task {
 public:
  std::string name;
  std::string description;
  bool finishedTask = false;

  Task(std::string n, std::string d, bool f) {
    name = n;
    description = d;
    finishedTask = f;
  }
};

/**
 * This class will be used to create tasks, and mark tasks as complete.
 */
class TaskManager {
 public:
  // A method for creating new incomplete tasks.
  Task createTask() {
    std::string name;
    std::string description;

    // Prompt the user to enter a new name and description for the task being
    // made.
    while (true) {
      std::cout << "Enter the name of the task: " << "\n";
      std::getline(std::cin, name);

      std::cout << "Enter the description of the task: " << "\n";
      std::getline(std::cin, description);
      if (name != "" || description != "") {
        break;
      }
    }
    std::cout << "Successfully created task." << "\n";
    Task task(name, description, false);
    return task;
  }
};