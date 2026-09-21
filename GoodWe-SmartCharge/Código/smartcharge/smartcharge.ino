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