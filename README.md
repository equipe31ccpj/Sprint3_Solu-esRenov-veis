# Sprint3_Solu-esRenov-veis

#  GoodWe SmartCharge — Sistema Inteligente de Gestão de Recarga

##  Sprint 3 — Prototipagem Funcional e Integração

**Instituição:** FIAP
**Curso:** Ciência da Computação
**Turma:** [PREENCHER]
**Disciplina:** [PREENCHER]
**Equipe:** [PREENCHER]
**Integrantes:**

* [Nome completo — RM]
* [Nome completo — RM]
* [Nome completo — RM]
* [Nome completo — RM]

---

# 1.  Sobre o Projeto

O **GoodWe SmartCharge** é um protótipo de sistema inteligente para gerenciamento de recarga de veículos elétricos.

O projeto tem como objetivo demonstrar, por meio de um circuito simulado no **Tinkercad**, como um sistema automatizado pode identificar diferentes condições de operação e alterar o comportamento de uma estação de recarga.

Para isso, foi utilizado um **Arduino Uno**, dois botões como entradas e três LEDs como indicadores visuais das condições do sistema.

O protótipo representa uma solução simplificada de gerenciamento de demanda, na qual o sistema pode adaptar o carregamento de acordo com as condições da rede elétrica.

---

# 2. Objetivo

O objetivo do protótipo é demonstrar a integração entre:

* Programação;
* Eletrônica;
* Automação;
* Gerenciamento de energia;
* Eficiência energética;
* Mobilidade elétrica.

O sistema simula três situações principais:

1. Veículo não conectado;
2. Veículo conectado em condição normal;
3. Horário de pico com redução simulada da potência de carregamento.

---

# 3. Funcionamento do Sistema

O sistema utiliza dois botões como entradas.

### Botão 1 — Veículo conectado

Representa a conexão de um veículo elétrico à estação de carregamento.

### Botão 2 — Horário de pico

Representa uma situação em que existe maior demanda de energia na rede elétrica.

O Arduino recebe essas informações e executa uma lógica de decisão, acionando um dos três LEDs.

### Estados do sistema

| Condição              | LED          | Representação       |
| --------------------- | ------------ | ------------------- |
| Nenhum botão acionado | 🔴 Vermelho  | Sistema aguardando  |
| Botão 1 acionado      | 🔵/🟢 Normal | Carregamento normal |
| Botão 2 acionado      | 🟡 Amarelo   | Potência reduzida   |

> **Observação:** a redução de potência é uma simulação visual da lógica de gerenciamento de demanda. O protótipo não realiza medição real de potência elétrica.

---

# 4. Componentes Utilizados

| Componente     | Quantidade | Função                              |
| -------------- | ---------: | ----------------------------------- |
| Arduino Uno    |          1 | Controlador do sistema              |
| Push Button    |          2 | Simulação das condições de operação |
| LED azul/verde |          1 | Indicação de carregamento normal    |
| LED amarelo    |          1 | Indicação de potência reduzida      |
| LED vermelho   |          1 | Indicação de sistema aguardando     |
| Resistor 220 Ω |          3 | Proteção dos LEDs                   |
| Fios           |   Diversos | Conexão dos componentes             |

---

# 5. Ligações do Circuito

## LEDs

### LED normal

```text
Arduino D8
    ↓
Resistor 220 Ω
    ↓
Perna longa do LED
    ↓
Perna curta
    ↓
GND
```

### LED amarelo

```text
Arduino D9
    ↓
Resistor 220 Ω
    ↓
Perna longa do LED
    ↓
Perna curta
    ↓
GND
```

### LED vermelho

```text
Arduino D10
    ↓
Resistor 220 Ω
    ↓
Perna longa do LED
    ↓
Perna curta
    ↓
GND
```

## Botões

### Botão 1 — Veículo

```text
D2 → Botão → GND
```

### Botão 2 — Horário de pico

```text
D3 → Botão → GND
```

Os botões utilizam a configuração `INPUT_PULLUP` do Arduino, não sendo necessários resistores externos para eles.

---

# 6. Diagrama de Integração

```text
                 ESTAÇÃO DE RECARGA
                        │
                        ▼
              ┌─────────────────┐
              │    ARDUINO UNO  │
              │                 │
              │ Lógica de       │
              │ controle        │
              └────────┬────────┘
                       │
             ┌─────────┴─────────┐
             │                   │
             ▼                   ▼
       ┌───────────┐       ┌───────────┐
       │  BOTÃO 1  │       │  BOTÃO 2  │
       │   D2      │       │    D3     │
       │  Veículo  │       │ Horário   │
       │ conectado │       │ de pico   │
       └───────────┘       └───────────┘
                       │
                       ▼
                LÓGICA DE DECISÃO
                       │
            ┌──────────┼──────────┐
            │          │          │
            ▼          ▼          ▼
          🔵/🟢       🟡         🔴
           D8         D9         D10
         Normal     Reduzido   Aguardando
```

---

# 7. Fluxo de Funcionamento

```text
                 INÍCIO
                    │
                    ▼
          Veículo conectado?
             │            │
            NÃO          SIM
             │            │
             ▼            ▼
        🔴 AGUARDAR   Horário de pico?
                         │       │
                        NÃO     SIM
                         │       │
                         ▼       ▼
                      🔵/🟢     🟡
                      NORMAL   REDUZIDO
```

---

# 8. Código

O código utilizado no protótipo foi desenvolvido em Arduino/C++.

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

  // Primeiro verifica o botão de pico
  if (digitalRead(botaoPico) == LOW) {

    digitalWrite(ledNormal, LOW);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);

  }

  // Depois verifica o veículo
  else if (digitalRead(botaoVeiculo) == LOW) {

    digitalWrite(ledNormal, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);

  }

  // Nenhum botão
  else {

    digitalWrite(ledNormal, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
  }
}
```

---

# 9. Testes Realizados

Foram realizados testes para verificar o funcionamento dos componentes e a integração do sistema.

## Teste 1 — Sistema aguardando

**Ação:** nenhum botão pressionado.

**Resultado esperado:**

 LED vermelho aceso.

**Resultado obtido:** funcionamento confirmado.

---

## Teste 2 — Carregamento normal

**Ação:** pressionar o botão de veículo conectado.

**Resultado esperado:**

 LED normal aceso.

**Resultado obtido:** funcionamento confirmado.

---

## Teste 3 — Horário de pico

**Ação:** pressionar o botão correspondente ao horário de pico.

**Resultado esperado:**

 LED amarelo aceso.

**Resultado obtido:** funcionamento confirmado.


# 10. Sustentabilidade e Eficiência Energética

O protótipo está relacionado ao conceito de eficiência energética porque simula uma estratégia de gerenciamento de demanda.

Durante um período de maior demanda elétrica, o sistema altera seu estado e representa visualmente uma redução da potência de carregamento.

Em uma implementação real, essa lógica poderia ser integrada a sensores de consumo, medidores inteligentes, sistemas de geração solar e informações da rede elétrica.

Dessa maneira, seria possível adaptar automaticamente a operação dos carregadores às condições de disponibilidade de energia.

---

# 11. Automação e Inteligência

O protótipo demonstra automação porque o Arduino recebe informações das entradas e modifica automaticamente as saídas.

A decisão é realizada por meio de uma estrutura condicional:

```text
Entrada → Processamento → Decisão → Saída
```

Exemplo:

```text
Botão acionado
      ↓
Arduino identifica a condição
      ↓
Executa a lógica
      ↓
Aciona o LED correspondente
```

Essa estrutura pode ser expandida futuramente para utilizar sensores e dados reais.

---

# 12. Relação com os Conteúdos do Curso

O projeto utiliza conhecimentos de diferentes áreas.

### Programação

Foram utilizados conceitos como:

* Variáveis;
* Estruturas condicionais;
* `if`;
* `else if`;
* `else`;
* `digitalRead()`;
* `digitalWrite()`;
* `pinMode()`.

### Eletrônica

Foram utilizados:

* Arduino;
* LEDs;
* Resistores;
* Push buttons;
* Entradas digitais;
* Saídas digitais;
* GND.

### Automação

O sistema realiza decisões automaticamente de acordo com as condições recebidas pelos botões.

### Sustentabilidade

O gerenciamento da demanda representa uma estratégia de utilização mais eficiente da energia durante períodos de maior consumo.

---

# 13. Possíveis Melhorias Futuras

O protótipo desenvolvido é uma versão inicial e pode ser expandido.

Entre as possíveis melhorias estão:

* Utilização de sensores reais;
* Medição real de corrente e tensão;
* Medição do consumo energético;
* Integração com painéis solares;
* Monitoramento de geração de energia renovável;
* Controle real da potência do carregador;
* Display para apresentação dos dados;
* Aplicativo ou dashboard para acompanhamento;
* Integração com banco de dados;
* Utilização de inteligência artificial para previsão de demanda;
* Comunicação com sistemas externos.

---

# 14. Simulação no Tinkercad

**Link do projeto:**

[COLE AQUI O LINK DO TINKERCAD]

---

# 15. Estrutura do Repositório

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
├── imagens/
│   ├── circuito-completo.png
│   ├── teste-vermelho.png
│   ├── teste-normal.png
│   └── teste-amarelo.png
│
└── documentos/
    └── Sprint3.pdf
```

---

# 16. Vídeo da Demonstração

O vídeo apresenta:

1. Introdução do projeto;
2. Apresentação dos componentes;
3. Explicação da integração;
4. Teste do sistema aguardando;
5. Teste do carregamento normal;
6. Teste do horário de pico;
7. Explicação da eficiência energética;
8. Conclusão do protótipo.

**Link do vídeo:** [INSERIR LINK, SE NECESSÁRIO]

---

# 17. Conclusão

O projeto GoodWe SmartCharge apresentou um protótipo funcional de uma estação inteligente de gerenciamento de recarga de veículos elétricos.

Através do Arduino, foi possível integrar entradas e saídas para simular diferentes condições de operação. Os botões representam informações do ambiente, enquanto os LEDs apresentam visualmente as decisões tomadas pelo sistema.

O protótipo demonstra os conceitos de automação, programação, eletrônica e gerenciamento de energia. Apesar de utilizar uma simulação, sua estrutura pode ser ampliada para uma solução real utilizando sensores, medidores de energia, fontes renováveis e sistemas inteligentes de controle.

Assim, o projeto demonstra uma aplicação prática da tecnologia no contexto da mobilidade elétrica e da eficiência energética.

---

## Equipe

* **[Nome completo — RM]**
* **[Nome completo — RM]**
* **[Nome completo — RM]**
* **[Nome completo — RM]**

---

## Observação

Este projeto foi desenvolvido como atividade acadêmica da FIAP, utilizando simulação no Tinkercad para demonstrar a integração dos componentes e o funcionamento da lógica de gerenciamento de recarga.
