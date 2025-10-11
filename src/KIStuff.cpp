#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <pybind11/embed.h>
#include <iostream>
#include "KIStuff.hpp"
namespace py = pybind11;

int UserStuff() {
    py::scoped_interpreter guard{}; // start Python interpreter

    // Import your Python LLM module
    py::module llm = py::module::import("llm_module");

    // Call the Python function
    std::string prompt = "Hello from C++!";
    py::object result = llm.attr("generate_text")(prompt);

    // Convert Python result to C++ string
    std::string output = result.cast<std::string>();

    std::cout << output << std::endl;

    return 0;
}
