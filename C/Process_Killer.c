#include <windows.h>
#include <process.h>
#include <Tlhelp32.h>
#include <winbase.h>
#include <string.h>

//Using WinApi to scan active processes and if calc.exe is active - kill it.


void killProcessByName(const char *filename)
{
    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);// Taking a Snapshot and Viewing Processes
    PROCESSENTRY32 pEntry; //stores an entry from the snapshot list
    pEntry.dwSize = sizeof (pEntry);// The size of the structure in bytes.
    BOOL hRes = Process32First(hSnapShot, &pEntry); // checks if the first value from the process list is in the snapshot(true if yes)
    while (hRes)
    {
        if (strcmp(pEntry.szExeFile, filename) == 0) // if the process that exist in the list is equal to the process we want to terminate..
        {
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0,
                                          (DWORD) pEntry.th32ProcessID); // Opens an existing local process object to terminate

            if (hProcess != NULL)
            {
                printf("Process found and killed\n");
                TerminateProcess(hProcess, 9);//Terminates the specified process and all of its threads.
                CloseHandle(hProcess);//Closes an open object handle - hProcess
            }
        }
        hRes = Process32Next(hSnapShot, &pEntry);//moving to the next process in the list
    }
    CloseHandle(hSnapShot);
    printf("Scan Completed\n");
}

int main()
{

    killProcessByName("calc.exe");

    return 0;
}
