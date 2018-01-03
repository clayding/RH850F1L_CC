# RH850_Cube_CC

2017年12月18日前已经一下Driver和编写和测试。
1.Clock controller的代码编写测试，经过OSTM的测试，验证PLL输出的时钟频率可以达到80MHz（最大96MHz）
2.Port部分完成gpio的输入输出操作，成功点亮Led1/Led2(StartBoard),使用复用功能结合中断/异常部分完成INTP按键中断测试。
3.中断/异常部分完成INTP的按键中断测试，OSTM计数器的中断响应
4.OSTM计数器/定时器 定时1us，使用Interval mode 和free-run compare mode

2018年1月3号
1.完成TAUB interval timer function 和PWM output function 的代码编写和测试
2.添加新版的user manual,在1.32版的中发现一些问题。新版改正了。因此TAUD下面的用新版的UM
