# SearchBroV2

SearchBroV2 is a desktop application built with C++ and Qt6 that provides a simple interface to interact with a local Large Language Model (LLM) powered by Ollama. It uses pybind11 to seamlessly call a Python script from C++ to handle API requests.

## Features

-   *Simple UI*: A clean and straightforward interface with an input field for your prompts and an output field for the LLM's response.
-   *Local LLM Integration*: Connects to a local Ollama server instance to process prompts.
-   *C++/Python Bridge*: Utilizes pybind11 to integrate Python's requests library for communicating with the Ollama API.
-   *Cross-Platform*: Built with Qt6 and CMake, making it portable across different operating systems.

## Prerequisites

Before building and running SearchBroV2, ensure you have the following installed:

-   A C++ compiler that supports C++23.
-   CMake (version 3.16 or higher).
-   Qt6 (including Widgets, Core, Gui, Network, and Test components).
-   Python 3 (with development headers).
-   pybind11 library.
-   *Ollama*: A running instance of Ollama is required. The application is configured to use the llama3.2:3b model by default. You can install it by running ollama pull llama3.2:3b.
-   Python requests library:
    bash
    pip install requests
    

## Building and Running

1.  *Clone the repository:*
    bash
    git clone https://github.com/catzeyea/SearchBroV2.git
    cd SearchBroV2
    

2.  *Create a build directory:*
    bash
    mkdir build
    cd build
    

3.  *Configure the project with CMake:*
    bash
    cmake ..
    

4.  *Compile the source code:*
    bash
    make
    

5.  *Run the application:*
    Ensure your Ollama server is running in the background.
    bash
    ./SearchBroV2
    

## Usage

Once the application is running, you will see a window with an input field. Type your prompt and press Enter. The application will send the prompt to your local Ollama instance, and the generated response will appear in the output field above the input.

### Hyprland Configuration

If you are using the Hyprland window manager, you can add the following rules to your configuration file for a floating window experience:

```
windowrule = float,class:SearchBroV2
windowrule = size 1234 1,class:SearchBroV2
