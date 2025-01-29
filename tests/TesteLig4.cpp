#include "lig4.hpp"
#include "doctest.h"
#include <iostream>
#include <stdexcept>

TEST_CASE("Testando o jogo Lig4") {
    Jogador jogador1("Jogador1", "X");
    Jogador jogador2("Jogador2", "O");
    Lig4 jogo(jogador1, jogador2);

    SUBCASE("Testando inserção de peças válidas") {
        CHECK(jogo.inserirPeca(0, 'X') == true);  // Inserir peça do jogador 1
        CHECK(jogo.inserirPeca(0, 'O') == true);  // Inserir peça do jogador 2
    }

    SUBCASE("Testando coluna cheia") {
        // Preenchendo a coluna 0
        CHECK(jogo.inserirPeca(0, 'X') == true);
        CHECK(jogo.inserirPeca(0, 'O') == true);
        CHECK(jogo.inserirPeca(0, 'X') == true);
        CHECK(jogo.inserirPeca(0, 'O') == true);
        CHECK(jogo.inserirPeca(0, 'X') == true);
        CHECK(jogo.inserirPeca(0, 'O') == true);
        
        // Tentando inserir em uma coluna cheia
        CHECK(jogo.inserirPeca(0, 'X') == false);
    }

    SUBCASE("Testando vitória horizontal") {
        // Inserindo peças para vencer horizontalmente
        CHECK(jogo.inserirPeca(0, 'X') == true);
        CHECK(jogo.inserirPeca(1, 'X') == true);
        CHECK(jogo.inserirPeca(2, 'X') == true);
        CHECK(jogo.inserirPeca(3, 'X') == true);
        CHECK(jogo.verificarVitoria('X') == true);  // Vitória horizontal
    }

    SUBCASE("Testando vitória vertical") {
        // Inserindo peças para vencer verticalmente
        CHECK(jogo.inserirPeca(0, 'X') == true);
        CHECK(jogo.inserirPeca(0, 'O') == true);
        CHECK(jogo.inserirPeca(0, 'X') == true);
        CHECK(jogo.inserirPeca(0, 'O') == true);
        CHECK(jogo.inserirPeca(0, 'X') == true);
        CHECK(jogo.verificarVitoria('X') == true);  // Vitória vertical
    }

    SUBCASE("Testando vitória diagonal crescente") {
        // Inserindo peças para vencer diagonalmente (crescente)
        CHECK(jogo.inserirPeca(0, 'X') == true);
        CHECK(jogo.inserirPeca(1, 'O') == true);
        CHECK(jogo.inserirPeca(1, 'X') == true);
        CHECK(jogo.inserirPeca(2, 'O') == true);
        CHECK(jogo.inserirPeca(2, 'X') == true);
        CHECK(jogo.inserirPeca(3, 'O') == true);
        CHECK(jogo.verificarVitoria('X') == true);  // Vitória diagonal crescente
    }

    SUBCASE("Testando vitória diagonal decrescente") {
        // Inserindo peças para vencer diagonalmente (decrescente)
        CHECK(jogo.inserirPeca(3, 'X') == true);
        CHECK(jogo.inserirPeca(2, 'O') == true);
        CHECK(jogo.inserirPeca(2, 'X') == true);
        CHECK(jogo.inserirPeca(1, 'O') == true);
        CHECK(jogo.inserirPeca(1, 'X') == true);
        CHECK(jogo.inserirPeca(0, 'O') == true);
        CHECK(jogo.verificarVitoria('X') == true);  // Vitória diagonal decrescente
    }

    SUBCASE("Testando empate") {
        // Preencher o tabuleiro sem vitória para testar empate
        CHECK(jogo.inserirPeca(0, 'X') == true);
        CHECK(jogo.inserirPeca(1, 'O') == true);
        CHECK(jogo.inserirPeca(2, 'X') == true);
        CHECK(jogo.inserirPeca(3, 'O') == true);
        CHECK(jogo.inserirPeca(4, 'X') == true);
        CHECK(jogo.inserirPeca(5, 'O') == true);
        CHECK(jogo.inserirPeca(6, 'X') == true);

        // Testar empate (sem mais espaços e sem vitória)
        CHECK(jogo.verificarVitoria('X') == false);
        CHECK(jogo.verificarVitoria('O') == false);
    }

    SUBCASE("Testando exceção ao inserir peça fora do intervalo") {
        // Testando exceção para inserção em coluna fora do intervalo
        CHECK_THROWS_AS(jogo.inserirPeca(-1, 'X'), std::out_of_range);  // Coluna negativa
        CHECK_THROWS_AS(jogo.inserirPeca(7, 'X'), std::out_of_range);   // Coluna fora do limite
    }
}
