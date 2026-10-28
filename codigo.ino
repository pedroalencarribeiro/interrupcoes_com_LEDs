//porque o LED precisa do Resistor:

//O pino da ESP tem 3,3V.
//O LED vermelho só “aceita” ficar em ~2 V.
//Qualquer tensão a mais no LED faz a corrente subir muito, porque tem 1,3V sobrando, e a porta da ESP tenta empurrar essa tensão restante que o LED não consome.
//Sem nada para segurar, a corrente dispara e algo sofre: o LED, o pino, ou os dois.

//O resistor resolve isso porque fica com a diferença de 1,3 V e transforma uma situação descontrolada numa corrente previsível, calculada pela Lei de Ohm.

// Por que o botão precisa do resistor (pull-down):

// O botão é só uma chave: solto, separa os dois lados; apertado, liga os dois como um fio.
// O pino BOTAO_VERDE do ESPBOTAO_AMARELO não tem resistor interno de pull-up/pull-down.
// Sem resistor, o pino solto não fica em 0 V: fica "flutuando", sem tensão definida,
// guardando carga ou captando ruído, e lê HIGH/LOW aleatoriamente.

// Botão solto: o resistor liga o pino ao GND. Qualquer carga ou ruído no pino escoa
// pelo resistor até o GND (em bilionésimos de segundo), então o pino fica em 0 V (LOW).
// Botão apertado: o pino fica ligado direto no 3,3 V e lê HIGH.
// Funciona como um cabo de guerra: o botão (~0 Ω) ganha do resistor (1 kΩ).

// O resistor não protege o pino: a entrada quase não puxa corrente.
// A corrente vai 3,3 V -> botão -> resistor -> GND, e o pino só "lê" a tensão.
// Tem que ser resistor, e não fio: um fio ligaria 3,3 V direto no GND (curto) ao apertar,
// derrubando a alimentação do ESP32. O resistor limita a corrente (3,3 V / 1 kΩ ≈ 3,3 mA).


// ATRIBUIÇÃO DOS PINOS

const int BOTAO_VERDE = 34;
const int BOTAO_AZUL = 35;
const int BOTAO_AMARELO = 32;

const int LED_VERMELHO = 23;
const int LED_AMARELO = 16;
const int LED_AZUL = 00;
const int LED_VERDE = 15;

void setup() {
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT); 
  pinMode(LED_AZUL, OUTPUT); 
  pinMode(LED_VERDE, OUTPUT); 
  pinMode(BOTAO_VERDE, INPUT);  
  pinMode(BOTAO_AZUL, INPUT);  
  pinMode(BOTAO_AMARELO, INPUT);  
  attachInterrupt(digitalPinToInterrupt(BOTAO_VERDE), acendeLEDVerde, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BOTAO_AZUL), acendeLEDAzul, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BOTAO_AMARELO), acendeLEDAmarelo, CHANGE);
}

void loop() {
  digitalWrite(LED_VERMELHO, HIGH); // Coloca o pino do LED VERMELHO em HIGH
  delay(1000); // 1000 ms, que é 1 s
  digitalWrite(LED_VERMELHO, LOW); // Coloca o pino do LED VERMELHO em LOW
  delay(1000);
}

void acendeLEDVerde() {
  if(digitalRead(BOTAO_VERDE) == HIGH){ // Verifica estado do botão
    digitalWrite(LED_VERDE, HIGH); // Coloca o pino do LED VERDE em HIGH
  } else{
    digitalWrite(LED_VERDE, LOW); // Coloca o pino do LED VERDE em LOW
  }
}

void acendeLEDAzul() {
  if(digitalRead(BOTAO_AZUL) == HIGH){ // Verifica estado do botão
    digitalWrite(LED_AZUL, HIGH); // Coloca o pino do LED VERDE em HIGH
  } else{
    digitalWrite(LED_AZUL, LOW); // Coloca o pino do LED VERDE em LOW
  }
}

void acendeLEDAmarelo() {
  if(digitalRead(BOTAO_AMARELO) == HIGH){ // Verifica estado do botão
    digitalWrite(LED_AMARELO, HIGH); // Coloca o pino do LED VERDE em HIGH
  } else{
    digitalWrite(LED_AMARELO, LOW); // Coloca o pino do LED VERDE em LOW
  }
}
