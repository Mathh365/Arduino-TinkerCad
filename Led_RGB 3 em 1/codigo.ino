// C++ code

const int
red = 2, green = 3,
blue = 4, yellow = 5,
magenta = 6, cyan = 7,
//------------------------
ledRed = 11,
ledGreen = 9,
ledBlue = 10;
//------------------------
unsigned long lastCall = 0; //variaveis usadas no temporizador principal
int estado = 0;

void setup()
{
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(red, INPUT);
  pinMode(green, INPUT);
  pinMode(blue, INPUT);
  pinMode(yellow, INPUT);
  pinMode(magenta, INPUT);
  pinMode(cyan, INPUT);
}
void loop()
{
  transicao();
}
//--------------------------------------------------------------------------
//FUNÇÕES
void inverteLed(int led){ // função util para debug em alguns casos
	digitalWrite(led, !digitalRead(led));
}
//--------------------------------------------------------------------------
void potenciometro(void){
  analogWrite(9, analogRead(A0) / 4);
  analogWrite(10, analogRead(A1) / 4);
  analogWrite(11, analogRead(A2) / 4);
}
//--------------------------------------------------------------------------
void controleDeCores(bool isToggle) { // parametro 1 para botoes persistentes, 0 para pulso
  if (digitalRead(red)) {           // vermelho
    if (isToggle == 1) apagaTudo(0);     // só apaga se NÃO estiver em toggle
    digitalWrite(ledRed, 1);
  } else if (digitalRead(green)) {    // apaga tudo e ascende verde
    if (isToggle == 1) apagaTudo(0);
    digitalWrite(ledGreen, 1);
  } else if (digitalRead(blue)) {     // apaga tudo e ascende azul
    if (isToggle == 1) apagaTudo(0);
    digitalWrite(ledBlue, 1);
  } else if (digitalRead(yellow)) {   // apaga tudo e ascende amarelo
    if (isToggle == 1) apagaTudo(0);
    digitalWrite(ledRed, 1);
    digitalWrite(ledGreen, 1);
  } else if (digitalRead(magenta)) {  // apaga tudo e ascende roxo
    if (isToggle == 1) apagaTudo(0);
    digitalWrite(ledBlue, 1);
    digitalWrite(ledRed, 1);
  } else if (digitalRead(cyan)) {     // apaga tudo e ascende ciano
    if (isToggle == 1) apagaTudo(0);
    digitalWrite(ledBlue, 1);
    digitalWrite(ledGreen, 1);
  }
  //executa só se isToggle == false
  if (isToggle == 0) {
    apagaTudo(0);
  }
}
//--------------------------------------------------------------------------
void apagaTudo(int isFade){ // apaga todos os leds subitamente se receber parametro 0, e em fade se receber 1
  if (isFade){
  	fadeOut(ledRed);
    fadeOut(ledGreen);
    fadeOut(ledBlue);
  } else{
  	digitalWrite(ledRed, 0);
  	digitalWrite(ledGreen, 0);
  	digitalWrite(ledBlue, 0);
  }
}
//--------------------------------------------------------------------------
void fadeIn(int cor){ // função que ascende o led gradualmente
  int intensidade = 0; // usando variaveis privadas para nao interferir com as globais da funçao transicao
  unsigned long lastPrivado = 0, atualPrivado; // desta maneira, ela trava o sistema assim como o delay, mas quis praticar o uso do millis, entao usei ele mesmo
  
  while(intensidade <= 255){
    atualPrivado = millis();
    if ((atualPrivado - lastPrivado) > 5) {
      analogWrite(cor, intensidade); // a função analogWrite aceita valores de 0-255
      intensidade++;                 // e essa alta resolução isso foi usada para fazer a transição gradual dos leds
      lastPrivado = atualPrivado;
    }
  }
}
//--------------------------------------------------------------------------
void fadeOut(int cor){ // função que apaga o led gradualmente
  int intensidade = 255; // usando variaveis privadas para nao interferir com as globais da funçao transicao
  unsigned long lastPrivado = 0, atualPrivado;
  
  while(intensidade > 0){
    atualPrivado = millis();
    if ((atualPrivado - lastPrivado) > 5) {
      analogWrite(cor, intensidade);
      intensidade--;
      lastPrivado = atualPrivado;
    }
  }
}
//--------------------------------------------------------------------------
void transicao(void){ // função responsavel pelo gerenciamento dos fades em intervalos fixos
  unsigned long msAtual = millis();
  if ((msAtual - lastCall) > 1000){
    switch (estado){
      case 0:
      	apagaTudo(0);
      	estado++;
      	break;
      case 1:
      	fadeIn(ledRed);
      	estado++;
      	break;
      case 2:
      	fadeIn(ledGreen);
      	fadeOut(ledRed);
      	estado++;
      	break;
      case 3:
      	fadeIn(ledBlue);
      	fadeOut(ledGreen);
      	estado++;
      	break;
      case 4:
      	fadeOut(ledBlue);
      	estado = 0;
      	break;
    }
  	lastCall = msAtual;
  }
}
//---------------------------------------------------------------------------

