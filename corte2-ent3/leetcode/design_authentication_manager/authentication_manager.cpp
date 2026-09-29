#include <unordered_map>
#include <string>

class AuthenticationManager {
private:
    int ttl;
    std::unordered_map<std::string, int> tokens;

public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(std::string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + ttl;
    }
    
    void renew(std::string tokenId, int currentTime) {
        if (tokens.find(tokenId) != tokens.end() && tokens[tokenId] > currentTime) {
            tokens[tokenId] = currentTime + ttl;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;

        for (const auto& pair : tokens) {
            if (pair.second > currentTime) {
                count++;
            }
        }

        return count;
    }
};
