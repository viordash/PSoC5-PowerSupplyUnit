
#include <device.h>
#include "MainWork.h"
#include "Storage.h"
#include "Utils\Crc.h"

void LoadFromStorage() {    
    INT i;
    PBYTE pBuffer = (PBYTE) &(MainWorkObj.Storage);
    WORD adress;
    for (adress = 0; adress < (INT)sizeof(TEepromStrorage); adress++){
        *(pBuffer++) = EEPROMStorage_ReadByte(adress);       
    }   
    DWORD crc = MainWorkObj.Storage.Crc;
    MainWorkObj.Storage.Crc = 0x11223344;
    MainWorkObj.Storage.Ok = 0;
    i = sizeof(MainWorkObj.Storage.Dummy);
    memset(&MainWorkObj.Storage.Dummy, 0, i); 
    if (crc != CalcCrc32((PBYTE) &(MainWorkObj.Storage), (INT)sizeof(TEepromStrorage))) {
        return;
    }
//    for (i = 0; i < (INT)(sizeof(MainWorkObj.Storage.CalibratedVoltage) / sizeof(TCalibrateItem)); i++){
//        PTCalibrateItem pCalibrateItem = &(MainWorkObj.Storage.CalibratedVoltage[i]);
//        if (pCalibrateItem->Crc != CalcCalibrateItemCrc8(pCalibrateItem)) {
//            return;    
//        }
//    }
//    for (i = 0; i < (INT)(sizeof(MainWorkObj.Storage.CalibratedAmperage) / sizeof(TCalibrateItem)); i++){
//        PTCalibrateItem pCalibrateItem = &(MainWorkObj.Storage.CalibratedAmperage[i]);
//        if (pCalibrateItem->Crc != CalcCalibrateItemCrc8(pCalibrateItem)) {
//            return;    
//        }
//    }       
    MainWorkObj.SetPointVoltageA = MainWorkObj.Storage.Settings.VoltageA;
    MainWorkObj.SetPointAmperageA = MainWorkObj.Storage.Settings.AmperageA;
    MainWorkObj.StabilizeModeA = MainWorkObj.Storage.Settings.StabilizeModeA;
    MainWorkObj.SetPointVoltageB = MainWorkObj.Storage.Settings.VoltageB;
    MainWorkObj.SetPointAmperageB = MainWorkObj.Storage.Settings.AmperageB;
    MainWorkObj.StabilizeModeB = MainWorkObj.Storage.Settings.StabilizeModeB;
    MainWorkObj.Storage.Ok = STORAGE_OK_MAGIC;
}

void SaveToStorage() {
    MainWorkObj.Storage.Settings.VoltageA = MainWorkObj.SetPointVoltageA;
    MainWorkObj.Storage.Settings.AmperageA = MainWorkObj.SetPointAmperageA;
    MainWorkObj.Storage.Settings.StabilizeModeA = MainWorkObj.StabilizeModeA;
    MainWorkObj.Storage.Settings.VoltageB = MainWorkObj.SetPointVoltageB;
    MainWorkObj.Storage.Settings.AmperageB = MainWorkObj.SetPointAmperageB;
    MainWorkObj.Storage.Settings.StabilizeModeB = MainWorkObj.StabilizeModeB;
    MainWorkObj.Storage.Crc = 0x11223344;
    MainWorkObj.Storage.Ok = 0;
    MainWorkObj.Storage.Crc = CalcCrc32((PBYTE) &(MainWorkObj.Storage), (INT)sizeof(TEepromStrorage));
    
    EEPROMStorage_UpdateTemperature();
    PBYTE pBuffer = (PBYTE) &(MainWorkObj.Storage);
    INT row;
    INT rowCount = (INT)sizeof(TEepromStrorage) / EEPROM_ROW_SIZE_BYTES;
    for (row = 0; row < rowCount; row++){
        cystatus status = EEPROMStorage_StartWrite(pBuffer, row);  
        if (status != CYRET_STARTED) {
            return;    
        }
        pBuffer += EEPROM_ROW_SIZE_BYTES;
        while (EEPROMStorage_Query() == CYRET_STARTED) {        
		    TaskSleep(&MainWorkFunction, SYSTICK_mS(2));	
        }
    }  
}