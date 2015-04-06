#include "mbed.h"
#include "BME280.h"

Serial pc(USBTX, USBRX);

#if defined(TARGET_LPC1768)
BME280 sensor(p28, p27);
#else
BME280 sensor(I2C_SDA, I2C_SCL);
#endif

int main() {
    
    while(1) {
        pc.printf("%2.2f degC, %04.2f hPa, %2.2f %%\n", sensor.getTemperature(), sensor.getPressure(), sensor.getHumidity());
        wait(1);
    }
}
