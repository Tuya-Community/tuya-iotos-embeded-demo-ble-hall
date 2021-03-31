#ifndef HALL_SENSOR_H_
#define HALL_SENSOR_H_

#include "tuya_ble_common.h"
#include "tuya_ble_log.h"

#define SENSOR_PIN		GPIO_PB4
#define ON			1
#define OFF 		0

void hall_sensor_fun(void);
int hall_value_get(void);

#endif
