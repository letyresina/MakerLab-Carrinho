#include <Wire.h>
#include <Adafruit_VL53L0X.h>

Adafruit_VL53L0X sensor = Adafruit_VL53L0X();

// L298N
#define IN1 11
#define IN2 10
#define IN3 9
#define IN4 8

// 20 cm
#define DISTANCIA_OBSTACULO 200

void frente() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void tras() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void direita() {
  // Uma roda para frente e outra para trás
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void parar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setup() {
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  parar();

  Wire.begin();

  Serial.println("Iniciando sensor...");

  if (!sensor.begin()) {
    Serial.println("ERRO: sensor VL53L0X nao encontrado!");

    while (1) {
      parar();
      delay(100);
    }
  }

  Serial.println("Sensor OK!");
  Serial.println("Carrinho iniciado!");

  delay(1000);
}

void loop() {

  VL53L0X_RangingMeasurementData_t medida;

  sensor.rangingTest(&medida, false);

  if (medida.RangeStatus != 4) {

    int distancia = medida.RangeMilliMeter;

    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" mm");

    if (distancia <= DISTANCIA_OBSTACULO) {

      Serial.println("OBSTACULO!");

      // Para
      parar();
      delay(300);

      // Dá ré
      tras();
      delay(700);

      parar();
      delay(200);

      // Vira para direita
      direita();
      delay(650);

      parar();
      delay(200);

    } else {

      // Sem obstáculo
      frente();
    }

  } else {

    // Se não enxergar nada, caminho livre
    Serial.println("Sem obstaculo no alcance");
    frente();
  }

  delay(50);
}
