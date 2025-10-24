const int led1 = 13, led2 = 12, switch1 = 4, switch2 = 2;
bool soma = 0, vaiUm = 0;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
}

void loop()
{
  soma = portaXor(digitalRead(switch1), digitalRead(switch2));
  vaiUm = portaAnd(digitalRead(switch1), digitalRead(switch2));
  digitalWrite(led1, soma);
  digitalWrite(led2, vaiUm);
}
//-----------------------------------------------------------------------
//FUNÇÔES
bool portaAnd (int a, int b){
  if (a && b){
  	return 1;
  } else {
  	return 0;
  }
}
//-----------------------------------------------------------------------
bool portaOr (int a, int b){
  if (a || b){
  	return 1;
  } else {
  	return 0;
  }
}
//-----------------------------------------------------------------------
bool portaNot(bool val){
	return !val;
}
//-----------------------------------------------------------------------
bool portaXor(bool a, bool b){
  return portaOr((portaAnd(portaNot(b), a)), (portaAnd(portaNot(a), b)));
}
//-----------------------------------------------------------------------



