

#include "Utils\Calibrating.h"
#include "Regulator\RegulatorTask.h"

TElectrValue GetCalibratedPwmValue(TElectrValue setPointValue) {
    return setPointValue;//RegulatorObj.CalibratedVoltage[0].Pwm;

}