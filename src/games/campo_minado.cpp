#include "campo_minado.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Construtor
CampoMinado::CampoMinado(int tamanho, int minas) : Tabuleiro(tamanho), minas(minas) {
    tabuleiroVisivel = std::vector<std::vector<char>>(tamanho, std::vector<char>(tamanho, '-'));
    gerarMinas();
    calcularNumeros();
}

// Gerar minas aleatórias
void CampoMinado::gerarMinas() {
    srand(time(0));
    for (int i = 0; i < minas; i++) {
        int x, y;
        do {
            x = rand() % tamanho;
            y = rand() % tamanho;
        } while (tabuleiro[x][y] == '*');
        tabuleiro[x][y] = '*';
    }
}

// Calcular números ao redor das minas
void CampoMinado::calcularNumeros() {
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (tabuleiro[i][j] == '*') continue;

            int minasAoRedor = 0;
            for (int d = 0; d < 8; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (nx >= 0 && nx < tamanho && ny >= 0 && ny < tamanho && tabuleiro[nx][ny] == '*') {
                    minasAoRedor++;
                }
            }
            tabuleiro[i][j] = minasAoRedor + '0';
        }
    }
}

// Revelar posição
void CampoMinado::revelar(int x, int y) {
    if (x < 0 || y < 0 || x >= tamanho || y >= tamanho || tabuleiroVisivel[x][y] != '-') {
        return;
    }

    tabuleiroVisivel[x][y] = tabuleiro[x][y];

    if (tabuleiro[x][y] == '0') {
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int d = 0; d < 8; d++) {
            revelar(x + dx[d], y + dy[d]);
        }
    }
}

// Verificar vitória
bool CampoMinado::verificarVitoria() const {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (tabuleiroVisivel[i][j] == '-' && tabuleiro[i][j] != '*') {
                return false;
            }
        }
    }
    return true;
}

// Verificar se perdeu
bool CampoMinado::perdeu(int x, int y) const {
    return tabuleiro[x][y] == '*';
}

// Exibir tabuleiro visível
void CampoMinado::exibirVisivel() const {
    for (const auto& linha : tabuleiroVisivel) {
        for (char c : linha) {
            std::cout << c << ' ';
        }
        std::cout << '\n';
    }
}

