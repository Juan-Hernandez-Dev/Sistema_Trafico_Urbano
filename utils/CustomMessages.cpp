#include <chrono>
#include <iostream>
#include <thread>
#include "CustomMessages.h"

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

void cls() {
    system("cls");
}

void Jump() {
    std::cout << std::endl;
}

void Pause(const int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void Header(const std::string& message) {
    std::cout << BOLD << GREEN << message << RESET << std::endl;
}

void SubHeader(const std::string& message) {
    std::cout << GREEN << message << RESET << std::endl;
}

void Msg(const std::string& message) {
    std::cout << message << std::endl;
}

void MsgLoading(const std::string& message, int cycles, bool clear_after) {
    std::cout << std::endl;
    for (int i = 0; i < cycles; ++i) {
        std::cout << CYAN << BOLD << "[INFO]: " << RESET << message;
        for (int j = 0; j < 3; ++j) {
            std::cout << ".";
            std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        std::cout << "\r" << std::string(50, ' ') << "\r"; // Clear line
    }
    if(clear_after) {
        cls();
    }
}

void MsgModuleLoad(const std::string& module_name, bool* state_variable, const std::string& message, int cycles, bool clear_after) {
    if (*state_variable) {
        Header(module_name);
        MsgLoading(message, cycles, clear_after);
        *state_variable = false;  // <-- modifies the original flag
    }
    SubHeader(module_name);
}

void MsgSuccess(const std::string& message) {
    std::cout << BOLD << GREEN << "[SUCCESS] " << RESET << message << std::endl;
}

void MsgError(const std::string& message) {
    std::cout << BOLD << RED << "[ERROR] " << RESET << message << std::endl;
}

void MsgWarning(const std::string& message) {
    std::cout << BOLD << YELLOW << "[WARNING] " << RESET << message << std::endl;
}

void MsgInfo(const std::string& message) {
    std::cout << BOLD << CYAN << "\n[INFO] " << RESET << message << std::endl;
}

// template <typename AnyType>
void Prompt(const std::string& message) {
    std::cout << message << ": ";
}