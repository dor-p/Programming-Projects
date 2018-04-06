#define _WIN32_WINNT 0x0500
#include <windows.h>

// Locking the computer if password is wrong using WinApi

int main()
{
    int pass;

    printf("Enter a password:\n");
    scanf(" %d", &pass);

    if(pass != 12345)
    {
        return LockWorkStation();
    }

    else if(pass == 12345)
    {
        printf("Success! keep on working\n");
    }

    return 0;

}
