#pragma once
#include <string>

class Actions {
    private:
        std::string output;
    public:
        std::string getOutput() const;
        //void setOutput(const std::string& inputFieldText);


    // Call the Python function
        int UserRequest(std::string& inputFieldText);
        void processOutput(std::string& inputFieldText);;
   
};
