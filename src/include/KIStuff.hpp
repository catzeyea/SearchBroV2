#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <pybind11/embed.h>
#include <iostream>

namespace py = pybind11;

class KIStuff {
    public:
        py::scoped_interpreter guard{}; // start Python interpreter

    // Import your Python LLM module
        py::module llm = py::module::import("llm_module");

    // Call the Python function
        int UserStuff();
};
