/*
 * File      : board.h
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2009, RT-Thread Development Team
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rt-thread.org/license/LICENSE
 *
 * Change Logs:
 * Date           Author       Notes
 * 2009-09-22     Bernard      add board.h to this bsp
 */

// <<< Use Configuration Wizard in Context Menu >>>
#ifndef __BOARD_H__
#define __BOARD_H__

#include "stm32f10x.h"

/* board configuration */

/* whether use board external SRAM memory */
// <e>Use external SRAM memory on the board
// 	<i>Enable External SRAM memory
#define STM32_EXT_SRAM          0
//	<o>Begin Address of External SRAM
//		<i>Default: 0x68000000
#define STM32_EXT_SRAM_BEGIN    0x68000000 /* the begining address of external SRAM */
//	<o>End Address of External SRAM
//		<i>Default: 0x68080000
#define STM32_EXT_SRAM_END      0x68080000 /* the end address of external SRAM */
// </e>

// <o> Internal SRAM memory size[Kbytes] <8-64>
//	<i>Default: 64
#define STM32_SRAM_SIZE         20
#define STM32_SRAM_END          (0x20000000 + STM32_SRAM_SIZE * 1024)

// <o> Console on USART: <0=> no console <1=>USART 1 <2=>USART 2 <3=> USART 3
// 	<i>Default: 1
#define STM32_CONSOLE_USART		1

#define CONSOLE_NULL  0x00
#define CONSOLE_A  		0x01
#define CONSOLE_B  		0x02
#define CONSOLE_C  		0x03
#define CONSOLE_ALL   0x10

#define RT_USING_BOARD_C




/*Haraware setting,only one active*/ 
#ifdef RT_USING_BOARD_A
#define FeiYu_Board_A
#define CONSOLE_O  CONSOLE_A
/* USART driver select. */
#define RT_USING_UART1
//#define RT_USING_UART2
//#define RT_USING_UART3
#endif

#ifdef RT_USING_BOARD_B
#define FeiYu_Board_B
#define CONSOLE_O  CONSOLE_B
/* USART driver select. */
#define RT_USING_UART1
//#define RT_USING_UART2
#define RT_USING_UART3
#endif

#ifdef RT_USING_BOARD_C
#define FeiYu_Board_C
#define CONSOLE_O  CONSOLE_C
/* USART driver select. */
#define RT_USING_UART1
//#define RT_USING_UART2
#define RT_USING_UART3
#endif


#ifdef FeiYu_Board_A
#define Encoder_Align_Pos  5232
#define Level_Mec_Angle    -3568
#endif

#ifdef FeiYu_Board_B
#define Encoder_Align_Pos  8109
#define Level_Mec_Angle    286
#endif

#ifdef FeiYu_Board_C
#define Encoder_Align_Pos   15538
#define Level_Mec_Angle     1034
#endif

void rt_hw_board_init(void);

#if STM32_CONSOLE_USART == 0
#define CONSOLE_DEVICE "no"
#elif STM32_CONSOLE_USART == 1
#define CONSOLE_DEVICE "uart1"
#elif STM32_CONSOLE_USART == 2
#define CONSOLE_DEVICE "uart2"
#elif STM32_CONSOLE_USART == 3
#define CONSOLE_DEVICE "uart3"
#endif

#define FINSH_DEVICE_NAME   CONSOLE_DEVICE

#endif /* __BOARD_H__ */
