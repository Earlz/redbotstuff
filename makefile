LIBS=-L../make-wiring/output/lib
INC=-I../make-wiring/output/include
CFLAGS=-fno-use-cxa-atexit -Wall -DF_CPU=16000000UL -Os -mmcu=atmega328p
default:
	avr-g++ ${CFLAGS} ${LIBS} ${INC} -o main.elf main.cpp -lredbot -lSoftwareSerial -larduino -lWire -lEEPROM 
	avr-objcopy -O ihex -R .eeprom main.elf out.hex
upload:
	avrdude -c arduino -p ATMEGA328P -b 115200 -F -V -P /dev/ttyUSB0 -U flash:w:out.hex

all: default upload
