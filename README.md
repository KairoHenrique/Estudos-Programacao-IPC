# Introdução à Programação de Computadores (IPC)

Repositório com exercícios, laboratórios e exemplos desenvolvidos na disciplina de **Introdução à Programação de Computadores (IPC)** do curso de Engenharia de Computação. O foco é apresentar conceitos básicos de lógica de programação e estruturas fundamentais em **C**.

---

## Visão Geral

Este projeto reúne atividades práticas que cobrem desde a sintaxe básica até estruturas de controle e manipulação de dados em C. Cada pasta corresponde a um conjunto de exercícios ou laboratório, permitindo acompanhamento sequencial do aprendizado.

---

## Objetivos

- Aprender os fundamentos da linguagem C  
- Desenvolver raciocínio lógico para solução de problemas  
- Trabalhar com estruturas de controle (condicionais, loops)  
- Utilizar funções e modularizar código  
- Gerenciar entrada e saída de dados  
- Manipular arrays e strings  
---

## Conteúdo

- **Sintaxe e Compilação**: comentários, tipos básicos, operadores e processo de compilação.  
- **Estruturas de Controle**: `if`/`else`, `switch`, `for`, `while`, `do…while`.  
- **Funções**: declaração, passagem de parâmetros, retorno de valores e escopo.  
- **Vetores e Matrizes**: manipulação de arrays unidimensionais e bidimensionais.  
- **Strings**: bibliotecas e funções de tratamento de texto.  
- **Ponteiros Básicos**: conceitos iniciais e uso em funções.  
- **Entrada e Saída**: `printf`, `scanf` e operações com arquivos (introdução).  
---

## Estrutura do Repositório
```bash
Estudos-IPC/
├── Exercícios-Sintaxe/ # Programas de “Hello World”, operadores e variáveis
├── Lab1-Condicionais/ # if, else, switch
├── Lab2-Repetição/ # for, while, do…while
├── Lab3-Funções/ # definição e chamadas de funções
├── Lab4-Arrays/ # vetores e matrizes
├── Lab5-Strings/ # manipulação de texto
├── Lab6-Ponteiros/ # ponteiros e parâmetros por referência
├── Lab7-IO-Arquivos/ # leitura e escrita em arquivos
└── README.md # Este documento
```

---

## Como Compilar e Executar

Em qualquer pasta de exercício ou laboratório:


```bash
cd NomeDaPasta
gcc -std=c11 -Wall -Wextra -o programa *.c
./programa [argumentos]
```
- NomeDaPasta: substitua pelo diretório desejado (por ex. Lab2-Repetição).

- programa: nome do executável.

---
## Boas Práticas

- Use nomes de variáveis claros e comentado o código onde necessário.

- Valide entradas do usuário e trate possíveis erros.

- Separe funções em arquivos distintos para melhor organização.

- Sempre libere recursos alocados dinamicamente (quando aplicável).
---
## Autor

- Feito por Kairo Henrique Ferreira Martins
- Professor: Eduardo Habib Bechelane Maia
