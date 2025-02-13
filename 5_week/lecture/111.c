25MHz를 48MHz로 세팅하기
1. PREDIV2 에서 /5 
2. PLL2MUL 에서 *12
3. PREDIV1 에서 /5
4. PLLMUL 에서 *48


25MHz를 20MHz로 세팅하기
25 /5
PREDIV2 = /5 = 5
PLL2MUL = *2 = 10
PREDIV1 = /2 = 5
PLLMUL = *4 = 20




//@TODO - 1 Set the clock
/* HCLK = SYSCLK */
RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1;
/* PCLK2 = HCLK */
RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1;
/* PCLK1 = HCLK */
RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV1;

/* Configure PLLs ------------------------------------------------------*/
RCC->CFGR &= (uint32_t)~(RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL);
RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLXTPRE_PREDIV1 | RCC_CFGR_PLLSRC_PREDIV1 | RCC_CFGR_PLLMULL4);

RCC->CFGR2 &= (uint32_t)~(RCC_CFGR2_PREDIV2 | RCC_CFGR2_PLL2MUL | RCC_CFGR2_PREDIV1 | RCC_CFGR2_PREDIV1SRC);
RCC->CFGR2 |= (uint32_t)(RCC_CFGR2_PREDIV2_DIV5 | RCC_CFGR2_PLL2MUL_2 | RCC_CFGR2_PREDIV1SRC_PLL2 | RCC_CFGR2_PREDIV1_DIV2);
//@End of TODO - 1





/* Configure PLLs ------------------------------------------------------*/
/* PLL configuration: PLLCLK = ???? */
// HSE = 25, PREDIV1_div2 : /2 , PLLMULL4: *4

//HSE, PLL, PULLMUL 사용을 위한 초기화
RCC->CFGR &= (uint32_t)~(RCC_CFGR_PLLXTPRE |  RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL);

//아래 코드에서 계산한 값에 *4
RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLXTPRE_PREDIV1 | RCC_CFGR_PLLSRC_PREDIV1 | RCC_CFGR_PLLMULL4);

/* PLL2 configuration: PLL2CLK = ???? */
/* PREDIV1 configuration: PREDIV1CLK = ???? */

//PREDIV2, PLL2MUL, PREDIV1 사용을 위한 초기화
RCC->CFGR2 &= (uint32_t)~(RCC_CFGR2_PREDIV2 | RCC_CFGR2_PLL2MUL | RCC_CFGR2_PREDIV1 | RCC_CFGR2_PREDIV1SRC);

//HSE /5, *12, /5
RCC->CFGR2 |= (uint32_t)(RCC_CFGR2_PREDIV2_DIV5 | RCC_CFGR2_PLL2MUL12 | RCC_CFGR2_PREDIV1SRC_PLL2  | RCC_CFGR2_PREDIV1_DIV5);

