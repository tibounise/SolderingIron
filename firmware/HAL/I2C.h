#include <stdint.h>
#include <util/twi.h>

#define SCL_CLOCK  100000L

class I2C {
public:
    I2C();
    void init(uint8_t address);
    uint8_t start();
    uint8_t write(uint8_t data);
    void stop(void);
private:
    uint8_t address;
    uint8_t twi_status_register;
};