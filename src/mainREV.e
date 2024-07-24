

// #include <Arduino.h>

// #define AP_SSID "TP-LINK"
// #define AP_PASS "214365Qq"
// // #define GH_INCLUDE_PORTAL
// #define GH_NO_PORTAL
// #include <LittleFS.h>
// #define GH_FS LittleFS

// #include <GyverHub.h>
// GyverHub hub;
// #define WIFI_TIMEOUT_MS 20000
// #define WIFI_NETWORK "TP-LINK"
// #define WIFI_PASSWORD "214365Qq"



// //  GyverHub hub("MyDevices2", "ESP", "");  // можно настроить тут, но без F-строк!

// /// ====== НАСТРОЙКИ КОМПИЛЯЦИИ ======
// //#define ATOMIC_FS_UPDATE  // OTA обновление GZIP файлом
// #define GH_ASYNC          // использовать ASYNC библиотеки

// // отключение модулей
// //#define GH_NO_PORTAL    // открытие сайта из памяти esp
// //#define GH_NO_WS        // WebSocket
// //#define GH_NO_MQTT      // MQTT
// //#define GH_NO_FS        // работа с файлами (включая ОТА!)
// //#define GH_NO_OTA       // ОТА файлом с приложения
// //#define GH_NO_OTA_URL   // ОТА по URL
// // =================================
// // GH_MOD_INFO     // разрешить вкладку инфо
// // GH_MOD_FSBR     // разрешить вкладку менеджера файлов
// // GH_MOD_FORMAT   // разрешить форматирование FS
// // GH_MOD_DOWNLOAD // разрешить скачивание
// // GH_MOD_UPLOAD   // разрешить загрузку
// // GH_MOD_OTA      // разрешить ОТА
// // GH_MOD_OTA_URL  // разрешить ОТА по URL
// // GH_MOD_REBOOT   // разрешить перезагрузку из инфо
// // GH_MOD_SET      // разрешить установку значений
// // GH_MOD_READ     // разрешить чтение
// // GH_MOD_DELETE   // разрешить удаление файлов
// // GH_MOD_RENAME   // разрешить переименование файлов

// // GH_MOD_SERIAL   // разрешить Serial
// // GH_MOD_BT       // разрешить Bluetooth
// // GH_MOD_WS       // разрешить WebSocket
// // GH_MOD_MQTT     // разрешить MQTT
// // выключить менеджер файлов и кнопку переименования файлов

// // hub.modules.unset(GH_MOD_FSBR | GH_MOD_RENAME);

// // // разрешить связь по WS
// // hub.modules.set(GH_MOD_WS);


// // иконки
// // https://fontawesome.com/v5/cheatsheet/free/solid
// // https://fontawesome.com/v5/search?o=r&m=free&s=solid
// // переменные для интерфейса


// #include "ThingSpeak.h"

// #define CHANNEL_ID 1551807
// #define CHANNEL_API_KEY "EZVNSKEUD4RWXAAD"


// #define CHANNEL_ID2 1628917
// #define CHANNEL_API_KEY2 "R5VFO73Q37GESE3V"


// WiFiClient client;


//  #include "PCF8575.h"

//  // Set i2c address
//  PCF8575 pcf8575(0x20);
//  PCF8575 pcf85752(0x21);

//  float Temperatura= 25.5;


//  float vent0=25.0;
//  float vent1=25.5;
//  float vent2=26.0;
//  float vent3=26.3;
//  float vent4=26.5;
//  float vent5=27.0;
//  float vent6=27.5;
//  float vent7=28.0;


//  float ventel=0 ;


//  int timePoliv = 40000;
//  int timeDoliv = 180000;


//  #include <microDS3231.h>
//  MicroDS3231 rtc;


//  #include <Wire.h>
//  #include <LiquidCrystal_I2C.h>

//  LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
//  const int capteur_D = 19;
//  const int capteur_A = 15;

//  const int UTECHKA_PIN = 5;
//  int val_utechka;
//  int val_utechkaD;
//  #include <TimerMs.h>
//  #include "GyverTimer.h"
//  // (период, мс), (0 не запущен / 1 запущен), (режим: 0 период / 1 таймер)
//  TimerMs tmr(5000, 1, 0);
//  // TimerMs dolivpause(3000, 1, 1);
//  TimerMs textp(3000, 1, 0);
//  TimerMs tmrWF(20000, 1, 1);
//  // TimerMs WATERPING(5000, 1, 0);

//  GTimer dolivpause(MS);  // можно сразу указать период (по умолч. в режиме интервала)
//  GTimer polivtimer(MS);  // можно сразу указать период (по умолч. в режиме интервала)


//  // int value = 0;
//  unsigned long next_time; // время очередного переключения первого светодиода
//  int timeout = 2500; // половина периода мигания
//  //int led_state = 0; // начальное состояние светодиода - выключен


//  int DP=1;
//  // int grelka_PIN;
//  int grelka;



//  // Текущее состояние сенсора
//  bool SensorStateWS = HIGH;
//  // Время начала смены
//  unsigned long SensorStartChangeWS = 0;
//  // Защитный интервал между сменами состояния
//  unsigned long TIMEOUTWS = 1000;
//  // Текущее время
//  unsigned long CurrentTimeWS = 0;



//  // Текущее состояние сенсора
//  bool SensorStateDS = HIGH;
//  // Время начала смены
//  unsigned long SensorStartChangeDS = 0;
//  // Защитный интервал между сменами состояния
//  unsigned long TIMEOUTDS = 2000;
//  // Текущее время
//  unsigned long CurrentTimeDS = 0;

//  // Пример использования библиотеки GyverButton, все возможности в одном скетче.
//  // автоматический тик


//  #include "Button2.h"

//  // Button2 button;
//  byte pin = 13;
//  /////////////////////////////////////////////////////////////////

//  Button2 button;
//   #define BUTTON_PIN  13


//  #include <OneWire.h>
//  #include <DallasTemperature.h>

//  #define ONE_WIRE_BUS_1 23
//  #define ONE_WIRE_BUS_2 0

//  OneWire oneWire_in(ONE_WIRE_BUS_1);
//  OneWire oneWire_out(ONE_WIRE_BUS_2);

//  DallasTemperature sensor_inhouse(&oneWire_in);
//  DallasTemperature sensor_outhouse(&oneWire_out);

 
//    float Wtemp; // temperature in Celsius
//  int dolivSENS;
//  int waterSENS;
//  int podachawater;
//  bool polivpompa;

//  float poliv;


//   bool dolivpompa;
//  float Rtemp; // temperature in Celsius

//  #include "GyverFilters.h"
//  GFilterRA analog35;    // фильтр назовём analog0

//  const int voltPin = 35;

//  // variable for storing the potentiometer value
//  float voltValue;
//  float adcValue;
//  float filtrvolt;



// // обработчик кнопки (см. ниже)
// void btn_cb() {
//     Serial.println("click 4");
// }

// // обработчик кнопки с информацией о билде (см. ниже)
// void btn_cb_b(GH::Build& b) {
//     Serial.print("click 5 from client ID: ");
//     Serial.println(b.client.id);
// }

// // билдер
// void build(GH::Builder& b) {
//     // =================== КОНТЕЙНЕРЫ ===================

//     // основной контейнер страницы - столбец, т.е. виджеты будут располагаться на новых строках
//     b.Button();
//     b.Button();

//     // СПОСОБ 1
//     // вот так можно сделать горизонтальный контейнер
//     b.beginRow();  // начать
//     b.Button();
//     b.Button();
//     b.endRow();  // ВАЖНО НЕ ЗАБЫТЬ ЕГО ЗАВЕРШИТЬ

//     // СПОСОБ 2
//     // для красоты и удобства можно обернуть контейнер в блок {}
//     // функции beginRow() и beginCol() всегда возвращают true
//     if (b.beginRow()) {
//         b.Button();
//         b.Button();

//         b.endRow();  // завершить
//     }

//     // СПОСОБ 3
//     // есть ещё такой трюк - контейнер сам себя закроет в рамках блока {}
//     // назвать его можно как угодно, передать во внутрь аргумент билдера
//     {
//         GH::Row r(b);  // контейнер сам создастся здесь
//         b.Button();
//         b.Button();
//     }  // контейнер сам закроется здесь

//     // СПОСОБ 4
//     // и ещё вот такой макрос. Ширина контейнера 1 по умолчанию
//     GH_ROW(b, 1,
//            b.Button();
//            b.Button(););

//     // для вертикального контейнера справедлив такой же синтаксис:
//     // beginCol(), endCol(), GH::Col(), GH_COL()

//     // =================== ШИРИНА ===================

//     // ширина виджетов задаётся в "долях" - отношении их ширины друг к другу
//     // виджеты займут пропорциональное место во всю ширину контейнера
//     {
//         GH::Row r(b);
//         b.Slider().size(3);  // слайдер шириной 3
//         b.Button().size(1);  // кнопка шириной 1
//         b.Button();
//         b.Button();
//         // система запоминает последнюю установленную ширину
//         // у последних двух кнопок она автоматически станет 1
//     }

//     // посмотрим, как работает задание ширины контейнеру
//     {
//         GH::Row r(b);
//         {
//             // этот контейнер будет в 2 раза шире...
//             GH::Row r(b, 2);
//             b.Button();
//             b.Button();
//         }
//         {
//             // ...чем этот
//             GH::Row r(b, 1);
//             b.Button();
//             b.Button();
//         }
//     }

//     // =================== ПАРАМЕТРЫ ВИДЖЕТА ===================

//     if (b.beginRow()) {
//         // параметры виджета можно задавать цепочкой. Например:
//         b.Button().label(F("woo button")).color(GH::Colors::Red);

//         // также можно продолжить настраивать ПРЕДЫДУЩИЙ виджет, обратившись к widget:
//         b.Button();                        // кнопка без параметров
//         b.widget.label(F("button 2"));     // настраиваем кнопку выше
//         b.widget.color(GH::Colors::Blue);  // её же

//         b.endRow();
//     }

//     // =================== ДЕЙСТВИЯ ВИДЖЕТА ===================

//     // с активных виджетов можно получить сигнал о действии - клик или изменение значения
//     if (b.beginRow()) {
//         // СПОСОБ 1
//         // проверить условие click() - он вернёт true при действии
//         // click() нужно вызывать ПОСЛЕДНИМ в цепочке!!!
//         if (b.Button().click()) Serial.println("click 1");

//         // СПОСОБ 2
//         // подключить bool переменную - флаг
//         bool flag = 0;
//         b.Button().attach(&flag);
//         if (flag) Serial.println("click 2");

//         // СПОСОБ 3
//         // подключить GH::Flag переменную - флаг
//         // данный флаг сам сбросится в false при проверке!
//         GH::Flag gflag;
//         b.Button().attach(&gflag);
//         if (gflag) Serial.println("click 3");
//         // здесь gflag уже false

//         // СПОСОБ 4
//         // подключить функцию-обработчик (см. выше)
//         b.Button().attach(btn_cb);

//         // СПОСОБ 5
//         // подключить функцию-обработчик с инфо о билде (см. выше)
//         b.Button().attach(btn_cb_b);

//         // attach() может быть НЕ ПОСЛЕДНИМ в цепочке, также их может быть несколько:
//         // b.Button().attach(f1).attach(f2).label("kek");

//         b.endRow();
//     }

//     // =============== ПОДКЛЮЧЕНИЕ ПЕРЕМЕННОЙ ===============

//     if (b.beginRow()) {
//         // библиотека позволяет подключить к активному виджету переменную для чтения и записи
//         // я создам статические переменные для ясности. Они могут быть глобальными и так далее
//         // таким образом изменения останутся при перезагрузке страницы
//         static int sld;
//         static String inp;
//         static bool sw;

//         // для подключения нужно передать переменную по адресу
//         // библиотека сама определит тип переменной и будет брать из неё значение и записывать при действиях
//         // библиотека поддерживает все стандартные типы данных, а также некоторые свои (Pairs, Pos, Button, Log...)
//         b.Slider(&sld).size(2);
//         b.Input(&inp).size(2);

//         // внутри обработки действия переменная уже будет иметь новое значение:
//         if (b.Switch(&sw).size(1).click()) {
//             Serial.print("switch: ");
//             Serial.println(sw);
//         }

//         b.endRow();
//     }

//     // ==================== ОБНОВЛЕНИЕ ====================

//     // библиотека позволяет обновлять значения на виджетах. Это можно делать
//     // - из основной программы (см. ниже)
//     // - из билдера - но только при действиях по виджетам!

//     // для отправки обновления нужно знать ИМЯ компонента. Его можно задать почти у всех виджетов
//     // к функции добавляется подчёркивание, всё остальное - как раньше

//     if (b.beginRow()) {
//         b.Label_(F("label")).size(2).valueStr("default");  // с указанием стандартного значения

//         if (b.Button().size(1).click()) {
//             hub.update(F("label")).valueInt(random(100, 500));
//         }

//         b.endRow();
//     }

//     // в самом низу сделаем заголовок, текст будем обновлять из loop() (см. ниже)
//     b.Title_(F("title"));

//     // =================== ИНФО О БИЛДЕ ===================

//     // можно получить информацию о билде и клиенте для своих целей
//     // поставь тут 1, чтобы включить вывод =)
//     if (1) {
//         // запрос информации о виджетах
//         if (b.build.isUI()) {
//             Serial.println("=== UI BUILD ===");
//         }

//         // действие с виджетом
//         if (b.build.isSet()) {
//             Serial.println("=== SET ===");
//             Serial.print("name: ");
//             Serial.println(b.build.name);
//             Serial.print("value: ");
//             Serial.println(b.build.value);
//         }

//         Serial.print("client from: ");
//         Serial.println(GH::readConnection(b.build.client.connection));
//         Serial.print("ID: ");
//         Serial.println(b.build.client.id);
//         Serial.println();
//     }
// }



//  void pressed(Button2& btn) {
//      Serial.println("pressed");
//     	// pcf8575.digitalWrite(P3, LOW);
//      poliv=1;
//  //  dolivpause.setTimeout(timeDoliv);       //  пауза долива и подогрева
//  //   polivtimer.setTimeout(timePoliv);

//  }
//  void released(Button2& btn) {
//      Serial.print("released: ");
//      Serial.println(btn.wasPressedFor());
    
//            	// pcf8575.digitalWrite(P3, LOW);
//  //  dolivpause.setTimeout(timeDoliv);       //  пауза долива и подогрева
//  //   polivtimer.setTimeout(timePoliv);
//  }
//  void changed(Button2& btn) {
//      Serial.println("changed");
//  }
//  void click(Button2& btn) {
//      Serial.println("click\n");
//          poliv=1;
//         	// pcf8575.digitalWrite(P3, LOW);
//  //  dolivpause.setTimeout(timeDoliv);       //  пауза долива и подогрева
//  //   polivtimer.setTimeout(timePoliv);
//  }
//  void longClickDetected(Button2& btn) {
//      Serial.println("long click detected");
//      poliv=0;
//  }
//  void longClick(Button2& btn) {
//      Serial.println("long click\n");
//          poliv=0;
//     	// pcf8575.digitalWrite(P3, HIGH);
//  }
//  void doubleClick(Button2& btn) {
//      Serial.println("double click\n");
//          poliv=1;
//          // pcf8575.digitalWrite(P3, LOW);

//  //  dolivpause.setTimeout(timeDoliv);       //  пауза долива и подогрева
//  //   polivtimer.setTimeout(timePoliv);
//  }
//  void tripleClick(Button2& btn) {
//      Serial.println("triple click\n");
//      Serial.println(btn.getNumberOfClicks());
//          poliv=0;
//  }
//  void tap(Button2& btn) {
//      Serial.println("tap");
//      poliv=1;
//  }




// void setup() {
//     Serial.begin(115200);

// #ifdef GH_ESP_BUILD
//     // подключение к роутеру
//     WiFi.mode(WIFI_STA);
//     WiFi.begin(AP_SSID, AP_PASS);
//     while (WiFi.status() != WL_CONNECTED) {
//         delay(500);
//         Serial.print(".");
//     }
//     Serial.println();
//     Serial.println(WiFi.localIP());



//      button.begin(BUTTON_PIN);
//      // pinMode(BUTTON_PIN);
//    button.setLongClickTime(3000);
//    button.setDoubleClickTime(300);
//   button.setChangedHandler(changed);
//     button.setPressedHandler(pressed);
//    button.setReleasedHandler(released);

//    // button.setTapHandler(tap);
//    button.setClickHandler(click);
//    button.setLongClickDetectedHandler(longClickDetected);
//    button.setLongClickHandler(longClick);
//    button.setLongClickDetectedRetriggerable(false);
  
//    button.setDoubleClickHandler(doubleClick);
//    button.setTripleClickHandler(tripleClick);



  
//  pcf8575.begin();
//   pcf85752.begin();

//  // установка коэффициента фильтрации (0.0... 1.0). Чем меньше, тем плавнее фильтр
//    analog35.setCoef(0.01);

//    // установка шага фильтрации (мс). Чем меньше, тем резче фильтр
//    analog35.setStep(10);
//  // #define P00  	0
//  // 	#define P01  	1
//  // 	#define P02  	2
//  // 	#define P03  	3
//  // 	#define P04  	4
//  // 	#define P05  	5
//  // 	#define P06  	6
//  // 	#define P07  	7
//  // 	#define P10  	8
//  // 	#define P11  	9
//  // 	#define P12  	10
//  // 	#define P13  	11
//  // 	#define P14  	12
//  // 	#define P15  	13
//  // 	#define P16  	14
//  // 	#define P17  	15
//  	pcf8575.pinMode(P0, OUTPUT);
//    pcf8575.pinMode(P1, OUTPUT);
//    pcf8575.pinMode(P2, OUTPUT);
//    pcf8575.pinMode(P3, OUTPUT);
//    pcf8575.pinMode(P4, OUTPUT);
//    pcf8575.pinMode(P5, OUTPUT);
//    pcf8575.pinMode(P6, OUTPUT);
//    pcf8575.pinMode(P7, OUTPUT);
//    pcf8575.pinMode(P8, OUTPUT);
//    pcf8575.pinMode(P9, OUTPUT);

//  pcf8575.pinMode(P10, OUTPUT);
//  pcf8575.pinMode(P11, OUTPUT);
//  pcf8575.pinMode(P12, OUTPUT);
//  pcf8575.pinMode(P15, OUTPUT);
//  pcf8575.pinMode(P14, OUTPUT);
//  pcf8575.pinMode(P13, OUTPUT);

//  pcf8575.digitalWrite(P0, HIGH);


//  	pcf8575.digitalWrite(P1, HIGH);



//  	pcf8575.digitalWrite(P2, HIGH);

//  	pcf8575.digitalWrite(P3, HIGH);
	
//  	pcf8575.digitalWrite(P4, HIGH);

//  	pcf8575.digitalWrite(P5, HIGH);

//  	pcf8575.digitalWrite(P6, HIGH);

//  	pcf8575.digitalWrite(P7, HIGH);

//  	pcf8575.digitalWrite(P8, HIGH);

//  	pcf8575.digitalWrite(P9, HIGH);


//    	pcf8575.digitalWrite(P10, HIGH);

//    	pcf8575.digitalWrite(P11, HIGH);

//  	pcf8575.digitalWrite(P12, HIGH);

//       	pcf8575.digitalWrite(P13, HIGH);

//      	pcf8575.digitalWrite(P14, HIGH);

//      	pcf8575.digitalWrite(P15, HIGH);



//  	pcf85752.pinMode(P0, OUTPUT);
//    pcf85752.pinMode(P1, OUTPUT);
//    pcf85752.pinMode(P2, OUTPUT);
//    pcf85752.pinMode(P3, OUTPUT);
//    pcf85752.pinMode(P4, OUTPUT);
//    pcf85752.pinMode(P5, OUTPUT);
//    pcf85752.pinMode(P6, OUTPUT);
//    pcf85752.pinMode(P7, OUTPUT);
//    pcf85752.pinMode(P8, OUTPUT);
//    pcf85752.pinMode(P9, OUTPUT);

//  pcf85752.pinMode(P10, OUTPUT);
//  pcf85752.pinMode(P11, OUTPUT);
//  pcf85752.pinMode(P12, OUTPUT);
//  pcf85752.pinMode(P15, OUTPUT);
//  pcf85752.pinMode(P14, OUTPUT);
//  pcf85752.pinMode(P13, OUTPUT);



//  pcf85752.digitalWrite(P0, HIGH);


//  	pcf85752.digitalWrite(P1, HIGH);



//  	pcf85752.digitalWrite(P2, HIGH);

//  	pcf85752.digitalWrite(P3, HIGH);
	
//  	pcf85752.digitalWrite(P4, HIGH);

//  	pcf85752.digitalWrite(P5, HIGH);

//  	pcf85752.digitalWrite(P6, HIGH);

//  	pcf85752.digitalWrite(P7, HIGH);

//  	pcf85752.digitalWrite(P8, HIGH);

//  	pcf85752.digitalWrite(P9, HIGH);


//    	pcf85752.digitalWrite(P10, HIGH);

//    	pcf85752.digitalWrite(P11, HIGH);

//  	pcf85752.digitalWrite(P12, HIGH);

//       	pcf85752.digitalWrite(P13, HIGH);

//      	pcf85752.digitalWrite(P14, HIGH);

//      	pcf85752.digitalWrite(P15, HIGH);

//    // Serial.println(" Longpress Time:\t" + String(button.getLongClickTime()) + "ms");
//    // Serial.println(" DoubleClick Time:\t" + String(button.getDoubleClickTime()) + "ms");
//    // Serial.println();

   

//  // tmrWF.setTimerMode();
//  tmrWF.setPeriodMode();
//  // tmr.setPeriodMode();
//  // tmr2.setPeriodMode();
//  // textp.setPeriodMode();


//     // настройка таймаута на удержание (по умолчанию 500 мс)


 
//    lcd.begin(SDA, SCL); //initialize 1602  LiquidCrystal_I2C::begin(int8_t sda, int8_t scl)
//    // Print a message to the LCD.
//    lcd.backlight();
//    lcd.setCursor(0,0);
//    lcd.print("Hello, world!");
//    lcd.setCursor(0,1);
//    lcd.print("by EasyIoT");
//  // sensors.begin();
//   Serial.begin(115200);
//     Serial.print("Locating devices...");
//    Serial.print("Found ");
//    // Serial.print(sensors.getDeviceCount(), DEC);
//    Serial.println(" devices.");

//     // start serial port

//    Serial.println("Dallas Temperature IC Control Library Demo");




//    sensor_inhouse.begin();
//    sensor_outhouse.begin();
//    // проверка наличия модуля на линии i2c
//   rtc.begin();
   
//  pinMode(4, INPUT); // СЕНСОР ДОЛИВА
//  pinMode(17, INPUT);    // СЕНСОР ПОДАЧИ ВОДЫ (ВЕРХ)
//  pinMode(19, INPUT); //sens 1
//  pinMode(15, INPUT);

//   rtc.setTime(BUILD_SEC, BUILD_MIN, BUILD_HOUR, BUILD_DAY, BUILD_MONTH, BUILD_YEAR);

  

//    lcd.clear();

// //   connectToWiFi(); // this function comes from a previous video
  
//    ThingSpeak.begin(client);

//     // если нужен MQTT - подключаемся
//     hub.mqtt.config("test.mosquitto.org", 1883);
//     // hub.mqtt.config("test.mosquitto.org", 1883, "login", "pass");

//     // ИЛИ

//     // режим точки доступа
//     // WiFi.mode(WIFI_AP);
//     // WiFi.softAP("My Hub");
//     // Serial.println(WiFi.softAPIP());    // по умолч. 192.168.4.1
// #endif

//     // указать префикс сети, имя устройства и иконку
//     hub.config(F("TP-LINK"), F("ESP32"), F(""));

//     // подключить билдер
//     hub.onBuild(build);

//     // запуск!
//     hub.begin();
// }

// void loop() {




//     // =================== ТИКЕР ===================
//     // вызываем тикер в главном цикле программы
//     // он обеспечивает работу связи, таймаутов и прочего
//     hub.tick();

// //  static GH::Timer tmrhubsend(1000);
// //   if (tmrhubsend) hub.sendUpdate("comp", "val");

//     // =========== ОБНОВЛЕНИЯ ПО ТАЙМЕРУ ===========
//     // в библиотеке предусмотрен удобный класс асинхронного таймера
//     static GH::Timer tmrhub(1000);  // период 1 секунда

//     // каждую секунду будем обновлять заголовок
//     if (tmrhub) {
//         hub.update(F("title")).valueInt(millis());
//     }
//      DateTime now = rtc.getTime();
//    button.loop();


//  val_utechkaD = digitalRead(19);



//       int dolivSENS = digitalRead(4);

//   int waterSENS = digitalRead(17);





//     int podachawater =  pcf8575.digitalRead(P1);
//       bool polivpompa = !pcf8575.digitalRead(P3);
//    bool dolivpompa = pcf8575.digitalRead(P8);


//  adcValue = analogRead(voltPin);
//  voltValue = 3.6320 * ((adcValue * 3.3) / 4095);
//    // voltValue = 3.047 * ((adcValue * 3.7875) / 4095);
//    filtrvolt = analog35.filteredTime(voltValue);



//      lcd.setCursor(0,0);
//    lcd.print(rtc.getTimeString());
   





//   // butt1.tick();  // НЕ НУЖНА, в этом режиме (AUTO) она входит в каждую функцию

//  //   butt1.tick();
//  //  if (butt1.isClick()) {
//  //   Serial.println("Click");
//  //    poliv=1;}  ;      // проверка на один клик
//  //   if (butt1.isSingle()) {
//  //     Serial.println("Single");
//  //    poliv=1;};       // проверка на один клик
//  //   if (butt1.isDouble()){
//  //      Serial.println("Double");
//  //    poliv=1;}  ;     // проверка на двойной клик
//  //   if (butt1.isTriple()) {
//  //     Serial.println("Triple");
//  //     poliv=0;} ;     // проверка на тройной клик

//  //   if (butt1.hasClicks())                                // проверка на наличие нажатий
//  //     Serial.println(butt1.getClicks());                  // получить (и вывести) число нажатий

//  //   if (butt1.isPress()) {
//  //     Serial.println("Press");
//  //    poliv=1;}   ;      // нажатие на кнопку (+ дебаунс)
//  //   if (butt1.isRelease()) Serial.println("Release");     // отпускание кнопки (+ дебаунс)
//  //   if (butt1.isHolded())
//  //   {Serial.println("Holded");
//  //       poliv=0;}   ;      // проверка на удержание
//  //   if (butt1.isHold())
//  //   {Serial.println("Holding");
//  //    poliv=0;}   ;    // проверка на удержание
//  //   //if (butt1.state()) Serial.println("Hold");          // возвращает состояние кнопки

//  //   if (butt1.isStep()) {                                 // если кнопка была удержана (это для инкремента)
//  //     value++;                                            // увеличивать/уменьшать переменную value с шагом и интервалом
//  //     Serial.println(value);                              // для примера выведем в порт
//  //   };


//  if (poliv==1) {
//      // Serial.println("poliv on");
//     pcf8575.digitalWrite(P3, LOW);
//    };

//  if (poliv==0) {
//      // Serial.println("poliv oFF");
//     pcf8575.digitalWrite(P3, HIGH);
//    };


//  float grelkatime = now.hour;
//   if (grelkatime >=10.00 && grelkatime <=21.00){
//      if (Wtemp < Temperatura && Wtemp >= 11) {
//    	pcf8575.digitalWrite(P2, LOW);
//      grelka = 1;
//      //  Serial.println(grelkatime);
//    }
//      else  {
//    	pcf8575.digitalWrite(P2, HIGH);
//      grelka = 0;

//    };
//   };

//       sensor_inhouse.requestTemperatures();
//    sensor_outhouse.requestTemperatures();
//    float Wtempl=sensor_inhouse.getTempCByIndex(0);

//  float Rtempl=sensor_outhouse.getTempCByIndex(0);
//  if (tmr.tick()){


//  if  (Wtempl >=10 && Wtempl <=50) {
//  Wtemp = Wtempl;};

//  if  (Rtempl >=10 && Rtempl <=50) {
//  Rtemp = Rtempl;};

//     if (Rtemp <= vent0 && Rtemp <= vent1 ) {
//  ventel=0;
//      Serial.println("VENT-0");
    
//   lcd.setCursor(10,8);
//    lcd.print("VENT-0");
//    };

//      if (Rtemp >= vent1 && Rtemp <= vent2 ) {
//    ventel=1;
//       Serial.println("VENT-1");
     
//   lcd.setCursor(10,8);
//    lcd.print("VENT-1");
//    };

//   if (Rtemp >= vent2 && Rtemp <= vent3) {
//  ventel=2;;
//          Serial.println("VENT-2");
        
//   lcd.setCursor(10,8);
//    lcd.print("VENT-2");
//    };

//   if (Rtemp >= vent3 && Rtemp <= vent4) {
//  ventel=3;
//          Serial.println("VENT-3");
        
//   lcd.setCursor(10,8);
//    lcd.print("VENT-3");
 

 
//    };


//     if (Rtemp >= vent4 && Rtemp <= vent5) {
//  	ventel=4;
//          Serial.println("VENT-4");
        
//   lcd.setCursor(10,8);
//    lcd.print("VENT-4");
 

 
//    };


//     if (Rtemp >= vent5 && Rtemp <= vent6) {
//  	ventel=5;
//          Serial.println("VENT-5");
        
//   lcd.setCursor(10,8);
//    lcd.print("VENT-5");
 

 
//    };



//     if (Rtemp >= vent6 && Rtemp <= vent7) {
//    	ventel=6;
//          Serial.println("VENT-6");
        
//   lcd.setCursor(10,8);
//    lcd.print("VENT-6");
//     };
//      if (Rtemp >= vent7) {
//  	ventel=7;
//          Serial.println("VENT-7");
        
//   lcd.setCursor(10,8);
//    lcd.print("VENT-7");

 
//    };

//  };





   

//   // Устанавливаем текущее время
//    CurrentTimeWS = millis();
//    // считываем сенсор
//    boolean CurrentStateWS = waterSENS;
//    // если текущее состояние сенсора отличается считанного
//    if (CurrentStateWS != SensorStateWS) {
//      // если отсчет таймера смены состояния не начат, начинаем
//      if (SensorStartChangeWS == 0) SensorStartChangeWS = CurrentTimeWS;
//      // если новое состояние приняло свое значение за время большее чем время таймаута
//      if (CurrentTimeWS - SensorStartChangeWS > TIMEOUTWS) {
//          // меняем состояние сенсора
//          SensorStateWS=!SensorStateWS;
//          // сбрасываем время начала смены состояния
//          SensorStartChangeWS = 0;
//          // если текущее состояние сенсора 1, то включаем светодиод
//          if(SensorStateWS){
//            	pcf8575.digitalWrite(P1, HIGH);
//          // если текущее состояние сенсора 0, то выключаем светодиод
//          }else{
//           pcf8575.digitalWrite(P1, LOW);
//          }
//      }
//    // смена состояния не состоялась, сбрасываем таймер
//    }else{
//      SensorStartChangeWS = 0;
//    };


//  // Устанавливаем текущее время
//    CurrentTimeDS = millis();
//    // считываем сенсор
//    boolean CurrentStateDS = dolivSENS;
//    // если текущее состояние сенсора отличается считанного
//    if (CurrentStateDS != SensorStateDS) {
//      // если отсчет таймера смены состояния не начат, начинаем
//      if (SensorStartChangeDS == 0) SensorStartChangeDS = CurrentTimeDS;
//      // если новое состояние приняло свое значение за время большее чем время таймаута
//      if (CurrentTimeDS - SensorStartChangeDS > TIMEOUTDS) {
//          // меняем состояние сенсора
//          SensorStateDS=!SensorStateDS;
//          // сбрасываем время начала смены состояния
//          SensorStartChangeDS = 0;
//          // если текущее состояние сенсора 1, то включаем светодиод
//          if(SensorStateDS){
//            	pcf8575.digitalWrite(P8, HIGH);
//          // если текущее состояние сенсора 0, то выключаем светодиод
//          }else{
//           pcf8575.digitalWrite(P8, LOW);
//          }
//      }
//    // смена состояния не состоялась, сбрасываем таймер
//    }else{
//      SensorStartChangeDS = 0;
//    };





//     if (textp.tick()){
//      Serial.println(voltValue);
//   Serial.println("   ");
//  Serial.println(adcValue);



//  //    if (Rtemp <= vent0) {
//  //   	pcf8575.digitalWrite(P15, HIGH);
//  //      pcf8575.digitalWrite(P14, HIGH);
//  //     pcf8575.digitalWrite(P13, HIGH);
//  //     Serial.println("VENT-0");
    
//  //  lcd.setCursor(10,8);
//  //   lcd.print("VENT-0");
//  //   };

//  //     if (Rtemp >= vent1) {
//  //   	pcf8575.digitalWrite(P15, LOW);
//  //     pcf8575.digitalWrite(P14, HIGH);
//  //     pcf8575.digitalWrite(P13, HIGH);
//  //      Serial.println("VENT-1");
     
//  //  lcd.setCursor(10,8);
//  //   lcd.print("VENT-1");
//  //   };

//  //  if (Rtemp >= vent2) {
//  //   	pcf8575.digitalWrite(P14, LOW);
//  //   pcf8575.digitalWrite(P15, HIGH);
//  //     pcf8575.digitalWrite(P13, HIGH);
//  //         Serial.println("VENT-2");
        
//  //  lcd.setCursor(10,8);
//  //   lcd.print("VENT-2");
//  //   };

//  //  if (Rtemp >= vent3) {
//  //   	pcf8575.digitalWrite(P13, LOW);
//  //     pcf8575.digitalWrite(P14, HIGH);
//  //     pcf8575.digitalWrite(P15, HIGH);
//  //         Serial.println("VENT-3");
        
//  //  lcd.setCursor(10,8);
//  //   lcd.print("VENT-3");
 

 
//  //   };


//  //    if (Rtemp >= vent4) {
//  // 	pcf8575.digitalWrite(P15, LOW);
//  //     pcf8575.digitalWrite(P14, LOW);
//  //     pcf8575.digitalWrite(P13, HIGH);
//  //         Serial.println("VENT-4");
        
//  //  lcd.setCursor(10,8);
//  //   lcd.print("VENT-4");
 

 
//  //   };


//  //    if (Rtemp >= vent5) {
//  // 	pcf8575.digitalWrite(P15, HIGH);
//  //     pcf8575.digitalWrite(P14, LOW);
//  //     pcf8575.digitalWrite(P13, LOW);
//  //         Serial.println("VENT-5");
        
//  //  lcd.setCursor(10,8);
//  //   lcd.print("VENT-5");
 

 
//  //   };



//  //    if (Rtemp >= vent6) {
//  //   	pcf8575.digitalWrite(P13, LOW);
//  //     pcf8575.digitalWrite(P14, LOW);
//  //     pcf8575.digitalWrite(P15, LOW);
//  //         Serial.println("VENT-6");
        
//  //  lcd.setCursor(10,8);
//  //   lcd.print("VENT-6");
 

 
//  //   };


//    Serial.println();


//   if  (Wtemp >=10) {
//      Serial.print("Sensor W(*C): ");
//    Serial.print(Wtemp, 2);
 
//    };
//    Serial.println();
//   if  (Rtemp >=10) {
//      Serial.print("Sensor R(*C): ");
//    Serial.print(Rtemp, 2);
//    };
 

//  Serial.println();





//   Serial.print("Кипятильник-");
//   if  (grelka ==1) {
//      Serial.println("ВКЛ ");
  
//    }
//      else  {
//        Serial.println("ВЫКЛ ");
//    };


//  Serial.print("СЕНСОР НИЖНИЙ УРОВНЯ ВОДЫ--");
//   if  (dolivSENS == 1) {
//      Serial.println(" ВКЛ ");
  
//    }
//      else  {
//        Serial.println(" ВЫКЛ ");
//    };




//  Serial.print("СЕНСОР ВЕРХНИЙ УРОВНЯ ВОДЫ---");
//   if  (waterSENS == 1) {
//      Serial.println(" ВКЛ ");
  
//    }
//     if  (waterSENS == 0) {
//        Serial.println(" ВЫКЛ ");
//    };


//  Serial.print("Помпа на долив--");
//   if  (dolivpompa ==0) {
//      Serial.println(" ВКЛ ");
  
//    }
//      else  {
//        Serial.println(" ВЫКЛ ");
//    };

//  Serial.print("Помпа на Полив--");
//   if  (dolivpompa ==0) {
//      Serial.println(" ВКЛ ");
  
//    }
//      else  {
//        Serial.println(" ВЫКЛ ");
//    };

//  Serial.print("Подача воды с фильтра--");
//   if  (podachawater ==0) {
//      Serial.println(" ВКЛ ");
  
//    }
//      else  {
//        Serial.println(" ВЫКЛ ");
//    };




//  Serial.print("переменная долива--");
//   if  (DP >=0) {
//      Serial.println(" ВКЛ ");
  
//    }
//      else  {
//        Serial.println(" ВЫКЛ ");
//    };

//  if(digitalRead(19) == 0)
//    {
//   	pcf8575.digitalWrite(P4, LOW);
//      Serial.println("УТЕЧКА ВОДЫ/220 ОБЕСТОЧЕНО");
//      Serial.println(" ");
//    };


//  if(digitalRead(19) == 1)
//    {
//    	pcf8575.digitalWrite(P4, HIGH);
//      Serial.println("УТЕЧКИ ВОДЫ НЕТ");
//      Serial.println(" ");
//    };






//    lcd.setCursor(0,2);
//    lcd.print("WS-");
//    lcd.setCursor(3,2);
//    lcd.print(waterSENS);

//      lcd.setCursor(0,3);
//    lcd.print("DS-");
//    lcd.setCursor(3,3);
//    lcd.print(dolivSENS);

//   lcd.setCursor(10,0);
//    lcd.print("W-");
//    lcd.setCursor(12,0);
//    lcd.print(Wtemp, 2);

//   lcd.setCursor(10,1);
//    lcd.print("R-");
//    lcd.setCursor(12,1);
//    lcd.print(Rtemp, 2);


//    lcd.setCursor(0,1);
//    lcd.print("220-");
//    lcd.setCursor(4,1);
//    lcd.print(val_utechkaD);

  
//    };
   
//  if (tmrWF.tick()){

//    Serial.println("SENDED");

//   ThingSpeak.setField(1, Wtemp);
//    ThingSpeak.setField(2, Rtemp);
//     ThingSpeak.setField(3, waterSENS);
//    ThingSpeak.setField(4, dolivSENS);

//     ThingSpeak.setField(5, grelka);
//    ThingSpeak.setField(6, podachawater);
//     ThingSpeak.setField(7, dolivpompa);
//   ThingSpeak.setField(8, polivpompa);

//    ThingSpeak.writeFields(CHANNEL_ID, CHANNEL_API_KEY);


//   ThingSpeak.setField(1, ventel);
//    ThingSpeak.setField(2, filtrvolt);
//     ThingSpeak.setField(3, waterSENS);
//    ThingSpeak.setField(4, dolivSENS);

//     ThingSpeak.setField(5, grelka);
//    ThingSpeak.setField(6, podachawater);
//     ThingSpeak.setField(7, dolivpompa);
//    ThingSpeak.setField(8, ventel);
//  //  ThingSpeak.setField(9, ventel);
//    ThingSpeak.writeFields(CHANNEL_ID2, CHANNEL_API_KEY2);


//   if (ventel == 0) {
//    pcf8575.digitalWrite(P9, HIGH);
//  	pcf8575.digitalWrite(P15, HIGH);
//       pcf8575.digitalWrite(P14, HIGH);
//      pcf8575.digitalWrite(P13, HIGH);
//        Serial.println("VENTEL0");
//    };

//    if (ventel == 1) {
//      pcf8575.digitalWrite(P9, LOW); //2.4
//  pcf8575.digitalWrite(P15, HIGH); // 1.96
//      pcf8575.digitalWrite(P14, HIGH); // 1.80
//      pcf8575.digitalWrite(P13, HIGH); // 1.61
//      Serial.println("VENTEL1");
//  };

//      if (ventel == 2) {
//      pcf8575.digitalWrite(P9, HIGH); //2.4
//  pcf8575.digitalWrite(P15, LOW); // 1.96
//      pcf8575.digitalWrite(P14, HIGH); // 1.80
//      pcf8575.digitalWrite(P13, HIGH); // 1.61
//      Serial.println("VENTEL2");
//  };
//        if (ventel == 3) {
//              pcf8575.digitalWrite(P9, HIGH); //2.4
//  pcf8575.digitalWrite(P15, HIGH); // 1.96
//      pcf8575.digitalWrite(P14, LOW); // 1.80
//      pcf8575.digitalWrite(P13, HIGH); // 1.61
//      Serial.println("VENTEL3");
//  };

//          if (ventel == 4) {
//       pcf8575.digitalWrite(P9, HIGH); //2.4
//  pcf8575.digitalWrite(P15, HIGH); // 1.96
//      pcf8575.digitalWrite(P14, HIGH); // 1.80
//      pcf8575.digitalWrite(P13, LOW); // 1.61
//      Serial.println("VENTEL4");
//  };
//            if (ventel == 5) {
//                  pcf8575.digitalWrite(P9, LOW); //2.4
//  pcf8575.digitalWrite(P15, LOW); // 1.96
//      pcf8575.digitalWrite(P14, HIGH); // 1.80
//      pcf8575.digitalWrite(P13, HIGH); // 1.61
//      Serial.println("VENTEL5");
//  };
//              if (ventel == 6) {
//                    pcf8575.digitalWrite(P9, LOW); //2.4
//  pcf8575.digitalWrite(P15, HIGH); // 1.96
//      pcf8575.digitalWrite(P14, HIGH); // 1.80
//      pcf8575.digitalWrite(P13, LOW); // 1.61
//      Serial.println("VENTEL6");
//  };

//              if (ventel == 7) {
//                   pcf8575.digitalWrite(P9, HIGH); //2.4
//  pcf8575.digitalWrite(P15, LOW); // 1.96
//      pcf8575.digitalWrite(P14, LOW); // 1.80
//      pcf8575.digitalWrite(P13, LOW); // 1.61
//      Serial.println("VENTEL7");
//  };

//  }
// }


