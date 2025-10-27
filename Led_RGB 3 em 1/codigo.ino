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
  potenciometro();         // EX 01 || controle de brilho via potenciometros
  controleDeCores(1);      // EX 02 || controle de cores via botoes (1 para persistente, 0 para pulso)
  transicao();             // EX 03 || transição automatica entre as cores com fade
}
//--------------------------------------------------------------------------
//FUNÇÕES
void potenciometro(void){ //EX 01 || função que controla o brilho via potenciometros
  analogWrite(9, analogRead(A0) / 4);
  analogWrite(10, analogRead(A1) / 4);
  analogWrite(11, analogRead(A2) / 4);
}
//--------------------------------------------------------------------------
void controleDeCores(bool isToggle) {    // EX 02 || função que controla as cores via botões
  if (digitalRead(red)) {             // apaga tudo e ascende vermelho
    if (isToggle == 1) apagaTudo(0);  // se isToggle for true, apaga tudo antes de acender a nova cor
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
  // se nenhum botão estiver pressionado e isToggle for falso, apaga todos os leds
  if (isToggle == 0) {
    apagaTudo(0);
  }
}
//--------------------------------------------------------------------------
void transicao(void){ // função que faz a transição automatica entre as cores com fade
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
//--------------------------------------------------------------------------

void apagaTudo(int isFade){ // função que apaga todos os leds, com ou sem fade decicido pelo parametro isFade
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
void fadeIn(int cor){ // função que acende o led gradualmente
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
//---------------------------------------------------------------------------
void inverteLed(int led){ // função util para debug em alguns casos, inverte o estado do led passado como parametro
	digitalWrite(led, !digitalRead(led));
}
//--------------------------------------------------------------------------
