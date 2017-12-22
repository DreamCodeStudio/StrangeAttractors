#include <iostream>

#include "../Header/App/App.h"

int main()
{
    /* Create Application */
    App Application;
    Application.Create();

    /* Run Application */
    while(Application.IsOpen())
    {
        Application.Run();
    }

    return 0;
}