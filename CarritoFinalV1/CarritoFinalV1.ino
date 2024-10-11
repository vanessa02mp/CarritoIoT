// Definimos los pines para el L298D en un arreglo
int motores[] = {23, 22, 19, 21};  // IN1, IN2, IN3, IN4 para ambos motores

// Pines de habilitación (PWM) en un arreglo
int enable[] = {5, 18};  // ena para motor derecho, enb para motor izquierdo

// Pines del sensor ultrasonido
const int EchoPin = 35;
const int TriggerPin = 32;

// Velocidad de los motores (PWM 0-255)
int velocidad = 100; // Ajustar la velocidad entre 0 y 255

void setup() {
  // Configurar pines de control de los motores como salida
  for (int i = 0; i < 4; i++) {
    pinMode(motores[i], OUTPUT);
  }

  // Configurar pines de habilitación (PWM) como salida
  for (int i = 0; i < 2; i++) {
    pinMode(enable[i], OUTPUT);
  }

  // Configuramos los pines del sensor ultrasonido
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);

  // Inicializar la velocidad de los motores
  for (int i = 0; i < 2; i++) {
    analogWrite(enable[i], velocidad);
  }

  // Iniciar la comunicación serial
  Serial.begin(9600);
}

void loop() {
  // Medir la distancia
  float distancia = ping(TriggerPin, EchoPin);
  Serial.print("Distancia: ");
  Serial.println(distancia);

  // Comprobar si hay un obstáculo
  if (distancia < 30) {  // Si la distancia es menor a 30 cm
    detenerCarrito();
    delay(1000);         // Esperar 1 segundo
    girarDerecha();      // Girar a la derecha si hay un obstáculo
    delay(1000);         // Mant

