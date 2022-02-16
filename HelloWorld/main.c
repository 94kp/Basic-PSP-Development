#include <pspkernel.h>
#include <pspdebug.h>

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
    int thid = sceKernelCreateThread("update_thread", callbackThread, 0x11, 0xFA0, 0, NULL);
    if (thid >= 0)
    {
        sceKernelStartThread(thid, 0, NULL);
    }
}

int main()
{
    int i = 1;
    setupCallbacks();
    pspDebugScreenInit();

    while(i <= 10)
    {
        pspDebugScreenPrintf("Hello for the %dth time!\n", i);
        i++;
    }

    pspDebugScreenPrintf("\n\nHello Karan, PSP here!");
}