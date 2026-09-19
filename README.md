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

O projeto **GoodWe SmartCharge** apresenta um protótipo funcional de um sistema inteligente para gerenciamento da recarga de veículos elétricos. O objetivo é demonstrar a integração entre programação, eletrônica e automação para simular o gerenciamento de demanda durante um horário de pico, representando de forma visual a redução da potência de carregamento para alívio da rede elétrica.

*  **Vídeo de Demonstração (Até 5 minutos):** [COLE AQUI O LINK DO VÍDEO DO YOUTUBE/VIMEO]
*  **Simulação Interativa:** [COLE AQUI O LINK DO TINKERCAD]

---

## 3. Esquema de Integração e Arquitetura

O funcionamento do sistema ocorre através da integração entre blocos de entradas, processamento e saídas:

* **Entradas:** 
  * **Botão 1 (Pino D2):** Simula a conexão física de um veículo elétrico à estação.
  * **Botão 2 (Pino D3):** Simula o sinal de horário de pico emitido pela rede elétrica.
* **Processamento:** Microcontrolador **Arduino Uno** que recebe as informações das entradas digitais e executa a lógica de automação programada.
* **Saídas:** 
  * **LED D8:** Representa o estado de carregamento normal (Potência Máxima).
  * **LED D9:** Representa a redução simulada da potência (Horário de Pico).
  * **LED D10:** Representa o sistema em espera (Aguardando Veículo).

![Diagrama de integração](diagramas/diagrama-integracao.png)

---

## 4. Código-Fonte do Protótipo

O algoritmo de controle foi desenvolvido na IDE do Arduino e implementa resistores internos via software (`INPUT_PULLUP`). O arquivo original pode ser acessado em [`codigo/smartcharge.ino`](./codigo/smartcharge.ino).

<details>
<summary><b>▶ Clique aqui para expandir e visualizar o código completo</b></summary>

```cpp
const int botaoVeiculo = 2;
const int botaoPico = 3;

const int ledNormal = 8;
const int ledAmarelo = 9;
const int ledVermelho = 10;

void setup() {
  // Configuração dos botões como entrada com pull-up interno
  pinMode(botaoVeiculo, INPUT_PULLUP);
  pinMode(botaoPico, INPUT_PULLUP);

  // Configuração dos pinos dos LEDs como saída
  pinMode(ledNormal, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop() {
  // Cenário 1: Se o horário de pico estiver ativo (Prioridade de segurança da rede)
  if (digitalRead(botaoPico) == LOW) {
    digitalWrite(ledNormal, LOW);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);
  }
  // Cenário 2: Se o veículo estiver conectado e fora do horário de pico
  else if (digitalRead(botaoVeiculo) == LOW) {
    digitalWrite(ledNormal, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  }
  // Cenário 3: Estado de espera (Nenhum veículo conectado)
  else {
    digitalWrite(ledNormal, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
  }
}
```

</details>

---

## 5. Documentação Técnica Aprofundada

Para manter este guia objetivo, as seções completas de análises, diagramas de fluxo e manuais detalhados exigidos pelos critérios de avaliação da Sprint 3 foram movidas para arquivos dedicados:

*  **[Resultados de Testes e Validações](./docs/RESULTADOS_TESTES.md):** Contém a tabela de cenários, o fluxograma lógico do sistema e os prints de comprovação de funcionamento de cada LED na simulação.
*  **[Fundamentação e Justificativa Técnica](./docs/RELATORIO_TECNICO.md):** Apresenta o embasamento teórico da escolha dos componentes (resistores de 220 Ω, pinos digitais), a conexão do projeto com as disciplinas da FIAP e os pilares de sustentabilidade e eficiência energética.
*  **[Manual de Operação e Instruções](./docs/INSTRUCOES.md):** Guia passo a passo com o fluxo de comandos para o professor ligar, interagir e validar o circuito no ambiente virtual.

---

## Estrutura de Arquivos do Repositório

```text
GoodWe-SmartCharge/
│
├── README.md                 # Visão geral, arquitetura e código-fonte
├── codigo/
│   └── smartcharge.ino       # Código-fonte oficial do Arduino
├── diagramas/
│   ├── diagrama-integracao.png
│   └── fluxograma.png
├── imagens/
│   ├── circuito-completo.png
│   ├── teste-vermelho.png
│   ├── teste-normal.png
│   └── teste-amarelo.png
└── docs/
    ├── RELATORIO_TECNICO.md  # Justificativas técnicas e sustentabilidade
    ├── RESULTADOS_TESTES.md  # Evidências em imagem e tabela de testes
    └── INSTRUCOES.md         # Guia passo a passo de funcionamento
```
