#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <stdint.h>
#include <stdbool.h>
// #include <init_run.h>
//����pwm����

Timer_A_PWMConfig pwmConfig =
{
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_12,
        2500,
        TIMER_A_CAPTURECOMPARE_REGISTER_1,
        TIMER_A_OUTPUTMODE_RESET_SET,
        0
};
//�ҵ��pwm����
Timer_A_PWMConfig pwmConfig1 =
{
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_12,
        2500,
        TIMER_A_CAPTURECOMPARE_REGISTER_2,
        TIMER_A_OUTPUTMODE_RESET_SET,
        0
};
const eUSCI_UART_ConfigV1 uartConfig =
{
        EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
        78,                                     // BRDIV = 78
        2,                                       // UCxBRF = 2
        0,                                       // UCxBRS = 0
        EUSCI_A_UART_NO_PARITY,                  // No Parity
        EUSCI_A_UART_LSB_FIRST,                  // LSB First
        EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
        EUSCI_A_UART_MODE,                       // UART mode
        EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION,  // Oversampling
        EUSCI_A_UART_8_BIT_LEN                  // 8 bit data length
};
                   //ʱ�Ӽ�pwm��ʼ��
void GetLineWalking();              //��ȡ16·ѭ��ģ��״̬
void LinePin_init();                //ѭ��ģ���ʼ��
void motor_init();                   //������ų�ʼ��
void Run_Back();                    //ʵ�ֺ���
void Run_sit(int circle);
void Run_Right();                   //ʵ����ת
void Run_Lift();                    //ʵ����ת
void Run_Foword(int check);         //ǰ����ѭ��������Ĳ�������ǰ���ĸ���
void Run_Stop();                    //ֹͣ
void All_init();
void Run_Speed(int rate,int rate1);           //���Ƶ���ٶȣ���Χ0~320
int i,j,turns=0,turns1=0,x,y,strick1,strick2,strick3,strick4;
//int speed_L=2500,speed_R=2500;
int speed_L=2332,speed_R=2320,forward=2;
int line[16];
int main(void)
{
    All_init();
    Run_Speed(speed_L,speed_R);
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN6);
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN7);
    GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN6);
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN7);

    //test
//                        Run_Back();
//                        Run_Lift();
//                        Run_Foword(2);
//                        while(1);
//                        Run_Lift();
    //                    Run_Right();
    //                    Run_Foword(1);//
    //                    for (i = 1344538; i > 0; i--);
    //                    Run_Back();
    //test
    while(1)
        {
            GetLineWalking();
             if((line[0]||line[1])&&(line[6]||line[7]))//&&(!line[11]||!line[12])
                {
        //             MAP_UART_transmitData(EUSCI_A0_BASE, 48);
        //            Run_Speed(speed_L,speed_R);

                    for (i = 25000; i > 0; i--);//85000
                    Run_Stop();
                    break;
                }
        }
    Run_Right();
    Run_Foword(1);
    Run_Lift();
    //test
//                    Run_Foword(1);
//                    Run_Right();
//                    Run_Foword(1);//
//                    for (i = 1344538; i > 0; i--);
//                    Run_Back();
//                    Run_Lift();
//                    Run_Foword(3);
//                    Run_Lift();
//                    Run_Foword(1);//
//                    for (i = 1344538; i > 0; i--);
//                    Run_Back();
//                    Run_Right();
//                    Run_Foword(1);
//                    Run_Right();
//                    Run_Foword(1);//
//                    for (i = 1344538; i > 0; i--);
//                    Run_Right();
//                    Run_Foword(5);//
//                    while(1);
    //test
    for(j=0;j<3;j++)
        {
            Run_Foword(1);
            Run_Right();
            Run_Foword(1);//
            for (i = 1344538; i > 0; i--);
            Run_Back();
            Run_Lift();
            Run_Foword(3);
            Run_Lift();
            Run_Foword(1);//
            for (i = 1344538; i > 0; i--);
            Run_Back();
            Run_Right();
            Run_Foword(1);
            Run_Right();
            Run_Foword(1);//
            for (i = 1344538; i > 0; i--);
            Run_Lift();
            Run_Foword(3);
            Run_Lift();
        }
    Run_Foword(1);
     Run_Right();
     Run_Foword(1);//
     for (i = 1344538; i > 0; i--);
     Run_Back();
     Run_Lift();
     Run_Foword(3);
     Run_Lift();
     Run_Foword(1);//
     for (i = 1344538; i > 0; i--);
     Run_Back();
     Run_Right();
     Run_Foword(1);
     Run_Right();
     Run_Foword(1);//
     for (i = 1344538; i > 0; i--);
     Run_Lift();
     Run_Foword(2);
     Run_Lift();


    Run_Speed(1695,1620);
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN6);
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN7);
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN7);
    while(1)
    {
        GetLineWalking();
         if(!line[0]&&!line[1]&&!line[6]&&!line[7]&&!line[2]&&!line[3]&&!line[4]&&!line[5])//&&(!line[11]||!line[12])
            {
                for (i = 110000; i > 0; i--);
                Run_Stop();
                break;
            }
    }

    while(1);
}
void All_init()
{
    MAP_WDT_A_holdTimer();

    /* Selecting P1.2 and P1.3 in UART mode */
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1,
            GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);
    CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_12);

    MAP_UART_initModule(EUSCI_A0_BASE, &uartConfig);
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
    MAP_UART_enableModule(EUSCI_A0_BASE);

    MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN1);
    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P1, GPIO_PIN1);
    MAP_GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN1);
    //test
//    MAP_GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
    MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN4);
    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P1, GPIO_PIN4);
    MAP_GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN4);
    //test
    MAP_Interrupt_enableInterrupt(INT_PORT1);
    /* Enabling SRAM Bank Retention */

    MAP_SysCtl_enableSRAMBankRetention(SYSCTL_SRAM_BANK1);

    /* Enabling MASTER interrupts */
    MAP_Interrupt_enableMaster();
//    MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P5, GPIO_PIN5);
    motor_init();
    LinePin_init();

    GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
    for (i = 1344538; i > 0; i--);
    GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
    for (i = 1344538; i > 0; i--);
    GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
    for (i = 1344538; i > 0; i--);
    GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
    for (i = 1344538; i > 0; i--);
    GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
    for (i = 1344538; i > 0; i--);
    GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
    for (i = 1344538; i > 0; i--);
};
void PORT1_IRQHandler(void)
{
    uint32_t status;

    status = MAP_GPIO_getEnabledInterruptStatus(GPIO_PORT_P1);
    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P1, status);

    /* Toggling the output on the LED */
    if(status & GPIO_PIN1)
    {
        MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
        Run_Speed(speed_L+=10,speed_R);
        forward ++;

    }
    if(status & GPIO_PIN4)
    {
        MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
        Run_Speed(speed_L,speed_R+=10);
        forward ++;
    }
}
void motor_init()                                //������ų�ʼ��
{   //motor

    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN6);
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN6);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN7);
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, GPIO_PIN4,GPIO_PRIMARY_MODULE_FUNCTION);  //���Ÿ���
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, GPIO_PIN5,GPIO_PRIMARY_MODULE_FUNCTION);
    Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig);
    Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig1);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P5, GPIO_PIN5);//��ǰ����
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P5, GPIO_PIN4);//
};
void Run_Foword(int check)              //ǰ����ѭ��������Ĳ�������ǰ���ĸ���
{
    int way=0;
    int grid=1;
//    Run_Speed(speed_L,speed_R);
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN6);
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN7);
    GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN6);
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN7);
    while(1)
    {
        if(check==0)
            break;
        Run_Speed(speed_L,speed_R);
        GetLineWalking();
         if((!line[4]||!line[3])&&(!line[11]||!line[12]))//&&(!line[11]||!line[12])
            {
//             MAP_UART_transmitData(EUSCI_A0_BASE, 48);
//            Run_Speed(speed_L,speed_R);
                GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN6);
                GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN7);
                GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN6);
                GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN7);
                GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN6);
                GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN7);
            }//��ȡ16·ѭ��ģ��״̬
         else if((!line[0]||!line[1]||!line[2])&&line[4]&&line[6]&&line[7]&&line[5])//ǰ������ƫ||( (!line[8]||!line[9]||!line[10])&&line[13]&&line[14]&&line[15] )
            {
//             Run_Speed(1500,2320);//1332 1320
             GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN6);
             GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN7);
             GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN6);
             GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN7);
             GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN6);//
//             GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN6);//����
             GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN7);//
            }

        else if((!line[5]||!line[6]||!line[7])&&line[4]&&line[0]&&line[1]&&line[2] )//ǰ��������ƫ||((!line[13]||!line[14]||!line[15])&&line[8]&&line[9]&&line[10])
            {
//            Run_Speed(2332,1500);
            GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN6);
            GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN7);
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN6);
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN7);
            GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN6);
//            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN7);//����
            GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN7);//

            }
        else
            {
                GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN6);
                GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN7);
                GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN6);
                GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN7);
                GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN6);
                GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN7);
            }//��ȡ16·ѭ��ģ��״̬

        GetLineWalking();               //��ȡ16·ѭ��ģ��״̬
        //ɨ��·�ߣ����߹��ĸ������м���
        if(!line[0]&&!line[1]&&!line[2]&&!line[3]&&!line[4]&&!line[5]&&!line[6]&&!line[7])
            {
                way=1;                  //��ӱ���wayʹ�ý���ǰ��ѭ���ͺ���ѭ��ģ�������������ʱgrid++
                if(grid==check)         //��grid��ֵ�������봫�����check���ʱ���˳�ѭ��
                    break;
            }
        else if(way==1&&!line[8]&&!line[9]&&!line[10]&&!line[11]&&!line[12]&&!line[13]&&!line[14]&&!line[15])//
                {
                    way=0;                  //����way��ֵ
                    grid++;
                }
    }
    for (i = 50000; i > 0; i--);//95000
    Run_Stop();
//    Run_Speed(speed_L,speed_R);
//    Run_sit(1000);
//    Run_sit(forward);

};
void Run_Back()                         //ʵ�ֺ���
{
    Run_Speed(1695,1620);
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN6);
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN7);
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN7);
    while(1)
    {
        GetLineWalking();

        if(!line[8]&&!line[9]&&!line[10]&&!line[11]&&!line[12]&&!line[13]&&!line[14]&&!line[15])
            {

                    break;
            }

    }
    for (i = 100000; i > 0; i--);//110000
    Run_Stop();
    Run_Speed(speed_L,speed_R);
};
void Run_Right()                        //ʵ����ת
{
    Run_Speed(speed_L,speed_R);
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN6);
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN7);
    GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN6);
    GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN7);
    for (i = 242000; i > 0; i--);
    Run_Stop();
};
void Run_Lift()                         //ʵ����ת
{
    Run_Speed(speed_L,speed_R);
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN6);
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN7);
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN7);
    for (i = 242000; i > 0; i--);//360000
    Run_Stop();
};
void Run_Stop()                         //ֹͣ
{

    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN6);
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN7);
//
//    GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN6);
//    GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN7);
//    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN6);
//    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN7);
};
void Run_sit(int circle)
{       turns1=0;
        while(1)
        {

            x=GPIO_getInputPinValue(GPIO_PORT_P5, GPIO_PIN5);
            y=GPIO_getInputPinValue(GPIO_PORT_P5, GPIO_PIN4);
                if(x)
                    {
                            strick1=1;
                            if(strick2)
                            {
                                strick2=0;
                                turns++;
                            }
                    }
                else
                    {       strick2=1;
                            if(strick1)
                            {
                                strick1=0;
                                turns++;
                            }
                    }
                    if(y)
                        {
                                strick3=1;
                                if(strick4)
                                {
                                    strick4=0;
                                    turns1++;
                                }
                        }
                    else
                        {       strick4=1;
                                if(strick3)
                                {
                                    strick3=0;
                                    turns1++;
                                }
                        }
                    //lift
                    MAP_UART_transmitData(EUSCI_A0_BASE, 48+(turns%10000)/1000);
                    MAP_UART_transmitData(EUSCI_A0_BASE, 48+(turns%1000)/100);
                    MAP_UART_transmitData(EUSCI_A0_BASE, 48+(turns%100)/10);
                    MAP_UART_transmitData(EUSCI_A0_BASE, 48+(turns%10));
                    MAP_UART_transmitData(EUSCI_A0_BASE, ' ');
                    //right
                    MAP_UART_transmitData(EUSCI_A0_BASE, 48+(turns1%10000)/1000);
                    MAP_UART_transmitData(EUSCI_A0_BASE, 48+(turns1%1000)/100);
                    MAP_UART_transmitData(EUSCI_A0_BASE, 48+(turns1%100)/10);
                    MAP_UART_transmitData(EUSCI_A0_BASE, 48+(turns1%10));


                MAP_UART_transmitData(EUSCI_A0_BASE, '\r');
                MAP_UART_transmitData(EUSCI_A0_BASE, '\n');
                if(turns1==circle)
                                   {
                                       Run_Stop();
                                       break;
                                   }
        }
};
void Run_Speed(int rate,int rate1)                    //���Ƶ���ٶȣ���Χ0~320
{
//    pwmConfig.dutyCycle = rate;
//    pwmConfig1.dutyCycle = rate1;
//    MAP_Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig);
//    MAP_Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig1);
    Timer_A_setCompareValue(TIMER_A0_BASE,TIMER_A_CAPTURECOMPARE_REGISTER_1,rate);
    Timer_A_setCompareValue(TIMER_A0_BASE,TIMER_A_CAPTURECOMPARE_REGISTER_2,rate1);
};
void GetLineWalking()               //��ȡ16·ѭ��ģ��״̬
{
    //���ߵ���Ϊ�㣬���ߵ���Ϊ1������������1-8
    line[0] = GPIO_getInputPinValue(GPIO_PORT_P7, GPIO_PIN7);       //��ɫ1
    line[1] = GPIO_getInputPinValue(GPIO_PORT_P7, GPIO_PIN6);      //��ɫ2
    line[2] = GPIO_getInputPinValue(GPIO_PORT_P10, GPIO_PIN1);      //��ɫ3
    line[3] = GPIO_getInputPinValue(GPIO_PORT_P10, GPIO_PIN0);     //��ɫ4
    line[4] = GPIO_getInputPinValue(GPIO_PORT_P10, GPIO_PIN3);      //��ɫ5
    line[5] = GPIO_getInputPinValue(GPIO_PORT_P10, GPIO_PIN2);      //��ɫ6
    line[6] = GPIO_getInputPinValue(GPIO_PORT_P10, GPIO_PIN5);      //��ɫ7
    line[7] = GPIO_getInputPinValue(GPIO_PORT_P10, GPIO_PIN4);      //��ɫ8
    line[8] = GPIO_getInputPinValue(GPIO_PORT_P7, GPIO_PIN0);       //��ɫ1
    line[9] = GPIO_getInputPinValue(GPIO_PORT_P9, GPIO_PIN4);      //��ɫ2
    line[10] = GPIO_getInputPinValue(GPIO_PORT_P9, GPIO_PIN5);      //��ɫ3
    line[11] = GPIO_getInputPinValue(GPIO_PORT_P9, GPIO_PIN6);     //��ɫ4
    line[12] = GPIO_getInputPinValue(GPIO_PORT_P9, GPIO_PIN7);      //��ɫ5
    line[13] = GPIO_getInputPinValue(GPIO_PORT_P8, GPIO_PIN0);      //��ɫ6
    line[14] = GPIO_getInputPinValue(GPIO_PORT_P7, GPIO_PIN5);      //��ɫ7
    line[15] = GPIO_getInputPinValue(GPIO_PORT_P7, GPIO_PIN4);      //��ɫ8
};
void LinePin_init()                             //ѭ��ģ���ʼ��
{
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4, GPIO_PIN0);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4, GPIO_PIN1);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4, GPIO_PIN2);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4, GPIO_PIN3);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4, GPIO_PIN0);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4, GPIO_PIN1);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4, GPIO_PIN2);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4, GPIO_PIN3);

};
