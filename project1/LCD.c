/** \file
 * \brief Functions for applications that use the LCD
 */

#include <msp430g2553.h>
#include "LCD.h"

const uint8_t font_proportional_8px_data[] = {
    0x02, 0x01, 0x03, 0x05, 0x05, 0x07, 0x05, 0x01, 0x03, 0x03, 0x05, 0x05, 0x02, 0x03, 0x01, 0x04,
    0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x01, 0x01, 0x04, 0x05, 0x04, 0x04,
    0x07, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x03, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05,
    0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x03, 0x04, 0x03, 0x05, 0x05,
    0x02, 0x05, 0x05, 0x04, 0x05, 0x05, 0x04, 0x05, 0x04, 0x01, 0x02, 0x04, 0x02, 0x05, 0x04, 0x04,
    0x05, 0x05, 0x04, 0x04, 0x04, 0x04, 0x05, 0x07, 0x05, 0x04, 0x04, 0x04, 0x02, 0x04, 0x05, 0x00,
    0x04, 0x05, 0x02, 0x00, 0x04, 0x08, 0x03, 0x03, 0x04, 0x09, 0x00, 0x03, 0x06, 0x00, 0x00, 0x00,
    0x00, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x00, 0x04, 0x06, 0x00, 0x03, 0x05, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x04, 0x04, 0x05, 0x05, 0x02, 0x04, 0x05, 0x06, 0x03, 0x05, 0x04, 0x03, 0x07, 0x05,
    0x04, 0x05, 0x03, 0x03, 0x02, 0x04, 0x05, 0x02, 0x03, 0x02, 0x04, 0x05, 0x06, 0x06, 0x06, 0x04,
    0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x03, 0x03, 0x03,
    0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x04, 0x04, 0x04, 0x05, 0x04, 0x04,
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x05, 0x03, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x03, 0x03,
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x05, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x03, 0x03,
    0x00, 0x00, 0x5F, 0x07, 0x00, 0x07, 0x74, 0x1C, 0x77, 0x1C, 0x17, 0x2E, 0x6A, 0x3E, 0x2B, 0x3A,
    0x06, 0x49, 0x36, 0x08, 0x36, 0x49, 0x30, 0x36, 0x49, 0x59, 0x76, 0x48, 0x07, 0x3C, 0x42, 0x81,
    0x81, 0x42, 0x3C, 0x0A, 0x04, 0x1F, 0x04, 0x0A, 0x08, 0x08, 0x3E, 0x08, 0x08, 0x80, 0x60, 0x08,
    0x08, 0x08, 0x40, 0xC0, 0x30, 0x0C, 0x03, 0x3E, 0x41, 0x41, 0x41, 0x3E, 0x44, 0x42, 0x7F, 0x40,
    0x40, 0x46, 0x61, 0x51, 0x49, 0x46, 0x22, 0x41, 0x49, 0x49, 0x36, 0x18, 0x14, 0x12, 0x7F, 0x10,
    0x27, 0x45, 0x45, 0x45, 0x39, 0x3E, 0x49, 0x49, 0x49, 0x30, 0x01, 0x01, 0x71, 0x0D, 0x03, 0x36,
    0x49, 0x49, 0x49, 0x36, 0x06, 0x49, 0x49, 0x29, 0x1E, 0x36, 0xD0, 0x08, 0x14, 0x22, 0x41, 0x14,
    0x14, 0x14, 0x14, 0x14, 0x41, 0x22, 0x14, 0x08, 0x02, 0x51, 0x09, 0x06, 0x3C, 0x42, 0x99, 0xA5,
    0xBD, 0x42, 0x1C, 0x7C, 0x12, 0x11, 0x12, 0x7C, 0x7F, 0x49, 0x49, 0x49, 0x36, 0x3E, 0x41, 0x41,
    0x41, 0x22, 0x7F, 0x41, 0x41, 0x41, 0x3E, 0x7F, 0x49, 0x49, 0x49, 0x41, 0x7F, 0x09, 0x09, 0x09,
    0x01, 0x3E, 0x41, 0x49, 0x49, 0x7A, 0x7F, 0x08, 0x08, 0x08, 0x7F, 0x41, 0x7F, 0x41, 0x40, 0x41,
    0x41, 0x3F, 0x7F, 0x08, 0x14, 0x22, 0x41, 0x7F, 0x40, 0x40, 0x40, 0x40, 0x7F, 0x06, 0x0C, 0x06,
    0x7F, 0x7F, 0x06, 0x08, 0x30, 0x7F, 0x3E, 0x41, 0x41, 0x41, 0x3E, 0x7F, 0x09, 0x09, 0x09, 0x06,
    0x3E, 0x41, 0x61, 0xC1, 0xBE, 0x7F, 0x09, 0x19, 0x29, 0x46, 0x26, 0x49, 0x49, 0x49, 0x32, 0x01,
    0x01, 0x7F, 0x01, 0x01, 0x3F, 0x40, 0x40, 0x40, 0x3F, 0x07, 0x38, 0x40, 0x38, 0x07, 0x1F, 0x60,
    0x1F, 0x60, 0x1F, 0x63, 0x14, 0x08, 0x14, 0x63, 0x01, 0x06, 0x78, 0x06, 0x01, 0x61, 0x51, 0x49,
    0x45, 0x43, 0x7F, 0x41, 0x41, 0x03, 0x0C, 0x30, 0xC0, 0x41, 0x41, 0x7F, 0x04, 0x02, 0x01, 0x02,
    0x04, 0x80, 0x80, 0x80, 0x80, 0x80, 0x01, 0x02, 0x20, 0x54, 0x54, 0x54, 0x78, 0x7F, 0x44, 0x44,
    0x44, 0x38, 0x38, 0x44, 0x44, 0x44, 0x38, 0x44, 0x44, 0x44, 0x7F, 0x38, 0x54, 0x54, 0x54, 0x58,
    0x08, 0x7E, 0x09, 0x01, 0x18, 0xA4, 0xA4, 0xA4, 0x78, 0x7F, 0x04, 0x04, 0x78, 0x7D, 0x80, 0x7D,
    0x7F, 0x10, 0x28, 0x44, 0x3F, 0x40, 0x7C, 0x04, 0x78, 0x04, 0x78, 0x7C, 0x04, 0x04, 0x78, 0x38,
    0x44, 0x44, 0x38, 0xFC, 0x24, 0x24, 0x24, 0x18, 0x18, 0x24, 0x24, 0x24, 0xFC, 0x7C, 0x08, 0x04,
    0x04, 0x48, 0x54, 0x54, 0x24, 0x04, 0x3F, 0x44, 0x40, 0x3C, 0x40, 0x40, 0x7C, 0x1C, 0x20, 0x40,
    0x20, 0x1C, 0x1C, 0x60, 0x60, 0x1C, 0x60, 0x60, 0x1C, 0x44, 0x28, 0x10, 0x28, 0x44, 0x9C, 0xA0,
    0x60, 0x1C, 0x64, 0x54, 0x54, 0x4C, 0x18, 0x7E, 0x81, 0x81, 0xFF, 0xFF, 0x81, 0x81, 0x7E, 0x18,
    0x18, 0x04, 0x08, 0x10, 0x0C, 0x14, 0x3E, 0x55, 0x55, 0xFF, 0x81, 0x81, 0x81, 0xFF, 0x80, 0x60,
    0x80, 0x60, 0x80, 0x60, 0x60, 0x60, 0x00, 0x60, 0x60, 0x00, 0x60, 0x60, 0x04, 0x7F, 0x04, 0x14,
    0x7F, 0x14, 0x02, 0x01, 0x01, 0x02, 0x46, 0x29, 0x16, 0x08, 0x34, 0x4A, 0x31, 0x48, 0x30, 0x00,
    0x18, 0x24, 0x3E, 0x41, 0x22, 0x7F, 0x49, 0x41, 0x03, 0x04, 0x04, 0x03, 0x03, 0x04, 0x03, 0x04,
    0x04, 0x03, 0x04, 0x03, 0x18, 0x3C, 0x3C, 0x18, 0x08, 0x08, 0x08, 0x08, 0x03, 0x01, 0x02, 0x03,
    0x02, 0x0E, 0x02, 0x0E, 0x06, 0x0E, 0x00, 0x48, 0x30, 0x38, 0x44, 0x38, 0x54, 0x48, 0x38, 0x44,
    0xFE, 0x44, 0x48, 0x7E, 0x49, 0x01, 0x44, 0x38, 0x28, 0x38, 0x44, 0x03, 0x14, 0x7C, 0x14, 0x03,
    0xE7, 0xE7, 0x4E, 0x55, 0x55, 0x39, 0x01, 0x01, 0x00, 0x01, 0x01, 0x1C, 0x2A, 0x55, 0x55, 0x22,
    0x1C, 0x1D, 0x15, 0x1E, 0x18, 0x24, 0x00, 0x18, 0x24, 0x08, 0x08, 0x08, 0x18, 0x08, 0x08, 0x08,
    0x3C, 0x42, 0xBD, 0x95, 0xA9, 0x42, 0x3C, 0x01, 0x01, 0x01, 0x01, 0x01, 0x06, 0x09, 0x09, 0x06,
    0x44, 0x44, 0x5F, 0x44, 0x44, 0x19, 0x15, 0x12, 0x15, 0x15, 0x0A, 0x02, 0x01, 0xFC, 0x20, 0x20,
    0x1C, 0x0E, 0x7F, 0x01, 0x7F, 0x01, 0x18, 0x18, 0x00, 0x80, 0x40, 0x02, 0x1F, 0x06, 0x09, 0x09,
    0x06, 0x24, 0x18, 0x00, 0x24, 0x18, 0x82, 0x4F, 0x30, 0x4C, 0x62, 0xF1, 0x82, 0x4F, 0x30, 0x0C,
    0xD2, 0xB1, 0x95, 0x5F, 0x30, 0x4C, 0x62, 0xF1, 0x30, 0x48, 0x45, 0x20, 0x60, 0x39, 0x2E, 0x38,
    0x60, 0x60, 0x38, 0x2E, 0x39, 0x60, 0x70, 0x1D, 0x13, 0x1D, 0x70, 0x72, 0x1D, 0x12, 0x1E, 0x71,
    0x70, 0x1D, 0x12, 0x1D, 0x70, 0x60, 0x3B, 0x25, 0x3B, 0x60, 0x7E, 0x11, 0x7F, 0x49, 0x41, 0x1E,
    0x21, 0x61, 0x92, 0x7C, 0x55, 0x56, 0x44, 0x7C, 0x56, 0x55, 0x44, 0x7C, 0x56, 0x55, 0x46, 0x7D,
    0x54, 0x54, 0x45, 0x45, 0x7E, 0x44, 0x44, 0x7E, 0x45, 0x46, 0x7D, 0x46, 0x45, 0x7C, 0x45, 0x08,
    0x7F, 0x49, 0x41, 0x3E, 0x7E, 0x09, 0x12, 0x22, 0x7D, 0x38, 0x45, 0x46, 0x44, 0x38, 0x38, 0x44,
    0x46, 0x45, 0x38, 0x38, 0x46, 0x45, 0x46, 0x38, 0x3A, 0x45, 0x45, 0x46, 0x39, 0x38, 0x45, 0x44,
    0x45, 0x38, 0x22, 0x14, 0x08, 0x14, 0x22, 0xBC, 0x62, 0x5A, 0x46, 0x3D, 0x3C, 0x41, 0x42, 0x3C,
    0x3C, 0x42, 0x41, 0x3C, 0x3C, 0x42, 0x41, 0x3E, 0x3D, 0x40, 0x40, 0x3D, 0x06, 0x08, 0xF2, 0x09,
    0x06, 0x7F, 0x22, 0x22, 0x1C, 0xFE, 0x09, 0x89, 0x76, 0x20, 0x55, 0x56, 0x78, 0x20, 0x56, 0x55,
    0x78, 0x22, 0x55, 0x55, 0x7A, 0x23, 0x55, 0x56, 0x7B, 0x20, 0x55, 0x54, 0x79, 0x27, 0x55, 0x57,
    0x78, 0x20, 0x54, 0x38, 0x54, 0x48, 0x38, 0x44, 0xC4, 0x38, 0x55, 0x56, 0x58, 0x38, 0x56, 0x55,
    0x58, 0x3A, 0x55, 0x55, 0x5A, 0x39, 0x54, 0x54, 0x59, 0x01, 0x7A, 0x7A, 0x01, 0x02, 0x79, 0x02,
    0x02, 0x78, 0x02, 0x60, 0x91, 0x92, 0x7C, 0x7B, 0x09, 0x0A, 0x73, 0x38, 0x45, 0x46, 0x38, 0x38,
    0x46, 0x45, 0x38, 0x3A, 0x45, 0x45, 0x3A, 0x3B, 0x45, 0x46, 0x3B, 0x39, 0x44, 0x44, 0x39, 0x08,
    0x08, 0x2A, 0x08, 0x08, 0xB8, 0x64, 0x4C, 0x3A, 0x3C, 0x41, 0x42, 0x7C, 0x3C, 0x42, 0x41, 0x7C,
    0x3A, 0x41, 0x41, 0x7A, 0x3D, 0x40, 0x40, 0x7D, 0x98, 0x62, 0x19, 0xFF, 0x42, 0x3C, 0x9A, 0x60,
    0x1A
};
/**< Character table / font data*/

const struct font_info font_proportional_8px = {0x58+(0x04<<8),0x08,0x08,0x20,0xFF,(uint8_t*)font_proportional_8px_data,(uint8_t*)font_proportional_8px_data+0xFF-0x20+1};
/**< Create font definition*/

void LCD_write_cmd(int8_t cmd)
{
    uint8_t i;

    P1DIR = DATA | CLK; // Pins DATA and CLK are outputs
    LCD_CS_CLEAR; // activate contol of LCD
    LCD_CD_CLEAR; // byte to send is a command

    for(i=0; i<8; i++)
    {
        LCD_CLK_CLEAR;
        if (cmd & 0x80)
        {
            LCD_DATA_SET;
        }
        else
        {
            LCD_DATA_CLEAR;
        }
        LCD_CLK_SET;
        cmd = cmd << 1;
    }

    LCD_CLK_CLEAR;
    LCD_DATA_CLEAR;
    LCD_CS_SET; // deactivate control of LCD
}

void LCD_write_data(int8_t data)
{
    int8_t i;

    P1DIR = DATA | CLK; // Pins DATA and CLK are outputs
    LCD_CS_CLEAR; // activate contol of LCD
    LCD_CD_SET; // byte to send is a data byte

    for(i=0; i<8; i++)
    {
        LCD_CLK_CLEAR;
        if (data & 0x80)
        {
            LCD_DATA_SET;
        }
        else
        {
            LCD_DATA_CLEAR;
        }
        LCD_CLK_SET;
        data = data << 1;
    }

    LCD_CLK_CLEAR;
    LCD_DATA_CLEAR;
    LCD_CS_SET; // deactivate control of LCD
}

void LCD_set_page(int8_t page)
{
    LCD_CS_CLEAR;
    LCD_write_cmd((page & 0x0F) + 0xB0);
    LCD_CS_SET;
}

void LCD_set_col(uint8_t col)
{
    LCD_CS_CLEAR;
    LCD_write_cmd(((col>>4) & 0x0F) + 0x10);
    LCD_write_cmd((col & 0x0F));
    LCD_CS_SET;
}


void LCD_clear(void)
{
    uint8_t i1;
    uint8_t i2;
    for(i1=0;i1<8;i1++)
    {
        LCD_set_col(0);
        LCD_set_page(i1);
        for(i2=0;i2<132;i2++)
        {
            LCD_write_data(0);
        }
    }
}

void LCD_init(void)
{
    // Configure IOs
    P1DIR = DATA | CLK;
    P2DIR = CD | RST | CS;

    LCD_CS_CLEAR;
    // wait for a release reset
    LCD_RST_SET;
    __delay_cycles(0xFF);

    LCD_RST_CLEAR;
    __delay_cycles(STAY_LOW_RST);
    __delay_cycles(0xFF);

    LCD_RST_SET;
    __delay_cycles(WAIT_WR);

    LCD_CS_SET;
    __delay_cycles(0xFF);

    LCD_CS_CLEAR;
    LCD_write_cmd(SET_SCROLL_LINE); // Start line 0
    LCD_CS_SET;

    LCD_CS_CLEAR;
    LCD_write_cmd(SET_SEG_DIRECTION); // SEG inverse
    LCD_CS_SET;

    LCD_CS_CLEAR;
    LCD_write_cmd(SET_COM_DIRECTION | MY); // Normal COM
    LCD_CS_SET;

    LCD_CS_CLEAR;
    LCD_write_cmd(SET_ALL_PIXEL_ON); // All pixels on
    LCD_CS_SET;

    LCD_CS_CLEAR;
    LCD_write_cmd(SET_INVERSE_DISPLAY); // Inverse display off
    LCD_CS_SET;

    LCD_CS_CLEAR;
    LCD_write_cmd(SET_LCD_BIAS_RATIO); // Set bias 1/9
    LCD_CS_SET;

    LCD_CS_CLEAR;
    LCD_write_cmd(SET_POWER_CONTROL | PC2 | PC1 | PC0); // Booster, Regulator, Follower on
    LCD_CS_SET;

    LCD_CS_SET;
    __delay_cycles(0xFF);

    LCD_CS_CLEAR;
    LCD_write_cmd(SET_VLCD_RESISTOR_RATIO | 0x07); // Set resistor ratio
    LCD_CS_SET;

    LCD_CS_CLEAR;
    LCD_write_cmd(SET_ELECTRONIC_VOLUME_MSB); // Set contrast
    LCD_write_cmd(SET_ELECTRONIC_VOLUME_LSB | 0x10);
    LCD_CS_SET;

    LCD_CS_CLEAR;
    LCD_write_cmd(SET_ADV_PROGRAM_CONTROL_MSB); // Set Temperature compensation
    LCD_write_cmd(SET_ADV_PROGRAM_CONTROL_LSB | TC);
    LCD_CS_SET;

    LCD_CS_CLEAR;
    LCD_write_cmd(SET_DISPLAY_ENABLE | C2); // Display on
    LCD_CS_SET;

    LCD_clear();
}

void LCD_put_char(struct font_info* font, char c)
{
    int offset;
    uint8_t i;

    if (((uint8_t)c >= font->firstchar) & ((uint8_t)c <= font->lastchar))
    {
        i=0;
        c -= font->firstchar;
        offset=0;
        while(i<(uint8_t)c)
        {
            offset += font->widthtable[i];
            i++;
        }
        for(i=0;i<font->widthtable[(uint8_t)c];i++)
        {
            LCD_write_data(font->data[ offset + i]);
        }
        LCD_write_data(0);
    }
}

void LCD_print(char* str)
{
    int i=0;
    while(str[i])
    {
        LCD_put_char((struct font_info*) &font_proportional_8px, str[i]);
        i++;
    }
}