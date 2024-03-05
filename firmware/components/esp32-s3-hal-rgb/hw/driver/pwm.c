#include "pwm.h"
#include "gpio.h"


static bool is_init = false;



bool pwmInit(void)
{
  is_init = true;

  logPrintf("[OK] pwmInit()\n");   
  return true;  
}

bool pwmIsInit(void)
{
  return is_init;
}

void pwmWrite(uint8_t ch, uint16_t pwm_data)
{
  if (ch >= HW_PWM_MAX_CH || is_init != true) 
    return;

  if (pwm_data > 0)
    gpioPinWrite(_PIN_GPIO_LCD_BLK, _DEF_HIGH);
  else
    gpioPinWrite(_PIN_GPIO_LCD_BLK, _DEF_LOW);
}
 
uint16_t pwmRead(uint8_t ch)
{
  uint8_t ret = 0;

  if (ch >= HW_PWM_MAX_CH || is_init != true) 
    return 0;

  return (uint16_t)ret;
}

uint16_t pwmGetMax(uint8_t ch)
{
  return 255;
}