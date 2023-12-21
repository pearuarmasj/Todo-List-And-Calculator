// Creator: Pearu Järveläinen
#include <iostream> //for input/output
#include <fstream> //for file input/output
#include <vector> //for std::vector which stores tasks in memory
#include <string> //for std::string which stores task names

int main() {
    int Todo();
    int Calculator();
    int choice;
    int return_to_menu;
    std::cout << "Welcome to the Todo List and Calculator Program" << std::endl;
    std::cout << "Please choose from the following options:" << std::endl;
    std::cout << "1. Todo List" << std::endl;
    std::cout << "2. Calculator" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear input buffer
    switch (choice) {
        case 1:
            Todo();
            break;
        case 2:
            Calculator();
            break;
        case 3:
            std::cout << "Thank you for using the Todo List and Calculator Program" << std::endl;
            exit(0);
        default:
            std::cout << "Invalid input" << std::endl;
            main();
    }
}

int Todo() {
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
                continue; //skip the rest of the loop and start the next iteration
            }
            std::cout << "Enter the number of the task to delete: ";
            int taskNumber;
            std::cin >> taskNumber; //read task number from user
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear input buffer
            tasks.erase(tasks.begin() + taskNumber - 1); //delete task from vector 
        } else if (task == "q") { //if user entered 'q'
            break; //exit the loop
        } else { //if user entered anything else
            std::cout << "Invalid input" << std::endl; //print error message
        }
    }

    std::ofstream file_out("todo.txt"); //open file for writing
    for (const auto& task : tasks) { //loop through tasks
        file_out << task << std::endl; //write task to file
    }
    file_out.close(); //close file

    return main(); //return to main menu
}

int Calculator() {
    float num1, num2;
    char operation;
    float result = 0.0f; // Initialize 'result' with a default value

    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter any operator (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    switch(operation) {
        case '+':
            std::cout << num1 + num2;
            break;

        case '-':
            std::cout << num1 - num2;
            break;

        case '*':
            std::cout << num1 * num2;
            break;
        case '/':
        if (num2 != 0) {
            result = static_cast<float>(num1) / static_cast<float>(num2);
            if (result == static_cast<int>(result)) {
                std::cout << "The result is an integer: " << result << std::endl;
                std::cout << "Would you like to return to the main menu? (1 for yes, 2 for no)" << std::endl;
                int return_to_menu;
                std::cin >> return_to_menu;
                switch (return_to_menu) {
                    case 1:
                        main();
                        break;
                    case 2:
                        std::cout << "Thank you for using the Todo List and Calculator Program" << std::endl;
                        exit(0);
                    default:
                        std::cout << "Invalid input" << std::endl;
                        Calculator();
                }
            } else {
                std::cout << "The result is not an integer: " << result << std::endl;
                std::cout << "Would you like to return to the main menu? (1 for yes, 2 for no)" << std::endl;
                int return_to_menu;
                std::cin >> return_to_menu;
                switch (return_to_menu) {
                    case 1:
                        main();
                        break;
                    case 2:
                        std::cout << "Thank you for using the Todo List and Calculator Program" << std::endl;
                        exit(0);
                    default:
                        std::cout << "Invalid input" << std::endl;
                        Calculator();
                }
            }
        } else {
            std::cout << "Error! Division by zero is not allowed." << std::endl;
            std::cout << "Would you like to return to the main menu? (1 for yes, 2 for no)" << std::endl;
            int return_to_menu;
            std::cin >> return_to_menu;
            switch (return_to_menu) {
                case 1:
                    main();
                    break;
                case 2:
                    std::cout << "Thank you for using the Todo List and Calculator Program" << std::endl;
                    exit(0);
                default:
                    std::cout << "Invalid input" << std::endl;
                    Calculator();
            }
        }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    getchar();

    return 0;
}