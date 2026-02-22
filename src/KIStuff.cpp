/**
 * @brief Disables Qt macros that could collide with C++ keywords.
 *
 * QT_NO_KEYWORDS prevents Qt from defining macros like "signals", "slots", and
 * "emit" as preprocessor definitions. This allows these terms to be used as
 * regular variable or function names in C++ code. Instead of "signals",
 * "Q_SIGNALS" must be used.
 */
#define QT_NO_KEYWORDS //
#include "KIStuff.hpp"
#include "Colors.hpp"
#include <QDebug>
#include <filesystem>
#include <iostream>
#include <pybind11/embed.h>
#include <string>
// std::string& inputFieldText
using namespace color;
namespace py = pybind11;
namespace fs = std::filesystem;

int KIStuff::UserStuff(std::string &inputFieldText) {
  static py::scoped_interpreter guard{};
  py::module sys = py::module::import("sys");

  // Path to Python Scripts
  auto build_path = fs::current_path();
  auto python_path = build_path.parent_path() / "src" / "KI";

  sys.attr("path").attr("append")(python_path.string());

  // Load Python Script
  py::module llm = py::module::import("llm_module");

  // std::string userInput;

  std::cout << "Your input >>> " << green << inputFieldText << reset << "\n";

  output = llm.attr("generate_text")(inputFieldText).cast<std::string>();
  std::cout << "KI > " << bright_cyan << output << reset << "\n";
  return 0;
}

// void KIStuff::setOutput(const std::string& text) {
//     output = text;
// }

std::string KIStuff::getOutput() const {
  // Access the output from UserStuff
  // std::cout << output << std::endl;
  return output;
}

void KIStuff::processOutput(std::string &inputFieldText) {
  // Process the output as needed
  std::cout << "Processed Output: " << inputFieldText << std::endl;
}
