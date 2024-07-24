
#include <Arduino.h>
 #include <Wire.h>




#include <LittleFS.h>
#include <UnixTime.h>
#include <PairsFile.h>
PairsFile conFile(&LittleFS, "/data2.dat", 3000);
// PairsFile conFile(&GH_FS, "/data.dat", 3000);
#define GH_FS LittleFS
#include <PubSubClient.h>
 #define GH_NO_MQTT
#define GH_INCLUDE_PORTAL
#define GH_FILE_PORTAL
#include <GyverTimer.h> 
// #include <GyverTimers.h>
#include <GyverHub.h>
 #include <GSON.h>
#include <Stamp.h>
 #include <TimerMs.h>




 static uint32_t Stamps;

UnixTime stamp(0);  // указать GMT (3 для Москвы)

#include <WIFI.h>
#include <WiFiClientSecure.h>
WebServer server(80);

#define AP_SSID "TP-LINK"
#define AP_PASS "214365Qq"
#define WIFI_TIMEOUT_MS 20000
#define WIFI_NETWORK "TP-LINK"
#define WIFI_PASSWORD "214365Qq"
// базовый пример работы с библиотекой, основные возможности. Загрузи и изучай код
// WiFi
const char *ssid = "TP-LINK"; // Enter your Wi-Fi name
const char *password = "214365Qq";  // Enter Wi-Fi password

// MQTT Broker
const char *mqtt_broker = "m8.wqtt.ru";
const char *topic = "topic/esp32";
const char *TEMPR = "topic/TR";
const char *TEMPW = "topic/TW";

const char *mqtt_username = "wootang";
const char *mqtt_password = "398958";
const int mqtt_port = 14396;




 const int sending_period = 25;
const bool retain_flag = true;
const char* Wtemp_topic = "Wtempt";
const char* ventel_topic = "ventelt";
const char* Rtemp_topic = "Rtempt";
const char* Rtemp2_topic = "Rtemp2t";
int pwm27;

const char* pwm27_topic = "pwm27t";

const int pwmv = 27;
// int ventpin = 27; 

int pwm27new;

int brightness = 0;
int step = 5;


const char* waterSENS_topic = "waterSENSt";
const char* dolivSENS_topic = "dolivSENSt";
const char* val_utechkaD_topic = "val_utechkaDt";


WiFiClient espClient;
PubSubClient client(espClient);




// // логин-пароль от роутера


GyverHub hub;

#include "ThingSpeak.h"

#define CHANNEL_ID 1551807
#define CHANNEL_API_KEY "EZVNSKEUD4RWXAAD"


#define CHANNEL_ID2 1628917
#define CHANNEL_API_KEY2 "R5VFO73Q37GESE3V"

uint32_t rndColor() {
    uint32_t colors[] = {
        0xcb2839,
        0xd55f30,
        0xd69d27,
        0x37A93C,
        0x25b18f,
        0x2ba1cd,
        0x297bcd,
        0x825ae7,
        0xc8589a,
    };
    return colors[random(9)];
};
String rndText() {
    String s;
    uint8_t len = random(5, 12);
    for (uint8_t i = 0; i < len; i++) {
        s += (char)random('a', 'z');
    };
    return s;
};
gh::Align rndAlign() {
    static uint8_t i;
    if (++i >= 3) i = 0;
    return (gh::Align)i;
};
const char* rndIcon() {
    static uint8_t i;
    if (++i >= 4) i = 0;
    const char* icons[] = {
        "",
        "f0ad",
        "f5ce",
        "",
    };
    return icons[i];
};



// WiFiClient client;
// MQTTPubSubClient mqtt;

 #include "PCF8575.h"

 // Set i2c address
 PCF8575 pcf1(0x20);
 PCF8575 pcf2(0x22);

 float Temperatura;

   bool autos=1;

String messager = "";
String messagew = "";
 
 
 // СТУПЕНИ ТЕМПЕРАТУРЫ ВЕНТЕЛЯ
 float vent0=22.0;
 float vent1=23.0;
 float vent2=24.0;
 float vent3=26.5;
 float vent4=27.5;
 float vent5=28.0;
 float vent6=29.5;
 float vent7=30.5;
 float vent8=31.5;
 float vent9=32.5;
 // СТУПЕНИ ВЕНТЕЛЯ
  float ventob0=85;
 float ventob1=95;
 float ventob2=100;
 float ventob3=100;
 float ventob4=100;
 float ventob5=100;
 float ventob6=110;
 float ventob7=120;
 float ventob8=130;
float ventob9=140;


float volt;

float pwm100;

 float ventel=0 ;

   float ventday;
  float ventdayn;



 float ventup = 11.00;
  float ventdown = 23.00;

 int timePoliv = 40000;
 int timeDoliv = 180000;


  float ventdd;

 float venttime;


#include <NTPClient.h>
#include <WiFiUdp.h>
// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

//Week Days
String weekDays[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//Month names
String months[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


time_t epochTime;



const int vdnpin = 16;

 const int capteur_D = 19;   //DIGITAL UTECHKA
 const int capteur_A = 18;    //ANALOG UTECHKA

// int ventpin = 27;           // контакт ШИМ, к которому подключен светодиод

//  const int UTECHKA_PIN = 5;   //PIN UTECHKA
 int val_utechka;
 int val_utechkaD;

 // (период, мс), (0 не запущен / 1 запущен), (режим: 0 период / 1 таймер)
 TimerMs tmr(5000, 1, 0);
 // TimerMs dolivpause(3000, 1, 1);
 TimerMs textp(15000, 1, 0);
 TimerMs tmrWF(20000, 1, 0);
 // TimerMs WATERPING(5000, 1, 0);
  TimerMs tmrvent(25000, 1, 0);


  TimerMs tmrug(1000, 1, 0);


//  GTimer dolivpause(MS);  // можно сразу указать период (по умолч. в режиме интервала)
//  GTimer polivtimer(MS);  // можно сразу указать период (по умолч. в режиме интервала)


 // int value = 0;
 unsigned long next_time; // время очередного переключения первого светодиода
 int timeout = 2500; // половина периода мигания
 //int led_state = 0; // начальное состояние светодиода - выключен


 int DP=1;
 // int grelka_PIN;
 bool grelka;



 bool obogrev;
 bool obogrevt;


 // Текущее состояние сенсора
 bool SensorStateWS = HIGH;
 // Время начала смены
 unsigned long SensorStartChangeWS = 0;
 // Защитный интервал между сменами состояния
 unsigned long TIMEOUTWS = 1000;
 // Текущее время
 unsigned long CurrentTimeWS = 0;



 // Текущее состояние сенсора
 bool SensorStateDS = HIGH;
 // Время начала смены
 unsigned long SensorStartChangeDS = 0;
 // Защитный интервал между сменами состояния
 unsigned long TIMEOUTDS = 2000;
 // Текущее время
 unsigned long CurrentTimeDS = 0;

 // Пример использования библиотеки GyverButton, все возможности в одном скетче.
 // автоматический тик


 #include "Button2.h"

 // Button2 button;
 byte pin = 2;
 /////////////////////////////////////////////////////////////////

 Button2 button;
  #define BUTTON_PIN  2


 #include <OneWire.h>
 #include <DallasTemperature.h>

 #define ONE_WIRE_BUS 0
#define TEMPERATURE_PRECISION 12 // Lower resolution
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

 DeviceAddress outsideThermometer = { 0x28, 0x52, 0x37, 0x14, 0x64, 0x20, 0x01, 0x19 };  //28 D6 B5 3D 9 0 0 AE
DeviceAddress  insideThermometer  = { 0x28, 0xFA, 0xED, 0x23, 0x64, 0x20, 0x01, 0xC9 };
DeviceAddress  ROOMThermometer  = { 0x28, 0xD6, 0xB5, 0x3D, 0x09, 0x00, 0x00, 0xAE };

   float Wtemp; // temperature in Celsius
 int dolivSENS;
 int waterSENS;
 int podachawater;
 int polivpompa;

bool dolivSE;
bool waterSE;

 float poliv;


  int dolivpompa;
 float Rtemp; // temperature in Celsius

float Rtemp2; // temperature in Celsius


uint8_t tab=0;


uint32_t tmr1;





void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP32-" + WiFi.macAddress();
    if (client.connect(clientId.c_str(), mqtt_username, mqtt_password) ) {
      Serial.println("connected");
      digitalWrite(vdnpin,  HIGH);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // delay(5000);
    }
  }
};

// // обновить панель управления в приложении
void sendRefresh(gh::Client* client = nullptr)
{

};



 void pressed(Button2& btn) {
     Serial.println("pressed");
    	// pcf8575.digitalWrite(P3, LOW);
     poliv=1;
 //  dolivpause.setTimeout(timeDoliv);       //  пауза долива и подогрева
 //   polivtimer.setTimeout(timePoliv);

 };
 void released(Button2& btn) {
     Serial.print("released: ");
     Serial.println(btn.wasPressedFor());
    
           	// pcf8575.digitalWrite(P3, LOW);
 //  dolivpause.setTimeout(timeDoliv);       //  пауза долива и подогрева
 //   polivtimer.setTimeout(timePoliv);
 };
 void changed(Button2& btn) {
     Serial.println("changed");
 };
 void click(Button2& btn) {
     Serial.println("click\n");
         poliv=1;
        	// pcf8575.digitalWrite(P3, LOW);
 //  dolivpause.setTimeout(timeDoliv);       //  пауза долива и подогрева
 //   polivtimer.setTimeout(timePoliv);
 };
 void longClickDetected(Button2& btn) {
     Serial.println("long click detected");
     poliv=0;
 };
 void longClick(Button2& btn) {
     Serial.println("long click\n");
         poliv=0;
    	// pcf8575.digitalWrite(P3, HIGH);
 };
 void doubleClick(Button2& btn) {
     Serial.println("double click\n");
         poliv=1;
         // pcf8575.digitalWrite(P3, LOW);

 //  dolivpause.setTimeout(timeDoliv);       //  пауза долива и подогрева
 //   polivtimer.setTimeout(timePoliv);
 };
 void tripleClick(Button2& btn) {
     Serial.println("triple click\n");
     Serial.println(btn.getNumberOfClicks());
         poliv=0;
 };
 void tap(Button2& btn) {
     Serial.println("tap");
     poliv=1;
 };








// обработчик кнопки (см. ниже)
void btn_cb() {
    Serial.println("AUTO ON");
        if (Rtemp <= vent0 && Rtemp <= vent1 ) {
 ventel=0;
   };

     if (Rtemp >= vent1 && Rtemp <= vent2 ) {
   ventel=1;
    };

  if (Rtemp >= vent2 && Rtemp <= vent3) {
 ventel=2;
     
   };

  if (Rtemp >= vent3 && Rtemp <= vent4) {
 ventel=3;
        };


    if (Rtemp >= vent4 && Rtemp <= vent5) {
 	ventel=4;
   };


    if (Rtemp >= vent5 && Rtemp <= vent6) {
 	ventel=5;
    };

    if (Rtemp >= vent6 && Rtemp <= vent7) {
   	ventel=6;
         };
    
     if (Rtemp >= vent7 && Rtemp <= vent8) {
 	ventel=7; 
  };

  if (Rtemp >= vent8 && Rtemp <= vent9) {
 	ventel=8;
  };
    if (Rtemp >= vent9) {
 	ventel=9;
     };
// hub.refresh();
};





// обработчик кнопки с информацией о билде (см. ниже)
void btn_cb_b(gh::Build& b) {
    Serial.print("click 5 from client ID: ");
    Serial.println(b.client.id);
    // b.refresh();
};



// билдер
// void build(gh::Builder& b) {
    // =================== КОНТЕЙНЕРЫ ===================
void build(gh::Builder& b) {




    if (b.beginRow()) {

  b.Slider(&vent0).label(F("VENT0")).color(gh::Colors::Red).size(1).range(20, 26, 0.5);
       b.endRow();   }
        if (b.beginRow()) {
   b.Slider(&vent1).label(F("VENT1")).color(gh::Colors::Red).size(1).range(22, 27, 0.5);
 b.endRow();   }
        if (b.beginRow()) {
    b.Slider(&vent2).label(F("VENT2")).color(gh::Colors::Red).size(1).range(23, 28, 0.5);
 b.endRow();   }
        if (b.beginRow()) {
     b.Slider(&vent3).label(F("VENT3")).color(gh::Colors::Red).size(1).range(23.5, 29, 0.5);
 b.endRow();   }
        if (b.beginRow()) {
      b.Slider(&vent4).label(F("VENT4")).color(gh::Colors::Red).size(1).range(24, 30, 0.5);
 b.endRow();   }
        if (b.beginRow()) {
       b.Slider(&vent5).label(F("VENT5")).color(gh::Colors::Red).size(1).range(24.5, 31, 0.5);
 b.endRow();   }
        if (b.beginRow()) {
        b.Slider(&vent6).label(F("VENT6")).color(gh::Colors::Red).size(1).range(25, 32, 0.5);
 b.endRow();   }
        if (b.beginRow()) {
         b.Slider(&vent7).label(F("VENT7")).color(gh::Colors::Red).size(1).range(25.5, 33, 0.5);
 b.endRow();   }
        if (b.beginRow()) {
          b.Slider(&vent8).label(F("VENT8")).color(gh::Colors::Red).size(1).range(26, 34, 0.5);

       b.endRow();
    }
if (b.beginRow()) {
          b.Slider(&vent9).label(F("VENT9")).color(gh::Colors::Red).size(1).range(26.5, 34, 0.5);

       b.endRow();
    }
    b.refresh();
};
// }

void build_1(gh::Builder& b) {
 if (b.beginRow()) {

  b.Slider(&ventob0).label(F("ОБОРОТЫ-0")).color(gh::Colors::Blue).size(1).range(50, 125, 1);
   b.endRow();   }
        if (b.beginRow()) {
   b.Slider(&ventob1).label(F("ОБОРОТЫ-1")).color(gh::Colors::Blue).size(1).range(80, 140, 1);
    b.endRow();   }
        if (b.beginRow()) {
    b.Slider(&ventob2).label(F("ОБОРОТЫ-2")).color(gh::Colors::Blue).size(1).range(90, 160, 1);
     b.endRow();   }
        if (b.beginRow()) {
     b.Slider(&ventob3).label(F("ОБОРОТЫ-3")).color(gh::Colors::Blue).size(1).range(90, 150, 1);
      b.endRow();   }
        if (b.beginRow()) {
      b.Slider(&ventob4).label(F("ОБОРОТЫ-4")).color(gh::Colors::Blue).size(1).range(100, 180, 1);

       b.endRow();   }
        if (b.beginRow()) {
       b.Slider(&ventob5).label(F("ОБОРОТЫ-5")).color(gh::Colors::Blue).size(1).range(100, 200, 1);
        b.endRow();   }
        if (b.beginRow()) {
        b.Slider(&ventob6).label(F("ОБОРОТЫ-6")).color(gh::Colors::Blue).size(1).range(110, 220, 1);
         b.endRow();   }
        if (b.beginRow()) {
         b.Slider(&ventob7).label(F("ОБОРОТЫ-7")).color(gh::Colors::Blue).size(1).range(110, 255, 1);
          b.endRow();   }
        if (b.beginRow()) {
          b.Slider(&ventob8).label(F("ОБОРОТЫ-8")).color(gh::Colors::Blue).size(1).range(120, 255, 1);

       b.endRow();
    }
 if (b.beginRow()) {
          b.Slider(&ventob9).label(F("ОБОРОТЫ-9")).color(gh::Colors::Blue).size(1).range(130, 255, 1);

       b.endRow();
    }

b.refresh();

};

//  if (b.beginRow()) {

//   b.Slider(&ventel).label(F("СКОРОСТЬ")).color(gh::Colors::Green).size(1).range(0, 9, 1);
//       b.endRow();} 




void build_2(gh::Builder& b) {




if (b.beginRow()) {

 
  b.Slider(&Temperatura).label(F("Температура водонагревателя")).color(gh::Colors::Red).size(1).range(10, 27, 0.1, 1 );
   
  //  b.Label().label("Temperatura").size(2).valueFloat(Temperatura); 
    b.endRow();};



if (b.beginRow()) {

 
  b.Label().label("Ускорение вытяжки с").size(2).value(ventup); 
   b.Label().label("Замедление вытяжки с").size(2).value(ventdown); 
    b.endRow();};



if (b.beginRow()) {

  b.Slider(&ventup).label(F("Ускорение вытяжки с")).color(gh::Colors::Yellow).size(1).range(0, 24, 0.1, 1 );
   
    b.endRow();
    };


    if (b.beginRow()) {

  b.Slider(&ventdown).label(F("Замедление вытяжки с")).color(gh::Colors::Yellow).size(1).range(0, 24, 0.1, 1 );
   
    b.endRow();
    };



if (b.beginRow()) {

  b.Slider(&ventday).label(F("Дневное ускорение")).color(gh::Colors::Red).size(1).range(-50, 100, 1, 1 );
   
    b.endRow();
    };


   if (b.beginRow()) {
    b.Label().label("℃ верх").size(2).value(Rtemp);   // с указанием стандартного значения

    
     b.Label().label("℃ воды").size(2).value(Wtemp);   // с указанием стандартного значения
   

b.Label().label("℃ низ").size(2).value(Rtemp2);   // с указанием стандартного значения
   

  //  b.Label().label("Температура водонагревателя").size(2).valueFloat(Temperatura); 

   b.endRow();
   };


 if (b.beginRow()) {


     b.Slider(&ventel).label(F("Шаг вентиляции")).color(gh::Colors::Blue).size(1).range(0, 9, 1);


    b.endRow();
    };


//  if (b.beginRow()) {
//         b.Label_("PWM")).size(2).valueInt(pwm27);  // с указанием стандартного значения

//       b.Label_(F("Volt")).size(2).valueInt(volt);  // с указанием стандартного значения

//         b.endRow();
//     }



// (&vent1).label(F("VENT1"))

 if (b.beginRow()) {
        // b.Label.label("pwm27").valueInt(pwm27);;  // с указанием стандартного значения

   b.Label().label("volt").size(2).value(volt);   // с указанием стандартного значения
//  b.Label().label("ШИМ").size(2).valueFloat(pwm27);   // с указанием стандартного значения
  // b.Input().label("pwm27").size(2).valueFloat(pwm27); 
  b.Label().label("%").size(2).value(pwm100);  


        b.endRow();
    };


if (b.beginRow()) {

  b.Slider(&pwm27).label(F("ШИМ вентиляци")).color(gh::Colors::Red).size(1).range(80, 255, 1);
   b.endRow();  
    };



 if (b.beginRow()) {
        // b.Input(&poliv).size(2);
   if (b.Switch(&autos).label("Режим АВТО").size(1).click()) {
Serial.println("Режим АВТО");

Serial.println(autos);


   };
        // СПОСОБ 4
        // подключить функцию-обработчик (см. выше)
        b.Button().label("Синхронизация").attach(btn_cb);
        // внутри обработки действия переменная уже будет иметь новое значение:
        if (b.Switch(&poliv).label("POLIV").size(1).click()) {
            Serial.print("poliv: ");
            Serial.println(poliv);
        };

        b.endRow();

    };
 if (b.beginRow()) {
    b.Label().label("obogrev").size(2).value(obogrev);   // с указанием стандартного значения
 if (b.Switch(&obogrev).label("obogrev").size(1).click()) {
            Serial.print("obogrev: ");
            Serial.println(obogrev);
        };
        b.endRow();

    };
// Temperatura
//  if (b.beginRow()) {
//         b.Input(&Wtemp).size(2);
//        b.endRow();
//     }
//     // =================== ПАРАМЕТРЫ ВИДЖЕТА ===================

    if (b.beginRow()) {
        // параметры виджета можно задавать цепочкой. Например:
        b.Button().label(F("my button")).color(gh::Colors::Red);

        // также можно продолжить настраивать ПРЕДЫДУЩИЙ виджет, обратившись к widget:
        b.Button();                        // кнопка без параметров
        b.widget.label(F("button 2"));     // настраиваем кнопку выше
        b.widget.color(gh::Colors::Blue);  // её же

        b.endRow();
    };

    // =================== ДЕЙСТВИЯ ВИДЖЕТА ===================

    // с активных виджетов можно получить сигнал о действии - клик или изменение значения
    if (b.beginRow()) {
        // // СПОСОБ 1
        // // проверить условие click() - он вернёт true при действии
        // // click() нужно вызывать ПОСЛЕДНИМ в цепочке!!!
        // if (b.Button().click()) Serial.println("click 1");

        // // СПОСОБ 2
        // // подключить bool переменную - флаг
        // bool flags=0;
        // b.Button().attach(&flags);
        // if (flags) Serial.println("click 2");

        // // СПОСОБ 3
        // // подключить gh::Flag переменную - флаг
        // // данный флаг сам сбросится в false при проверке!
        // gh::Flag gflag;
        // b.Button().attach(&gflag);
        // if (gflag) Serial.println("click 3");
        // // здесь gflag уже false
//    if (b.Switch(&autos).label("AUTOS").size(1).click()) {
// Serial.println("AUTOS");

// Serial.println(autos);


//    }
//         // СПОСОБ 4
//         // подключить функцию-обработчик (см. выше)
//         b.Button().attach(btn_cb);

        // СПОСОБ 5
        // подключить функцию-обработчик с инфо о билде (см. выше)
        b.Button().attach(btn_cb_b);

        // attach() может быть НЕ ПОСЛЕДНИМ в цепочке, также их может быть несколько:
        // b.Button().attach(f1).attach(f2).label("kek");

        b.endRow();
    };

    // =============== ПОДКЛЮЧЕНИЕ ПЕРЕМЕННОЙ ===============

    // if (b.beginRow()) {
    //     // библиотека позволяет подключить к активному виджету переменную для чтения и записи
    //     // я создам статические переменные для ясности. Они могут быть глобальными и так далее
    //     // таким образом изменения останутся при перезагрузке страницы
    //     // static int sld;
    //     static String inp;
      

    //     // для подключения нужно передать переменную по адресу
    //     // библиотека сама определит тип переменной и будет брать из неё значение и записывать при действиях
    //     // библиотека поддерживает все стандартные типы данных, а также некоторые свои (Pairs, Pos, Button, Log...)
    //


//  if (b.beginRow()) {
//         b.Input(&Rtemp).size(2);

//         // внутри обработки действия переменная уже будет иметь новое значение:
//         if (b.Switch(&ventel).size(1).click()) {
//             Serial.print("switch: ");
//             Serial.println(ventel);
//         }

//         b.endRow();
//     }


    // ==================== ОБНОВЛЕНИЕ ====================

    // библиотека позволяет обновлять значения на виджетах. Это можно делать
    // - из основной программы (см. ниже)
    // - из билдера - но только при действиях по виджетам!

    // для отправки обновления нужно знать ИМЯ компонента. Его можно задать почти у всех виджетов
    // к функции добавляется подчёркивание, всё остальное - как раньше

    if (b.beginRow()) {
        b.Label_(F("label")).size(2).value("default");  // с указанием стандартного значения

        if (b.Button().size(1).click()) {
            hub.update(F("label")).value(random(100, 500));
        };

        b.endRow();
    };

    // в самом низу сделаем заголовок, текст будем обновлять из loop() (см. ниже)
    b.Title_(F("title"));

    // =================== ИНФО О БИЛДЕ ===================

    // можно получить информацию о билде и клиенте для своих целей
    // поставь тут 1, чтобы включить вывод =)
    if (1) {
        // запрос информации о виджетах
        if (b.build.isUI()) {
            Serial.println("=== UI BUILD ===");
        };

        // действие с виджетом
        if (b.build.isSet()) {
            Serial.println("=== SET ===");
            Serial.print("name: ");
            Serial.println(b.build.name);
            Serial.print("value: ");
            Serial.println(b.build.value);
        };

        Serial.print("client from: ");
        // Serial.println(gh::readConnection(b.client.connection()));
          //  Serial.print(gh::readConnection(req.client.connection()));
              // Serial.print(gh::readConnection(client.connected());
        Serial.print("ID: ");
        Serial.println(b.build.client.id);
        Serial.println();  
         b.refresh();
    };
    //  b.Hook_("Wtemp", &Wtemp);
    //  b.Hook_("Rtemp2", &Rtemp2);
       
    //      b.Hook_("ventob8", &ventob8);
    //        b.Hook_("ventob7", &ventob7);
    //          b.Hook_("ventob6", &ventob6);
    //            b.Hook_("ventob5", &ventob5);
    //              b.Hook_("ventob4", &ventob4);
    //                b.Hook_("ventob3", &ventob3);
    //                  b.Hook_("ventob2", &ventob2);
    //                    b.Hook_("ventob1", &ventob1);
    //                      b.Hook_("ventob0", &ventob0);
    //                        b.Hook_("ventob9", &ventob9);
    //             //              b.Hook_("ventob", &ventob);
    //             //                b.Hook_("ventob", &ventob);
    //             //                  b.Hook_("ventob", &ventob);

             

};


void btn_grelka() {
grelka = 1;
 
      //  pcf1.digitalWrite(P2, LOW);
 if (Wtemp >= Temperatura){
grelka = 0;
 
      //  pcf1.digitalWrite(P2, HIGH);
    };
// b.refresh();

};


void build_3(gh::Builder& b) {
    // СПОСОБ 4
    if (b.beginRow()) {
        // подключить функцию-обработчик (см. выше)
         b.Label().label("grelka").size(2).value(grelka); 
        // внутри обработки действия переменная уже будет иметь новое значение:
        if (b.Switch(&grelka).label("grelka").size(1).click()) {
            Serial.print("grelka: ");
            Serial.println(grelka);
        };

        b.endRow();
    };



 if (b.beginRow()) {
    b.Label().label("waterSENS").size(2).value(waterSENS);   // с указанием стандартного значения

     b.Label().label("dolivSENS").size(2).value(dolivSENS);   // с указанием стандартного значения
   
  //  b.Label().label("Температура водонагревателя").size(2).valueFloat(Temperatura); 

   b.endRow();};


 if (b.beginRow()) {
    b.Label().label("val_utechkaD").size(2).value(val_utechkaD);   // с указанием стандартного значения

     b.Label().label("grelka").size(2).value(grelka);   // с указанием стандартного значения
   
  //  b.Label().label("Температура водонагревателя").size(2).valueFloat(Temperatura); 

   b.endRow();};


 if (b.beginRow()) {
    b.Label().label("dolivpompa").size(2).value(dolivpompa);   // с указанием стандартного значения

     b.Label().label("polivpompa").size(2).value(polivpompa);   // с указанием стандартного значения
   
  //  b.Label().label("Температура водонагревателя").size(2).valueFloat(Temperatura); 

   b.endRow();};


 if (b.beginRow()) {
    b.Label().label("переменная долива").size(2).value(DP);   // с указанием стандартного значения

    //  b.Label().label("polivpompa").size(2).valueFloat(polivpompa);   // с указанием стандартного значения
   
  //  b.Label().label("Температура водонагревателя").size(2).valueFloat(Temperatura); 

   b.endRow();}
  //  b.refresh();
};

void build_Menu(gh::Builder& b) {



  if (b.beginRow()) {  
//  Stamps = stamp;
// stamp = Stamps;
// b.DateTime(&unix);
// b.DateTime(&d);
// b.DateTime(&Stamp);
// b.DateTime(&stamp);

 Stamps = timeClient.getEpochTime();
 stamp.getDateTime(Stamps);
// stamp = Stamps;

b.DateTime(&Stamps);
  Serial.println(Stamps);
  // Serial.println(stamp);
 uint32_t unix = stamp.getUnix();
  


b.refresh();
 b.endRow();
};


 

  if (b.beginRow()) {
    bool ref = false;

    ref |= b.Tabs(&tab).text(F("Main;°C;Step;int")).noLabel().size(4).click();
    if (ref) b.refresh();
    b.endRow();

    switch (tab) {
      // вкладки меню
      case 0: build_2(b);              break;
      case 1: build(b);      break;
       case 2: build_1(b);       break;
       case 3: build_3(b);           break;
      // case 4: build_SettingsRoot(b);    break;
      // меню, вызываемые по кнопкам
      // case 10: build_ManualEQ(b);       break;
      // case 11: build_SettingsEQ(b);     break;
      // case 12: build_SettingsNight(b);  break;
    };
  };
};


void callback(char *topic, byte *payload, unsigned int length) {
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);
    Serial.print("Message:");
    for (int i = 0; i < length; i++) {
        Serial.print((char) payload[i]);
    };
    Serial.println();
    Serial.println("-----------------------");
};



void sendData() {




  client.publish(Wtemp_topic, String(Wtemp).c_str(), retain_flag);
  client.publish(ventel_topic, String(ventel).c_str(), retain_flag);
  client.publish(Rtemp_topic, String(Rtemp).c_str(), retain_flag);
    client.publish(Rtemp2_topic, String(Rtemp2).c_str(), retain_flag);


  client.publish(pwm27_topic, String(pwm27).c_str(), retain_flag);
  client.publish(waterSENS_topic, String(waterSENS).c_str(), retain_flag);
  client.publish(dolivSENS_topic, String(dolivSENS).c_str(), retain_flag);
  client.publish(val_utechkaD_topic, String(val_utechkaD).c_str(), retain_flag);




};


void getDateTime(uint32_t t);   // конвертировать unix stamp дату и время (в переменные члены класса)
    
// установка даты и времени (удобнее чем писать переменные вурчную)
void setDateTime(uint16_t nyear, uint8_t nmonth, uint8_t nday, uint8_t nhour, uint8_t nminute, uint8_t nsecond);




void onunix(uint32_t stamp) {

};

    // hub.onCLI([](String str) {
    //     Serial.println(str);
    //     hub.sendCLI(str + "!");
    // });

void handleRoot() {
  File file = LittleFS.open("/variables.txt", "r");
  if (!file) {
    server.send(500, "text/plain", "Failed to open file for reading");
    return;
  }
  String fileContent;
  while (file.available()) {
    fileContent += char(file.read());
  }
  server.send(200, "text/plain", fileContent);
  file.close();
}


void setup() { 
   LittleFS.begin();
  //  hub.onCLI(cli);
 Serial.begin(115200); 
 pinMode(vdnpin, OUTPUT);  // D10 как выход
digitalWrite(vdnpin,  LOW); // высокий сигнал на D10

pinMode(pwmv, OUTPUT);
//  PWM_resolution(pwmv, 8, FAST_PWM);

pwm27new=0;


sensors.begin();
  sensors.setResolution(insideThermometer, TEMPERATURE_PRECISION);
  sensors.setResolution(outsideThermometer, TEMPERATURE_PRECISION);
  sensors.setResolution(ROOMThermometer, TEMPERATURE_PRECISION);
   







 WiFi.mode(WIFI_STA);
    WiFi.begin(AP_SSID, AP_PASS);
    while (WiFi.status() != WL_CONNECTED) {
delay(500);
      // digitalWrite(vdnpin,  HIGH); // высокий сигнал на D10
        
        Serial.print(".");
    };
    Serial.println();
    Serial.println(WiFi.localIP());

    // hub.mqtt.config("test.mosquitto.org", 1883);


    hub.onBuild(build);

    // hub.onCLI([](String str) {
    //     Serial.println(str);
    //     hub.sendCLI(str + "!");
    // });






    hub.begin();

    // data2.begin();
    Serial.println(hub.getUI());
    Serial.println(hub.getValues());
    hub.setBufferSize(2000);


  // WiFi.begin(ssid, password);
  //   while (WiFi.status() != WL_CONNECTED) {
  //       delay(500);
  //       Serial.println("Connecting to WiFi..");
  //   };
    Serial.println("Connected to the Wi-Fi network");
    //connecting to a mqtt broker
    client.setServer(mqtt_broker, mqtt_port);
    client.setCallback(callback);
    // while (!client.connected()) {
        String client_id = "esp32";
        client_id += String(WiFi.macAddress());
        Serial.printf("The client %s connects to the public MQTT broker\n", client_id.c_str());
       Serial.println(WiFi.localIP());
  
 timeClient.begin();
 
  timeClient.setTimeOffset(10800);

 if (Temperatura == 0) {
Temperatura = 22.5;
};



    
if (client.connected()){
client.loop();
// TempSend();
};
       
       
      if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
            Serial.println("Public EMQX MQTT broker connected");
            
    
    hub.config(F("TP-LINK"), F("testesp32"), F(""));

    // подключить билдер
    hub.onBuild(build_Menu);

   
  hub.setVersion("v1.12");      // установить версию (отображается в info)
  hub.setPIN(3989);            // установить пин-код
  hub.sendGetAuto(true); 


     button.begin(BUTTON_PIN);
     // pinMode(BUTTON_PIN);
   button.setLongClickTime(3000);
   button.setDoubleClickTime(300);
  button.setChangedHandler(changed);
    button.setPressedHandler(pressed);
   button.setReleasedHandler(released);

   // button.setTapHandler(tap);
   button.setClickHandler(click);
   button.setLongClickDetectedHandler(longClickDetected);
   button.setLongClickHandler(longClick);
   button.setLongClickDetectedRetriggerable(false);
  
   button.setDoubleClickHandler(doubleClick);
   button.setTripleClickHandler(tripleClick);
  
 pcf1.begin();
  pcf2.begin();


 
pwm27=120;
 analogWrite(pwmv, 120); 



 // #define P00  	0
 // 	#define P01  	1
 // 	#define P02  	2
 // 	#define P03  	3
 // 	#define P04  	4
 // 	#define P05  	5
 // 	#define P06  	6
 // 	#define P07  	7
 // 	#define P10  	8
 // 	#define P11  	9
 // 	#define P12  	10
 // 	#define P13  	11
 // 	#define P14  	12
 // 	#define P15  	13
 // 	#define P16  	14
 // 	#define P17  	15
 	pcf1.pinMode(P0, OUTPUT);
   pcf1.pinMode(P1, OUTPUT);
   pcf1.pinMode(P2, OUTPUT);
   pcf1.pinMode(P3, OUTPUT);
   pcf1.pinMode(P4, OUTPUT);
   pcf1.pinMode(P5, OUTPUT);
   pcf1.pinMode(P6, OUTPUT);
   pcf1.pinMode(P7, OUTPUT);
   pcf1.pinMode(P8, OUTPUT);
   pcf1.pinMode(P9, OUTPUT);

 pcf1.pinMode(P10, OUTPUT);
 pcf1.pinMode(P11, OUTPUT);
 pcf1.pinMode(P12, OUTPUT);
 pcf1.pinMode(P15, OUTPUT);
 pcf1.pinMode(P14, OUTPUT);
 pcf1.pinMode(P13, OUTPUT);

 pcf1.digitalWrite(P0, HIGH);


 	pcf1.digitalWrite(P1, HIGH);



 	pcf1.digitalWrite(P2, HIGH);

 	pcf1.digitalWrite(P3, HIGH);
	
 	pcf1.digitalWrite(P4, HIGH);

 	pcf1.digitalWrite(P5, HIGH);

 	pcf1.digitalWrite(P6, HIGH);

 	pcf1.digitalWrite(P7, HIGH);

 	pcf1.digitalWrite(P8, HIGH);

 	pcf1.digitalWrite(P9, HIGH);


   	pcf1.digitalWrite(P10, HIGH);

   	pcf1.digitalWrite(P11, HIGH);

 	pcf1.digitalWrite(P12, HIGH);

      	pcf1.digitalWrite(P13, HIGH);

     	pcf1.digitalWrite(P14, HIGH);

     	pcf1.digitalWrite(P15, LOW);



 	pcf2.pinMode(P0, INPUT);
   pcf2.pinMode(P1, INPUT);
   pcf2.pinMode(P2, INPUT);
   pcf2.pinMode(P3, INPUT);
   pcf2.pinMode(P4, INPUT);
   pcf2.pinMode(P5, INPUT);
   pcf2.pinMode(P6, INPUT);
   pcf2.pinMode(P7, INPUT);
   pcf2.pinMode(P8, INPUT);
   pcf2.pinMode(P9, INPUT);

 pcf2.pinMode(P10, INPUT);
 pcf2.pinMode(P11, INPUT);
 pcf2.pinMode(P12, INPUT);
 pcf2.pinMode(P15, INPUT);
 pcf2.pinMode(P14, INPUT);
 pcf2.pinMode(P13, INPUT);



//  pcf2.digitalWrite(P0, LOW);


//  	pcf2.digitalWrite(P1, LOW);



//  	pcf2.digitalWrite(P2, LOW);

//  	pcf2.digitalWrite(P3, LOW);
	
//  	pcf2.digitalWrite(P4, LOW);

//  	pcf2.digitalWrite(P5, LOW);

//  	pcf2.digitalWrite(P6, LOW);

//  	pcf2.digitalWrite(P7, LOW);

//  	pcf2.digitalWrite(P8, LOW);

//  	pcf2.digitalWrite(P9, LOW);


//    	pcf2.digitalWrite(P10, LOW);

//    	pcf2.digitalWrite(P11, LOW);

//  	pcf2.digitalWrite(P12, LOW);

//       	pcf2.digitalWrite(P13, LOW);

//      	pcf2.digitalWrite(P14, LOW);

//      	pcf2.digitalWrite(P15, LOW);


    // pinMode(ventpin, OUTPUT); // объявляем  вывод ШИМ как выход:

 tmrWF.setTimerMode();
 tmrWF.setPeriodMode();
 tmr.setPeriodMode();
//  tmr2.setPeriodMode();
 textp.setPeriodMode();
tmrvent.setPeriodMode();

 pinMode(19, INPUT); //sens 1
 pinMode(25, INPUT);

 


obogrevt=0;
obogrev=0;
  
   ThingSpeak.begin(espClient);


 File file = LittleFS.open("/variables.txt", "r");
  if (!file) {
    Serial.println("Ошибка открытия файла для чтения");
  
  };
  while (file.available()) {
    String line = file.readStringUntil('\n');
    int separatorIndex = line.indexOf('=');
    if (separatorIndex == -1) continue;
    String key = line.substring(0, separatorIndex);
    String value = line.substring(separatorIndex + 1);
    if (key == "ventel") ventel = value.toFloat();
    else if (key == "poliv") poliv = value.toFloat();
    else if (key == "Wtemp") Wtemp = value.toFloat();
    else if (key == "Rtemp") Rtemp = value.toFloat();
    else if (key == "Rtemp2") Rtemp2 = value.toFloat();
    else if (key == "dolivSENS") dolivSENS = value.toInt();
    else if (key == "waterSENS") waterSENS = value.toInt();
    else if (key == "ventday") ventday = value.toFloat();
  };
  file.close();
  Serial.println("Переменные загружены из файла");

 Serial.println(ventday);

ventdayn=0;
ventday=45;


 server.on("/", handleRoot);

  server.begin();
  Serial.println("HTTP server started");
   server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
};

};
void loop()
 {


timeClient.update();
 sensors.requestTemperatures();
   float Wtempl=sensors.getTempC(insideThermometer);

 
float Rtempl=sensors.getTempC(outsideThermometer);
 
float Rtempl2=sensors.getTempC(ROOMThermometer);




  if  (Wtempl >=10 && Wtempl <=50) {
 Wtemp = Wtempl;};

 if  (Rtempl >=10 && Rtempl <=50) {
 Rtemp = Rtempl;};

 if  (Rtempl2 >=10 && Rtempl <=50) {
 Rtemp2 = Rtempl2;};





  time_t epochTime = timeClient.getEpochTime();
  // Serial.print("Epoch Time: ");
  // Serial.println(epochTime);
  
  String formattedTime = timeClient.getFormattedTime();
  // Serial.print("Formatted Time: ");
  // Serial.println(formattedTime);  

  int currentHour = timeClient.getHours();
  // Serial.print("Hour: ");
  // Serial.println(currentHour);  

  int currentMinute = timeClient.getMinutes();
  // Serial.print("Minutes: ");
  // Serial.println(currentMinute); 
   
  int currentSecond = timeClient.getSeconds();
  // Serial.print("Seconds: ");
  // Serial.println(currentSecond);  

  String weekDay = weekDays[timeClient.getDay()];
  // Serial.print("Week Day: ");
  // Serial.println(weekDay);    

  //Get a time structure
  struct tm *ptm = gmtime ((time_t *)&epochTime); 

  int monthDay = ptm->tm_mday;
  // Serial.print("Month day: ");
  // Serial.println(monthDay);

  int currentMonth = ptm->tm_mon+1;
  // Serial.print("Month: ");
  // Serial.println(currentMonth);

  String currentMonthName = months[currentMonth-1];
  // Serial.print("Month name: ");
  // Serial.println(currentMonthName);

  int currentYear = ptm->tm_year+1900;
  // Serial.print("Year: ");
  // Serial.println(currentYear);

  //Print complete date:
  String currentDate = String(currentYear) + "-" + String(currentMonth) + "-" + String(monthDay);
  // Serial.print("Current date: ");
  // Serial.println(currentDate);
 Stamps = timeClient.getEpochTime();

 stamp.getDateTime(Stamps);





  val_utechkaD = digitalRead(19);

dolivSENS = pcf2.digitalRead(P0);
waterSENS = pcf2.digitalRead(P1);   


  podachawater =  pcf1.digitalRead(P3);
       polivpompa = !pcf1.digitalRead(P1);
    dolivpompa = pcf1.digitalRead(P0);
 volt = 10000/255*pwm27/1000;


pwm100 = pwm27/255*100;



   venttime = currentHour;
 
//  Serial.println();
if ( venttime >=ventup &&  venttime <=ventdown){
        //  ventday;
        // if (ventday == 0){
        //   ventday = 10;
        // ventday = 40;
        ventdd = 1;






 if (ventdd == 1) {
// ventday = 20;

        if (ventel == 0) {
          
   pwm27 = ventob0 + ventday;
//  analogWrite(ventpin, pwm27); 
  // pwm.write(pwmv, pwm27);
  //  pwm.analogWrite(pwmv, pwm27);
   analogWrite(pwmv, pwm27); 
   };

   if (ventel == 1) {
     pwm27 = ventob1 + ventday;
  // analogWrite(ventpin, pwm27); 
  analogWrite(pwmv, pwm27);  };

     if (ventel == 2) {
         pwm27 = ventob2 + ventday;
  //  analogWrite(ventpin, pwm27); 
  analogWrite(pwmv, pwm27); 
 };
       if (ventel == 3) {
         pwm27 = ventob3 + ventday;
  // analogWrite(ventpin, pwm27); 
      analogWrite(pwmv, pwm27); 
 };

         if (ventel == 4) {
             pwm27 = ventob4 + ventday;
  // analogWrite(ventpin, pwm27); 
      analogWrite(pwmv, pwm27); 
 };
           if (ventel == 5) {
             pwm27 = ventob5 + ventday;
  // analogWrite(ventpin, pwm27); 
      analogWrite(pwmv, pwm27); 
 };
             if (ventel == 6) {
                 pwm27 = ventob6 + ventday;
  // analogWrite(ventpin, pwm27); 
       analogWrite(pwmv, pwm27); 
 };

             if (ventel == 7) {
                 pwm27 = ventob7 + ventday;
  // analogWrite(ventpin, pwm27); 
      analogWrite(pwmv, pwm27); 
 };

  if (ventel == 8) {
     pwm27 = ventob8 + ventday;
  // analogWrite(ventpin, pwm27); 
    analogWrite(pwmv, pwm27); 
 };

  if (ventel == 9) {
     pwm27 = ventob9 + ventday;
  // analogWrite(ventpin, pwm27); 
   analogWrite(pwmv, pwm27); 
 };
 };
   }; 
if (venttime <= ventup &&  venttime >= ventdown){

ventdd = 0;



 if (ventdd == 0){
  //  ventday = 0;
          // ventday = 0;
        // if (ventday == 0){
        //   ventday = 10;
       
       if (ventel == 0) {
   pwm27 = ventob0 - ventday;
//  analogWrite(ventpin, pwm27); 
     analogWrite(pwmv, pwm27); 
   };

   if (ventel == 1) {
    //  ventday = 0;
     pwm27 = ventob1 + ventdayn - ventday;
  // analogWrite(ventpin, pwm27); 
    analogWrite(pwmv, pwm27);  };

     if (ventel == 2) {
      //  ventday = 0;
         pwm27 = ventob2 + ventdayn - ventday;
  //  analogWrite(ventpin, pwm27); 
    analogWrite(pwmv, pwm27); 
      };
        if (ventel == 3) {
          //  ventday = 0;
         pwm27 = ventob3 + ventdayn - ventday;
  // analogWrite(ventpin, pwm27); 
    analogWrite(pwmv, pwm27); 
 };
         if (ventel == 4) {
          //  ventday = 0;
             pwm27 = ventob4 + ventdayn - ventday;
  // analogWrite(ventpin, pwm27); 
   analogWrite(pwmv, pwm27);  };
         
           if (ventel == 5) 
           {
            //  ventday = 0;
             pwm27 = ventob5 + ventdayn - ventday;
  // analogWrite(ventpin, pwm27); 
     analogWrite(pwmv, pwm27); 
 };
             if (ventel == 6) {
              //  ventday = 0;
                 pwm27 = ventob6 + ventdayn - ventday;
  // analogWrite(ventpin, pwm27); 
      analogWrite(pwmv, pwm27); 
 };

             if (ventel == 7) {
              //  ventday = 0;
                 pwm27 = ventob7 + ventdayn - ventday;
  // analogWrite(ventpin, pwm27); 
       analogWrite(pwmv, pwm27); 
 };

  if (ventel == 8) {
    //  ventday = 0;
     pwm27 = ventob8 + ventdayn - ventday;
  // analogWrite(ventpin, pwm27); 
     analogWrite(pwmv, pwm27); 
 };

  if (ventel == 9) {
    //  ventday = 0;
     pwm27 = ventob9 + ventdayn - ventday;
  // analogWrite(ventpin, pwm27); 
    analogWrite(pwmv, pwm27); 

  };       
  };
 };


 
  if (pwm27new != pwm27) {

    pwm27new = pwm27;
Serial.print("Обороты-");Serial.println(pwm27);
  };

 

if (ventel != ventel) {
   Serial.println("Vent-");
Serial.print(ventel);


 Serial.println("");
 };

  hub.tick();


// =========== ОБНОВЛЕНИЯ ПО ТАЙМЕРУ ===========
    // в библиотеке предусмотрен удобный класс асинхронного таймера
    static gh::Timer tmr(1000);  // период 1 секунда

    // каждую секунду будем обновлять заголовок
    if (tmr) {
        hub.update(F("title")).value(millis());
    };



   button.loop();








 // Устанавливаем текущее время
   CurrentTimeWS = millis();
   // считываем сенсор
   boolean CurrentStateWS = waterSENS;
   // если текущее состояние сенсора отличается считанного
   if (CurrentStateWS != SensorStateWS) {
     // если отсчет таймера смены состояния не начат, начинаем
     if (SensorStartChangeWS == 0) SensorStartChangeWS = CurrentTimeWS;
     // если новое состояние приняло свое значение за время большее чем время таймаута
     if (CurrentTimeWS - SensorStartChangeWS > TIMEOUTWS) {
         // меняем состояние сенсора
         SensorStateWS=!SensorStateWS;
         // сбрасываем время начала смены состояния
         SensorStartChangeWS = 0;
         // если текущее состояние сенсора 1, то включаем светодиод
         if(SensorStateWS){
           	pcf1.digitalWrite(P3, HIGH);
         // если текущее состояние сенсора 0, то выключаем светодиод
         }else{
          pcf1.digitalWrite(P3, LOW);
         }
     }
   // смена состояния не состоялась, сбрасываем таймер
   }else{
     SensorStartChangeWS = 0;
   };


 // Устанавливаем текущее время
   CurrentTimeDS = millis();
   // считываем сенсор
   boolean CurrentStateDS = dolivSENS;
   // если текущее состояние сенсора отличается считанного
   if (CurrentStateDS != SensorStateDS) {
     // если отсчет таймера смены состояния не начат, начинаем
     if (SensorStartChangeDS == 0) SensorStartChangeDS = CurrentTimeDS;
     // если новое состояние приняло свое значение за время большее чем время таймаута
     if (CurrentTimeDS - SensorStartChangeDS > TIMEOUTDS) {
         // меняем состояние сенсора
         SensorStateDS=!SensorStateDS;
         // сбрасываем время начала смены состояния
         SensorStartChangeDS = 0;
         // если текущее состояние сенсора 1, то включаем светодиод
         if(SensorStateDS){
           	pcf1.digitalWrite(P0, HIGH);
         // если текущее состояние сенсора 0, то выключаем светодиод
         }else{
          pcf1.digitalWrite(P0, LOW);
         }
     }
   // смена состояния не состоялась, сбрасываем таймер
   }else{
     SensorStartChangeDS = 0;
   };



 if (poliv==1) {
     // Serial.println("poliv on");
    pcf1.digitalWrite(P1, LOW);
   };

 if (poliv==0) {
     // Serial.println("poliv oFF");
    pcf1.digitalWrite(P1, HIGH);
   };




 if (tmr.tick()){
 
  
  
 
 float grelkatime = currentHour;
  // if (grelkatime >=10.00 && grelkatime <=21.00){
     if (Wtemp < Temperatura && Wtemp >= 11  ) {
obogrevt=1;
  }
   else  {
   	obogrevt=0;
  };
      if (obogrev==1 && obogrevt==1) { 
   	pcf1.digitalWrite(P2, LOW);
    //  grelka = 1;    && obogrev==1
     //  Serial.println(grelkatime);
 
     }
     else  {
   	pcf1.digitalWrite(P2, HIGH);
    //  grelka = 0;

   }
  };


 



 if (autos == 1) {

    if (Rtemp <= vent0 && Rtemp <= vent1 ) {
 ventel=0;
   
   };

     if (Rtemp >= vent1 && Rtemp <= vent2 ) {
   ventel=1;
   
   };

  if (Rtemp >= vent2 && Rtemp <= vent3) {
 ventel=2;;
     
   };

  if (Rtemp >= vent3 && Rtemp <= vent4) {
 ventel=3;
    
   };


    if (Rtemp >= vent4 && Rtemp <= vent5) {
 	ventel=4;
    
   };


    if (Rtemp >= vent5 && Rtemp <= vent6) {
 	ventel=5;
 
   };

    if (Rtemp >= vent6 && Rtemp <= vent7) {
   	ventel=6;
    
    };
    
     if (Rtemp >= vent7 && Rtemp <= vent8) {
 	ventel=7;
      
     };


  if (Rtemp >= vent8 && Rtemp <= vent9) {
 	ventel=8;
    
   };
    if (Rtemp >= vent9) {
 	ventel=9;
      
     };

 

 };
  

   
 if (tmrWF.tick()){


   Serial.println("SENDED");

  ThingSpeak.setField(1, Wtemp);
   ThingSpeak.setField(2, Rtemp);
    ThingSpeak.setField(3, waterSENS);
   ThingSpeak.setField(4, Rtemp2);

    ThingSpeak.setField(5, grelka);
   ThingSpeak.setField(6, podachawater);
    ThingSpeak.setField(7, dolivpompa);
  ThingSpeak.setField(8, polivpompa);

   ThingSpeak.writeFields(CHANNEL_ID, CHANNEL_API_KEY);


  ThingSpeak.setField(1, ventel);
   ThingSpeak.setField(2, digitalRead(19));
    ThingSpeak.setField(3, waterSENS);
   ThingSpeak.setField(4, dolivSENS);

    ThingSpeak.setField(5, grelka);
   ThingSpeak.setField(6, podachawater);
    ThingSpeak.setField(7, dolivpompa);
   ThingSpeak.setField(8, ventel);
 //  ThingSpeak.setField(9, ventel);
   ThingSpeak.writeFields(CHANNEL_ID2, CHANNEL_API_KEY2);


 };





  if (textp.tick()){


  if (ventel==0) {

     Serial.println("VENT-0");
  //        lcd.cursor(10, 3);
  //  lcd.display("V-0");
  // (char(223));
   };

     if (ventel==1) {

      Serial.println("VENT-1");
  //       lcd.cursor(10, 3);
  //  lcd.display("V-1");

   };

  if (ventel==2) {
 
         Serial.println("VENT-2");
  //            lcd.cursor(10, 3);
  //  lcd.display("V-2");
            

   };

  if (ventel==3) {
 
         Serial.println("VENT-3");
        
  //  lcd.cursor(10, 3);
  //  lcd.display("V-3");
 

 
   };


    if (ventel==4) {
 	
         Serial.println("VENT-4");
        
  //    lcd.cursor(10, 3);
  //  lcd.display("V-4");
 

 
   };


    if (ventel==5) {

         Serial.println("VENT-5");
        
  //   lcd.cursor(10, 3);
  //  lcd.display("V-5");
 

 
   };



    if (ventel==6) {
  
         Serial.println("VENT-6");
  //             lcd.cursor(10, 3);
  //  lcd.display("V-6");

    };
    




     if (ventel==7) {
 	
         Serial.println("VENT-7");
        
  //      lcd.cursor(10, 3);
  //  lcd.display("V-7");
     };


  if (ventel==8) {
 
         Serial.println("VENT-8");
        
  //      lcd.cursor(10, 3);
  //  lcd.display("V-8");

   };
    if (ventel==9) {
 
         Serial.println("VENT-9");
        
  //      lcd.cursor(10, 3);
  //  lcd.display("V-9");
     };



  if  (Wtemp >=10) {
     Serial.print("℃ W(*C): ");
   Serial.print(Wtemp, 3);
 
  
   Serial.println();
    };

  if  (Rtemp >=10) {
     Serial.print("℃ верх(*C): ");
   Serial.print(Rtemp, 3);
     Serial.println();
   };
 
 if  (Rtemp2 >=10 && Rtemp2 <=50) {
     Serial.print("℃ низ(): ");
   Serial.print(Rtemp2, 3);
    Serial.println();
   };


  Serial.print("Кипятильник-");
  if  (pcf1.digitalRead(P3) == 1) {
     Serial.println("ВКЛ ");
  // pcf1.digitalWrite(P2, LOW);
   }
     else  {
        Serial.println("ВЫКЛ ");
   };




//  Serial.print("НИЖНИЙ УРОВНЯ ВОДЫ--");
  if  (dolivSENS == 1) {
     Serial.println("Растворный бак полон");
  
   }
     else  {
       Serial.println("Растворный бак требуется долить");
   };




//  Serial.print("СЕНСОР ВЕРХНИЙ УРОВНЯ ВОДЫ---");
  if  (waterSENS == 1) {
     Serial.println("Бак воды полон");
  
   };
    if  (waterSENS == 0) {
       Serial.println("Бак воды требуется долить");
   };


//  Serial.print("Помпа на долив--");
  if  (dolivpompa ==0) {
     Serial.println("Помпа чистой ВКЛ");
  
   }
     else 
      {
       Serial.println("Помпа чистой ВЫКЛ");
   };

//  Serial.print("Помпа на Полив--");
  if  (polivpompa ==0) {
     Serial.println("Помпа на Полив ВЫКЛ");
  
   }
     else  {
       Serial.println("Помпа на ПоливВКЛ ");
   };

//  Serial.print("Подача воды с фильтра--");
  if  (podachawater ==0) {
     Serial.println("Подача воды с фильтра ВКЛ ");
  
   }
     else  {
       Serial.println("Подача воды с фильтра ВЫКЛ ");
   };




 Serial.print("переменная долива--");
  if  (DP >=0) {
     Serial.println(" ВКЛ ");
  
   }
     else  {
       Serial.println(" ВЫКЛ ");
   };

 if(digitalRead(19) == 0)
   {
  	pcf1.digitalWrite(P4, LOW);
     Serial.println("УТЕЧКА ВОДЫ/220 ОБЕСТОЧЕНО");
     Serial.println(" ");
   };


 if(digitalRead(19) == 1)
   {
   	pcf1.digitalWrite(P4, HIGH);
     Serial.println("УТЕЧКИ ВОДЫ НЕТ");
     Serial.println(" ");
   };



};


   Stamps = timeClient.getEpochTime();

  stamp.getDateTime(Stamps);






  if (millis() - tmr1 >= (sending_period * 20000)) {
    tmr1 = millis();
    sendData();

  };


   if (tmrvent.tick()) {  



 
  };






 conFile["Wtemp"] = Wtemp;  // изменили
    conFile["Rtemp"] = Rtemp;  // изменили

 conFile["Rtemp2"] = Rtemp2;  // изменили


    conFile["ventday"] = ventday;  // изменили
    conFile["volt"] = volt;  // изменили


        conFile["Temperatura"] = Temperatura;  // изменили
    conFile["pwm27"] = pwm27;  // изменили

  conFile["Stamp"] = Stamps;  // изменили


conFile["vent0"] = vent0;  // изменили
conFile["vent1"] = vent1;  // изменили
conFile["vent2"] = vent2;  // изменили
conFile["vent3"] = vent3;  // изменили
conFile["vent4"] = vent4;  // изменили
conFile["vent5"] = vent5;  // изменили
conFile["vent6"] = vent6;  // изменили
conFile["vent7"] = vent7;  // изменили
conFile["vent8"] = vent8;  // изменили
conFile["vent9"] = vent9;  // изменили


conFile["ventob0"] = ventob0;  // изменили
conFile["ventob1"] = ventob1;  // изменили
conFile["ventob2"] = ventob2;  // изменили
conFile["ventob3"] = ventob3;  // изменили
conFile["ventob4"] = ventob4;  // изменили
conFile["ventob5"] = ventob5;  // изменили
conFile["ventob6"] = ventob6;  // изменили
conFile["ventob7"] = ventob7;  // изменили
conFile["ventob8"] = ventob8;  // изменили
conFile["ventob9"] = ventob9;  // изменили


conFile.tick();


  File file = LittleFS.open("/variables.txt", "w");
  if (!file) {
    Serial.println("Ошибка открытия файла для записи");
    return;
  }
  file.printf("ventel=%.2f\n", ventel);
  file.printf("poliv=%.2f\n", poliv);
  file.printf("Wtemp=%.2f\n", Wtemp);
  file.printf("Rtemp=%.2f\n", Rtemp);
  file.printf("Rtemp2=%.2f\n", Rtemp2);
  file.printf("dolivSENS=%d\n", dolivSENS);
  file.printf("waterSENS=%d\n", waterSENS);
  file.printf("ventday=%d\n", ventday);
  file.close();

server.handleClient();


 if (ventdayn != ventday) {
    Serial.println(ventday);
    ventdayn = ventday;
  };
  };
 