#include "utils.hpp"
#include <sstream>

std::vector<std::string> dividirEntrada(const std::string& entrada) {
    std::istringstream iss(entrada);
    std::vector<std::string> palavras;
    std::string palavra;
    while (iss >> palavra) {
        palavras.push_back(palavra);
    }
    return palavras;
}
