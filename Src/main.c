/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stdio.h"


/* Private function prototypes -----------------------------------------------*/
#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

IWDG_HandleTypeDef hiwdg;

UART_HandleTypeDef huart1;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_IWDG_Init(void);
static void MX_USART1_UART_Init(void);
void HAL_Delay_s(unsigned int Time);
uint8_t get_settimes(void);
uint8_t get_settimer(void);


uint8_t Settime = 0;
uint8_t Setcount = 0;
uint8_t SWcount = 0;
uint8_t set_delay_time = 0;
uint8_t set_check_time = 0;
int main(void)
{
	uint32_t sw = 0;
	uint32_t cs_h = 0, cs_l = 0;
	
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();
	MX_IWDG_Init();
	MX_USART1_UART_Init();
	log_info("Init_SysTick OK!\r\n");
	
	HAL_Delay(100);
	HAL_IWDG_Refresh(&hiwdg);
	HAL_Delay(100);
	HAL_IWDG_Refresh(&hiwdg);
	Setcount = get_settimes(); //
	Settime = get_settimer();  //
	
	log_info("Setcount:%d,Settime:%d,set_delay_time:%d,set_check_time:%d\r\n", Setcount, Settime, set_delay_time,set_check_time);
	
//	while(1)
//	{
//		HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);
//		
//	};
	
//	while(1)
//	{
//		power_ON();

//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		
//		
//		
//		power_OFF();
//		
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		HAL_Delay(200);HAL_IWDG_Refresh(&hiwdg);
//		
//		
//	}
	
	
	
	
  while (1)
  {
	  	//1:输出24V，无报警
		log_info("Step1:Power_ON\r\n");
		power_ON();
		Alarm_OFF();
		HAL_IWDG_Refresh(&hiwdg);

		//2:
		log_info("Step2:Delay_S:%ds\r\n",set_delay_time*10);
		HAL_Delay_s(set_delay_time * 10);	//延时设置时间，拨码开关前四位

		
	//3:检测触点
	Dect_Input_Singel:
		log_info("Step3:Dect_Input_Singel:%ds\r\n",set_check_time*10);

		cs_h = 0;
		cs_l = 0;
		while (1) //
		{
			HAL_IWDG_Refresh(&hiwdg);
			if (Read_InputSignal()) //
			{
				HAL_Delay(10);
				cs_h++;
				cs_l = 0;
				if (cs_h >= (uint32_t)set_check_time * 10 * 100)
				{
					sw = 1;
					break;
				}
			}

			if (!Read_InputSignal()) //
			{
				HAL_Delay(10);
				cs_l++;
				cs_h = 0;
				if (cs_l >= (uint32_t)set_check_time * 10 * 100)
				{
					sw = 0;
					break;
				}
			}
		}

		HAL_IWDG_Refresh(&hiwdg);

		//3-1:如果触点接触长达设置时间，拨码开关后四位
		if (sw == 1)
		{
			log_info("Step3-1:SW_always_ON:%d\r\n", sw);
			while (1)	//持续输出24V
			{
				HAL_IWDG_Refresh(&hiwdg);
				HAL_Delay(10);
				if (!Read_InputSignal()) //
				{
					uint32_t cs_h2 = 0, cs_l2 = 0, sw2 = 0;
					log_info("Dect_Input_Singel again:%ds\r\n",20);
					while (1) //再次检测20S
					{
						HAL_IWDG_Refresh(&hiwdg);
						if (Read_InputSignal()) //
						{
							HAL_Delay(10);
							cs_h2++;
							cs_l2 = 0;
							if (cs_h2 >= 20 * 100)
							{
								sw2 = 1;
								break;
							}
						}

						if (!Read_InputSignal()) //
						{
							HAL_Delay(10);
							cs_l2++;
							cs_h2 = 0;
							if (cs_l2 >= 20 * 100)
							{
								sw2 = 0;
								break;
							}
						}
					}
					if (sw2 == 0)				//如果触点不接触长达20S
						goto goto_power_off;
					if (sw2 == 1)	//如果触点持续接触，则一直保持该状态
					{
						log_info("continued power on \r\n");
						while (1)
						{
							HAL_IWDG_Refresh(&hiwdg);
							HAL_Delay(10);
						}
					}
				}
			}
		}
		HAL_IWDG_Refresh(&hiwdg);

		
		if (sw == 0)
		{
			log_info("Step3-2:SW_always_OFF:%d\r\n", sw);
		goto_power_off:
			power_OFF();
			log_info("Step3-2-1:Power_Off\r\n");
			log_info("Step3-2-2:Delay-%ds\r\n",set_delay_time*10);
			HAL_Delay_s(set_delay_time * 10);	//延时拨码开关前四位
			power_ON();	//输出24V
			SWcount++;  //计数+1
			log_info("Step3-2-3:Power_ON,SWcount++:%d\r\n", SWcount);
			HAL_IWDG_Refresh(&hiwdg);
			//3-2-4:
			log_info("Step3-2-4:Dect-SWcount\r\n");
			if (SWcount >= Setcount)	//检测计数值
			{
				//3-2-4-1:如果到达设定次数
				log_info("Step3-2-4-1:SWcount=Setcount,Power_Off,Delay-1s,Alarm_On\r\n");
				power_OFF();
				HAL_Delay_s(1);
				Alarm_ON();
				log_info("while(1):\r\n");
				while (1)
				{
					HAL_IWDG_Refresh(&hiwdg);
					HAL_Delay(5);
				}
			}
			else
			{
				HAL_IWDG_Refresh(&hiwdg);
				//3-2-4-2
				log_info("Step3-2-4-2:SWcount!=Setcount,goto Dect_Input_Singel\r\n");
				goto Dect_Input_Singel;
			}
		}

		log_info("Step3-3:SW Not always_ON And SW Not always_OFF,Restart!!!\r\n");
	  
	  
  }
}



uint8_t get_settimes(void)
{
	uint8_t tim_C[8]={0};
	uint8_t times=0;
	
	tim_C[0]= HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_11);
	tim_C[1]= HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_10);
	tim_C[2]= HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12);
	tim_C[3]= HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13);
	tim_C[4]= HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_14);
	tim_C[5]= HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_15);
	tim_C[6]= HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_8);
	tim_C[7]= HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_11);
	
	times=~((tim_C[7]<<7)|(tim_C[6]<<6)|(tim_C[5]<<5)|(tim_C[4]<<4)|(tim_C[3]<<3)|(tim_C[2]<<2)|(tim_C[1]<<1)|tim_C[0]);
	return times;
}

uint8_t get_settimer(void)
{
	uint8_t tim_C[8]={0};
	uint8_t timer=0;
	
	tim_C[0]= HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_12);	
	tim_C[1]= HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15);
	tim_C[2]= HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3);
	tim_C[3]= HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4);
	tim_C[4]= HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5);
	tim_C[5]= HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6);
	tim_C[6]= HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_7);
	tim_C[7]= HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_8);
	
	log_info("tim_C[0]:0x%x\r\n",tim_C[0]);
	log_info("tim_C[1]:0x%x\r\n",tim_C[1]);
	log_info("tim_C[2]:0x%x\r\n",tim_C[2]);
	log_info("tim_C[3]:0x%x\r\n",tim_C[3]);
	log_info("tim_C[4]:0x%x\r\n",tim_C[4]);
	log_info("tim_C[5]:0x%x\r\n",tim_C[5]);
	log_info("tim_C[6]:0x%x\r\n",tim_C[6]);
	log_info("tim_C[7]:0x%x\r\n",tim_C[7]);
	
	timer=~((tim_C[7]<<7)|(tim_C[6]<<6)|(tim_C[5]<<5)|(tim_C[4]<<4)|(tim_C[3]<<3)|(tim_C[2]<<2)|(tim_C[1]<<1)|tim_C[0]);
	
	set_delay_time=timer>>4;
	set_check_time=timer&0x0f;
	
	return timer;
}



void HAL_Delay_s(unsigned int Time)
{
	uint32_t i = 0, j = 0;
	j = Time * 10;
	while (i <= j)
	{
		HAL_IWDG_Refresh(&hiwdg);
		HAL_Delay(100);
		i++;
	}
}



/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief IWDG Initialization Function
  * @param None
  * @retval None
  */
static void MX_IWDG_Init(void)
{

  /* USER CODE BEGIN IWDG_Init 0 */

  /* USER CODE END IWDG_Init 0 */

  /* USER CODE BEGIN IWDG_Init 1 */

  /* USER CODE END IWDG_Init 1 */
  hiwdg.Instance = IWDG;
  hiwdg.Init.Prescaler = IWDG_PRESCALER_16;
  hiwdg.Init.Reload = 4095;
  if (HAL_IWDG_Init(&hiwdg) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN IWDG_Init 2 */

  /* USER CODE END IWDG_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/*******************************************************************************
* Function Name  : printf
* Description    : Retargets the C library printf function to the USART.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART2 and Loop until the end of transmission */
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA3 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA2 PA8 PA11 PA12 
                           PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_8|GPIO_PIN_11|GPIO_PIN_12 
                          |GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB10 PB11 PB12 PB13 
                           PB14 PB15 PB3 PB4 
                           PB5 PB6 PB7 PB8 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13 
                          |GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_3|GPIO_PIN_4 
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
