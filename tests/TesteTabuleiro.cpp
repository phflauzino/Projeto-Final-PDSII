#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tabuleiro.hpp"

TEST_CASE("Testando construtores do Tabuleiro") {
  Tabuleiro tab1;
  CHECK(tab1.getTamanho() == 3);

  Tabuleiro tab2(5);
  CHECK(tab2.getTamanho() == 5);
}

TEST_CASE("Testando limpeza do tabuleiro") {
  Tabuleiro tab(4);
  tab.limparTabuleiro();

  for (int i = 0; i < tab.getTamanho(); ++i) {
    for (int j = 0; j < tab.getTamanho(); ++j) {
      CHECK(tab.getCelula(i, j) == ' ');
    }
  }
}
