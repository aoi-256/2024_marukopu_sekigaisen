#include "wrapper.hpp"
#include "usart.h"
#include "tim.h"
#include <string>
#include "adc.h"
#include "SBUS.h"

nokolat::SBUS sbus;
nokolat::SBUS_DATA data;

uint16_t adc_value = 0;
uint16_t servo = 1500;


void init(){

	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);

	HAL_UART_Receive_DMA(&huart3, sbus.getReceiveBufferPtr(),sbus.getDataLen());

}

void loop(){

	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1,1000);
	adc_value = HAL_ADC_GetValue(&hadc1);

	if(adc_value > 1000){

		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1, GPIO_PIN_SET);
		HAL_Delay(250);
	}
	else{

		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1, GPIO_PIN_RESET);

	}
	if(data[5] >= 1500){
		servo = 2000;
	}
	else{
		servo = 1000;
	}

	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4,servo);

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

	  sbus.requireDecode();
	  data = sbus.getData();

	  HAL_UART_Receive_DMA(&huart3, sbus.getReceiveBufferPtr(),sbus.getDataLen());
}
