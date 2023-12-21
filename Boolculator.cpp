#include <iostream> //for input/output
#include <fstream> //for file input/output
#include <vector> //for std::vector which stores tasks in memory
#include <string> //for std::string which stores task names in memory

bool handleTodoList() {
    std::vector<std::string> tasks; //vector to store tasks
    std::string task; //string to store task name
    std::ifstream file("todo.txt"); //open file for reading

    while(std::getline(file, task)) { //read each line from file
        tasks.push_back(task); //add line to vector
    }
    file.close(); //close file

    while (true) { //Loop forever
        std::cout << "Todo List" << std::endl;
        std::cout << "---------" << std::endl;
        for (int i = 0; i < tasks.size(); i++) { //loop through tasks
            std::cout << i + 1 << ". " << tasks[i] << std::endl; //print task
        }
        std::cout << std::endl;
        std::cout << "Enter 'a' to add a task to the list, 'd' to delete a task, or 'q' to quit to main menu: ";
        std::getline(std::cin, task); //read task from user

        if (task == "a") { //if user entered 'a'
            std::cout << "Enter task to add to the list: ";
            std::getline(std::cin, task); //read task from user
            tasks.push_back(task); //add task to vector
        } else if (task == "d") { //if user entered 'd'
            if (tasks.empty()) { //if there are no tasks
                std::cout << "There are no tasks to delete" << std::endl; //print error message
            } else { //if there are tasks
                std::cout << "Enter task number to delete: ";
                std::getline(std::cin, task); //read task number from user
                int task_number = std::stoi(task); //convert task number to int
                if (task_number > 0 && task_number <= tasks.size()) { //if task number is valid
                    tasks.erase(tasks.begin() + task_number - 1); //delete task
                } else { //if task number is invalid
                    std::cout << "Invalid task number" << std::endl; //print error message
                }
            }
        } else if (task == "q") { //if user entered 'q'
            std::ofstream file("todo.txt"); //open file for writing
            for (int i = 0; i < tasks.size(); i++) { //loop through tasks
                file << tasks[i] << std::endl; //write task to file
            }
            file.close(); //close file
            return true;
        } else { //if user entered invalid input
            std::cout << "Invalid input" << std::endl; //print error message
        }
    }
}

bool handleCalculator() {
    std::string num1, num2; //strings to store numbers
    std::cout << "Enter first number: ";
    std::getline(std::cin, num1); //read first number from user
    std::cout << "Enter second number: ";
    std::getline(std::cin, num2); //read second number from user

    float num1_float = std::stof(num1); //convert first number to float
    float num2_float = std::stof(num2); //convert second number to float

    std::cout << "Enter operator (+, -, *, /): ";
    std::string op; //string to store operator
    std::getline(std::cin, op); //read operator from user

    if (op == "+") { //if user entered '+'
        std::cout << num1_float << " + " << num2_float << " = " << num1_float + num2_float << std::endl; //print sum
    } else if (op == "-") { //if user entered '-'
        std::cout << num1_float << " - " << num2_float << " = " << num1_float - num2_float << std::endl; //print difference
    } else if (op == "*") { //if user entered '*'
        std::cout << num1_float << " * " << num2_float << " = " << num1_float * num2_float << std::endl; //print product
    } else if (op == "/") { //if user entered '/'
        std::cout << num1_float << " / " << num2_float << " = " << num1_float / num2_float << std::endl; //print quotient
    } else { //if user entered invalid input
        std::cout << "Invalid input" << std::endl; //print error message
    }
    return true;
}

int main() {
    while (true) { //Loop forever
        std::cout << "Main Menu" << std::endl;
        std::cout << "---------" << std::endl;
        std::cout << "Enter 't' to use the todo list, 'c' to use the calculator, or 'q' to quit: ";
        std::string input; //string to store user input
        std::getline(std::cin, input); //read user input from user

        if (input == "t") { //if user entered 't'
            if (handleTodoList()) { //if user quit to main menu
                continue; //skip the rest of the loop and start the next iteration
            }
        } else if (input == "c") { //if user entered 'c'
            if (handleCalculator()) { //if user quit to main menu
                continue; //skip the rest of the loop and start the next iteration
            }
        } else if (input == "q") { //if user entered 'q'
            break; //exit the loop
        } else { //if user entered invalid input
            std::cout << "Invalid input" << std::endl; //print error message
        }
    }
    return 0; //exit program
}