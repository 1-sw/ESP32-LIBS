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
    uint8_t previous_row = 0;
    for(uint8_t next_row = 8; next_row <= 64; next_row+=8)
    {

        uint8_t random_R = rand()%255;
        srand(time(NULL));

        uint8_t random_G = rand()%255;
        srand(time(NULL));

        simple_leds.fill_advanced
        (
            leds,
            previous_row,next_row,
            random_R,random_G,255
        );

        previous_row = next_row;
        delay(25);

    }
}
