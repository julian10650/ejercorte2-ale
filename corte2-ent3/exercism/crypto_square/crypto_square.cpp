#include "crypto_square.h"
#include <vector>
#include <cctype>

namespace crypto_square {

cipher::cipher(std::string text) : input_text(text) {}

std::string cipher::normalized_cipher_text() const {

    std::string normalized = "";

    for (char ch : input_text) {
        if (std::isalnum(static_cast<unsigned char>(ch))) {
            normalized += std::tolower(static_cast<unsigned char>(ch));
        }
    }

    int L = normalized.length();

    if (L == 0) {
        return "";
    }

    int r = 0;
    int c = 0;

    for (int i = 1; ; ++i) {
        if (i * i >= L) {
            r = i;
            c = i;
            break;
        }

        if (i * (i + 1) >= L) {
            r = i;
            c = i + 1;
            break;
        }
    }

    std::vector<std::string> rows(r, std::string(c, ' '));

    for (int i = 0; i < L; ++i) {
        int row = i / c;
        int col = i % c;
        rows[row][col] = normalized[i];
    }

    std::string result = "";

    for (int col = 0; col < c; ++col) {
        std::string chunk = "";

        for (int row = 0; row < r; ++row) {
            chunk += rows[row][col];
        }

        result += chunk;

        if (col < c - 1) {
            result += " ";
        }
    }

    return result;
}

}  // namespace crypto_square
