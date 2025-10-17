import requests
import json

def generate_text(prompt: str) -> str:
    url = "http://localhost:11434/api/chat"
    data = {
        "model": "llama3.2:3b",
        "messages": [
            {"role": "user", "content": prompt}
        ],
        "stream": False
}   

    response = requests.post(url, json=data)
    result = response.json()
    return result.get("message", {}).get("content", "")
