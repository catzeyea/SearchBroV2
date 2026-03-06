#include "Communication.hpp"

// Callback to store response data
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    userp->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string Communication::GetMessage(const std::string& message) {
    CURL* curl = curl_easy_init();
    std::string response;

    if (curl) {
        std::string jsonStr = R"({
            "model": ")" + model + R"(",
            "messages": [
                {
                    "role": "system",
                    "content": ")" + systemContent + R"("
                },
                {
                    "role": "user",
                    "content": ")" + message + R"("
                }
            ],
            "temperature": 0.7,
            "max_tokens": -1,
            "stream": false
        })";

        std::string url = "http://" + baseUrl + ":" + std::to_string(port) + "/v1/chat/completions";

        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonStr.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);

        // curl request
        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            response = "Error: " + std::string(curl_easy_strerror(res));
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    return response;
}

