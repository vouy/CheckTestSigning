#include <windows.h>
#include <iostream>

void CheckTestSigning()
{
    const char* TestSigning = "bcdedit /enum | findstr /i \"testsigning\"";
    FILE* File = _popen(TestSigning, "r");
    char Buffer[128];
    while (fgets(Buffer, sizeof(Buffer), File))
    {
        if (strstr(Buffer, "testsigning"))
        {
            printf("Test Signing Is Enabled..");
            std::cin.get();
        }
    }
}

int main()
{
    CheckTestSigning();
    std::cin.get();
}