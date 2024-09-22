# 🖥️ Servidor Web Multithread

Este projeto é uma implementação de um servidor web multithread em **C++**, desenvolvida para a disciplina de **Redes de Computadores**. O servidor é capaz de lidar com múltiplas requisições simultâneas, aproveitando a concorrência proporcionada pelas threads.

## 🚀 Funcionalidades

- **Suporte a múltiplas conexões**: Graças ao uso de threads, o servidor consegue atender várias requisições ao mesmo tempo.
- **Serviço de arquivos estáticos**: O servidor entrega arquivos HTML, permitindo que os clientes naveguem por páginas web estáticas.
- **Facilidade de acesso**: Uma vez em execução, o servidor pode ser acessado facilmente pelo navegador através do endereço `http://localhost:5005/index.html`.

## 🛠️ Configuração e Execução

### Pré-requisitos

Para compilar e executar o servidor, certifique-se de ter o seguinte ambiente configurado:

- **Compilador C++**: Recomendado `g++` (GCC) ou outro compilador compatível com C++11 ou superior.
- **Biblioteca pthread**: Necessária para o suporte a threads no Linux.

### Compilação

1. Compile o código utilizando o comando abaixo (assumindo que o código está em um arquivo chamado `servidor.cpp`):

    ```bash
    g++ -pthread -o servidor servidor.cpp
    ```

2. Após a compilação, execute o servidor:

    ```bash
    ./servidor
    ```

### Acessando o Servidor

Uma vez que o servidor estiver em execução, você pode acessá-lo através de um navegador da web no seguinte endereço:

```bash
http://localhost:5005/index.html
