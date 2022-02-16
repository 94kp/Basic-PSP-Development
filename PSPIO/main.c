#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>

PSP_MODULE_INFO("Tutorial", 0, 1, 0);

int exit_callback(int arg1, int arg2, void* common)
{
    sceKernelExitGame();
    return 0;
}

int callbackThread(SceSize args, void* argp)
{
    int cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
    sceKernelRegisterExitCallback(cbid);

    sceKernelSleepThreadCB();

    return 0;
}

int setupCallbacks()
{
    int thid = sceKernelCreateThread("update thread", callbackThread, 0x11, 0xFA0, 0, NULL);

    if (thid >= 0)
    {
        sceKernelStartThread(thid, 0, NULL);
    }
}

int main()
{
    setupCallbacks();
    pspDebugScreenInit();

    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

    struct SceCtrlData ctrlData;

    while(1)
    {
        sceCtrlReadBufferPositive(&ctrlData, 1);

        if (ctrlData.Buttons & PSP_CTRL_CROSS)
        {
            pspDebugScreenPrintf("CROSS PRESSED!\n");
        }

        else if (ctrlData.Buttons & PSP_CTRL_CIRCLE)
        {
            pspDebugScreenPrintf("CIRCLE PRESSED!\n");
        }

        else if (ctrlData.Buttons & PSP_CTRL_TRIANGLE)
        {
            pspDebugScreenPrintf("TRIANGLE PRESSED!\n");
        }

        else if (ctrlData.Buttons & PSP_CTRL_SQUARE)
        {
            pspDebugScreenPrintf("SQUARE PRESSED!\n");
        }

        else if(ctrlData.Lx & PSP_CTRL_MODE_ANALOG)
        {
            pspDebugScreenPrintf("Analog stick moved to the left!!\n");
        }

    }
}
