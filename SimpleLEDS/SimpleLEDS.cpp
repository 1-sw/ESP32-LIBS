#include "Arduino.h"
#include "FastLED.h"
#include "SimpleLEDS.h"

#define PIN 33
#define COUNT_OF_LEDS 64


SimpleLEDS::SimpleLEDS(CRGB arg_leds[COUNT_OF_LEDS])
{
    pinMode(PIN, OUTPUT);
}
void SimpleLEDS::restart(CRGB arg_leds[COUNT_OF_LEDS])
{
    FastLED.addLeds<NEOPIXEL, PIN>(arg_leds, COUNT_OF_LEDS);
}

void SimpleLEDS::test_all_by_random(CRGB arg_leds[COUNT_OF_LEDS])
{
    for(uint8_t led = 0; led < COUNT_OF_LEDS; led++ )
    {
        arg_leds[ led ] = CHSV(rand()%255,rand()%255,rand()%255);
        FastLED.delay(50);
        arg_leds[ led ] = CHSV(0,0,0);
    }
}
void SimpleLEDS::clear_all_slow(CRGB arg_leds[COUNT_OF_LEDS])
{
    for(uint8_t led = 0; led < COUNT_OF_LEDS; led++ )
    {
        FastLED.delay(10);
        arg_leds[ led ] = CHSV(0,0,0);
    }
}

void SimpleLEDS::clear_all(CRGB arg_leds[COUNT_OF_LEDS])
{
    for(uint8_t led = 0; led < COUNT_OF_LEDS; led++ )
    {
        FastLED.delay(0);
        arg_leds[ led ] = CHSV(0,0,0);
    }
}

void SimpleLEDS::fill_all_slow
(
    CRGB arg_leds[COUNT_OF_LEDS],
    uint8_t R,uint8_t G,uint8_t B
    ){
    for(uint8_t led = 0; led < COUNT_OF_LEDS; led++ )
    {
        FastLED.delay(10);
        arg_leds[ led ] = CHSV(R,G,B);
    }
}

void SimpleLEDS::fill_all
(
    CRGB arg_leds[COUNT_OF_LEDS],
    uint8_t R,uint8_t G,uint8_t B
    ){
    for(uint8_t led = 0; led < COUNT_OF_LEDS; led++ )
    {
        FastLED.delay(0);
        arg_leds[ led ] = CHSV(R,G,B);
    }
}

void SimpleLEDS::nervous_blinking
(
    CRGB arg_leds[COUNT_OF_LEDS],
    uint8_t R,uint8_t G,uint8_t B
    ){
    SimpleLEDS::fill_all(arg_leds,R,G,B);
    delay(1);
    SimpleLEDS::clear_all(arg_leds);
}

void SimpleLEDS::fast_advanced_blinking
(
    CRGB arg_leds[COUNT_OF_LEDS],
    uint8_t FROM_LED, uint8_t TO_LED,
    uint8_t R,uint8_t G,uint8_t B,
    uint8_t r,uint8_t g,uint8_t b
    ){
    for(uint8_t led=FROM_LED; led<TO_LED; led++)
    {
        SimpleLEDS::fill_advanced(arg_leds,FROM_LED,TO_LED,R, G, B);
        SimpleLEDS::fill_advanced(arg_leds,FROM_LED,TO_LED,r,g,b);
    }
}

void SimpleLEDS::show_all_colors
(
    CRGB arg_leds[COUNT_OF_LEDS]
    ){
    int color = 0;
    do
    {
       for(;color < 255; color+=5)
       {
           SimpleLEDS::fill_all(arg_leds,color, color, color);
           FastLED.delay(0);
       }
    } while( color != 255 );
    for(;color >= 0; color-=5)
    {
        SimpleLEDS::fill_all(arg_leds,color, color, color);
        FastLED.delay(0);
    }
}



void SimpleLEDS::fill_advanced
(
    CRGB arg_leds[COUNT_OF_LEDS],
    uint8_t START_LED, uint8_t END_LED,
    uint8_t R,uint8_t G,uint8_t B
    ){
    for(;START_LED < END_LED; START_LED++)
    {
        arg_leds[ START_LED ] = CHSV(R, G, B);
        FastLED.delay(0);
    }
}

uint8_t SimpleLEDS::convert_led_index(uint8_t NUM_OF_LED, uint8_t NUM_OF_ROW)
{
    return (NUM_OF_ROW * 8) + (NUM_OF_LED - 8);
}
void SimpleLEDS::DRAW_ONCE_WITH_BLOCKED_AREA
(
    CRGB arg_leds[COUNT_OF_LEDS],
    uint8_t LED_FROM, uint8_t LED_TO,
    uint8_t BLOCK_LED_FROM, uint8_t BLOCK_LED_TO,
    uint8_t R,uint8_t G,uint8_t B
    ){

    SimpleLEDS::WRITEBLE_MODE = true;
    SimpleLEDS::fill_advanced(arg_leds, LED_FROM, LED_TO, R, G, B);


    SimpleLEDS::fill_advanced
    (
        arg_leds,
        BLOCK_LED_FROM,BLOCK_LED_TO,
        0,0,0
    );
    SimpleLEDS::WRITEBLE_MODE = false;
}

void SimpleLEDS::fill_one_led
(
    CRGB arg_leds[COUNT_OF_LEDS],
	
    uint8_t INDEX,uint8_t DELAY_TIME,
    uint8_t R,uint8_t G,uint8_t B
    ){

    arg_leds[INDEX] = CHSV(R, G, B);
    FastLED.delay(DELAY_TIME);
}


void SimpleLEDS::fill_all_active_leds
(
    CRGB arg_all_leds[COUNT_OF_LEDS],
    uint8_t arg_active_leds[],
    uint8_t R,uint8_t G,uint8_t B

){
    uint8_t len = sizeof(arg_active_leds) / sizeof(arg_active_leds[0]);
    for(uint8_t led = 0; led < len; led++)
    {
        SimpleLEDS::fill_one_led(arg_all_leds,arg_active_leds[led],0,R,G,B);
    }
}

void SimpleLEDS::fill_chunk_advanced
(
	CRGB arg_leds[COUNT_OF_LEDS],
	uint8_t BLOCKED_LEDS[4],
	uint8_t LED_FROM, uint8_t LED_TO,
	uint8_t R,uint8_t G,uint8_t B
	){
		
		
	}
	
	
void SimpleLEDS::make_circle(CRGB arg_leds[COUNT_OF_LEDS],uint8_t R,uint8_t G,uint8_t B)
{
    uint8_t row1[] = {1,2,3,4};
    uint8_t row2[] = {5,6,8,15};
    uint8_t row3[] = {8+8,15+8,8+16,15+16};
    uint8_t row4[] = {8+16,15+16,8+24,15+24};
    uint8_t row5[] = {8+24,15+24,8+32,15+32};
    uint8_t row6[] = {8+32,15+32,8+40,15+40};
    uint8_t row7[] = {57,58,59,60};
    uint8_t row8[] = {61,62,62,62};

    SimpleLEDS::fill_all_active_leds(arg_leds,row1,R,G,B);
    SimpleLEDS::fill_all_active_leds(arg_leds,row2,R,G,B);
    SimpleLEDS::fill_all_active_leds(arg_leds,row3,R,G,B);
    SimpleLEDS::fill_all_active_leds(arg_leds,row4,R,G,B);
    SimpleLEDS::fill_all_active_leds(arg_leds,row5,R,G,B);
    SimpleLEDS::fill_all_active_leds(arg_leds,row6,R,G,B);
    SimpleLEDS::fill_all_active_leds(arg_leds,row7,R,G,B);
    SimpleLEDS::fill_all_active_leds(arg_leds,row8,R,G,B);

}


