#define sound 500

int buzzer = 24;

int light = 23;
int signalsend = 11;

void setup() {
  Serial.begin(9600);
  
  pinMode(light, OUTPUT);
  pinMode(signalsend, OUTPUT);


  srand(millis()); //incializar random

  Serial.println("A = secuencia al azar con buzzer");
  Serial.println("B = secuencia fija con buzzer");
  Serial.println("C = secuencia al azar con luz");
  Serial.println("D = secuencia fija con luz");
  
}

void loop() {
  if (Serial.available() > 0) {char incomingdata = Serial.read();
  switch (incomingdata) {
  case 'A': 
  Serial.println("Sequencia buzzer random iniciado");
  randomsequence_b();
  Serial.println("Finalizado");
  break;
  
  case 'B': 
  Serial.println("Sequencia buzzer tiempo fijo iniciado");
  fisequence_b();
  Serial.println("Finalizado");
  break;

  case 'C': 
  Serial.println("Sequencia luz random iniciado");
  randomsequence_l();
  Serial.println("Finalizado");
  break;

  case 'D': 
  Serial.println("Sequencia luz tiempo fijo iniciado");
  fisequence_l();
  Serial.println("Finalizado");
  break;

  //case -1: break;

  default: 
  Serial.println();
  Serial.println("A = secuencia al azar con buzzer");
  Serial.println("B = secuencia fija con buzzer");
  Serial.println("C = secuencia al azar con luz");
  Serial.println("D = secuencia fija con luz");
  break;}}
  
}

void randomsequence_b() {
  for (int x = 0; x < 10; x++) {
   
  int d = (rand() % 10) + 2;
  delay(d*1000);
  digitalWrite(signalsend, HIGH); //mandar señal al biopac
  tone(buzzer, sound, 500); //encender buzzer
  delay(500);
  digitalWrite(signalsend, LOW);
  Serial.print(x + 1);
  Serial.print(" "); 
  }
  
}

void randomsequence_l() {
  for (int x = 0; x < 10; x++) {
  int d = (rand() % 10) + 2;
  delay(d*1000);
  digitalWrite(light, HIGH);
  digitalWrite(signalsend, HIGH);
  delay(500);
  digitalWrite(light, LOW);
  digitalWrite(signalsend, LOW);
  Serial.print(x + 1);
  Serial.print(" "); }

}

void fisequence_b() {
  int d = (rand() % 6) + 2;
  for (int x = 0; x < 10; x++) {
    delay(d*1000);
    digitalWrite(signalsend, HIGH); //mandar señal al biopac
    tone(buzzer, sound, 500); //encender buzzer
    delay(500);
    digitalWrite(signalsend, LOW);
    Serial.print(x + 1);
  Serial.print(" "); 
  }
}

void fisequence_l() {
  int d = (rand() % 6) + 2;
  for (int x = 0; x < 10; x++) {
  delay(d*1000);
  digitalWrite(light, HIGH);
  digitalWrite(signalsend, HIGH);
  delay(500);
  digitalWrite(light, LOW);
  digitalWrite(signalsend, LOW);
  Serial.print(x + 1);
  Serial.print(" "); }
}
