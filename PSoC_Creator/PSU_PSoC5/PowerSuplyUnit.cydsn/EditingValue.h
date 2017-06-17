/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#ifndef __EditingValue_H__
#define __EditingValue_H__
	
#include <device.h>
	


void SelectValue();
void SelectNextIndicator();
void SelectPrevIndicator();
void ConfirmSelection();

void ChangeValue(INT shiftValue);
//TChangedValue SelectedValueToChangedValue(TSelectValue selectedValue);
//TSelectValue ChangedValueToSelectedValue(TChangedValue changedValue);
	
#endif  /* __EditingValue_H__ */
/* [] END OF FILE */
