#include "othello.hpp"
#include "doctest.h"
#include <iostream>
#include <memory>

TEST_CASE("Testando o jogo Othello") {
    // Criação dos jogadores
    auto jogador1 = std::make_shared<Jogador>("Jogador1", "X");
    auto jogador2 = std::make_shared<Jogador>("Jogador2", "O");
    Othello jogo(jogador1, jogador2);

    SUBCASE("Testando inicialização do tabuleiro") {
        // Verificando se as peças iniciais estão no lugar correto
        CHECK(jogo.getTabuleiro()[3][3] == 'X');
        CHECK(jogo.getTabuleiro()[4][4] == 'X');
        CHECK(jogo.getTabuleiro()[3][4] == 'O');
        CHECK(jogo.getTabuleiro()[4][3] == 'O');
    }

    SUBCASE("Testando jogada válida e captura de peças") {
        // Jogada válida e captura de peças
        CHECK(jogo.jogadaValida(2, 3) == true);  // Jogada válida
        jogo.capturarPecas(2, 3);  // Captura de peças
        CHECK(jogo.getTabuleiro()[2][3] == 'X');  // Verificando a peça do jogador 1

        jogo.exibirTabuleiro();
    }

    SUBCASE("Testando jogada inválida (posição ocupada)") {
        // Jogada inválida em posição já ocupada
        CHECK(jogo.jogadaValida(3, 3) == false);  // Posição ocupada
    }

    SUBCASE("Testando alternância de turnos") {
        // Testando se a alternância de turno entre os jogadores funciona corretamente
        CHECK(jogo.getTurnoJogador1() == true);  // Começando com o jogador 1
        jogo.capturarPecas(2, 3);
        CHECK(jogo.getTurnoJogador1() == false);  // Turno deveria ser alternado para o jogador 2
    }

    SUBCASE("Testando fim de jogo (sem jogadas válidas restantes)") {
        // Testando fim de jogo quando não há mais jogadas válidas
        CHECK(jogo.verificarFimDeJogo() == false);  // Jogo não terminou no começo

        // Simulando fim de jogo
        jogo.capturarPecas(2, 3);  // Jogada qualquer
        jogo.capturarPecas(5, 4);  // Jogada qualquer
        CHECK(jogo.verificarFimDeJogo() == true);  // Agora o jogo deve terminar
    }

    SUBCASE("Testando fim de jogo (com jogadas válidas restantes)") {
        // Jogando uma jogada válida e verificando se o jogo continua
        jogo.capturarPecas(2, 3);
        CHECK(jogo.verificarFimDeJogo() == false);  // O jogo ainda não deve ter terminado
    }

    SUBCASE("Testando jogada fora do tabuleiro") {
        // Testando jogada fora do tabuleiro
        CHECK(jogo.jogadaValida(-1, 5) == false);  // Linha negativa
        CHECK(jogo.jogadaValida(8, 5) == false);   // Linha fora do limite
        CHECK(jogo.jogadaValida(5, -1) == false);  // Coluna negativa
        CHECK(jogo.jogadaValida(5, 8) == false);   // Coluna fora do limite
    }
}

