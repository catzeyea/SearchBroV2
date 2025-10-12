#include "KIStuff.hpp"
namespace py = pybind11;

int KIStuff::UserStuff() {
    py::scoped_interpreter guard{}; // startet und beendet Python automatisch
    py::module llm = py::module::import("llm_module");

    std::string prompt = "Hello from C++!";
    std::string output = llm.attr("generate_text")(prompt).cast<std::string>();

    std::cout << output << std::endl;
    return 0;
}
