#include "hall_sensor.h"

#define 	TIME_MS		1000
#define		BUF_LEN		(sizeof(DP_buf) / sizeof(DP_buf[0]))

unsigned long sys_time = 0;
uint8_t DP_buf[4] = {0x65, 0x01, 0x01, 0x00}; //{DP_ID, DP_type, DP_len, DP_data}

int hall_value_get(void)
{
	uint16_t hall_val;

	hall_val = adc_sample_and_get_result();
	TUYA_APP_LOG_INFO("hall_val:%d", hall_val);

	return hall_val;
}

void hall_sensor_fun(void)
{
	if(!clock_time_exceed(sys_time, 1000 * TIME_MS)){
		return;
	}

	sys_time = clock_time();
	lux_adc_init();

	if(hall_value_get() > 0x1E) {
		DP_buf[3] = ON;
		tuya_ble_dp_data_report(DP_buf, BUF_LEN);
	} else {
		DP_buf[3] = OFF;
		tuya_ble_dp_data_report(DP_buf, BUF_LEN);
	}


}
