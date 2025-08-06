
# 🛫 Sistema de Malha Aérea (ANAC)  
# 🛫 Air Route Network System (ANAC)

[🇧🇷 Versão em Português](#-sistema-de-malha-aérea-anac) | [🇺🇸 English Version](#-air-route-network-system-anac)

---

## 🇧🇷 Sistema de Malha Aérea (ANAC)

Este repositório contém um projeto em linguagem C que simula uma **malha aérea nacional**, permitindo o **cadastro e gerenciamento de aeroportos e voos**, com funcionalidades de **busca e listagem de trajetos**. O projeto foi desenvolvido como parte da disciplina de Estrutura de Dados do curso de Sistemas de Informação na PUC-Campinas.

---

### ✈️ Objetivo

O sistema tem como objetivo simular uma malha aérea controlada pela ANAC, utilizando uma **estrutura de grafo representada por matriz de adjacência**, onde:

- **Aeroportos** são os vértices.  
- **Voos** entre aeroportos são as arestas com peso (distância).

---

### ⚙️ Funcionalidades

- ✅ Cadastro de aeroportos  
- ✅ Remoção de aeroportos  
- ✅ Cadastro de voos entre aeroportos (com distância)  
- ✅ Remoção de voos  
- ✅ Listagem de aeroportos e voos  
- ✅ Busca por conexões diretas entre aeroportos  
- ✅ Interface de menu no terminal  
- ✅ Tipos personalizados para portabilidade (`I8`, `U32`, `boolean`, etc.)

---

### 🗂️ Estrutura do Projeto

```
malha-aerea/
│
├── main.c                → Arquivo principal, com menu e interação com o usuário
├── meustipos.h           → Definições de tipos personalizados (I8, U32, boolean, etc.)
├── estrutura.h/.c        → Declaração e implementação da estrutura da malha aérea
├── aeroporto.h/.c        → Funções para cadastro e gerenciamento de aeroportos
├── voo.h/.c              → Funções para cadastro e gerenciamento de voos
└── README.md             → Documentação do projeto
```

---

### 🧠 Lógica do Grafo

- A malha aérea é implementada com **matriz de adjacência** de tamanho `MAX x MAX`.
- Cada posição `[i][j]` armazena a **distância** do voo entre os aeroportos `i` e `j`.
- Os aeroportos são armazenados em um vetor de structs com `nome`, `sigla` e `ID`.

---

### 💻 Como Compilar e Executar

#### Pré-requisitos

- GCC (compilador C)  
- Terminal

#### Compilação

```bash
gcc main.c estrutura.c aeroporto.c voo.c -o malha.exe
```

#### Execução

```bash
./malha.exe
```

---

### 👨‍💻 Autores

- **Thiago Mauri Gonzalez** – [PUC-Campinas](https://www.puc-campinas.edu.br/)  
- Projeto desenvolvido no 3º semestre do curso de Sistemas de Informação.

---

### 📌 Observações

- O sistema não possui interface gráfica, sendo totalmente baseado em **linha de comando**.
- Os dados não são persistidos em arquivos – são mantidos em tempo de execução.

---

## 🇺🇸 Air Route Network System (ANAC)

This repository contains a C language project that simulates a **national air route network**, allowing for **airport and flight management**, with features for **searching and listing routes**. The project was developed as part of the Data Structures course in the Information Systems program at PUC-Campinas.

---

### ✈️ Objective

The system aims to simulate an air route network controlled by ANAC, using a **graph structure represented by an adjacency matrix**, where:

- **Airports** are the vertices.  
- **Flights** between airports are weighted edges (distance).

---

### ⚙️ Features

- ✅ Airport registration  
- ✅ Airport removal  
- ✅ Flight registration between airports (with distance)  
- ✅ Flight removal  
- ✅ Listing of airports and flights  
- ✅ Search for direct connections between airports  
- ✅ Terminal-based menu interface  
- ✅ Custom types for portability (`I8`, `U32`, `boolean`, etc.)

---

### 🗂️ Project Structure

```
malha-aerea/
│
├── main.c                → Main file, containing the menu and user interaction
├── meustipos.h           → Custom type definitions (I8, U32, boolean, etc.)
├── estrutura.h/.c        → Graph structure declaration and implementation
├── aeroporto.h/.c        → Functions for airport registration and management
├── voo.h/.c              → Functions for flight registration and management
└── README.md             → Project documentation
```

---

### 🧠 Graph Logic

- The air route network is implemented using a `MAX x MAX` **adjacency matrix**.  
- Each `[i][j]` cell stores the **distance** of the flight between airports `i` and `j`.  
- Airports are stored in an array of structs with `name`, `code`, and `ID`.

---

### 💻 How to Compile and Run

#### Requirements

- GCC (C compiler)  
- Terminal

#### Compile

```bash
gcc main.c estrutura.c aeroporto.c voo.c -o malha.exe
```

#### Run

```bash
./malha.exe
```

---

### 👨‍💻 Authors

- **Thiago Mauri Gonzalez** – [PUC-Campinas](https://www.puc-campinas.edu.br/)  
- Project developed during the 3rd semester of the Information Systems program.

---

### 📌 Notes

- The system is entirely **command-line based**, with no graphical interface.  
- Data is not persisted in files – it is maintained only during runtime.
