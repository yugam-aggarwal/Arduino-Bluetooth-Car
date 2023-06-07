// C++ code
//
char input;
void setup() {
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, INPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potentiometer = analogRead(A0);
  int potent = potentiometer / 4;

  analogWrite(10, potent);
  analogWrite(11, potent);

  while (Serial.available()) 
  {
    input = Serial.read();

    if (input == 'F') {
      moveForward();
    }
    else if (input == 'G') {
      moveBackward();

    } else if (input == 'R') {
      moveright();

    } else if (input == 'L') {
      moveleft();

    } else if (input == 'S') {
      stop();
    }
  }
}

//Code for PIR SENSOR
// if (digitalRead(3) == LOW)
// {
//   //Serial.println("STOP");
//   stop();
// }
// else
// {
//   moveForward();
// }


void moveForward() {
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
}

void moveBackward() {
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
}

void moveright() {
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
}

void moveleft() {
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
}

void stop() {
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
}
