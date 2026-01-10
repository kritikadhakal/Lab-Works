//Prediction of future weather condition using Markov's chain
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float P[3][3] = {
        {0.6, 0.3, 0.1},
        {0.3, 0.4, 0.3},
        {0.2, 0.3, 0.5}
    };

    float state[3] = {1, 0, 0};   // Sunny today
    float nextState[3];

    int days;
    cout << "Enter number of days to predict: ";
    cin >> days;

    cout << fixed << setprecision(2);

    for(int d = 1; d <= days; d++)
    {
        for(int i = 0; i < 3; i++)
        {
            nextState[i] = 0;
            for(int j = 0; j < 3; j++)
            {
                nextState[i] += state[j] * P[j][i];
            }
        }

        for(int i = 0; i < 3; i++)
            state[i] = nextState[i];

        cout << "\nDay " << d << " Prediction:\n";
        cout << "Sunny   : " << state[0] * 100 << "%\n";
        cout << "Cloudy : " << state[1] * 100 << "%\n";
        cout << "Rainy  : " << state[2] * 100 << "%\n";
    }

    return 0;
}
