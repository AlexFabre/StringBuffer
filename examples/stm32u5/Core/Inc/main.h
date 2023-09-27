/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u5xx_hal.h"

#include "stm32u5xx_ll_bus.h"
#include "stm32u5xx_ll_cortex.h"
#include "stm32u5xx_ll_dma.h"
#include "stm32u5xx_ll_gpio.h"
#include "stm32u5xx_ll_pwr.h"
#include "stm32u5xx_ll_rcc.h"
#include "stm32u5xx_ll_system.h"
#include "stm32u5xx_ll_ucpd.h"
#include "stm32u5xx_ll_utils.h"

#include "stm32u5xx_ll_exti.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/*****************************************************************************/
/* Those pragma enable below listed warning for all files that include tools.h */
/* This way ensures the SOUPs are not concerned by the severity of those flags */
/* Warnings to enable */
#pragma GCC diagnostic warning "-Wextra"
#pragma GCC diagnostic warning "-Wmissing-include-dirs"
#pragma GCC diagnostic warning "-Wswitch-default"
#pragma GCC diagnostic warning "-Wswitch-enum"
#pragma GCC diagnostic warning "-Wconversion"
#pragma GCC diagnostic warning "-Wsign-conversion"
#pragma GCC diagnostic warning "-Wwrite-strings"
#pragma GCC diagnostic warning "-Wduplicated-cond"
#pragma GCC diagnostic warning "-Wduplicated-branches"
#pragma GCC diagnostic warning "-Wlogical-op"
#pragma GCC diagnostic warning "-Wnull-dereference"
#pragma GCC diagnostic warning "-Wjump-misses-init"
#pragma GCC diagnostic warning "-Wshadow"
#pragma GCC diagnostic warning "-Wformat=2"
#pragma GCC diagnostic warning "-Wfloat-equal"
/*****************************************************************************/

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define USER_BUTTON_Pin         GPIO_PIN_13
#define USER_BUTTON_GPIO_Port   GPIOC
#define VBUS_SENSE_Pin          GPIO_PIN_2
#define VBUS_SENSE_GPIO_Port    GPIOC
#define UCPD_FLT_Pin            GPIO_PIN_14
#define UCPD_FLT_GPIO_Port      GPIOB
#define UCPD1_CC2_Pin           GPIO_PIN_15
#define UCPD1_CC2_GPIO_Port     GPIOB
#define LED_RED_Pin             GPIO_PIN_2
#define LED_RED_GPIO_Port       GPIOG
#define LED_GREEN_Pin           GPIO_PIN_7
#define LED_GREEN_GPIO_Port     GPIOC
#define USART1_TX_Pin           GPIO_PIN_9
#define USART1_TX_GPIO_Port     GPIOA
#define USART1_RX_Pin           GPIO_PIN_10
#define USART1_RX_GPIO_Port     GPIOA
#define USB_OTG_FS_DM_Pin       GPIO_PIN_11
#define USB_OTG_FS_DM_GPIO_Port GPIOA
#define USB_OTG_FS_DP_Pin       GPIO_PIN_12
#define USB_OTG_FS_DP_GPIO_Port GPIOA
#define UCPD1_CC1_Pin           GPIO_PIN_15
#define UCPD1_CC1_GPIO_Port     GPIOA
#define UCPD_DBn_Pin            GPIO_PIN_5
#define UCPD_DBn_GPIO_Port      GPIOB
#define LED_BLUE_Pin            GPIO_PIN_7
#define LED_BLUE_GPIO_Port      GPIOB

/* USER CODE BEGIN Private defines */

/**
 * @brief Macro to check if a pointer is not null. If the pointer is null, a specified action will be performed.
 *
 * @param ptr The pointer to check.
 * @param action_if_null The action to perform if the pointer is null.
 */
#define check_not_null(ptr, action_if_null) \
    {                                       \
        if (ptr == NULL) {                  \
            action_if_null;                 \
        }                                   \
    }

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
