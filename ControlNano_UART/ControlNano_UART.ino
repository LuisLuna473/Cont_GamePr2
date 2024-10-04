// Definir pines para los botones y las entradas analógicas
const int buttonPin1 = 2;  // Botón en el pin D2
const int buttonPin2 = 3;  // Botón en el pin D3
const int buttonPin3 = 4;  // Botón en el pin D4
const int buttonPin4 = 5;  // Botón en el pin D5
const int analogPin1 = A0; // Entrada analógica en A0
const int analogPin2 = A3; // Entrada analógica en A3
String buffer = "";

void setup() {
  // Configurar pines de botones como entradas
  pinMode(buttonPin1, INPUT); // Usando resistencia pull-up interna
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);

  // Iniciar comunicación serie
  Serial.begin(9600);
}

void loop() {
  // Leer los estados de los botones
  buffer = "";
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  int buttonState3 = digitalRead(buttonPin3);
  int buttonState4 = digitalRead(buttonPin4);

  // Leer los valores de las entradas analógicas
  int analogValue1 = analogRead(analogPin1);
  int analogValue2 = analogRead(analogPin2);

  // Mostrar caracteres dependiendo del botón presionado
  if (buttonState1 == LOW) { // Botón 1 presionado
    Serial.println("a");
    buffer += "a"; 
  }
  if (buttonState2 == LOW) { // Botón 2 presionado
    Serial.println("b");
    buffer += "b";
  }
  if (buttonState3 == LOW) { // Botón 3 presionado
    Serial.println("c");
    buffer += "c";
  }
  if (buttonState4 == LOW) { // Botón 4 presionado
    Serial.println("d");
    buffer += "d";
  }

  // Verificar el valor de la entrada analógica A3 y mostrar "arriba" o "abajo"
  if (analogValue2 > 560) {
    Serial.println("arriba");
    buffer += "e";
  } else if (analogValue2 < 480) {
    Serial.println("abajo");
    buffer += "f";
  }
  if (analogValue1 > 520) {
    Serial.println("derecha");
    buffer += "g";
  } else if (analogValue1 < 480) {
    Serial.println("izquierda");
    buffer += "h";
  }

  // Enviar el contenido del buffer por UART
  if (buffer.length() > 0) {
    Serial.print(buffer); // Envía el buffer como una cadena de caracteres
  }

  // Pequeña pausa para evitar sobrecargar el monitor serie
  delay(200);
}
