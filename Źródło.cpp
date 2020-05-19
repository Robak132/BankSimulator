#include "Stand.h"
#include "ID.h"
#include <iostream>

using namespace std;

int main()
{
    //Client marek("MArek", "Nazwisko", "ABC123", ID(200001), numt::clientToAccount, 200);
    //TransferO trans(&marek);
    ATMin object;                       // Jak ju¿ bêdzie klient to bêdzie dzia³aæ.
    ATMout object_another;
    try
    {
        object.performOperation(numt::accountToClient);
        object_another.performOperation(numt::accountToClient);
    }
    catch (BadOperation e)
    {
        cout << e << endl;
    }
    catch (NoClient e)
    {
        cout << e << endl;
    }
    cout << object.getWorkTime() << endl;
    cout << object_another.getWorkTime() << endl;
}

