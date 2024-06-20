#include <arduino-mock/Arduino.h>
#include <arduino-mock/Serial.h>
#include "SimpleFIFO.h"

#define PROGNAME               " SIGNALESP "
#define VERSION_1              0x33
#define VERSION_2              0x1d
#define BAUDRATE               115200
#define FIFO_LENGTH            200
#define isHigh(pin) (digitalRead(pin) == HIGH)
#define isLow(pin) (digitalRead(pin) == LOW)
#define EE_MAGIC_OFFSET        0
#define addr_features          0xff
#define MAX_SRV_CLIENTS        2



#if defined(GTEST_OS_WINDOWS)
    #define ARDUINO 101
    #define NOSTRING
#endif

using ::testing::_;
using ::testing::Return;
using ::testing::Matcher;
using ::testing::AtLeast;
using ::testing::Invoke;



//SimpleFIFO<int,90> FiFo; //store FIFO_LENGTH # ints
SimpleFIFO<int, FIFO_LENGTH> FiFo; //store FIFO_LENGTH # ints

SignalDetectorClass musterDec;

#include <send.h>
#include <commands.h>

// static size_t println(int, int = DEC);
