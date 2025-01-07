# Sensor Anti-incêndio com Microcontrolador

<h1 align="center">
    <img align="center" style="border-radius: 50%;" src="https://moodle.embarcatech.cepedi.org.br/pluginfile.php/1/theme_moove/logo/1733422525/Group%20658.png" width="200px;" alt="">
</h1>

<h3 align="center"> Sensor Anti-incêndio com microcontrolador </h3>

<h4 align="center"> 🚧 Projeto em andamento 🚧 </h4>
<p align="center">Em fase de prototipagem</p>

---

## 📖 Tabela de Conteúdos
<!--ts-->
   * [Sobre o Projeto](#-sobre-o-projeto)
   * [Layout do Repositório](#-layout-do-repositório)
   * [Funcionalidades](#-funcionalidades)
   * [Como Executar o Projeto](#-como-executar-o-projeto)
     * [Pré-requisitos](#-pré-requisitos)
   * [Tecnologias Utilizadas](#-tecnologias-utilizadas)
   * [Contribuidores](#-contribuidores)
   * [Licença](#-licença)
<!--te-->

---

## 💡 Sobre o Projeto

Este projeto está sendo desenvolvido utilizando o **Design Thinking**, uma abordagem centrada no ser humano, focando em resolver problemas reais. Durante a fase de **empatia**, identificou-se a necessidade de aumentar a segurança em residências com pessoas que apresentam **demência**, como Alzheimer.

Pessoas com demência podem esquecer fogões ligados ou não perceber sinais de vazamento de gás, elevando o risco de incêndios e intoxicações. Para abordar essa dor, foi criado um sistema de **detecção de fumaça e vazamento de gás** utilizando sensores e microcontroladores, que emite alertas visuais e sonoros quando níveis perigosos são detectados.

Projeto desenvolvido durante o curso de **Formação Básica em Software Embarcado** oferecido pela [Embarcatech](https://embarcatech.softex.br).

---

## 🗂️ Layout do Repositório

/Sensor_anti-incendio
- sketch_sensor_anti-incendio/ &emsp;&emsp;&emsp;&emsp;# Diretório para o código-fonte
  - sketch_sensor_anti-incendio.ino  &emsp;&emsp;&emsp;&emsp;# Código principal
  - README.md  &emsp;&emsp;&emsp;&emsp;# Readme do projeto
  - License.md  &emsp;&emsp;&emsp;&emsp;# Licença de uso

---

## ⚙️ Funcionalidades

- [x] Monitoramento contínuo de gás e fumaça.
- [x] Alerta visual e sonoro para níveis críticos.
- [x] Diferenciação de alertas:
   - LED amarelo + Buzzer curto: Alerta leve.
   - LED vermelho piscando + Buzzer contínuo: Alerta crítico.
- [x] Botão físico para reset manual do alarme.

---

## 🚀 Como Executar o Projeto

💡Siga as instruções abaixo para configurar, compilar e executar o programa no seu **Arduino Uno**.

### 📦 Pré-requisitos

Antes de começar, certifique-se de ter instalado:
  - [Arduino IDE](https://www.arduino.cc/en/software) para programação do microcontrolador.
  - [Git](https://git-scm.com) para versionamento de código (opcional, mas recomendado).
  - Placa Arduino Uno.
  - Sensores: MQ-2 (Gás e Fumaça) e Sensor de Chama.
  - Componentes: Buzzer passivo, LEDs (vermelho e amarelo) e botão push-button.

### 🎲 Rodando o Projeto

```bash
# Clone o repositório
$ git clone https://github.com/ferreiramateusalencar/sensor_anti-incendio.git

# Acesse o diretório
$ cd sensor_anti-incendio

# Abra o arquivo .ino no Arduino IDE e faça o upload para a placa Arduino Uno.
```

---

## 🛠️ Tecnologias Utilizadas

- **Microcontrolador:** Arduino Uno.
- **Linguagem:** C/C++ para microcontroladores (Arduino IDE).
- **Sensores:** MQ-2 (gás/fumaça) e Sensor de Chama.
- **Protocolo de Comunicação (Planejado):** MQTT (próxima fase).

---

## 👨‍💻 Contribuidores

<table>
  <tr>
    <td align="center"><img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/86336670?v=4" width="100px;"/><br/><a href="https://github.com/ferreiramateusalencar">Mateus A. Ferreira</a><br/><sub>Desenvolvedor e idealizador</sub></td>
  </tr>
</table>

---

## 📄 Licença

Este projeto está sob a licença do discente **Mateus Alencar Ferreira**, aluno da Formação Básica em Software Embarcado da Embarcatech. Consulte o arquivo [License.md](https://github.com/ferreiramateusalencar/sensor_anti-incendio/blob/main/License.md) para mais detalhes.

---

