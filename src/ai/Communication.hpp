#pragma once
#include <curl/curl.h>
#include <string>
#include <stdint.h>

class Communication {
    private:
        std::string baseUrl{"localhost"};
        uint16_t port{1234};
        std::string model{"qwen3-4b-instruct-2507"};
        std::string systemContent{""};
    public:
        std::string GetMessage(const std::string& message);

        void setModel(const std::string& m) { model = m; }
        void setSystemContent(const std::string& s) { systemContent = s; }
        void setBaseUrl(const std::string& url) { baseUrl = url; }
        void setPort(uint8_t p) { port = p; }
};