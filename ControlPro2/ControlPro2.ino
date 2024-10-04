#include <Wire.h>

#define SLAVE1_ADDR 0x40  // Dirección del esclavo 1
#define SLAVE2_ADDR 0x50  // Dirección del esclavo 2

void setup() {
  Serial.begin(9600);      // Inicia la comunicación serie
  Wire.begin();            // Inicia la comunicación I2C como maestro
}

void loop() {
  char receivedChar;

  // Leer caracteres del esclavo 1 (0x40)
  Wire.requestFrom(SLAVE1_ADDR, 1);  // Solicita 1 byte desde el esclavo 0x40
  if (Wire.available()) {            // Si el esclavo envía datos
    receivedChar = Wire.read();      // Leer el carácter enviado por el esclavo 1
    if (receivedChar != '\0') {      // Si el dato no es nulo ('\0')
      Serial.print("Caracter del esclavo 1 (0x40): ");
      Serial.println(receivedChar);  // Imprimir el carácter leído
    }
  }
  delay(500);  // Espera 500 ms entre lecturas

  // Leer caracteres del esclavo 2 (0x50)
  Wire.requestFrom(SLAVE2_ADDR, 1);  // Solicita 1 byte desde el esclavo 0x50
  if (Wire.available()) {            // Si el esclavo envía datos
    receivedChar = Wire.read();      // Leer el carácter enviado por el esclavo 2
    if (receivedChar != '\0') {      // Si el dato no es nulo ('\0')
      Serial.print("Caracter del esclavo 2 (0x50): ");
      Serial.println(receivedChar);  // Imprimir el carácter leído
    }
  }
  delay(500);  // Espera 500 ms entre lecturas
}
