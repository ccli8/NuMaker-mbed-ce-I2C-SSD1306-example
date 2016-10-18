#define LCD_Xmax 128
#define LCD_Ymax 64
#define FG_COLOR 0xFFFF
#define BG_COLOR 0x0000

#define SSD1306_slave_addr           0x78

class SSD1306 {
    public:
    void initialize(void);
    void clearscreen(void);
    void printC_5x7(int x, int y, unsigned char ascii_code);
    void printC(int x, int y, unsigned char ascii_code);
    void printLine(int line, char text[]);
    void printS(int x, int y, char text[]);
    void printS_5x7(int x, int y, char text[]);
    void drawPixel(int x, int y, int fgColor, int bgColor);
    void drawBmp8x8(int x, int y, int fgColor, int bgColor, unsigned char bitmap[]);
    void drawBmp32x8(int x, int y, int fgColor, int bgColor, unsigned char bitmap[]);
    void drawBmp120x8(int x, int y, int fgColor, int bgColor, unsigned char bitmap[]);
    void drawBmp8x16(int x, int y, int fgColor, int bgColor, unsigned char bitmap[]);
    void drawBmp16x8(int x, int y, int fgColor, int bgColor, unsigned char bitmap[]);
    void drawBmp16x16(int x, int y, int fgColor, int bgColor, unsigned char bitmap[]);
    void drawBmp16x24(int x, int y, int fgColor, int bgColor, unsigned char bitmap[]);
    void drawBmp16x32(int x, int y, int fgColor, int bgColor, unsigned char bitmap[]);
    void drawBmp16x40(int x, int y, int fgColor, int bgColor, unsigned char bitmap[]);
    void drawBmp16x48(int x, int y, int fgColor, int bgColor, unsigned char bitmap[]);
    void drawBmp16x64(int x, int y, int fgColor, int bgColor, unsigned char bitmap[]);
    void drawBmp32x16(int x, int y, int fgColor, int bgColor, unsigned char bitmap[]);
    void drawBmp32x32(int x, int y, int fgColor, int bgColor, unsigned char bitmap[]);
    void drawBmp32x48(int x, int y, int fgColor, int bgColor, unsigned char bitmap[]);
    void drawBmp32x64(int x, int y, int fgColor, int bgColor, unsigned char bitmap[]);
    void drawBmp64x64(int x, int y, int fgColor, int bgColor, unsigned char bitmap[]);
    void drawBMP(unsigned char *buffer);
};