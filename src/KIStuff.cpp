#include "KIStuff.hpp"
#include "Colors.hpp"
#include <pybind11/embed.h>
#include <iostream>
#include <filesystem>
#include <string>
#include <QDebug>
//std::string& inputFieldText
using namespace color;
namespace py = pybind11;
namespace fs = std::filesystem;
int KIStuff::UserStuff(std::string& inputFieldText) {
    static py::scoped_interpreter guard{}; 
    py::module sys = py::module::import("sys");

    //Path to Python Scripts
    auto build_path = fs::current_path();
    auto python_path = build_path.parent_path() / "src" / "KI";

    sys.attr("path").attr("append")(python_path.string());

    // Load Python Script
    py::module llm = py::module::import("llm_module");

    //std::string userInput;
    

        system("clear");
        std::cout << "Your input >>> " << green << inputFieldText << reset << "\n";

        std::string output = llm.attr("generate_text")(inputFieldText).cast<std::string>();
        std::cout << "KI > " << bright_cyan << output << reset << "\n";
    return 0;
}
