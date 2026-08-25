# Firmware

> Firmware responsável pelo controle do braço mecânico e dos componentes eletrônicos do Projeto Mobo.

![Status](https://img.shields.io/badge/status-em%20desenvolvimento-yellow)
![C%2B%2B](https://img.shields.io/badge/C%2B%2B-00599C?logo=cplusplus)
![ESP](https://img.shields.io/badge/ESP-000000?logo=espressif)

---

## 📋 Sobre

O **Mobo Firmware** é responsável pelo controle dos componentes eletrônicos do braço mecânico utilizado no Projeto Mobo.

O firmware executa os comandos recebidos pelo sistema e controla os atuadores do braço, permitindo movimentação e acionamento da garra para auxiliar no processo automatizado de colheita da lichia.

---

## ✨ Funcionalidades

* 🤖 Controle dos movimentos do braço mecânico
* 🦾 Controle da garra automatizada
* ⚙️ Controle dos servomotores
* 📡 Comunicação com os demais componentes do sistema
* 🎮 Recebimento de comandos para movimentação
* 🔄 Controle da sequência de movimentos do braço

---

## 🛠️ Tecnologias

* **C++** — desenvolvimento do firmware
* **ESP** — microcontrolador utilizado no sistema
* **Servomotores** — movimentação dos eixos e da garra
* **Arduino Framework** — desenvolvimento e comunicação com o hardware

---

## 🏗️ Arquitetura

```text
firmware/
├── .gitignore
├── bracoEsteira.ino
├── LICENSE
└── README.md
```

---

## 🚀 Como Rodar Localmente

### Pré-requisitos

Antes de começar, instale:

* [Node.js](https://nodejs.org/) v20 LTS ou superior
* [Git](https://git-scm.com/)
* [Expo Go](https://expo.dev/go/) no dispositivo, caso utilize um dispositivo físico

### 1. Clonar o Repositório

```bash
git clone https://github.com/CW-Mobo/mobile.git
cd mobile
```

### 2. Instalar Dependências

```bash
npm install
```

### 3. Configurar Variáveis de Ambiente

Crie um arquivo `.env` baseado no `.env.example` disponível no repositório.

> Para execução local, utilize as configurações disponíveis no `.env.example`.

### 4. Executar o Projeto

```bash
npx expo start
```

Após iniciar o Expo, será exibido um QR Code no terminal.

* **Android:** escaneie o QR Code utilizando o Expo Go.
* **iOS:** escaneie o QR Code utilizando a câmera do dispositivo.
* **Emulador:** utilize as opções disponibilizadas pelo Expo para abrir o projeto no emulador configurado.

> ⚠️ A API precisa estar em execução para que as funcionalidades que dependem dos dados do sistema funcionem corretamente.

> 💡 O Mobile está configurado para consumir a API do Mobo. Caso a URL ou porta da API seja alterada, ajuste a configuração correspondente no aplicativo.

---

## 📱 Desenvolvimento

Para executar diretamente em uma plataforma específica:

```bash
npx expo start --android
```

```bash
npx expo start --ios
```

> A execução no iOS requer um ambiente compatível com o desenvolvimento para a plataforma.

---

## 📦 Build

Os builds da aplicação podem ser realizados utilizando as ferramentas do Expo.

```bash
npx expo export
```

---

## 🌐 API

O aplicativo utiliza a **Mobo API** para autenticação, consulta e gerenciamento dos dados do sistema.

**API local:**

```text
http://localhost:5000
```

> Em dispositivos físicos, `localhost` normalmente se refere ao próprio dispositivo. Para acessar uma API executando no computador, utilize o endereço IP local da máquina na configuração do aplicativo.

---

## 📄 Licença

Este projeto está sob a licença MIT.

Consulte o arquivo LICENSE para mais informações.
