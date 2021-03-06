#include <SimpleLEDS.h>


// Тут должно быть ваше количество лед-светодидов
// В моем случае - это матрица 8*8, итого 64
#define COUNT_OF_LEDS 64

// Обьявление глобального массива светодидов.
CRGB leds[COUNT_OF_LEDS];

// Создадим обьект на основе глобального массива
// Через этот обьект мы сможем менять состояние
// лед-ленты / матрицы
SimpleLEDS simple_leds(leds);

void setup()
{
    simple_leds.restart(leds);
    simple_leds.clear_all(leds);
}


void loop()
{
    uint8_t random_R = rand()%255;
    srand(time(NULL));
    uint8_t random_G = rand()%255;
    srand(time(NULL));
    uint8_t random_B = rand()%255;
    srand(time(NULL));
    simple_leds.fill_advanced
    (
        leds,
        0,64,
        random_R,random_G,random_B
    );
    random_R = rand()%255;
    srand(time(NULL));
    random_G = rand()%255;
    srand(time(NULL));
    random_B = rand()%255;
    srand(time(NULL));
    simple_leds.fill_advanced
    (
        leds,
        0,64,
        random_R,random_G,random_B
    );
    delay(50);

}
