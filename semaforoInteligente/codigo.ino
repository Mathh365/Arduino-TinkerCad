const int  // atalho para as portas dos leds e chaves
sensorA = 10, sensorB = 1,
vermelhoA = 13, vermelhoB = 4,
amareloA = 12, amareloB = 3,
verdeA = 11, verdeB = 2;

int estado = 0;
unsigned long lastCall = 0;
void timer(unsigned long tempo, void(*proximoEstado)()); //inicializando a função de timer criada mais a baixo

void setup() // configura e inicializa os leds e chaves
{ 

  iniciarLed(vermelhoA, 0);
  iniciarLed(vermelhoB, 0);
  iniciarLed(amareloA, 0);
  iniciarLed(amareloB, 0);
  iniciarLed(verdeA, 0);
  iniciarLed(verdeB, 0);
  pinMode(sensorA, INPUT);
  pinMode(sensorB, INPUT);
}
//Main------------------------------------------------------------------------
void loop() // dispara as funçoes para fazer o circuito funcionar corretamente
{
  if (!digitalRead(sensorA) && !digitalRead(sensorB)) piscaAmarelo(); //se nao tiver carros, dispara a função que faz piscar em amarelo
  if (digitalRead(sensorA) && digitalRead(sensorB)) padrao(); //se tiver carro nas duas, dispara a função que faz os semaforos rodarem na ordem padrao
  if ((digitalRead(sensorA) == 1) && (digitalRead(sensorB) == 0)) estado1(); //se tiver carro apenas na A, abre ela e fecha a B
  if ((digitalRead(sensorA) == 0) && (digitalRead(sensorB) == 1)) estado3(); //se tiver carro apenas na B, abre ela e fecha a A
}
//Main------------------------------------------------------------------------
//FUNÇÕES
void timer(unsigned long tempo, void(*proximoEstado)()){ //função de timer nao-travante
  unsigned long msAtual = millis();
  if ((msAtual - lastCall) > tempo){
    lastCall = msAtual;
    proximoEstado();
    estado++;
    if (estado > 3) estado = 0;
  }
}
//----------------------------------------------------------------------------
void estado1(void){ // A VERDE // B VERMELHO
  digitalWrite(verdeA, 1);
  digitalWrite(verdeB, 0);
  digitalWrite(amareloA, 0);
  digitalWrite(amareloB, 0);
  digitalWrite(vermelhoA, 0);
  digitalWrite(vermelhoB, 1);
}
//----------------------------------------------------------------------------
void estado2(void){ //A AMARELO // B VERMELHO
  digitalWrite(verdeA, 0);
  digitalWrite(verdeB, 0);
  digitalWrite(amareloA, 1);
  digitalWrite(amareloB, 0);
  digitalWrite(vermelhoA, 0);
  digitalWrite(vermelhoB, 1);
}
//----------------------------------------------------------------------------
void estado3(void){ //A VERMELHO // B VERDE
  digitalWrite(verdeA, 0);
  digitalWrite(verdeB, 1);
  digitalWrite(amareloA, 0);
  digitalWrite(amareloB, 0);
  digitalWrite(vermelhoA, 1);
  digitalWrite(vermelhoB, 0);
}
//----------------------------------------------------------------------------
void estado4(void){ // A VERMELHO // B AMARELO
  digitalWrite(verdeA, 0);
  digitalWrite(verdeB, 0);
  digitalWrite(amareloA, 0);
  digitalWrite(amareloB, 1);
  digitalWrite(vermelhoA, 1);
  digitalWrite(vermelhoB, 0);
}
//----------------------------------------------------------------------------
void piscaAmarelo(void){ //apaga tudo, e começa a piscar apenas os amarelos em intervalos de 500ms
  	digitalWrite(vermelhoA, 0);
    digitalWrite(vermelhoB, 0);
    digitalWrite(verdeA, 0);
    digitalWrite(verdeB, 0);
  if ((millis() - lastCall) > 500){
  	inverteLed(amareloA);
    inverteLed(amareloB);
    lastCall = millis();
  }
}
//----------------------------------------------------------------------------
void inverteLed(int led){ //apenas recebe o estado atual do led, e inverte ele, usada na função de piscaAmarelo
	digitalWrite(led, !digitalRead(led));
}
//----------------------------------------------------------------------------
void padrao(void){ //chama os respectivos estados, para que o semaforo opere em ordem padrao
  if (estado == 0) timer(3000, estado1);
  if (estado == 1) timer(1000, estado2);
  if (estado == 2) timer(3000, estado3);
  if (estado == 3) timer(1000, estado4);
}
//----------------------------------------------------------------------------
// AUXILIARES
void iniciarLed(int led, bool estado){
  pinMode(led, OUTPUT);
  digitalWrite(led, estado);
}
