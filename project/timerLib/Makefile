all: libTimer.a

CPU = msp430g2553
CFLAGS = -mmcu=${CPU}

#IKW Dr. F's Makefile, changing compiler to support internal make rules
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

libTimer.a: clocksTimer.o sr.o
	$(AR) crs $@ $^

install: libTimer.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

clean:
	rm -f timerLib.a *.o
