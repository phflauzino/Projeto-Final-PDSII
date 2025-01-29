#ifndef OTHELLO_HPP
#define OTHELLO_HPP

#include "jogador.hpp"
#include <memory>
#include <vector>

class Othello {
private:
    std::shared_ptr<Jogador> jogador1, jogador2;  
    bool turnoJogador1;  
    std::vector<std::vector<char>> tabuleiro;  

 
    void inicializarTabuleiro();

    bool jogadaValida(int linha, int coluna);


    void capturarPecas(int linha, int coluna);

public:

    Othello(std::shared_ptr<Jogador> j1, std::shared_ptr<Jogador> j2);


    void jogar();


    bool verificarFimDeJogo();


    void exibirJogadorAtual();


    void exibirTabuleiro();
};

#endif 
