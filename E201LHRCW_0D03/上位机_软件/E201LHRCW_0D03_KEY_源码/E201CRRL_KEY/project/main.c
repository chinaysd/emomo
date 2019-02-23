/* MAIN.C file
 * 
 * Copyright (c) 2002-2005 STMicroelectronics
 */
/*
	@func:E201LHRCW_KEY
	@version:V0.1.2.20170510_Release
	@date:2017/3/8
	@author:marco
*/


#include "system.h"

void main(void){ 

 	System_Init();
	while (1){
		System_Handle();
	}
}















