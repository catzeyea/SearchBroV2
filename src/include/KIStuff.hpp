#pragma once
#include <string>

// #define PY_SSIZE_T_CLEAN
// #undef slots
// #undef signals
// #include <Python.h>
// #include <pybind11/embed.h>
// #include <iostream>

// namespace py = pybind11;

class KIStuff {
    public:
    // Call the Python function
        int UserStuff(std::string& inputFieldText);

};
