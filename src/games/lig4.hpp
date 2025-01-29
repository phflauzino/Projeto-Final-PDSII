#ifndef LIG4_HPP
#define LIG4_HPP

#include "tabuleiro.hpp"
#include "jogador.hpp"

class Lig4 : public Tabuleiro {
private:
    Jogador jogador1, jogador2;
    Jogador* jogadorAtual;

public:
    Lig4(const Jogador& jogador1, const Jogador& jogador2);

    void jogar();
    bool inserirPeca(int coluna, char simbolo);
    bool verificarVitoria(char simbolo) const;
    void verificarVencedor() const; 
};

#endif
