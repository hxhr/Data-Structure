#include<iostream>
using namespace std;
int main()
{
    char array[100000];
    int sum = 0;
    int fin[100000] = { 0 };

   
    for (int i = 0; cin.getline(array, 100000) && array[0] != '#'; i++) {
        if (array[0] == '\r'||array[0]=='\0') {
            i = i - 1;
            continue;
        }
        sum = 0;
        for (int m = 0; array[m] != '\0'; m++) {
            if (array[m] >= 'A' && array[m] <= 'Z') sum += (m + 1) * (array[m] - 'A' + 1);

        }
        fin[i] = sum;
    }


    for (int i = 0; fin[i] != 0; i++) {
        cout << fin[i] << '\n';
    }

    return 0;
}

