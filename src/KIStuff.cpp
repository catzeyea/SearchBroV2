#include "KIStuff.hpp"
#include <pybind11/embed.h>
#include <iostream>
#include <filesystem>
#include <string>
namespace py = pybind11;
namespace fs = std::filesystem;
int KIStuff::UserStuff() {
    static py::scoped_interpreter guard{}; 
    py::module sys = py::module::import("sys");

    //Path to Python Scripts
    auto build_path = fs::current_path();
    auto python_path = build_path.parent_path() / "src" / "KI";

    sys.attr("path").attr("append")(python_path.string());

    // Load Python Script
    py::module llm = py::module::import("llm_module");

    std::string userInput;
    
    while (true) {
        
        std::cout << "Du > ";
        std::getline(std::cin, userInput);
        if (userInput == "exit") break;

        std::string output = llm.attr("generate_text")(userInput).cast<std::string>();
        std::cout << "KI > " << output << "\n";
    }
    return 0;
}