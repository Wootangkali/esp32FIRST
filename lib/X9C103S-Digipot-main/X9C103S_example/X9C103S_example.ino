#include "X9C103S_digipot.h"

#define PIN_CS 5
#define PIN_UD 6
#define PIN_INC 7

DigiPot pot(PIN_CS, PIN_UD, PIN_INC); // Пины дигипота CS,UD,INC

void setup() {
   pot.reset();  		    // Сбросить потенциометр в минимум
   pot.increment(20);   // Увеличить сопротивление на 20 шагов
   pot.write(30);		    // Установить сопротивление в 30/100	
}

void loop() {
   
}
