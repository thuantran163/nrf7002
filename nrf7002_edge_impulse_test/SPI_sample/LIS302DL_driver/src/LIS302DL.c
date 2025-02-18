#include "Accelero_instance.h"
#include "LIS302DL.h"
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

ACCELERO_DrvTypeDef Lis302dlDrv =
{
  LIS302DL_Init,
  LIS302DL_DeInit,
  LIS302DL_ReadID,
  LIS302DL_RebootCmd,
  LIS302DL_Click_IntConfig,
  0,
  0,
  0,
  0,
  LIS302DL_Click_IntClear,
  LIS302DL_FilterConfig,
  0,
  LIS302DL_ReadACC,
};

OutValue_TypeDef read_accelerometerData(void)
{
 //printf("Hello_world\r\n");
  LIS302DL_Init();
  //init_cs_gpio();
	uint8_t test_value = LIS302DL_ReadID();
	//printf("\r WHO_AM_I reg: %x \r\n", test_value);
  //uint8_t test_data;
  //LIS302DL_Read_WhoAmIRegister(test_data);
	OutValue_TypeDef read_data ={
		.OUT_X =0,
		.OUT_Y =0,
		.OUT_Z =0
	};
	LIS302DL_Read_Data(&read_data);
  
  //printk("Hello world\r\n");
  //k_sleep(K_SECONDS(1)) ;
	//printk("\n Xdata: %d\r\n", read_data.OUT_X);
	//printk("\n Ydata: %d\r\n", read_data.OUT_Y);
	//printk("\n Zdata: %d\r\n", read_data.OUT_Z);
	//printk("%d,%d,%d\r\n", read_data.OUT_X, read_data.OUT_Y,read_data.OUT_Z);
 // HAL_Delay(10);
 return read_data;
};


int Get_DataBlock (uint8_t assign_address, uint8_t *assign_value)
{
//  MX_SPI1_Init();
//  MX_GPIO_Init();

 //uint8_t tx_data[2] = { assign_address | 0x80, 0};
 uint8_t tx_data = (assign_address & 0b00111111) | 0x80;  
 // printf("transmit_address: %x\r\n", tx_data[0]);
 uint8_t get_value[2];
 ACCELERO_IO_Read(tx_data, get_value, sizeof(get_value));
//  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
//  HAL_SPI_TransmitReceive(&hspi1, tx_data,get_value,2,1000);
//  HAL_Delay(1);
//  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
 // printf("Receive data : %x\r\n", get_value[0]);
 // printf("Receive data : %x\r\n", get_value[1]);
 *assign_value = get_value[1];
 return 1;

};

int Set_DataBlock (uint8_t assign_address, uint8_t assign_value)
{
//  MX_GPIO_Init();
//  MX_SPI1_Init();

uint8_t tx_data[2] = {assign_address, assign_value};
uint8_t return_value[2];
ACCELERO_IO_Write(assign_address, assign_value);
 // printf( "\n transmit address: %x \r\n", tx_data[0]);
 // printf( "\n transmit data: %x \r\n",    tx_data[1]);
//  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
//  HAL_SPI_TransmitReceive(&hspi1, tx_data, return_value, 2, 10000);
//  HAL_Delay(1);
//  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
 return 1;
}

//int LIS302DL_Set_WhoAmIRegister(uint8_t assign_value)
//{
// uint8_t address = WHO_AM_I_BASE;
// Set_DataBlock(address, assign_value);
// return 1;
//}

int LIS302DL_Read_WhoAmIRegister(uint8_t *return_value)
{
 uint8_t data;
 uint8_t address = WHO_AM_I_BASE;
 Get_DataBlock(address, &data);
 *return_value = data;
	//ACCELERO_IO_Read(return_value, address, sizeof(return_value));
 return 1;
}

int LIS302DL_Set_CTRL_REG1(CTRL_REG1_TypeDef reg)
{
 uint8_t address = CTRL_REG1_BASE;
 uint8_t assign_value = 0;
 BFN_SET(assign_value, reg.DR , CTRL_REG1_DR );
 BFN_SET(assign_value, reg.PD , CTRL_REG1_PD );
 BFN_SET(assign_value, reg.FS , CTRL_REG1_FS );
 BFN_SET(assign_value, reg.STP, CTRL_REG1_STP );
 BFN_SET(assign_value, reg.STM, CTRL_REG1_STM );
 BFN_SET(assign_value, reg.Zen, CTRL_REG1_ZEN );
 BFN_SET(assign_value, reg.Yen, CTRL_REG1_YEN );
 BFN_SET(assign_value, reg.Xen, CTRL_REG1_XEN );
 Set_DataBlock(address, assign_value);
////ACCELERO_IO_Write(assign_value, address, sizeof(assign_value));


}
 
int LIS302DL_Read_CTRL_REG1(CTRL_REG1_TypeDef *reg)
{
 uint8_t address = CTRL_REG1_BASE;
	uint8_t return_value = 0;
	Get_DataBlock(address, &return_value);
	////ACCELERO_IO_Read(&return_value, address, sizeof(return_value));

	reg->DR   = BFN_GET(return_value, CTRL_REG1_DR);
	reg->PD   = BFN_GET(return_value, CTRL_REG1_PD);
	reg->FS   = BFN_GET(return_value, CTRL_REG1_FS);
	reg->STP  = BFN_GET(return_value, CTRL_REG1_STP);
	reg->STM  = BFN_GET(return_value, CTRL_REG1_STM);
	reg->Zen  = BFN_GET(return_value, CTRL_REG1_ZEN);
	reg->Yen  = BFN_GET(return_value, CTRL_REG1_YEN);
	reg->Xen  = BFN_GET(return_value, CTRL_REG1_XEN);
  // printf("return value: %d\r\n", return_value);
}

int LIS302DL_Set_CTRL_REG2(CTRL_REG2_TypeDef reg)
{
 uint8_t address = CTRL_REG2_BASE;
 uint8_t assign_value = 0;
 BFN_SET(assign_value, reg.SIM 				, CTRL_REG2_SIM );
 BFN_SET(assign_value, reg.BOOT 			, CTRL_REG2_BOOT );
 BFN_SET(assign_value, reg.FDS 				, CTRL_REG2_FDS );
 BFN_SET(assign_value, reg.HP_FF_WU, CTRL_REG2_HP_FF_WU );
 BFN_SET(assign_value, reg.HP_coeff, CTRL_REG2_HP_coeff );
 Set_DataBlock(address, assign_value);
	////ACCELERO_IO_Write(assign_value, address, sizeof(assign_value));
}
int LIS302DL_Read_CTRL_REG2(CTRL_REG2_TypeDef *reg)
{
 uint8_t address = CTRL_REG2_BASE;
	uint8_t return_value = 0;
	////ACCELERO_IO_Read(&return_value, address, sizeof(return_value));
	Get_DataBlock(address, &return_value);
	reg->SIM   					= BFN_GET(return_value, CTRL_REG2_SIM);
	reg->BOOT  					= BFN_GET(return_value, CTRL_REG2_BOOT);
	reg->FDS   					= BFN_GET(return_value, CTRL_REG2_FDS);
	reg->HP_FF_WU   = BFN_GET(return_value, CTRL_REG2_HP_FF_WU);
	reg->HP_coeff   = BFN_GET(return_value, CTRL_REG2_HP_coeff);
}

int LIS302DL_Set_CTRL_REG3(CTRL_REG3_TypeDef reg)
{
 uint8_t address = CTRL_REG3_BASE;
 uint8_t assign_value = 0;
 BFN_SET(assign_value, reg.IHL 						, CTRL_REG3_IHL );
 BFN_SET(assign_value, reg.PP_OD 				, CTRL_REG3_PP_OD );
 BFN_SET(assign_value, reg.I1CFG 				, CTRL_REG3_I1CFG );
 BFN_SET(assign_value, reg.I2CFG					, CTRL_REG3_I2CFG );
 Set_DataBlock(address, assign_value);
	////ACCELERO_IO_Write(assign_value, address, sizeof(assign_value));
}

int LIS302DL_Read_CTRL_REG3(CTRL_REG3_TypeDef *reg)
{
  uint8_t address = CTRL_REG3_BASE;
	uint8_t return_value = 0;
	Get_DataBlock(address, &return_value);
	////ACCELERO_IO_Read(&return_value, address, sizeof(return_value));
	reg->IHL   						= BFN_GET(return_value, CTRL_REG3_IHL);
	reg->PP_OD  					= BFN_GET(return_value, CTRL_REG3_PP_OD);
	reg->I1CFG   				= BFN_GET(return_value, CTRL_REG3_I1CFG);
	reg->I2CFG   				= BFN_GET(return_value, CTRL_REG3_I2CFG);
}


int LIS302DL_Read_STATUS_REG(STATUS_REG_TypeDef *reg)
{
	uint8_t address = STATUS_REG_BASE;
	uint8_t return_value = 0;
	Get_DataBlock(address, &return_value);
	reg->XDA   = BFN_GET(return_value, STATUS_REG_XDA  );
	reg->YDA   = BFN_GET(return_value, STATUS_REG_YDA  );
	reg->ZDA   = BFN_GET(return_value, STATUS_REG_ZDA  );
	reg->ZYXDA = BFN_GET(return_value, STATUS_REG_ZYXDA);
	reg->XOR   = BFN_GET(return_value, STATUS_REG_XOR  );
	reg->YOR   = BFN_GET(return_value, STATUS_REG_YOR  );
	reg->ZOR   = BFN_GET(return_value, STATUS_REG_ZOR  );
	reg->ZYXOR = BFN_GET(return_value, STATUS_REG_ZYXOR);
}
int LIS302DL_Read_Data(OutValue_TypeDef *outvalue)
{
	uint8_t data;
	uint8_t address = OUT_X_BASE;
	Get_DataBlock(address, &data);
  ////ACCELERO_IO_Read(&data, address, 8);
  //printf("%d\r\n", data);
	outvalue->OUT_X = _BF_PREP(data, 0, 8);

	address = OUT_Y_BASE;
	Get_DataBlock(address, &data);
  ////ACCELERO_IO_Read(&data, address, 8);
  //printf("%d\r\n", data);
	outvalue->OUT_Y = _BF_PREP(data, 0, 8);

	address = OUT_Z_BASE;
	Get_DataBlock(address, &data);
  ////ACCELERO_IO_Read(&data, address, 8);
  //printf("%d\r\n", data);
	outvalue->OUT_Z = _BF_PREP(data, 0, 8);
  //HAL_Delay(1);
	//printf("%d,%d,%d\r\n", outvalue->OUT_X, outvalue->OUT_Y,outvalue->OUT_Z);


};

void LIS302DL_Init(void)
{
	CTRL_REG1_TypeDef reg1 = {
		.DR =1,
		.PD =1,
		.FS =1,
		.STP=1,
		.STM=1,
		.Zen=1,
		.Yen=1,
		.Xen=1
	};
	int err =0;
	err = LIS302DL_Set_CTRL_REG1(reg1);

  LIS302DL_Read_CTRL_REG1(&reg1);

	CTRL_REG2_TypeDef reg2 = {
  	.SIM =1,
  	.BOOT = 0,
		.FDS = 0,
		.HP_FF_WU = 0b00,
		.HP_coeff = 0b00
	};
	err = LIS302DL_Set_CTRL_REG2(reg2);
	CTRL_REG3_TypeDef reg3 = {
		.IHL = 0,
		.PP_OD = 0,
		.I1CFG = 0b00,
		.I2CFG = 0b00
	};
	err =LIS302DL_Set_CTRL_REG3(reg3);
}

void LIS302DL_DeInit(void)
{

}

uint8_t LIS302DL_ReadID(void)
{
  uint8_t tmp = 0;

  /* Configure the low level interface */
  //ACCELERO_IO_Init();
  Get_DataBlock(WHO_AM_I_BASE, &tmp);
  /* Read WHO_AM_I register */
  //ACCELERO_IO_Read(&tmp, WHO_AM_I_BASE, 1);
  
  /* Return the ID */
  return (uint16_t)tmp;
}

void LIS302DL_FilterConfig(uint8_t FilterStruct)
{
  uint8_t ctrl = 0x00;
  
  /* Read CTRL_REG2 register */
  //ACCELERO_IO_Read(&ctrl, CTRL_REG2_BASE, 1);

  /* Clear high pass filter cut-off level, interrupt and data selection bits */
  ctrl &= (uint8_t)~( FILTERDATASELECTION_OUTPUTREGISTER | \
                      CTRL_HIGHPASS_FILTER_FREQ3 | \
                     HIGHPASS_FILTER_INTERRUPT_1_2 );

  ctrl |= FilterStruct;
  
  /* Write value to MEMS CTRL_REG2 register */
  //ACCELERO_IO_Write(&ctrl, CTRL_REG2_BASE, 1);
}

void LIS302DL_InterruptConfig(LIS302DL_InterruptConfigTypeDef *LIS302DL_IntConfigStruct)
{
  uint8_t ctrl = 0x00;
  
  /* Read CLICK_CFG register */
  //ACCELERO_IO_Read(&ctrl, CLICK_CFG , 1);
  
  /* Configure latch Interrupt request, click interrupts and double click interrupts */                   
  ctrl = (uint8_t)(LIS302DL_IntConfigStruct->Latch_Request| \
                   LIS302DL_IntConfigStruct->Singleclick_Axes| \
                   LIS302DL_IntConfigStruct->DoubleClick_Axes);
  
  /* Write value to MEMS CLICK_CFG register */
  //ACCELERO_IO_Write(&ctrl, CLICK_CFG, 1);
}

void LIS302DL_Click_IntConfig(void)
{
  uint8_t ctrl = 0x00;
  LIS302DL_InterruptConfigTypeDef   LIS302DL_InterruptStruct;
  
  //ACCELERO_IO_ITConfig();
  
  /* Set configuration of Internal High Pass Filter of LIS302DL */
  LIS302DL_InterruptStruct.Latch_Request = INTERRUPT_REQUEST_LATCHED;
  LIS302DL_InterruptStruct.Singleclick_Axes = CLICK_INTERRUPT_Z_ENABLE;
  LIS302DL_InterruptStruct.DoubleClick_Axes = DOUBLE_CLICK_INTERRUPT_Z_ENABLE;
  LIS302DL_InterruptConfig(&LIS302DL_InterruptStruct);
  
  /* Configure Interrupt control register: enable Click interrupt on INT1 and
  INT2 on Z axis high event */
  ctrl = 0x3F;
  //ACCELERO_IO_Write(&ctrl, CTRL_REG3_BASE, 1);
  
  /* Enable Interrupt generation on click on Z axis */
  ctrl = 0x50;
  //ACCELERO_IO_Write(&ctrl, CLICK_CFG, 1);
  
  /* Configure Click Threshold on X/Y axis (10 x 0.5g) */
  ctrl = 0xAA;
  //ACCELERO_IO_Write(&ctrl, CLICK_THSY_X, 1);
  
  /* Configure Click Threshold on Z axis (10 x 0.5g) */
  ctrl = 0x0A;
  //ACCELERO_IO_Write(&ctrl, CLICK_THSZ, 1);
  
  /* Enable interrupt on Y axis high event */
  ctrl = 0x4C;
  //ACCELERO_IO_Write(&ctrl, FF_WU_CFG_1_BASE, 1);
  
  /* Configure Time Limit */
  ctrl = 0x03;
  //ACCELERO_IO_Write(&ctrl, CLICK_TimeLimit, 1);
  
  /* Configure Latency */
  ctrl = 0x7F;
  //ACCELERO_IO_Write(&ctrl, CLICK_Latency, 1);
  
  /* Configure Click Window */
  ctrl = 0x7F;
  //ACCELERO_IO_Write(&ctrl, CLICK_Window, 1);
}

void LIS302DL_Click_IntClear(void)
{
  uint8_t buffer[6], clickreg = 0;

  /* Read click and status registers if the available MEMS Accelerometer is LIS302DL */
  //ACCELERO_IO_Read(&clickreg, CLICK_SRC, 1); 
  //ACCELERO_IO_Read(buffer, STATUS_REG_BASE, 6);
}


void LIS302DL_LowpowerCmd(uint8_t LowPowerMode)
{
  uint8_t tmpreg;
  
  /* Read CTRL_REG1 register */
  //ACCELERO_IO_Read(&tmpreg, CTRL_REG1_BASE, 1);
  
  /* Set new low power mode configuration */
  tmpreg &= (uint8_t)~LOWPOWERMODE_ACTIVE;
  tmpreg |= LowPowerMode;
  
  /* Write value to MEMS CTRL_REG1 register */
  //ACCELERO_IO_Write(&tmpreg, CTRL_REG1_BASE, 1);

}

void LIS302DL_DataRateCmd(uint8_t DataRateValue)
{
  uint8_t tmpreg;
  
  /* Read CTRL_REG1 register */
  //ACCELERO_IO_Read(&tmpreg, CTRL_REG1_BASE, 1);
  
  /* Set new Data rate configuration */
  tmpreg &= (uint8_t)~DATARATE_400;
  tmpreg |= DataRateValue;
  
  /* Write value to MEMS CTRL_REG1 register */
  //ACCELERO_IO_Write(&tmpreg, CTRL_REG1_BASE, 1);
}

void LIS302DL_FullScaleCmd(uint8_t FS_value)
{
  uint8_t tmpreg;
  
  /* Read CTRL_REG1 register */
  //ACCELERO_IO_Read(&tmpreg, CTRL_REG1_BASE, 1);
  
  /* Set new full scale configuration */
  tmpreg &= (uint8_t)~FULLSCALE_9_2;
  tmpreg |= FS_value;
  
  /* Write value to MEMS CTRL_REG1 register */
  //ACCELERO_IO_Write(&tmpreg, CTRL_REG1_BASE, 1);

}

void LIS302DL_RebootCmd(void)
{
  uint8_t tmpreg;
  /* Read CTRL_REG2 register */
  //ACCELERO_IO_Read(&tmpreg, CTRL_REG2_BASE, 1);
  
  /* Enable or Disable the reboot memory */
  tmpreg |= BOOT_REBOOTMEMORY;
  
  /* Write value to MEMS CTRL_REG2 register */
  //ACCELERO_IO_Write(&tmpreg, CTRL_REG2_BASE, 1);
}

void LIS302DL_ReadACC(int16_t *pData)
{
  int8_t buffer[6];
  int16_t pnRawData[3];
  uint8_t sensitivity =SENSITIVITY_2_3G ;
  uint8_t crtl, i = 0x00;
  
  ////ACCELERO_IO_Read(&crtl, CTRL_REG1_BASE, 1);
  ////ACCELERO_IO_Read((uint8_t*)buffer, OUT_X_BASE, 6);
  
  for(i=0; i<3; i++)
  {
    pnRawData[i] = buffer[2*i];
  }
  
  switch(crtl & FULLSCALE_9_2) 
  {
    /* FS bit = 0 ==> Sensitivity typical value = 18milligals/digit*/ 
  case FULLSCALE_2_3  :
    sensitivity = SENSITIVITY_2_3G;
    break;
    
    /* FS bit = 1 ==> Sensitivity typical value = 72milligals/digit*/ 
  case FULLSCALE_9_2 :
    sensitivity = SENSITIVITY_9_2G ;
    break;
    
  default:
    break;
  }
  
  /* Obtain the mg value for the three axis */
  for(i=0; i<3; i++)
  {
    pData[i]=(pnRawData[i] * sensitivity);
  }
}




