#include "I2C.h"

I2C::I2C() {}

void I2C::init(uint8_t address) {
    this->address = address;
    TWSR = 0;
    TWBR = ((F_CPU/SCL_CLOCK)-16)/2;
}

uint8_t I2C::start() {
    TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
    while(!(TWCR & (1<<TWINT)));

    twi_status_register = TW_STATUS & 0xF8;
    if ((this->twi_status_register != TW_START) && (this->twi_status_register != TW_REP_START)) {
        return 1;
    }

    TWDR = address;
    TWCR = (1<<TWINT) | (1<<TWEN);

    while(!(TWCR & (1<<TWINT)));

    this->twi_status_register = TW_STATUS & 0xF8;
    if ((this->twi_status_register != TW_MT_SLA_ACK) && (this->twi_status_register != TW_MR_SLA_ACK)) {
        return 1;
    }

    return 0;
}

uint8_t I2C::write(uint8_t data) {
    TWDR = data;
    TWCR = (1<<TWINT) | (1<<TWEN);

    while(!(TWCR & (1<<TWINT)));

    this->twi_status_register = TW_STATUS & 0xF8;
    if (this->twi_status_register != TW_MT_DATA_ACK) {
        return 1;
    } else {
        return 0;
    }
}

void I2C::stop(void) {
    TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
    while(TWCR & (1<<TWSTO));
}