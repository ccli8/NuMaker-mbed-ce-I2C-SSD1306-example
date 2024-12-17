#include "mbed.h"
#include "ssd1306.h"
#include "draw2D.h"

/* Select one demo exclusively */
#define DEMO_DRAWBMP        1
#define DEMO_MOVINGCIRCLE   0
#define DEMO_PRINTLINE      0

using namespace mbed_nuvoton;

#if TARGET_NUMAKER_PFM_NUC472
SSD1306 LCD(PD_12, PD_10, SSD1306_slave_addr, 400000);
#endif

Draw2D  D2D(LCD);

#if DEMO_DRAWBMP
void demo_drawBMP(void);
#elif DEMO_MOVINGCIRCLE
void demo_movingcircle(void);
#elif DEMO_PRINTLINE
void demo_printline(void);
#endif

int main() {

    LCD.initialize();
    LCD.clearscreen();

#if DEMO_DRAWBMP
    demo_drawBMP();
#elif DEMO_MOVINGCIRCLE
    demo_movingcircle();
#elif DEMO_PRINTLINE
    demo_printline();
#endif

    return 0;
}


#if DEMO_DRAWBMP

unsigned char BMP_128x64_Nuvoton_NuMaker[128*8] = { // Nuvoton NuMaker Logo 
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0xE0,0xF0,0x70,0x30,0x30,0x30,0x70,0xF0,0xE0,0xE0,0xC0,0x80,0x00,0x00,0xF0,0xF0,0xF0,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xF0,0xF0,0xF0,0x00,0x00,0x30,0x70,0xF0,0xE0,0x80,0x00,0x00,0x00,0x00,0x80,0xE0,0xF0,0xF0,0x30,0x00,0x80,0xC0,0xE0,0xE0,0xF0,0x70,0x70,0x30,0x30,0x70,0x70,0xF0,0xE0,0xE0,0xC0,0x00,0x18,0x08,0x08,0x0C,0x0C,0xFC,0xFC,0xFC,0xFC,0x1C,0x0C,0x0C,0x08,0x08,0x08,0x80,0xC0,0xE0,0xE0,0xF0,0x70,0x70,0x30,0x30,0x70,0x70,0xE0,0xE0,0xE0,0xC0,0x00,0x00,0x00,0x80,0xC0,0xE0,0xE0,0xF0,0x70,0x30,0x30,0x30,0x70,0xF0,0xE0,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x7F,0x7F,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x7F,0x7F,0x3F,0x00,0x00,0x0F,0x1F,0x3F,0x3F,0x78,0x70,0x70,0x60,0x70,0x70,0x78,0x3F,0x3F,0x1F,0x0F,0x00,0x00,0x00,0x00,0x01,0x07,0x0F,0x3F,0x7C,0x7C,0x3F,0x1F,0x07,0x01,0x00,0x00,0x00,0x0F,0x1F,0x3F,0x3F,0x38,0x70,0x70,0x70,0x70,0x70,0x70,0x3C,0x3F,0x1F,0x1F,0x07,0x00,0x00,0x00,0x00,0x00,0x3F,0x7F,0x7F,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x1F,0x3F,0x3F,0x38,0x70,0x70,0x70,0x70,0x70,0x70,0x3D,0x3F,0x1F,0x1F,0x07,0x00,0x00,0x3F,0x7F,0x7F,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x7F,0x7F,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x0F,0x3F,0xFC,0xF0,0xC0,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0xF0,0xF0,0xF0,0x00,0x00,0x00,0x00,0x00,0xF0,0xF0,0xF0,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x0F,0x7F,0xFE,0xF8,0xC0,0x00,0x00,0x00,0x00,0xC0,0xF0,0xFE,0x7F,0x0F,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0xE0,0xE0,0x70,0x70,0x70,0x70,0x70,0xF0,0xE0,0xC0,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x80,0xC0,0xE0,0x70,0x30,0x10,0x00,0x00,0xC0,0xE0,0xE0,0x70,0x70,0x70,0x70,0xF0,0xE0,0xC0,0x80,0x00,0x00,0x00,0xF0,0xF0,0xF0,0xE0,0x70,0x70,0x70,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x03,0x0F,0x3F,0xFC,0xE0,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x7F,0xFF,0xFF,0xE0,0xC0,0xC0,0xC0,0xE0,0xFF,0xFF,0xFF,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x03,0x0F,0x7F,0xFF,0xF8,0xF8,0xFE,0x3F,0x0F,0x01,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x78,0xFC,0xFC,0xCE,0xCE,0xC6,0xC6,0xE6,0xFF,0xFF,0xFF,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x06,0x0F,0x1F,0x7D,0xF8,0xE0,0xC0,0x80,0x00,0x3F,0x7F,0xFF,0xEC,0xCC,0xCC,0xCC,0xCC,0xCC,0xEF,0xEF,0x0F,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

unsigned char BMP_64x64_Academic[64*8] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x80,0x00,0x80,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x20,0xE0,0x20,0x20,0x00,0x00,0x00,0x80,0x80,0x80,0x00,0x00,0x00,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x01,0x00,0x00,0x1F,0x00,0x00,0x0F,0x10,0x10,0x10,0x1F,0x00,0x01,0x0E,0x10,0x0C,0x03,0x00,0x00,0x0F,0x10,0x10,0x10,0x0F,0x00,0x00,0x00,0x1F,0x00,0x00,0x00,0x00,0x0F,0x10,0x10,0x10,0x0F,0x00,0x00,0x1F,0x01,0x00,0x00,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0xC0,0xC0,0xC0,0xC0,0xC0,0xE0,0xE0,0xE0,0xE0,0xE0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF8,0xF8,0xF8,0xF8,0x7C,0x7C,0x7C,0xF8,0xF8,0xF8,0xF8,0xF8,0xF0,0xF0,0xF0,0xF0,0xF0,0xE0,0xE0,0xE0,0xE0,0xC0,0xC0,0xC0,0xC0,0xC0,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x03,0x03,0x03,0x07,0x07,0x07,0x0F,0x0F,0x8F,0x9F,0x9F,0x1F,0x3F,0x3F,0x3F,0x7F,0x7F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFC,0xF8,0xF8,0xF8,0xFC,0xFC,0xFC,0xFC,0xFC,0x7C,0x7C,0x7D,0x3D,0x39,0x39,0x19,0x19,0x99,0x89,0x89,0x09,0x01,0x01,0x03,0x03,0xFB,0x03,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x7F,0x7F,0xFF,0xFF,0xFF,0xFE,0xFE,0xFC,0xFC,0xFC,0xF8,0xF8,0xF9,0xF1,0xF1,0xF3,0xF1,0xF1,0xF9,0xF8,0xF8,0xFC,0xFC,0xFC,0xFE,0xFE,0xFE,0xFF,0xFF,0xFF,0x7F,0x3F,0x3F,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x03,0x07,0x07,0x0F,0x0F,0x1F,0x1F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x1F,0x1F,0x0F,0x0F,0x07,0x07,0x03,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x7C,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE0,0xC0,0x00,0x00,0xE0,0xE0,0x00,0x80,0x80,0x00,0x00,0x80,0x80,0x00,0x00,0xE0,0xE0,0xC0,0x00,0x00,0x00,0xC0,0xE0,0xE0,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0xF0,0xF0,0x00,0x80,0x80,0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x1F,0x00,0x03,0x0C,0x1F,0x1F,0x00,0x0F,0x1F,0x10,0x10,0x1F,0x1F,0x00,0x00,0x1F,0x1F,0x01,0x07,0x1C,0x07,0x01,0x1F,0x1F,0x00,0x0C,0x1E,0x12,0x1F,0x1F,0x00,0x1F,0x1F,0x06,0x1F,0x19,0x00,0x0F,0x1F,0x12,0x12,0x13,0x13,0x00,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

void demo_drawBMP(void)
{
    while(true) {
        LCD.drawBMP(BMP_128x64_Nuvoton_NuMaker);
        LCD.clearscreen();
        LCD.drawBmp64x64(32, 0, FG_COLOR, BG_COLOR, BMP_64x64_Academic);
        ThisThread::sleep_for(500ms);
    }
}

#elif DEMO_MOVINGCIRCLE

#define X0 15       // Circle initial X 
#define Y0 10       // Circle initial Y

void demo_movingcircle(void)
{
    int dirX, dirY;
    int movX, movY;
    int r;
    int x, y;

    x = X0;   // circle center x
    y = Y0;   // circle center y
    r = 3;    // circle radius

    movX = 3; // x movement
    movY = 3; // y movement
    dirX = 1; // x direction
    dirY = 1; // y direction

    while(true) {
       D2D.drawCircle(x, y, r, FG_COLOR, BG_COLOR); // draw a circle

       ThisThread::sleep_for(1s); // Delay for Vision

       D2D.drawCircle(x, y, r, BG_COLOR, BG_COLOR); // erase a circle

       x = x + dirX * movX; // change x of circle center
       y = y + dirY * movY; // change y of circle center 

       // boundary check for changing direction       
       if      ((x-r) <=0)        {dirX= 1; x= x + dirX*movX;}
       else if ((x+r) >=LCD_Xmax) {dirX=-1; x= x + dirX*movX;}

       if      ((y-r) <=0)        {dirY= 1; y= y + dirY*movY;}
       else if ((y+r) >=LCD_Ymax) {dirY=-1; y= y + dirY*movY;}                    
   }
}

#elif DEMO_PRINTLINE

void demo_printline(void)
{
    LCD.printLine(0,"NuMaker series  ");
    LCD.printLine(1,"Mbed CE         ");
    LCD.printLine(2,"SSD1306 I2C-OLED");
    LCD.printLine(3,"printLine Demo  ");
}

#endif
