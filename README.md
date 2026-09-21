# Sprint3_Solu-esRenov-veis

# GoodWe SmartCharge

## Sistema Inteligente de Gestão de Recarga de Veículos Elétricos

### Equipe

* Nome completo — RM
* Nome completo — RM
* Nome completo — RM
* Turma: [preencher]

---

## Objetivo do Projeto

O **GoodWe SmartCharge** é um protótipo de sistema inteligente para gerenciamento da recarga de veículos elétricos.

O projeto utiliza um **Arduino Uno** para simular a tomada de decisão de uma estação de carregamento a partir de duas condições:

* Veículo conectado;
* Horário de pico da rede elétrica.

A partir dessas condições, o sistema controla três LEDs que representam diferentes estados do carregamento.

---

## Esquema de Integração

O sistema é composto por entradas, processamento e saídas.

### Entradas

* **Botão 1 — D2:** representa um veículo conectado.
* **Botão 2 — D3:** representa um horário de pico.

### Processamento

* **Arduino Uno:** realiza a leitura dos botões e executa a lógica de controle do sistema.

### Saídas

* **LED D8 — Azul:** representa o carregamento normal.
* **LED D9 — Amarelo:** representa a potência reduzida.
* **LED D10 — Vermelho:** representa o sistema aguardando.

O diagrama de blocos apresenta a integração entre os componentes.

**Arquivo:** `Diagramas/diagrama-integracao.png`

---

## Fluxograma

O fluxograma representa a lógica utilizada pelo Arduino.

O sistema verifica primeiro se o botão de horário de pico está pressionado. Caso esteja, o LED amarelo é acionado, representando a redução da potência.

Caso não esteja em horário de pico, o sistema verifica se existe um veículo conectado. Se o botão do veículo estiver pressionado, o LED azul é acionado, representando o carregamento normal.

Quando nenhum botão está pressionado, o LED vermelho permanece ligado, indicando que o sistema está aguardando.

**Arquivo:** `Diagramas/fluxograma.png`

---

## Imagens e Resultados dos Testes

Os testes foram realizados no ambiente de simulação Tinkercad.

Foram verificados os seguintes estados:

* **LED vermelho:** sistema aguardando;
* **LED azul:** carregamento normal;
* **LED amarelo:** potência reduzida.

As imagens dos testes estão disponíveis na pasta:

`Resultado dos Testes/`

---

## Justificativa Técnica

O **Arduino Uno** foi escolhido como unidade de controle por permitir a leitura dos botões e o acionamento dos LEDs de maneira simples e integrada.

Os botões simulam as condições de operação da estação de recarga, enquanto os LEDs fornecem uma representação visual do estado atual do sistema.

A utilização de entradas digitais e saídas digitais permite demonstrar, de forma prática, conceitos de programação, automação e controle de dispositivos.

---

## Sustentabilidade, Automação e Eficiência Energética

O projeto demonstra o conceito de gerenciamento inteligente de energia aplicado ao carregamento de veículos elétricos.

Durante o horário de pico, o sistema simula a redução da potência de carregamento por meio do LED amarelo. Essa representação demonstra uma estratégia de gerenciamento de demanda, buscando evitar o uso excessivo de energia em períodos de maior demanda.

A automação ocorre porque o Arduino identifica as condições de entrada e define automaticamente o estado correspondente do sistema.

Dessa forma, o protótipo demonstra como a automação pode contribuir para um uso mais eficiente da energia em uma estação de carregamento.

---

## Conexão com os Conteúdos do Curso

O projeto integra diferentes conceitos trabalhados durante o curso, principalmente:

* Programação;
* Lógica de programação;
* Estruturas condicionais;
* Entradas e saídas digitais;
* Eletrônica básica;
* Sistemas embarcados;
* Automação;
* Microcontroladores.

A aplicação desses conceitos permite construir um protótipo funcional capaz de receber informações, processá-las e apresentar uma resposta visual.

---

## Código-Fonte

O código utilizado no protótipo está disponível na pasta:

`Código/smartcharge.ino`

### Funcionamento dos componentes

| Componente       | Pino | Função                   |
| ---------------- | ---: | ------------------------ |
| Botão do veículo |   D2 | Simula veículo conectado |
| Botão de pico    |   D3 | Simula horário de pico   |
| LED azul         |   D8 | Carregamento normal      |
| LED amarelo      |   D9 | Potência reduzida        |
| LED vermelho     |  D10 | Sistema aguardando       |

---

## Protótipo no Tinkercad

O protótipo foi desenvolvido e testado utilizando o Tinkercad.

**Link do protótipo:**

[https://www.tinkercad.com/things/h5m8NsnMyd2-goodwe-smartcharge]

---

## Estrutura do Projeto

```text
GoodWe-SmartCharge/
│
├── README.md
│
├── Diagramas/
│   ├── diagrama-integracao.png
│   └── fluxograma.png
│
├── Relatório Técnico/
│   └── relatorio-tecnico.pdf
│
├── Resultado dos Testes/
│   ├── circuito-completo.png
│   ├── teste-vermelho.png
│   ├── teste-azul.png
│   └── teste-amarelo.png
│
└── Código/
    └── smartcharge.ino
```

---

## Observação

A indicação de **potência reduzida** no protótipo é uma simulação visual realizada por meio do LED amarelo. O circuito não realiza uma medição real de potência elétrica.

