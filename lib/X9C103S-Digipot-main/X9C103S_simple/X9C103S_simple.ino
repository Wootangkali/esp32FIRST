// Простой пример для управления дигипотом X9C103S

#define PIN_CS 5
#define PIN_UD 6
#define PIN_INC 7

void setup() {
  digipotBegin();
  digipotAdjust(30);
}

void loop() {

}

void digipotBegin(void) {     // Настройка пинов дигипота
  pinMode(PIN_CS, OUTPUT);    // Все как выход
  pinMode(PIN_UD, OUTPUT);
  pinMode(PIN_INC, OUTPUT);

  digitalWrite(PIN_UD, HIGH);   // Эти два сразу подтянем
  digitalWrite(PIN_INC, HIGH);
}

void digipotAdjust(int8_t inc) {
  bool direction;           // Флаг для установки направления
  if (inc < 0) {            // Если сдвиг отрицательный
    direction = false;      // Флаг - false
    inc *= -1;              // Убираем отриц. знак
  } else {                  // Иначе
    direction = true;       // Флаг false
  }
  digitalWrite(PIN_CS, LOW);              // Начинаем передачу
  digitalWrite(PIN_UD, direction);        // Устанавливаем направление
  for (uint8_t i = 0; i < inc * 2; i++) {  // Цикл отправки
    digitalWrite(PIN_INC, !digitalRead(PIN_INC)); // Инверсия пина (можно через флаг - быстрее)
  }
  digitalWrite(PIN_CS, HIGH);             // Окончание передачи
}
