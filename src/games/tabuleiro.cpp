#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include <vector>
#include <iostream>

class Tabuleiro {
protected:
    int linhas;
    int colunas;
    std::vector<std::vector<char>> tabuleiro;

public:
    Tabuleiro(int tamanho);
    Tabuleiro(int linhas, int colunas);

    virtual void exibirTabuleiro() const;
    bool estaVazio(int linha, int coluna) const;
    void setPosicao(int linha, int coluna, char valor);
    char getPosicao(int linha, int coluna) const;
    int getLinhas() const { return linhas; }
    int getColunas() const { return colunas; }
};

#endif
