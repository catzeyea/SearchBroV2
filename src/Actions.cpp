#include "Actions.hpp"
#include "Colors.hpp"
#include <pybind11/embed.h>
#include <iostream>
#include <filesystem>
#include <string>
#include <QDebug>
#include "ai/Communication.hpp"
// std::string& inputFieldText
using namespace color;
namespace py = pybind11;
namespace fs = std::filesystem;

int Actions::UserRequest(std::string &inputFieldText) {
    Communication com;
    std::cout << "Your input >>> " << green << inputFieldText << reset << "\n";
    output = com.GetMessage(inputFieldText);
    std::cout << "KI > " << bright_cyan << output << reset << "\n";
    return 0;
}

// void Actions::setOutput(const std::string& text) {
//     output = text;
// }

std::string Actions::getOutput() const { return output; }

void Actions::processOutput(std::string &inputFieldText)
{
    // Process the output as needed
    std::cout << "Processed Output: " << inputFieldText << std::endl;
}
