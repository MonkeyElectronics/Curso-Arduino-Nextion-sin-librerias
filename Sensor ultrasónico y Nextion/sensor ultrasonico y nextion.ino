#define TRIG 3
#define ECHO 2
float distancia, suma, promedio;
int i;
void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  distancia = leer_distancia(TRIG, ECHO);
  // Serial.print("t0.txt=");
  // Serial.print("\"");
  // Serial.print(distancia);
  // Serial.print("\"");
  // Serial.write(0xff);
  // Serial.write(0xff);
  // Serial.write(0xff);
  enviar_mensaje(distancia, "t0.txt=");
  delay(200);
}

float leer_distancia(int trig, int echo) {
  float distancia;
  long tiempo;
  digitalWrite(trig, 1);
  delayMicroseconds(10);
  digitalWrite(trig, 0);
  delayMicroseconds(10);
  tiempo = pulseIn(echo, HIGH);
  distancia = tiempo / 58.00;
  delay(100);
  return distancia;
}

void enviar_mensaje(float mensaje, String componente) {
  Serial.print(componente);
  Serial.print("\"");
  Serial.print(mensaje);
  Serial.print("\"");
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
}
