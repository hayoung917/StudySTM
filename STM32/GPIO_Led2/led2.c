#define RCC             0X40023800
#define RCC_AHB1ENR     *((unsigned int*)(RCC + 0X30))          //0X40023830

#define GPIOC           0X40020800
#define GPIOC_MODER     *((unsigned int*)(GPIOC + 0X00))
#define GPIOC_OTYPER    *((unsigned int*)(GPIOC + 0X04))
#define GPIOC_OSPEEDR   *((unsigned int*)(GPIOC + 0X08))
#define GPIOC_PUPDR     *((unsigned int*)(GPIOC + 0X0C))
#define GPIOC_IDR       *((unsigned int*)(GPIOC + 0X10))
#define GPIOC_ODR       *((unsigned int*)(GPIOC + 0X14))

static void Delay(const unsigned int count)
{
  unsigned int i = 0;
  for(i = (5000 * count); i != 0; i--);
}

int main()
{
  RCC_AHB1ENR = 0x00000004;      //portc CLOCK ENABLE
  GPIOC_MODER = 0X00000055;      //PORTC[3:0] OUTPUT 모드 설정 (0101 일반적 출력모드)
  GPIOC_OTYPER = 0X00000000;     //PUSH-PULL 설정
  GPIOC_OSPEEDR = 0X00000000;    //SPEED
  GPIOC_PUPDR = 0X00000000;      //NO PULL-UP/DOWN
  
  while(1)
  {
    GPIOC_ODR = 0X0005;         //0,2 ON 1,3 OFF
    Delay(1000);
    GPIOC_ODR = 0X000A;         //1,3 ON 0,2 OFF
    Delay(1000);
  }
}