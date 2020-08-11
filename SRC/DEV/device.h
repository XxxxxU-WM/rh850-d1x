//============================================================================
// PROJECT  :  Example project
//============================================================================
//                           C O P Y R I G H T
//============================================================================
// Copyright (c) 2013 by Renesas Electronics Europe GmbH. All rights reserved.
// Arcadiastr.10
// D-40472 Duesseldorf
// Germany
//============================================================================
//
// Warranty Disclaimer :
// Because the Product(s) is licensed free of charge, there is no warranty of
// any kind whatsoever and expressly disclaimed and excluded by Renesas, either
// expressed or implied, including but not limited to those for non-
// infringement of intellectual property, merchantability and/or fitness for
// the particular purpose. Renesas shall not have any obligation to maintain,
// service or provide bug fixes for the supplied Product(s) and/or the
// Application.
//
// Each User is solely responsible for determining the appropriateness of
// using the Product(s) and assumes all risks associated with its exercise
// of rights under this Agreement, including, but not limited to the risks
// and costs of program errors, compliance with applicable laws, damage to
// or loss of data, programs or equipment, and unavailability or
// interruption of operations.
//
// Limitation of Liability :
// In no event shall Renesas be liable to the User for any incidental,
// consequential, indirect, or punitive damage (including but not limited to
// lost profits) regardless of whether such liability is based on breach of
// contract, tort, strict liability, breach of warranties, failure of
// essential purpose or otherwise and even if advised of the possibility of
// such damages. Renesas shall not be liable for any services or products provided
// by third party vendors, developers or consultants identified or referred
// to the User by Renesas in connection with the Product(s) and/or the
// Application.
//
//============================================================================
//
// Device specific main header file to be included in all source files.
//
//============================================================================

#ifndef   DEVICE_H
#define   DEVICE_H

//============================================================================
// Includes
//============================================================================

#include "dr7f701461.dvf.h"


//============================================================================
// Defines
//============================================================================

#define PROTECTED_WRITE(preg,pstatus,reg,value)   do{\
                                                  (preg) = (uint32) 0xa5u;\
                                                  (reg) = (uint32) (value);\
                                                  (reg) = (uint32) (~((uint32) value));\
                                                  (reg) = (uint32) (value);\
                                                  }while((pstatus)==1u)



#define INTC2_REGISTER_WRITE(reg, value)    do{PBG.FSGD0BPROT0.UINT32 = 0x07FFFFFFu;\
												(reg) = (value);}while(0)
	
#define DMA_REGISTER_WRITE(reg, value)      do{PBG.FSGD0BPROT1.UINT32 = 0x07FFFFFFu;\
												(reg) = (value);}while(0)

#define __no_operation() __asm("nop")

#define R_DEV_READ_REG(SIZE, ADDR)   ((*((volatile uint##SIZE##_t*)((ADDR)))))

#define R_DEV_WRITE_REG(SIZE, ADDR, VALUE)  {(*((volatile uint##SIZE##_t*)(ADDR)) = (VALUE)); }

#endif  /* DEVICE_H */
