#ifndef __ACCELERO_INSTANCE_H__
#define __ACCELERO_INSTANCE_H__
#include <stdio.h>
#include <stdint.h>
typedef enum
{
 ACCELERO_OK      = 0,
 ACCELERO_ERROR   = 1,
 ACCELERO_TIMEOUT = 2 
}ACCELERO_StatusTypeDef;

typedef struct
{
 void     (*Init)(uint16_t);
 void     (*DeInit)(void);
 uint8_t  (*ReadID)(void);
 void     (*Reset)(void);
 void     (*LowPower)(uint16_t);
 void     (*ConfigIT)(uint16_t);
 void     (*EnableIT)(uint8_t);
 void     (*DisableIT)(uint8_t);
 uint8_t  (*ITStatus)(uint16_t, uint16_t);
 void     (*ClearIT)(void);
 void     (*FilterConfig)(uint8_t);
 void     (*FilterCmd)(uint8_t);
 void     (*GetXYZ)(int16_t *);
}ACCELERO_DrvTypeDef;

typedef struct
{
 uint8_t Power_Mode;
 uint8_t AccOutput_DataRate;
 uint8_t Axes_Enable;
 uint8_t High_Resolution;
 uint8_t BlockData_Update;
 uint8_t Endianness;
 uint8_t AccFull_Scale;
 uint8_t Communication_Mode;
}ACCELERO_InitTypeDef;

typedef struct
{
 uint8_t HighPassFilter_Mode_Selection;
 uint8_t HighPassFilter_CutOff_Freq;
 uint8_t HighPassFilter_AOI1;
 uint8_t HighPassFilter_AOI2;
 uint8_t HighPassFilter_Data_Sel;
 uint8_t HighPassFilter_Stat;

}ACCELERO_FilterConfigTypeDef;


// void ACCELERO_IO_Init(void);
// void ACCELERO_IO_Write(uint8_t *pBuffer, uint8_t WriteAddr, uint16_t NumByteToWrite)
// void ACCELERO_IO_Read(uint8_t *pBuffer, uint8_t ReadAddr, uint16_t NumByteToRead)
//////////////////void init_cs_gpio(void);
int ACCELERO_IO_Read(uint8_t reg, uint8_t *data, uint8_t size);
int ACCELERO_IO_Write(uint8_t reg, uint8_t value);

// void ACCELERO_IO_Read(void);
// void ACCELERO_IO_Write(void);


#endif /*___ACCELERO_INSTANCE_H___*/
