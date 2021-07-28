#include <iostream>

using namespace std;

bool isBinary(string str);
bool follows(string str);

int main()
{
    cout << "This program determines whether a binary string obeys the following rule: " << endl << "There are an even number of 0's or 1's in the binary string " << endl << endl;

    string q;

    cout << "Enter a binary string: ";
    for(cin >> q; !isBinary(q); cin >> q)
        cout << endl << "Sorry! The string you have entered is not binary. " << endl << "Please make sure that each character is either a 0 or a 1. " << endl << "Please try again. " << endl << endl << "Enter another binary string: ";

    cout << endl;

    int index;

    cout << "The following binary string " << (follows(q) ? "obeys": "does not obey") << " the rule of containing only even number of 0's or 1's. " << endl << endl;

    return 0;
}

bool isBinary(string str)
{
    for(int count = 0; count < str.length(); count++)
        if(str[count] != '0' && str[count] != '1')
            return false;

    return true;
}

//Initial and final state are the same as q0
bool follows(string str)
{
    //Initial state with index = 0 as q[0] is state q0
    int index = 0;
    char alpha;

    bool indicator = false;

    for(int count = 0; count < str.length(); count++)
    {
        alpha = str[count];
        //Transition states are implemented as switch cases where the index represents the state as q[index]
        switch(index)
        {
            case 0:
                //0,1 indicates the same state transition
                index = 1;

                break;

            case 1:
                if(alpha == '0')
                    index = 3;
                else
                    index = 2;

                break;

            case 2:
                //State transition due to epsilon
                index = 4;

                //Transition occurs to same state as 1

                if(alpha == '1')
                    index = 6;

                break;

            case 3:
                //State transition due to epsilon
                index = 5;

                //Transition occurs to same state as 0

                if(alpha == '0')
                    index = 7;

                break;

            case 4:
                if(alpha = '0')
                    index = 4;
                else
                    index = 6;

                break;

            case 5:
                if(alpha == '0')
                    index = 7;
                else
                    index = 5;

                break;

            case 6:
                //Transition occurs to same state if 0 as input

                if(alpha == '1')
                    index = 4;

                break;

            case 7:
                //Transition occurs to same state if 1 as input

                if(alpha == '0')
                    index = 5;

                break;

            default:
                cout << "Sorry! There is an error in your choice of input. " << endl;
        }
        //End of Transition table definition

        //Final state with index = 0 as q[0] as state q0
    }

    if(index > 1 && index < 6)
        return true;

    return false;
}
