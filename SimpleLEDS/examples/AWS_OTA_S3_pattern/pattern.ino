#include <SimpleLEDS.h>


////////////////////////////////Без этих зависимостей библиотека не скомпилится
#define COUNT_OF_LEDS 64
CRGB leds[COUNT_OF_LEDS];
SimpleLEDS simple_leds(leds);




void setup() 
{
  //////КОНФИГ/////////////////////////////////////
  const char* SSIDS = "SOME_SSID";
  const char* PSWD = "SOME_PSWD";
  String host = "host.host.host";
  int port = 8080;
  String bin = "/path_to_file";
  
  //////НАЧИНАЕМ ПОДГОТОВКУ К ОБНОВЕ С РЕСТАРТА////
  simple_leds.SetupOTA(PSWD,SSIDS,host,port,bin);
}


void loop()
{ 
  //////ОБНОВЛЯЕМ//////////////////////////////////
  //simple_leds.execOTA(PSWD,SSIDS,host,port,bin); 
  //Также можно обновить после условия
  //if(кнопка в приложении нажата?){
  //    simple_leds.execOTA(PSWD,SSIDS,host,port,bin); 
  //}
}