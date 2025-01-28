#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "jogador.hpp"
#include "lig4.hpp"

TEST_CASE("Teste de insercao de peca no Lig4") {
  Jogador jogador1("Jogador1", "Nome1", "email1", "senha1");
  Jogador jogador2("Jogador2", "Nome2", "email2", "senha2");
  Lig4 jogo(jogador1, jogador2);

  CHECK(jogo.inserirPeca(0, 'X') == true);
  CHECK(jogo.inserirPeca(6, 'O') == true);
  CHECK(jogo.inserirPeca(7, 'X') == false); // Fora do tabuleiro
}

TEST_CASE("Teste de vitoria horizontal") {
  Jogador jogador1("Jogador1", "Nome1", "email1", "senha1");
  Jogador jogador2("Jogador2", "Nome2", "email2", "senha2");
  Lig4 jogo(jogador1, jogador2);

  for (int i = 0; i < 4; ++i) {
    jogo.inserirPeca(i, 'X');
  }
  CHECK(jogo.verificarVitoria('X') == true);
}

TEST_CASE("Teste de vitoria vertical") {
  Jogador jogador1("Jogador1", "Nome1", "email1", "senha1");
  Jogador jogador2("Jogador2", "Nome2", "email2", "senha2");
  Lig4 jogo(jogador1, jogador2);

  for (int i = 0; i < 4; ++i) {
    jogo.inserirPeca(0, 'O');
  }
  CHECK(jogo.verificarVitoria('O') == true);
}

TEST_CASE("Teste de vitoria diagonal crescente") {
  Jogador jogador1("Jogador1", "Nome1", "email1", "senha1");
  Jogador jogador2("Jogador2", "Nome2", "email2", "senha2");
  Lig4 jogo(jogador1, jogador2);

  jogo.inserirPeca(0, 'X');
  jogo.inserirPeca(1, 'O');
  jogo.inserirPeca(1, 'X');
  jogo.inserirPeca(2, 'O');
  jogo.inserirPeca(2, 'O');
  jogo.inserirPeca(2, 'X');
  jogo.inserirPeca(3, 'O');
  jogo.inserirPeca(3, 'O');
  jogo.inserirPeca(3, 'O');
  jogo.inserirPeca(3, 'X');

  CHECK(jogo.verificarVitoria('X') == true);
}

TEST_CASE("Teste de coluna cheia") {
  Jogador jogador1("Jogador1", "Nome1", "email1", "senha1");
  Jogador jogador2("Jogador2", "Nome2", "email2", "senha2");
  Lig4 jogo(jogador1, jogador2);

  for (int i = 0; i < 6; ++i) {
    jogo.inserirPeca(0, 'X');
  }
  CHECK(jogo.inserirPeca(0, 'O') == false);
}

TEST_CASE("Teste de entrada invalida") {
  Jogador jogador1("Jogador1", "Nome1", "email1", "senha1");
  Jogador jogador2("Jogador2", "Nome2", "email2", "senha2");
  Lig4 jogo(jogador1, jogador2);

  CHECK_THROWS_AS(jogo.inserirPeca(-1, 'X'), std::out_of_range);
  CHECK_THROWS_AS(jogo.inserirPeca(7, 'X'), std::out_of_range);
}
