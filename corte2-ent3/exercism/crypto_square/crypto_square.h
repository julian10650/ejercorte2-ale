#pragma once

#include <string>

namespace crypto_square {

class cipher {
private:
    std::string input_text;

public:
    explicit cipher(std::string text);
    std::string normalized_cipher_text() const;
};

}  // namespace crypto_square
