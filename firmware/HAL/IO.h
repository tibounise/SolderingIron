#include <avr/io.h>

class IO {
public:
    IO();
    void digitalWrite(uint8_t pin);
    void digitalRead(uint8_t pin);
    void pwmWrite(uint8_t pin);
    void setInput(uint8_t pin);
    void setOutput(uint8_t pin);
};