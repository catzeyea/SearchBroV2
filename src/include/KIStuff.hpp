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
    private:
        std::string output;
    public:
        std::string getOutput() const;
        //void setOutput(const std::string& inputFieldText);


    // Call the Python function
        int UserStuff(std::string& inputFieldText);
        void processOutput(std::string& inputFieldText);;
   
};
