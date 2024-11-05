/*
@file LIS302DL.h 
@brief LIS302DL three-axis digital gyroscope driver from stm32f407
@author Thuan Tran 
@date 27.07.2024 
*/

#ifndef __LIS302DL__
#define __LIS302DL__
#include <stdint.h>
#include "Bit_operation.h"
#include "Accelero_instance.h"
/* _____________DEFINE____________*/
/* Memory mapping */
#define RESERVED1_START_BASE        0x00000000UL /* Reserved register*/
#define RESERVER1_STOP_BASE         0x0000000EUL /* Reserved register*/
#define WHO_AM_I_BASE               0x0000000FUL /* Readable register*/
#define RESERVED2_START_BASE        0x00000010UL /* Reserved register*/
#define RESERVED2_STOP_BASE         0x0000001FUL /* Reserved register*/
#define CTRL_REG1_BASE              0x00000020UL /* Read-write register*/
#define CTRL_REG2_BASE              0x00000021UL /* Read-write register*/
#define CTRL_REG3_BASE              0x00000022UL /* Read-write register*/
#define HP_FILTER_RESET_BASE        0x00000023UL /* Readable register*/
#define RESERVED3_START_BASE        0x00000024UL /* Reserved register*/
#define RESERVED3_STOP_BASE         0x00000026UL /* Reserved register*/
#define STATUS_REG_BASE             0x00000027UL /* Readable register*/
#define OUT_X_BASE                  0x00000029UL /* Readable register*/
#define OUT_Y_BASE                  0x0000002BUL /* Readable register*/
#define OUT_Z_BASE                  0x0000002DUL /* Readable register*/
#define RESERVED4_START_BASE        0x0000002EUL /* Reserved register*/
#define RESERVED4_STOP_BASE         0x0000002FUL /* Reserved register*/
#define FF_WU_CFG_1_BASE            0x00000030UL /* Read-write register*/
#define FF_WU_SRC_1_BASE            0x00000031UL /* Readable register*/
#define FF_WU_THS_1_BASE            0x00000032UL /* Read-write register*/
#define FF_WU_DURATION_1_BASE       0x00000033UL /* Read-write register*/
#define FF_WU_CFG_2_BASE            0x00000030UL /* Read-write register*/
#define FF_WU_SRC_2_BASE            0x00000031UL /* Readable register*/
#define FF_WU_THS_2_BASE            0x00000032UL /* Read-write register*/
#define FF_WU_DURATION_2_BASE       0x00000033UL /* Read-write register*/
#define CLICK_CFG																			0x00000038UL /* Read-write register*/
#define CLICK_SRC																			0x00000039UL /* Readable register*/
#define CLICK_THSY_X																0x0000003BUL /* Read-write register*/
#define CLICK_THSZ																		0x00000038UL /* Read-write register*/
#define CLICK_TimeLimit													0x00000039UL /* Readable register*/
#define CLICK_Latency															0x0000003BUL /* Read-write register*/
#define CLICK_Window																0x0000003FUL /* Read-write register*/
#define RESERVED5_START_BASE        0x00000038UL /* Reserved register*/
#define RESERVED5_STOP_BASE         0x0000003FUL /* Reserved regsiter*/

/*_________________DEFAULT VALUE DECLARATION*/

typedef struct
{
	uint8_t Power_Mode;							/*Power-down/Active mode*/ 
	uint8_t Output_DataRate;		/* Set data rate 100Hz /400Hz*/
	uint8_t Axes_Enable;						/* Axes enable*/
	uint8_t Full_Scale;							/*Full scale*/
	uint8_t Self_Test;								/*Self test*/
}LIS302DL_InitTypeDef;

typedef struct
{
	uint8_t Latch_Request;					/* Latch interrupt request into CLICK_SRC register */
	uint8_t Singleclick_Axes;  /* Signle Click Axes Interrupts*/
	uint8_t DoubleClick_Axes;		/*	Double Click Axes Interrupt*/
}LIS302DL_InterruptConfigTypeDef;

typedef struct
{
	uint8_t HighPassFilter_Data_Selection; /* Internal filter bypassed or data from internal filter send to output register*/
	uint8_t HighPassFilter_CutOff_Freq;				/* High pass filter cut-off frequency*/
	uint8_t HighPassfilter_Interrupt;						/* High pass filter enabled for Freefall/Wakeup*/

}LIS302DL_FilterConfigTypeDef;

typedef enum
{
 WHO_AM_I_DEFAULT      = 0b00111011UL,
 CTRL_REG1_DEFAULT     = 0b00000111UL,
 CTRL_REG2_DEFAULT     = 0b00000000UL,
 CTRL_REG3_DEFAULT     = 0b00000000UL,
 COMMON_DEFAULT_VALUE  = 0UL
} Register_DefaultValue;

typedef enum
{
 CTRL_MODE_POWERDOWN = 0x00,
 CTRL_MODE_ACTIVE_100HZ = 0x01,
 CTRL_MODE_ACTIVE_400HZ = 0x11
} CTRL_Mode;

typedef enum
{
	SENSITIVITY_2_3G = 18,
	SENSITIVITY_9_2G = 72,
} Sensitivity_Selection;

typedef enum
{
	DATARATE_100 = 0x00,
	DATARATE_400 = 0x80
} DataRate_Selection;

typedef enum
{
	LOWPOWERMODE_POWERDOWN = 0x00,
	LOWPOWERMODE_ACTIVE = 0x40
} LowPowerMode_Selection;

typedef enum
{
	FULLSCALE_2_3 = 0x00,
	FULLSCALE_9_2 = 0x20
}FullScale_Selection;

typedef enum
{
	SERIALINTERFACE_4WIRE = 0x00,
	SERIALINTERFACE_3WIRE = 0x80,
} SerialInterface_Selection;

typedef enum
{
	BOOT_NORMALMODE 		= 0x00,
	BOOT_REBOOTMEMORY = 0x40,
}Boot_Selection;

typedef enum
{
	FILTERDATASELECTION_BYPASSED = 0x00,
	FILTERDATASELECTION_OUTPUTREGISTER = 0x20,
}FilterData_Selection;

typedef enum
{
	HIGHPASS_FILTER_INTERRUPT_OFF = 0x00,
	HIGHPASS_FILTER_INTERRUPT_1   = 0x04,
	HIGHPASS_FILTER_INTERRUPT_2   = 0x08,
	HIGHPASS_FILTER_INTERRUPT_1_2 = 0x0C,
}HighPassFilter_Selection;

typedef enum
{
	INTERRUPT_REQUEST_NOTLATCHED	= 0x00,
	INTERRUPT_REQUEST_LATCHED   	= 0x40,
}Interrupt_Selection;

typedef enum
{
	CLICK_INTERRUPT_XYZ_DISABLE	= 0x00,
	CLICK_INTERRUPT_X_ENABLE   	= 0x01,
	CLICK_INTERRUPT_Y_ENABLE   	= 0x04,
	CLICK_INTERRUPT_Z_ENABLE   	= 0x10,
	CLICK_INTERRUPT_XYZ_ENABLE 	= 0x15,
}ClickInterrupt_Enable;

typedef enum
{
	DOUBLE_CLICK_INTERRUPT_XYZ_DISABLE = 0x00,
	DOUBLE_CLICK_INTERRUPT_X_ENABLE    = 0x02,
	DOUBLE_CLICK_INTERRUPT_Y_ENABLE    = 0x08,
	DOUBLE_CLICK_INTERRUPT_Z_ENABLE    = 0x20,
	DOUBLE_CLICK_INTERRUPT_XYZ_ENABLE  = 0x2A
}DoubleClick_Interrupt_Enable;

typedef enum
{
 CTRL_SELF_TEST_NORMAL    = 0x00,
 CTRL_SELF_TEST_P         = 0x10,
 CTRL_SELF_TEST_M         = 0x01,
 CTRL_SELF_TEST_FORBIDDEN = 0x11
} CTRL_SelfTest;

typedef enum 
{
 CTRL_HIGHPASS_FILTER_FREQ1 = 0x00,
 CTRL_HIGHPASS_FILTER_FREQ2 = 0x01,
 CTRL_HIGHPASS_FILTER_FREQ3 = 0x10,
 CTRL_HIGHPASS_FILTER_FREQ4 = 0x11
} CTRL_HighPass_Filter_Cutoff_Freq;

/*__________DATA STRUCTURES_______*/

typedef struct
{
 uint8_t DR : 1; /* Output data rate selection*/
 uint8_t PD : 1; /* Power Down Control*/
 uint8_t FS : 1; /* Full Scale selection*/
 uint8_t STP: 1; /* Self Test Enable*/
 uint8_t STM: 1;
 uint8_t Zen: 1; /* Z axis enable*/
 uint8_t Yen: 1; /* Y axis enable*/
 uint8_t Xen: 1; /* X axis enable*/
} CTRL_REG1_TypeDef;

typedef struct
{
 uint8_t SIM :1; /* SPI serial interface mode selection*/
 uint8_t BOOT:1; /* Reboot memory content*/
 uint8_t FDS :1; /* Filter data selection*/
 uint8_t HP_FF_WU:2; /* High pass filter enabled for freefall or wakeup*/
 uint8_t HP_coeff:2; /* High pass filter enabled cut-off freq configuration*/
} CTRL_REG2_TypeDef;

typedef struct
{
 uint8_t IHL:1;   /* bit selects the polarity of the interrupt signal*/
 uint8_t PP_OD:1; /* bit defines whether the interrupt pad has to work in Push-pull or in Open drain mode*/
 uint8_t I2CFG:3; /*bit select which signal has to be sent out from the INT2 and INt1 interrupt pad as described in the following table*/
 uint8_t I1CFG:3;
}CTRL_REG3_TypeDef;

typedef struct 
{
 uint8_t ZYXOR :1;
 uint8_t ZOR   :1;
 uint8_t YOR   :1;
 uint8_t XOR   :1;
 uint8_t ZYXDA :1;
 uint8_t ZDA   :1;
 uint8_t YDA   :1;
 uint8_t XDA   :1;  
}STATUS_REG_TypeDef;

typedef struct
{
	uint16_t OUT_X;
	uint16_t OUT_Y;
	uint16_t OUT_Z;
}OutValue_TypeDef;

typedef struct
{
 uint8_t AOI :1;
 uint8_t LIR :1;
 uint8_t ZHIE:1;
 uint8_t ZLIE:1;
 uint8_t YHIE:1;
 uint8_t YLIE:1;
 uint8_t XHIE:1;
 uint8_t XLIE:1;
} FF_WU_CFG_TypeDef;

typedef struct
{
 uint8_t IA :1;
 uint8_t ZH :1;
 uint8_t ZL :1;
 uint8_t YH :1;
 uint8_t YL :1;
 uint8_t XH :1;
 uint8_t XL :1;
} FF_WU_SRC_TypeDef;

typedef struct
{
 uint8_t DCRM :1;
 uint8_t THS  :7;
} FF_WU_THS_TypeDef;

#define CTRL_REG1_DR_Pos  0
#define CTRL_REG1_DR_Msk BF_MASK(CTRL_REG1_DR_Pos,1)
#define CTRL_REG1_PD_Pos  1
#define CTRL_REG1_PD_Msk BF_MASK(CTRL_REG1_PD_Pos,1)
#define CTRL_REG1_FS_Pos  2
#define CTRL_REG1_FS_Msk BF_MASK(CTRL_REG1_FS_Pos,1)
#define CTRL_REG1_STP_Pos 3
#define CTRL_REG1_STP_Msk BF_MASK(CTRL_REG1_STP_Pos,1)
#define CTRL_REG1_STM_Pos 4
#define CTRL_REG1_STM_Msk BF_MASK(CTRL_REG1_STM_Pos,1)
#define CTRL_REG1_ZEN_Pos 5
#define CTRL_REG1_ZEN_Msk BF_MASK(CTRL_REG1_ZEN_Pos,1)
#define CTRL_REG1_YEN_Pos 6
#define CTRL_REG1_YEN_Msk BF_MASK(CTRL_REG1_YEN_Pos,1)
#define CTRL_REG1_XEN_Pos 7
#define CTRL_REG1_XEN_Msk BF_MASK(CTRL_REG1_XEN_Pos,1)

#define CTRL_REG2_SIM_Pos      0
#define CTRL_REG2_SIM_Msk      BF_MASK(CTRL_REG2_SIM_Pos,1)
#define CTRL_REG2_BOOT_Pos     1
#define CTRL_REG2_BOOT_Msk     BF_MASK(CTRL_REG2_BOOT_Pos,1)
#define CTRL_REG2_FDS_Pos      3
#define CTRL_REG2_FDS_Msk      BF_MASK(CTRL_REG2_FDS_Pos,1)
#define CTRL_REG2_HP_FF_WU_Pos 4
#define CTRL_REG2_HP_FF_WU_Msk BF_MASK(CTRL_REG2_HP_FF_WU_Pos,2)
#define CTRL_REG2_HP_coeff_Pos 6
#define CTRL_REG2_HP_coeff_Msk BF_MASK(CTRL_REG2_HP_coeff_Pos,2)

#define CTRL_REG3_IHL_Pos   0
#define CTRL_REG3_IHL_Msk   BF_MASK(CTRL_REG3_IHL_Pos,1)
#define CTRL_REG3_PP_OD_Pos 1
#define CTRL_REG3_PP_OD_Msk BF_MASK(CTRL_REG3_PP_OD_Pos,1)
#define CTRL_REG3_I2CFG_Pos 2
#define CTRL_REG3_I2CFG_Msk BF_MASK(CTRL_REG3_I2CFG_Pos,3)
#define CTRL_REG3_I1CFG_Pos 5
#define CTRL_REG3_I1CFG_Msk BF_MASK(CTRL_REG3_I1CFG_Pos,3)

#define STATUS_REG_ZYXOR_Pos 0
#define STATUS_REG_ZYXOR_Msk BF_MASK(STATUS_REG_ZYXOR_Pos,1)
#define STATUS_REG_ZOR_Pos   1
#define STATUS_REG_ZOR_Msk   BF_MASK(STATUS_REG_ZOR_Pos,1)
#define STATUS_REG_YOR_Pos   2
#define STATUS_REG_YOR_Msk   BF_MASK(STATUS_REG_YOR_Pos,1)
#define STATUS_REG_XOR_Pos   3
#define STATUS_REG_XOR_Msk   BF_MASK(STATUS_REG_XOR_Pos,1)
#define STATUS_REG_ZYXDA_Pos 4
#define STATUS_REG_ZYXDA_Msk BF_MASK(STATUS_REG_ZYXDA_Pos,1)
#define STATUS_REG_ZDA_Pos   5
#define STATUS_REG_ZDA_Msk   BF_MASK(STATUS_REG_ZDA_Pos,1)
#define STATUS_REG_YDA_Pos   6
#define STATUS_REG_YDA_Msk   BF_MASK(STATUS_REG_YDA_Pos,1)
#define STATUS_REG_XDA_Pos   7
#define STATUS_REG_XDA_Msk   BF_MASK(STATUS_REG_XDA_Pos,1)

#define OUT_X_Pos 0
#define OUT_X_Msk BF_MASK(OUT_X_Pos,8)
#define OUT_Y_Pos 0
#define OUT_Y_Msk BF_MASK(OUT_Y_Pos,8)
#define OUT_Z_Pos 0
#define OUT_Z_Msk BF_MASK(OUT_Z_Pos,8)

#define FF_WU_CFG_AOI_Pos  0
#define FF_WU_CFG_AOI_Msk  BF_MASK(FF_WU_CFG_AOI_Pos, 1)
#define FF_WU_CFG_LIR_Pos  1
#define FF_WU_CFG_LIR_Msk  BF_MASK(FF_WU_CFG_LIR_Pos, 1)
#define FF_WU_CFG_ZHIE_Pos 2
#define FF_WU_CFG_ZHIE_Msk BF_MASK(FF_WU_CFG_ZHIE_Pos, 1)
#define FF_WU_CFG_ZLIE_Pos 3
#define FF_WU_CFG_ZLIE_Msk BF_MASK(FF_WU_CFG_ZLIE_Pos, 1)
#define FF_WU_CFG_YHIE_Pos 4
#define FF_WU_CFG_YHIE_Msk BF_MASK(FF_WU_CFG_YHIE_Pos, 1)
#define FF_WU_CFG_YLIE_Pos 5
#define FF_WU_CFG_YLIE_Msk BF_MASK(FF_WU_CFG_YLIE_Pos, 1)
#define FF_WU_CFG_XHIE_Pos 6
#define FF_WU_CFG_XHIE_Msk BF_MASK(FF_WU_CFG_XHIE_Pos, 1)
#define FF_WU_CFG_XLIE_Pos 7
#define FF_WU_CFG_XLIE_Msk BF_MASK(FF_WU_CFG_XLIE_Pos, 1)

#define FF_WU_SRC_IA_Pos 1
#define FF_WU_SRC_IA_Msk BF_MASK(FF_WU_SRC_IA_Pos, 1)
#define FF_WU_SRC_ZH_Pos 2
#define FF_WU_SRC_ZH_Msk BF_MASK(FF_WU_SRC_ZH_Pos, 1)
#define FF_WU_SRC_ZL_Pos 3
#define FF_WU_SRC_ZL_Msk BF_MASK(FF_WU_SRC_ZL_Pos, 1)
#define FF_WU_SRC_YH_Pos 4
#define FF_WU_SRC_YH_Msk BF_MASK(FF_WU_SRC_YH_Pos, 1)
#define FF_WU_SRC_YL_Pos 5
#define FF_WU_SRC_YL_Msk BF_MASK(FF_WU_SRC_YL_Pos, 1)
#define FF_WU_SRC_XH_Pos 6
#define FF_WU_SRC_XH_Msk BF_MASK(FF_WU_SRC_XH_Pos, 1)
#define FF_WU_SRC_XL_Pos 7
#define FF_WU_SRC_XL_Msk BF_MASK(FF_WU_SRC_XL_Pos, 1)

#define FF_WU_THS_DCRM_Pos  0
#define FF_WU_THS_DCRM_Mask BF_MASK(FF_WU_THS_DCRM_Pos, 1)
#define FF_WU_THS_Pos       1
#define FF_WU_THS_Mask      BF_MASK(FF_WU_THS_Pos, 7)

#define FF_WU_DURATION_Pos  0
#define FF_WU_DURATION_Mask BF_MASK(FF_WU_DURATION_Pos, 8)

int LIS302DL_Set_WhoAmIRegister(uint8_t assign_value);
int LIS302DL_Read_WhoAmIRegister(uint8_t *return_value);
int LIS302DL_Set_CTRL_REG1(CTRL_REG1_TypeDef reg);
int LIS302DL_Read_CTRL_REG1(CTRL_REG1_TypeDef *reg);
int LIS302DL_Set_CTRL_REG2(CTRL_REG2_TypeDef reg);
int LIS302DL_Read_CTRL_REG2(CTRL_REG2_TypeDef *reg);
int LIS302DL_Set_CTRL_REG3(CTRL_REG3_TypeDef reg);
int LIS302DL_Read_CTRL_REG3(CTRL_REG3_TypeDef *reg);
int LIS302DL_Read_STATUS_REG(STATUS_REG_TypeDef *reg);
int LIS302DL_Read_Data(OutValue_TypeDef *outvalue);

extern ACCELERO_DrvTypeDef Lis302dlDrv;


//void LIS302DL_Init(void);
void    LIS302DL_Init(void);
void    LIS302DL_DeInit(void);
uint8_t LIS302DL_ReadID(void);
void    LIS302DL_FilterConfig(uint8_t FilterStruct);
//void 			LIS302DL_InterruptConfig(LIS302DL_InterruptConfigTypeDef *LIS302DL_IntConfigStruct);
//void 			LIS302DL_LowpowerCmd(uint8_t LowPowerMode);
void    LIS302DL_Click_IntConfig(void);
void    LIS302DL_Click_IntClear(void);
//void 			LIS302DL_FullScaleCmd(uint8_t FS_value)
//void 			LIS302DL_DataRateCmd(uint8_t DataRateValue);
void 			LIS302DL_ReadACC(int16_t *pData);
void    LIS302DL_RebootCmd(void);
int 				hello_world(void);



#endif