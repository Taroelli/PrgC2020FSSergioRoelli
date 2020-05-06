#include <msp430.h> 
#include "driverlib.h"
#include "battery.h"

// D E F I N E   C A S E S
#define InitialMode     0
#define TextMode        1
#define BatteryMode     2
#define BatterySwitch   3
//------------------------------------------------------------------------------

// TimerA0 UpMode Configuration Parameter
Timer_A_initUpModeParam initUpParam_A0 =
{
        TIMER_A_CLOCKSOURCE_SMCLK,              // SMCLK Clock Source
        TIMER_A_CLOCKSOURCE_DIVIDER_1,          // SMCLK/1 = 2MHz
        30000,                                  // 15ms debounce period
        TIMER_A_TAIE_INTERRUPT_DISABLE,         // Disable Timer interrupt
        TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE ,    // Enable CCR0 interrupt
        TIMER_A_DO_CLEAR,                       // Clear value
        true                                    // Start Timer
};


void Init_GPIO();
void Init_Clock();
void Init_RTC();

/**
 * main.c
 */
int main(void)
{
//D E F I N E  V A R I A B L E S
    unsigned int count = 0;
    unsigned int batteryStatus = 0;
    unsigned char S1buttom = 0;
    unsigned char S2buttom = 0;
    char switchCases = InitialMode;
    int i = 0;
    int countName = 2; // How many times do you want to see your Name?
//------------------------------------------------------------------------------

//C A L L  C A S E S
    while(1)
    {
        switch(switchCases)
        {
        //CASE: InitialMode Stop Watchdog timer
        case InitialMode:
            WDT_A_hold(__MSP430_BASEADDRESS_WDT_A__);     // Stop WDT
            Init_GPIO();
            Init_LCD();
            switchCases = TextMode;
            break;
        //CASE: TextMode Show your Name
        case TextMode:
             while(i <= countName-1)
             {
                 displayScrollText("PRG C SERGIO ROELLI");
                 ++i;
             }
            switchCases = BatteryMode;
            break;
        //CASE: Battery Mode
        case BatteryMode:
                LCDM12 = 0x10;
                LCDM13 = 0x01;
                switchCases = BatterySwitch;
                break;
        //CASE: Battery Switch, switch battery Level
        case BatterySwitch:
            // When Buttom S1 first time pressed
                         if (!(P1IN & BIT2) && (S1buttom == 0))
                         {
                             P1OUT |= BIT0;            // turn on LED1
                             S1buttom = 1;
                             if (batteryStatus > 0)
                             {
                                 batteryStatus--;
                                 batteryStatusChange(batteryStatus);
                             }
                             else //blinken wenn leer und gedruckt
                             {
                                 P1OUT |= BIT0;
                                 P4OUT |= BIT0;

                                 for(count=0;count<30000;count++)
                                 {
                                     ;
                                 }

                                 P1OUT &= ~BIT0;
                                 P4OUT &= ~BIT0;

                                 for(count=0;count<30000;count++)
                                 {
                                     ;
                                 }
                                 P1OUT |= BIT0;
                                 P4OUT |= BIT0;

                                 for(count=0;count<30000;count++)
                                 {
                                     ;
                                 }

                                 P1OUT &= ~BIT0;
                                 P4OUT &= ~BIT0;

                                 for(count=0;count<30000;count++)
                                 {
                                     ;
                                 }
                             }
                         }
                         // When Buttom S2 first time pressed
                         if (!(P2IN & BIT6) && S2buttom == 0)
                         {
                             P4OUT |= BIT0;            // turn on LED2
                             S2buttom = 1;
                             if (batteryStatus < 6)
                             {
                                 batteryStatus++;
                                 batteryStatusChange(batteryStatus);
                             }
                             else //blinken wenn voll und gedruckt
                             {
                                 P1OUT |= BIT0;
                                 P4OUT |= BIT0;

                                 for(count=0;count<30000;count++)
                                 {
                                     ;
                                 }

                                 P1OUT &= ~BIT0;
                                 P4OUT &= ~BIT0;

                                 for(count=0;count<30000;count++)
                                 {
                                     ;
                                 }
                                 P1OUT |= BIT0;
                                 P4OUT |= BIT0;

                                 for(count=0;count<30000;count++)
                                 {
                                     ;
                                 }

                                 P1OUT &= ~BIT0;
                                 P4OUT &= ~BIT0;

                                 for(count=0;count<30000;count++)
                                 {
                                     ;
                                 }
                             }
                         }
                         // Button S1 released
                         if (P1IN & BIT2)
                         {
                             S1buttom = 0;     // Clear button
                             P1OUT &= ~BIT0;           // turn off LED1
                         }

                         // Button S2 released
                         if (P2IN & BIT6)
                         {
                             S2buttom = 0;     // Clear button
                             P4OUT &= ~BIT0;           // turn off LED2
                         }
                         if (!(P1IN & BIT2) && !(P2IN & BIT6))
                         {
                             LCDM12 = 0x00;
                             LCDM13 = 0x00;
                             batteryStatus = 0;
                             switchCases = TextMode;
                         }
                         break;

        }
    }



    return 0;
}

void Init_GPIO()
{
    // Set all GPIO pins to output low to prevent floating input and reduce power consumption
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P6, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P7, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P8, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);

    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P6, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P7, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P8, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);

    GPIO_setAsInputPin(GPIO_PORT_P1, GPIO_PIN1);

    // Configure button S1 (P1.2) interrupt
    GPIO_selectInterruptEdge(GPIO_PORT_P1, GPIO_PIN2, GPIO_HIGH_TO_LOW_TRANSITION);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN2);
    GPIO_clearInterrupt(GPIO_PORT_P1, GPIO_PIN2);
    GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN2);

    // Configure button S2 (P2.6) interrupt
    GPIO_selectInterruptEdge(GPIO_PORT_P2, GPIO_PIN6, GPIO_HIGH_TO_LOW_TRANSITION);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_clearInterrupt(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_enableInterrupt(GPIO_PORT_P2, GPIO_PIN6);

    // Set P4.1 and P4.2 as Secondary Module Function Input, LFXT.
    GPIO_setAsPeripheralModuleFunctionInputPin(
           GPIO_PORT_P4,
           GPIO_PIN1 + GPIO_PIN2,
           GPIO_PRIMARY_MODULE_FUNCTION
           );

    // Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings
    PMM_unlockLPM5();
}







