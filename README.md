# Sprint3_Solu-esRenov-veis

# GoodWe SmartCharge — Sistema Inteligente de Gestão de Recarga

## 1. Título e Equipe

**Projeto:** GoodWe SmartCharge — Sistema Inteligente de Gestão de Recarga de Veículos Elétricos

**Instituição:** FIAP
**Curso:** Ciência da Computação
**Turma:** [PREENCHER]

**Integrantes:**

* [Nome completo — RM]
* [Nome completo — RM]
* [Nome completo — RM]
* [Nome completo — RM]

---

## 2. Objetivo do Projeto

O projeto GoodWe SmartCharge apresenta um protótipo funcional de um sistema inteligente para gerenciamento da recarga de veículos elétricos.

O objetivo é demonstrar a integração entre programação, eletrônica e automação para representar diferentes condições de funcionamento de uma estação de carregamento.

O protótipo utiliza um Arduino Uno, dois botões e três LEDs. Os botões simulam informações recebidas pelo sistema e os LEDs representam visualmente as decisões tomadas pelo Arduino.

O sistema também simula o gerenciamento de demanda durante um horário de pico, representando uma redução da potência de carregamento.

---

## 3. Esquema de Integração

O funcionamento do sistema ocorre através da integração entre entradas, processamento e saídas.

### Entradas

* **Botão 1 — D2:** representa a conexão de um veículo elétrico.
* **Botão 2 — D3:** representa um horário de pico da rede elétrica.

### Processamento

O **Arduino Uno** recebe as informações dos botões e executa a lógica de controle programada.

### Saídas

* **LED D8:** representa o carregamento normal.
* **LED D9:** representa a redução simulada da potência durante o horário de pico.
* **LED D10:** representa o sistema aguardando a conexão de um veículo.

### Diagrama

![Diagrama de integração](diagramas/diagrama-integracao.png)

### Ligações principais

```text
Botão 1 → D2 → Veículo conectado

Botão 2 → D3 → Horário de pico

D8 → LED normal
D9 → LED amarelo
D10 → LED vermelho

Todos os LEDs utilizam resistores de 220 Ω e possuem conexão ao GND.
```

---

## 4. Fluxograma

```text
                    INÍCIO
                       │
                       ▼
              ┌─────────────────┐
              │ Botão 2 ativo?  │
              └────────┬────────┘
                       │
                 ┌─────┴─────┐
                SIM          NÃO
                 │             │
                 ▼             ▼
           LED AMARELO   ┌─────────────────┐
          Potência         │ Botão 1 ativo?  │
          reduzida         └────────┬────────┘
                                    │
                              ┌─────┴─────┐
                             SIM          NÃO
                              │             │
                              ▼             ▼
                             LED D8       LED D10
                           Normal        Aguardando
```

A lógica do sistema verifica os botões e altera automaticamente o estado dos LEDs de acordo com a condição identificada.

---

## 5. Imagens do Protótipo

### Circuito completo

![Circuito completo](imagens/circuito-completo.png)

### Sistema aguardando

Nenhum botão acionado.

![Teste vermelho](imagens/teste-vermelho.png)

### Carregamento normal

Botão do veículo acionado.

![Teste normal](imagens/teste-normal.png)

### Horário de pico

Botão de horário de pico acionado.

![Teste amarelo](imagens/teste-amarelo.png)

---

## 6. Justificativa Técnica

O **Arduino Uno** foi utilizado como controlador do protótipo porque permite receber informações por meio das entradas digitais e controlar componentes de saída através da programação.

Os **botões** foram utilizados para representar condições de operação da estação de carregamento. O primeiro representa a conexão de um veículo elétrico e o segundo representa um período de horário de pico.

Os **LEDs** foram utilizados para apresentar visualmente os diferentes estados do sistema.

O LED conectado ao pino D8 representa o carregamento normal. O LED conectado ao D9 representa a redução simulada da potência durante o horário de pico. O LED conectado ao D10 representa o sistema aguardando a conexão de um veículo.

Os **resistores de 220 Ω** são utilizados para limitar a corrente dos LEDs e proteger os componentes.

A integração desses elementos permite demonstrar uma lógica de automação na qual as entradas são processadas pelo Arduino e geram respostas automáticas nas saídas.

---

## 7. Funcionamento e Resultados

Foram realizados testes para verificar o funcionamento do protótipo.

| Situação            | Entrada      | Resultado    |
| ------------------- | ------------ | ------------ |
| Sistema aguardando  | Nenhum botão |  LED D10   |
| Carregamento normal | Botão 1      |  LED D8 |
| Horário de pico     | Botão 2      |  LED D9    |

Os testes demonstraram que o Arduino consegue receber diferentes entradas e alterar automaticamente as saídas de acordo com a programação.

A redução de potência apresentada pelo LED amarelo é uma **simulação** da estratégia de gerenciamento de demanda. O protótipo não realiza medição ou controle de potência elétrica real.

---

## 8. Sustentabilidade, Automação e Eficiência Energética

O protótipo está relacionado ao gerenciamento inteligente de energia porque simula uma alteração no funcionamento do carregamento durante um período de maior demanda.

Quando o sistema identifica a condição de horário de pico, o LED amarelo é acionado para representar uma redução da potência de carregamento.

Em uma aplicação real, essa lógica poderia ser integrada a sensores, medidores de energia e sistemas de geração renovável, permitindo que o carregamento fosse adaptado de acordo com a disponibilidade de energia e as condições da rede.

Dessa forma, o protótipo demonstra conceitos de:

* **Automação:** o sistema responde automaticamente às entradas.
* **Eficiência energética:** simulação de redução da potência em horário de pico.
* **Sustentabilidade:** gerenciamento mais eficiente do uso de energia.
* **Inteligência:** utilização de condições de entrada para determinar uma ação.

---

## 9. Conexão com os Conteúdos do Curso

O projeto integra conhecimentos relacionados à programação, eletrônica e automação.

Na programação, foram utilizadas estruturas condicionais e funções do Arduino, como:

```cpp
if
else if
else
digitalRead()
digitalWrite()
pinMode()
```

Na parte de eletrônica, foram utilizados Arduino Uno, LEDs, resistores, botões, entradas digitais, saídas digitais e GND.

Na automação, o sistema recebe informações dos botões, processa essas informações e altera automaticamente os LEDs.

Esses conceitos são aplicados ao contexto de estações de carregamento de veículos elétricos e gerenciamento de energia.

---

## 10. Código-Fonte

O código utilizado no protótipo está disponível no arquivo:

```text
codigo/smartcharge.ino
```

Código utilizado:

```cpp
const int botaoVeiculo = 2;
const int botaoPico = 3;

const int ledNormal = 8;
const int ledAmarelo = 9;
const int ledVermelho = 10;

void setup() {

  pinMode(botaoVeiculo, INPUT_PULLUP);
  pinMode(botaoPico, INPUT_PULLUP);

  pinMode(ledNormal, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop() {

  if (digitalRead(botaoPico) == LOW) {

    digitalWrite(ledNormal, LOW);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);

  }

  else if (digitalRead(botaoVeiculo) == LOW) {

    digitalWrite(ledNormal, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);

  }

  else {

    digitalWrite(ledNormal, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
  }
}
```

---

## 11. Instruções de Funcionamento

Para executar o protótipo:

1. Abra o circuito no Tinkercad.
2. Inicie a simulação.
3. Com nenhum botão acionado, o LED vermelho deve permanecer aceso.
4. Pressione o botão de veículo conectado para acionar o LED normal.
5. Pressione o botão de horário de pico para acionar o LED amarelo.
6. Observe a alteração automática dos estados dos LEDs.

---

## 12. Link do Tinkercad

**Circuito utilizado na simulação:**

[COLE AQUI O LINK DO TINKERCAD]

---

## Estrutura do Repositório

```text
GoodWe-SmartCharge/
│
├── README.md
│
├── codigo/
│   └── smartcharge.ino
│
├── diagramas/
│   └── diagrama-integracao.png
│
└── imagens/
    ├── circuito-completo.png
    ├── teste-vermelho.png
    ├── teste-normal.png
    └── teste-amarelo.png
```

