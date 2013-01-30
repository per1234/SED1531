#include <SED1531.h>
#include "Arduino.h"

byte lcdFonts[][5] = {
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 }, 
{ 0x00 , 0x00 , 0x5F , 0x00 , 0x00 }, 
{ 0x00 , 0x07 , 0x00 , 0x07 , 0x00 }, 
{ 0x14 , 0x7F , 0x14 , 0x7F , 0x14 }, 
{ 0x24 , 0x2A , 0x7F , 0x2A , 0x12 }, 
{ 0x23 , 0x13 , 0x08 , 0x64 , 0x62 }, 
{ 0x36 , 0x49 , 0x55 , 0x22 , 0x50 }, 
{ 0x00 , 0x05 , 0x03 , 0x00 , 0x00 }, 
{ 0x00 , 0x1C , 0x22 , 0x41 , 0x00 }, 
{ 0x00 , 0x41 , 0x22 , 0x1C , 0x00 }, 
{ 0x08 , 0x2A , 0x1C , 0x2A , 0x08 }, 
{ 0x08 , 0x08 , 0x3E , 0x08 , 0x08 }, 
{ 0x00 , 0x50 , 0x30 , 0x00 , 0x00 }, 
{ 0x08 , 0x08 , 0x08 , 0x08 , 0x08 }, 
{ 0x00 , 0x60 , 0x60 , 0x00 , 0x00 }, 
{ 0x20 , 0x10 , 0x08 , 0x04 , 0x02 }, 
{ 0x3E , 0x51 , 0x49 , 0x45 , 0x3E }, 
{ 0x00 , 0x42 , 0x7F , 0x40 , 0x00 }, 
{ 0x42 , 0x61 , 0x51 , 0x49 , 0x46 }, 
{ 0x21 , 0x41 , 0x45 , 0x4B , 0x31 }, 
{ 0x18 , 0x14 , 0x12 , 0x7F , 0x10 }, 
{ 0x27 , 0x45 , 0x45 , 0x45 , 0x39 }, 
{ 0x3C , 0x4A , 0x49 , 0x49 , 0x30 }, 
{ 0x01 , 0x71 , 0x09 , 0x05 , 0x03 }, 
{ 0x36 , 0x49 , 0x49 , 0x49 , 0x36 }, 
{ 0x06 , 0x49 , 0x49 , 0x29 , 0x1E }, 
{ 0x00 , 0x36 , 0x36 , 0x00 , 0x00 }, 
{ 0x00 , 0x56 , 0x36 , 0x00 , 0x00 }, 
{ 0x00 , 0x08 , 0x14 , 0x22 , 0x41 }, 
{ 0x14 , 0x14 , 0x14 , 0x14 , 0x14 }, 
{ 0x41 , 0x22 , 0x14 , 0x08 , 0x00 }, 
{ 0x02 , 0x01 , 0x51 , 0x09 , 0x06 }, 
{ 0x32 , 0x49 , 0x79 , 0x41 , 0x3E }, 
{ 0x7E , 0x11 , 0x11 , 0x11 , 0x7E }, 
{ 0x7F , 0x49 , 0x49 , 0x49 , 0x36 }, 
{ 0x3E , 0x41 , 0x41 , 0x41 , 0x22 }, 
{ 0x7F , 0x41 , 0x41 , 0x22 , 0x1C }, 
{ 0x7F , 0x49 , 0x49 , 0x49 , 0x41 }, 
{ 0x7F , 0x09 , 0x09 , 0x01 , 0x01 }, 
{ 0x3E , 0x41 , 0x41 , 0x51 , 0x32 }, 
{ 0x7F , 0x08 , 0x08 , 0x08 , 0x7F }, 
{ 0x00 , 0x41 , 0x7F , 0x41 , 0x00 }, 
{ 0x20 , 0x40 , 0x41 , 0x3F , 0x01 }, 
{ 0x7F , 0x08 , 0x14 , 0x22 , 0x41 }, 
{ 0x7F , 0x40 , 0x40 , 0x40 , 0x40 }, 
{ 0x7F , 0x02 , 0x04 , 0x02 , 0x7F }, 
{ 0x7F , 0x04 , 0x08 , 0x10 , 0x7F }, 
{ 0x3E , 0x41 , 0x41 , 0x41 , 0x3E }, 
{ 0x7F , 0x09 , 0x09 , 0x09 , 0x06 }, 
{ 0x3E , 0x41 , 0x51 , 0x21 , 0x5E }, 
{ 0x7F , 0x09 , 0x19 , 0x29 , 0x46 }, 
{ 0x46 , 0x49 , 0x49 , 0x49 , 0x31 }, 
{ 0x01 , 0x01 , 0x7F , 0x01 , 0x01 }, 
{ 0x3F , 0x40 , 0x40 , 0x40 , 0x3F }, 
{ 0x1F , 0x20 , 0x40 , 0x20 , 0x1F }, 
{ 0x7F , 0x20 , 0x18 , 0x20 , 0x7F }, 
{ 0x63 , 0x14 , 0x08 , 0x14 , 0x63 }, 
{ 0x03 , 0x04 , 0x78 , 0x04 , 0x03 }, 
{ 0x61 , 0x51 , 0x49 , 0x45 , 0x43 }, 
{ 0x00 , 0x00 , 0x7F , 0x41 , 0x41 }, 
{ 0x02 , 0x04 , 0x08 , 0x10 , 0x20 }, 
{ 0x41 , 0x41 , 0x7F , 0x00 , 0x00 }, 
{ 0x04 , 0x02 , 0x01 , 0x02 , 0x04 }, 
{ 0x40 , 0x40 , 0x40 , 0x40 , 0x40 }, 
{ 0x00 , 0x01 , 0x02 , 0x04 , 0x00 }, 
{ 0x20 , 0x54 , 0x54 , 0x54 , 0x78 }, 
{ 0x7F , 0x48 , 0x44 , 0x44 , 0x38 }, 
{ 0x38 , 0x44 , 0x44 , 0x44 , 0x20 }, 
{ 0x38 , 0x44 , 0x44 , 0x48 , 0x7F }, 
{ 0x38 , 0x54 , 0x54 , 0x54 , 0x18 }, 
{ 0x08 , 0x7E , 0x09 , 0x01 , 0x02 }, 
{ 0x08 , 0x14 , 0x54 , 0x54 , 0x3C }, 
{ 0x7F , 0x08 , 0x04 , 0x04 , 0x78 }, 
{ 0x00 , 0x44 , 0x7D , 0x40 , 0x00 }, 
{ 0x20 , 0x40 , 0x44 , 0x3D , 0x00 }, 
{ 0x00 , 0x7F , 0x10 , 0x28 , 0x44 }, 
{ 0x00 , 0x41 , 0x7F , 0x40 , 0x00 }, 
{ 0x7C , 0x04 , 0x18 , 0x04 , 0x78 }, 
{ 0x7C , 0x08 , 0x04 , 0x04 , 0x78 }, 
{ 0x38 , 0x44 , 0x44 , 0x44 , 0x38 }, 
{ 0x7C , 0x14 , 0x14 , 0x14 , 0x08 }, 
{ 0x08 , 0x14 , 0x14 , 0x18 , 0x7C }, 
{ 0x7C , 0x08 , 0x04 , 0x04 , 0x08 }, 
{ 0x48 , 0x54 , 0x54 , 0x54 , 0x20 }, 
{ 0x04 , 0x3F , 0x44 , 0x40 , 0x20 }, 
{ 0x3C , 0x40 , 0x40 , 0x20 , 0x7C }, 
{ 0x1C , 0x20 , 0x40 , 0x20 , 0x1C }, 
{ 0x3C , 0x40 , 0x30 , 0x40 , 0x3C }, 
{ 0x44 , 0x28 , 0x10 , 0x28 , 0x44 }, 
{ 0x0C , 0x50 , 0x50 , 0x50 , 0x3C }, 
{ 0x44 , 0x64 , 0x54 , 0x4C , 0x44 }, 
{ 0x00 , 0x08 , 0x36 , 0x41 , 0x00 }, 
{ 0x00 , 0x00 , 0x7F , 0x00 , 0x00 }, 
{ 0x00 , 0x41 , 0x36 , 0x08 , 0x00 }, 
{ 0x08 , 0x08 , 0x2A , 0x1C , 0x08 }, 
{ 0x08 , 0x1C , 0x2A , 0x08 , 0x08 }
};

int lcdA0 = 12;
int lcdRW = 11;
int lcdEnable = 10;
int lcdDataPins[] = {9,8,7,6,5,4,3,2};
int currentLine = 0;
int charNum = 0;

void SED1531::begin(){
	pinMode(lcdA0, OUTPUT);
	pinMode(lcdRW, OUTPUT);
	pinMode(lcdEnable, OUTPUT);
	
	for(int i=0;i<=7;i++){
		pinMode(lcdDataPins[i], OUTPUT);
	}
	delay(2000);
	writecommand(0xe2);
	/*used to be a delay here not needed.*/
	writecommand(0xa1);
	writecommand(0xa2);
	writecommand(0x2c);
	writecommand(0x2e);
	writecommand(0x2f);
	writecommand(0xa6);
	writecommand(0x8f);
	writecommand(0xa4);
	writecommand(0xaf);
	writecommand(0x40);
	}

void SED1531::setContrast(byte contrast){
	writecommand(0x80+contrast);
	}

void SED1531::inverse(byte reverse){
	writecommand(0xA6+reverse);
	}

void SED1531::setMarker(byte marker, boolean on){
	byte highNibble, lowNibble;
	byte markerLCD;
	switch(marker){
		case 1:
			markerLCD = 20;
			break;
		case 2:
			markerLCD = 31;
			break;
		case 3:
			markerLCD = 32;
			break;
		case 4:
			markerLCD = 57;
			break;
		case 5:
			markerLCD = 69;
			break;
		case 6:
			markerLCD = 78;
			break;
		}
	lowNibble = markerLCD&0xf;
	highNibble = markerLCD;
	highNibble = highNibble >> 4;
	bitSet(highNibble, 4);
	writecommand(0xb6);
	writecommand(highNibble);
	writecommand(lowNibble);
	writePixData(on);
	}

void SED1531::setCursor(byte row){
	byte page = 0xb0+(row);
	writecommand(page);
	writecommand(0x08);
	writecommand(0x00);
	writecommand(page);
	writecommand(0x08);
	writecommand(0x00);
	}

void SED1531::writecommand(byte cmd){
	digitalWrite(lcdRW, LOW);
	digitalWrite(lcdA0, LOW);
	
	byte data = cmd;
	
	for (int i = 7; i >= 0; i--) {
		int value = data & 0x1;
		digitalWrite(lcdDataPins[i], value);
		data = data >> 1;
	}

	digitalWrite(lcdEnable, HIGH);
	delayMicroseconds(10);
	digitalWrite(lcdEnable, LOW);
	delayMicroseconds(10);
	digitalWrite(lcdEnable, HIGH);
	}

inline size_t SED1531::write(byte lcdData){
	digitalWrite(lcdRW, LOW);
	digitalWrite(lcdA0, HIGH);
	
	if(lcdData == '\n'|| charNum==19){
		charNum = 0;
		currentLine++;
		if(currentLine==6){
			currentLine = 0;
			setCursor(currentLine);
			}
		else{
			setCursor(currentLine);
			}
		}
	else if(isprint(lcdData)){
		charNum++;
		//Serial.print("currentLine number: ");
		//Serial.println(currentLine);
		byte character = lcdData - 32;
		for(int col = 0;col<5;col++){
			byte data = lcdFonts[character][col];
			for(int bit = 7;bit>=0;bit--){
				byte value = data & 0x01;
				digitalWrite(lcdDataPins[bit], value);
				data = data >> 1;
				//Serial.print(data);
				}
				//Serial.println(" ");
			digitalWrite(lcdEnable, HIGH);
			delayMicroseconds(10);
			digitalWrite(lcdEnable, LOW);
			delayMicroseconds(10);
			digitalWrite(lcdEnable, HIGH);
			}
		}
	}

void SED1531::writePixData(byte lcdData){
	digitalWrite(lcdRW, LOW);
	digitalWrite(lcdA0, HIGH);
	
	byte data = lcdData;
	
	for (int i = 7; i >= 0 ; i--) {
		int value = data & 0x01;
		digitalWrite(lcdDataPins[i], value);
		data = data >> 1;
	}
	
	digitalWrite(lcdEnable, HIGH);
	delayMicroseconds(10);
	digitalWrite(lcdEnable, LOW);
	delayMicroseconds(10);
	digitalWrite(lcdEnable, HIGH);
	}



