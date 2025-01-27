# 🎲 Projeto Final PDSII - Jogos de Tabuleiro

Este é o repositório do projeto final da disciplina **Programação e Desenvolvimento de Sistemas II (PDSII)**, desenvolvido no 2º semestre de 2024.

---

## 📋 Objetivo
O objetivo deste trabalho é implementar três jogos de tabuleiro: **Othelo**, **Lig 4** e **Jogo da Velha**, utilizando o paradigma de **orientação a objetos (POO)** e boas práticas de desenvolvimento. O sistema também contará com:
- Módulo para cadastro de jogadores e estatísticas.
- Execução de partidas entre jogadores.
- Possibilidade de adicionar funcionalidades extras, como **IA** ou interface gráfica.

---
##  Visão Geral da Solução

A solução é baseada na estrutura modular de classes, utilizando Programação Orientada a Objetos (POO) em C++. O sistema é composto pelas seguintes classes principais:

-Tabuleiro: Classe base que representa um tabuleiro genérico, permitindo reutilização para diferentes jogos.
-Jogador: Representa um jogador, armazenando seu apelido e informações pessoais.
-Jogo da Velha: Implementa as regras e funcionalidades do Jogo da Velha.
-Lig 4: Gerencia a lógica do Conecta 4, verificando jogadas válidas e condições de vitória.
-Othello: Implementa as regras do Othello, com lógica para virar peças e contabilizar pontos.

-Cada jogo estende a classe Tabuleiro e implementa suas regras específicas. O fluxo básico consiste em alternar entre jogadores, registrar jogadas e verificar condições de vitória ou empate.

---
## Estrutura e Funcionamento

-O programa inicializa os jogadores e o tabuleiro do jogo escolhido.
-Alternadamente, cada jogador faz uma jogada válida.
-O sistema atualiza o tabuleiro e verifica condições de vitória ou empate.
-O jogo termina quando há um vencedor ou empate, exibindo o resultado.

---
## Principais Dificuldades Encontradas

-Gerenciamento da lógica de captura no Othello, devido às regras de inversão de peças.
-Verificação de vitória no Lig 4, considerando todas as direções possíveis.
-Garantia de jogadas válidas e manipulação de entradas para evitar erros inesperados.


---
## 🛠️ Tecnologias Utilizadas
- **C++**: Linguagem principal do projeto.
- **Doctest**: Framework de testes unitários.
- **Doxygen**: Geração de documentação automatizada.
- **Git** e **GitHub**: Controle de versão e colaboração.

---

## 📂 Estrutura do Projeto
```plaintext
projeto-final-pdsii-2024-2/
├── README.md        # Documentação do projeto
├── LICENSE          # Licença do projeto 
├── .gitignore       # Arquivos e pastas a serem ignorados pelo Git
├── src/             # Código-fonte (arquivos .cpp e .hpp)
│   ├── games/       # Implementação dos jogos
│   ├── players/     # Gerenciamento de jogadores
│   └── utils/       # Funções utilitárias
├── tests/           # Arquivos de testes unitários com doctest
├── docs/            # Documentação adicional
├── assets/          # Recursos visuais (imagens, gráficos, etc.)
├── Makefile         # Automação de compilação
└── bin/             # Executáveis gerados pela compilação
