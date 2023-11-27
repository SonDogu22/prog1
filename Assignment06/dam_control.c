#include "base.h"
const double WASSERSTAND_EINZ = 20;
const double WASSERSTAND_ZWEI = 40;
const double WASSERSTAND_DREI = 67.5;

enum dam_mode_e {
    DM_IDLE,
    DM_PUMP_ONE,
    DM_PUMP_TWO,
    DM_PUMP_EMERGENCY,
};

typedef enum dam_mode_e DamMode;

DamMode dam_control(double water_level) {
    // TODO
	if(water_level < WASSERSTAND_EINZ){	
		return DM_IDLE;
	}else if(water_level >= WASSERSTAND_EINZ && water_level < WASSERSTAND_ZWEI){
		return DM_PUMP_ONE;
	}else if(water_level >= WASSERSTAND_ZWEI && water_level < WASSERSTAND_DREI){
		return DM_PUMP_TWO;
	}else if(water_level > WASSERSTAND_DREI){
		return DM_PUMP_EMERGENCY;
	}
	return 0;
}

void dam_control_test(void) {
    // TODO
    test_equal_i(dam_control(0.), DM_IDLE);
    test_equal_i(dam_control(20.), DM_PUMP_ONE);
    test_equal_i(dam_control(40.), DM_PUMP_TWO);
    test_equal_i(dam_control(123557.), DM_PUMP_EMERGENCY);
    test_equal_i(dam_control(13.2), DM_IDLE);
	test_equal_i(dam_control(80.2), DM_PUMP_EMERGENCY);
	test_equal_i(dam_control(25.4), DM_PUMP_ONE);
	test_equal_i(dam_control(43.), DM_PUMP_TWO);
	test_equal_i(dam_control(2.3), DM_IDLE);
	test_equal_i(dam_control(124124.), DM_PUMP_EMERGENCY);
}

int main(void) {
    dam_control_test();
    return 0;
}
