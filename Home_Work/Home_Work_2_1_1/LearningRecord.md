# 学习记录
## 11.26 - EIDE编译的时候内存不足
### 在VScode的EIDE进行Build的时候中断报错：
```
    *  正在文件夹 EIDE 中执行任务: "unify_builder -p d:\Amon_Projects_Repository\Learning_Projects_with_git_EIDE_Cubemx\Task2_1_1_Can_3508_C620\EIDE\build\Task2_1_1_Can_3508_C620\builder.params" 

    [ INFO ] start building at 2025-11-26 17:48:17

    [ TOOL ] Component: ARM Compiler 5.06 update 5 (build 528)

    [ INFO ] file statistics (incremental mode)

    +---------+-----------+-----------+---------------+--------+
    | C Files | Cpp Files | Asm Files | Lib/Obj Files | Totals |
    +---------+-----------+-----------+---------------+--------+
    | 18      | 0         | 1         | 0             | 19     |
    +---------+-----------+-----------+---------------+--------+

    [ INFO ] start compiling (jobs: 6) ...

    >> [  5%] CC '../Core/Src/gpio.c'
    >> [ 10%] CC '../Core/Src/system_stm32f1xx.c'
    >> [ 15%] CC '../Core/Src/main.c'
    >> [ 21%] CC '../Core/Src/stm32f1xx_hal_msp.c'
    >> [ 26%] CC '../Core/Src/stm32f1xx_it.c'
    >> [ 31%] CC '../Core/Src/can.c'
    >> [ 36%] CC '../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c'
    >> [ 42%] CC '../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c'
    >> [ 47%] CC '../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.c'
    >> [ 52%] CC '../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_can.c'
    >> [ 57%] CC '../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c'
    >> [ 63%] CC '../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.c'
    >> [ 68%] CC '../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.c'
    >> [ 73%] CC '../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.c'
    >> [ 78%] CC '../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.c'
    >> [ 84%] AS '../MDK-ARM/startup_stm32f103xb.s'
    >> [ 89%] CC '../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.c'
    >> [ 94%] CC '../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.c'
    >> [100%] CC '../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.c'

    [ INFO ] start linking ...

    Error: L6406E: No space in execution regions with .ANY selector matching startup_stm32f103xb.o(STACK).
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_hal_rcc.o(i.HAL_RCC_OscConfig). 
    Error: L6406E: No space in execution regions with .ANY selector matching startup_stm32f103xb.o(HEAP).
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_hal_gpio.o(i.HAL_GPIO_Init).    
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_hal_rcc.o(i.HAL_RCC_ClockConfig).
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_hal_can.o(i.HAL_CAN_Init).      
    Error: L6406E: No space in execution regions with .ANY selector matching can.o(i.HAL_CAN_MspInit).
    Error: L6406E: No space in execution regions with .ANY selector matching libspace.o(.bss).
    Error: L6406E: No space in execution regions with .ANY selector matching main.o(i.SystemClock_Config).
    Error: L6406E: No space in execution regions with .ANY selector matching rt_memclr_w.o(.text).
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_hal_rcc.o(i.HAL_RCC_GetSysClockFreq).
    Error: L6406E: No space in execution regions with .ANY selector matching sys_stackheap_outer.o(.text).
    Error: L6406E: No space in execution regions with .ANY selector matching can.o(i.MX_CAN_Init).
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_hal.o(i.HAL_InitTick).
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_hal_cortex.o(i.HAL_NVIC_SetPriority).
    Error: L6406E: No space in execution regions with .ANY selector matching startup_stm32f103xb.o(.text).
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_hal_msp.o(i.HAL_MspInit).       
    Error: L6406E: No space in execution regions with .ANY selector matching gpio.o(i.MX_GPIO_Init).
    Error: L6406E: No space in execution regions with .ANY selector matching can.o(.bss).
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_hal_cortex.o(i.HAL_SYSTICK_Config).
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_hal.o(i.HAL_Init).
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_hal_cortex.o(i.HAL_NVIC_SetPriorityGrouping).
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_hal_cortex.o(i.__NVIC_SetPriority).
    Error: L6406E: No space in execution regions with .ANY selector matching main.o(i.main).
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_hal_rcc.o(.constdata).
    Error: L6406E: No space in execution regions with .ANY selector matching exit.o(.text).
    Error: L6406E: No space in execution regions with .ANY selector matching system_stm32f1xx.o(.constdata).
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_hal.o(i.HAL_IncTick).
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_hal.o(i.HAL_GetTick).
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_hal.o(.data).
    Error: L6406E: No space in execution regions with .ANY selector matching sys_exit.o(.text).
    Error: L6406E: No space in execution regions with .ANY selector matching __rtentry2.o(.ARM.Collect$$rtentry$$0000000D).
    Error: L6406E: No space in execution regions with .ANY selector matching libspace.o(.text).
    Error: L6406E: No space in execution regions with .ANY selector matching heapauxi.o(.text).
    Error: L6406E: No space in execution regions with .ANY selector matching rtexit2.o(.ARM.Collect$$rtexit$$00000004).
    Error: L6406E: No space in execution regions with .ANY selector matching main.o(i.Error_Handler).
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_it.o(i.SysTick_Handler).        
    Error: L6406E: No space in execution regions with .ANY selector matching system_stm32f1xx.o(.data).
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_it.o(i.BusFault_Handler).       
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_it.o(i.DebugMon_Handler).       
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_it.o(i.HardFault_Handler).      
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_it.o(i.MemManage_Handler).      
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_it.o(i.NMI_Handler).
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_it.o(i.PendSV_Handler).
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_it.o(i.SVC_Handler).
    Error: L6406E: No space in execution regions with .ANY selector matching stm32f1xx_it.o(i.UsageFault_Handler).     
    Error: L6406E: No space in execution regions with .ANY selector matching system_stm32f1xx.o(i.SystemInit).
    Error: L6406E: No space in execution regions with .ANY selector matching libinit.o(.ARM.Collect$$libinit$$00000000).
    Error: L6406E: No space in execution regions with .ANY selector matching libshutdown.o(.ARM.Collect$$libshutdown$$00000000).
    Error: L6406E: No space in execution regions with .ANY selector matching use_no_semi.o(.text).
    Error: L6406E: No space in execution regions with .ANY selector matching indicate_semi.o(.text).
    Error: L6407E: Sections of aggregate size 0x126c bytes could not fit into .ANY selector(s).
    Not enough information to list image symbols.
    Not enough information to list the image map.
    Finished: 2 information, 0 warning and 52 error messages.

    ERROR  link failed !, exit code: 1

    ERROR  build failed !, elapsed time 0:1:27


    *  终端进程“cmd.exe /D /C "unify_builder -p d:\Amon_Projects_Repository\Learning_Projects_with_git_EIDE_Cubemx\Task2_1_1_Can_3508_C620\EIDE\build\Task2_1_1_Can_3508_C620\builder.params"”已终止，退出代码: 1。 
    *  终端将被任务重用，按任意键关闭。 
```
### 解决过程：
    * 问deepseek，说了一堆乱七八糟的，说是芯片内存不够，但是我明明没芯片；
    * 直接把代码粘贴上网搜索，没找到；
    * 用keil可以编译成功；
    * 文件删除重新再建，Build成功了；
    * 猜测原因：
        1.EIDE设置“芯片支持包”处选好DFP后没有更具体选芯片型号；
        2.初次选择使用了Jlink进行首次Build；
        3.不小心改了EIDE的配置文件；
    * 一天后我又遇见了该问题，问了粘贴给ai，ai讲得很复杂，看不懂，但使我知道了检索的关键词**EIDE编译的时候内存不足**
    * 然后我去上网找，就发现了解决方法；
#### 链接如下：
[CSDN解决方案https://blog.csdn.net/pdmnlb/article/details/134555702](https://blog.csdn.net/pdmnlb/article/details/134555702 "直接就解决了")

![CSDN解决方案图片](./images/EIDE编译超内存解决方案.png)


## 11.28 - 调试内存报错
### 继解决上面的错误后，在点击调试运行的时候报错：
    ```
    Cortex-Debug: VSCode debugger extension version 1.12.1 git(652d042). Usage info: https://github.com/Marus/cortex-debug#usage
    Reading symbols from C:/Users/Amon/.eide/tools/gcc_arm/bin/arm-none-eabi-objdump.exe --syms -C -h -w d:/Amon_Projects_Repository/Learning_Projects_with_git_EIDE_Cubemx/CAN_Loopbcak_Test/EIDE/build/CAN_Loopbcak_Test/CAN_Loopbcak_Test.elf
    Reading symbols from c:/users/amon/.eide/tools/gcc_arm/bin/arm-none-eabi-nm.exe --defined-only -S -l -C -p d:/Amon_Projects_Repository/Learning_Projects_with_git_EIDE_Cubemx/CAN_Loopbcak_Test/EIDE/build/CAN_Loopbcak_Test/CAN_Loopbcak_Test.elf
    Launching GDB: "C:\\Users\\Amon\\.eide\\tools\\gcc_arm\\bin\\arm-none-eabi-gdb.exe" -q --interpreter=mi2
        IMPORTANT: Set "showDevDebugOutput": "raw" in "launch.json" to see verbose GDB transactions here. Very helpful to debug issues or report problems
    Setting GDB-Server CWD: C:\Users\Amon\.eide\tools\stlink_gdb_server\bin
    Launching gdb-server: "C:\\Users\\Amon\\.eide\\tools\\stlink_gdb_server\\bin\\ST-LINK_gdbserver.exe" -p 50000 -cp "C:\\Users\\Amon\\.eide\\tools\\st_cube_programer\\bin" --swd --halt
        Please check TERMINAL tab (gdb-server) for output from C:\Users\Amon\.eide\tools\stlink_gdb_server\bin\ST-LINK_gdbserver.exe
    Finished reading symbols from objdump: Time: 38 ms
    Finished reading symbols from nm: Time: 41 ms
    Output radix now set to decimal 10, hex a, octal 12.
    Input radix now set to decimal 10, hex a, octal 12.
    warning: Loadable section "RW_IRAM1" outside of ELF segments
    in 
    d:\Amon_Projects_Repository\Learning_Projects_with_git_EIDE_Cubemx\CAN_Loopbcak_Test\EIDE\build\CAN_Loopbcak_Test\CAN_Loopbcak_Test.elf
    0x00000000 in ?? ()
    Program stopped, probably due to a reset and/or halt issued by debugger
    2
    STM32 Successfully completed reset operation (System reset)
    Trying to halt core...
    LiveGDB: Output radix now set to decimal 10, hex a, octal 12.
    LiveGDB: Input radix now set to decimal 10, hex a, octal 12.
    LiveGDB: warning: Loadable section "RW_IRAM1" outside of ELF segments
    in 
    LiveGDB: d:\Amon_Projects_Repository\Learning_Projects_with_git_EIDE_Cubemx\CAN_Loopbcak_Test\EIDE\build\CAN_Loopbcak_Test\CAN_Loopbcak_Test.elf
    LiveGDB: 0x00000000 in ?? ()
    LiveGDB: Program stopped, probably due to a reset and/or halt issued by debugger
    Started live-monitor-gdb session
    warning: could not convert 'main' from the host encoding (CP1252) to UTF-32.
    This normally should not happen, please file a bug report.

    warning: Exception condition detected on fd 484
    kill failed for -48100Error: kill ESRCH
    GDB session ended. exit-code: -1
    GDB never responded to an interrupt request. Trying to end session anyways
    ```

### 解决过程
* 看网上EIDE配置教学视频发现需要：
    在EIDE文件管理右键工程总文件，选择“生成调试器配置模板”；
    ![图片](./images/调试解决1.png)
    这样之后可以调试了，但是调试不是很正常，没有现在运行的指示，也看不到变量的变化；
    
* 问了ai，在回答里面看到是内存有问题，并且出现了熟悉的值“0x20000000”，马上去检查了一下内存设置，发现**keil和EIDE的ROM、RAM顺序是相反的！！！**
* 把它对应上改回来就没问题了

## 11.28 - CAN回环测试失败
### 回环测试收不到数据

### 解决过程：
* 设置断店，看看中断是否调用
    运行发现断点没有命中，判断是中断没有执行
* 检查cubemx配置，发现can的目录下USB打头的中断没有打开，打开后可以成功
* 注意：USB打头的两个中断里面有“or”是和can共享的，非常容易认为与can无关而导致漏设置；

## 11.29
### ozone无法显示图像
 * ozone里面所有数据都是0
### 解决过程：
* jlink版本不对，删除原先的老版本，下载链接里的版本也就是V722b
* 发现还是没有图像
* 注释掉马达驱动的程序，转动电机看看编码器的值
* 发现有图像
* 说明问题在马达驱动的程序里面
* 又通过设置断点知道回调函数只进行了一次（这也就是为什么之前测试的时候速度越来越快）
* 依旧注释掉主要的main函数，直接简单的设定固定值，发现有图像；
* 对比，怀疑是系统时钟的问题
* 试探性地补上HAL_Delay发现可以了，就是设置有一点慢
* 相关代码如下：
```
    while (1) {
        // motor_speed_control(700);
        // HAL_Delay(10);
        if (HAL_GetTick() - last_time >= 10) {

            last_time = HAL_GetTick();
            if (HAL_GetTick() % 1000 == 0) {
                switch (stage) {
                case 0:
                    motor_speed_control(0);
                    stage = 1;
                    break;
                case 1:
                    motor_speed_control(700);
                    stage = 2;
                    break;
                case 2:
                    motor_speed_control(1200);
                    stage = 0;
                    break;
                default:
                    break;
                }
            }
        }

        motor_speed_control(chassis_pid[0].target);
        HAL_Delay(10);
        /* USER CODE END WHILE */

        /* USER CODE BEGIN 3 */
    }
```
#### 总结：
* **在死循环里面加上HAL_Delay()是个好习惯**