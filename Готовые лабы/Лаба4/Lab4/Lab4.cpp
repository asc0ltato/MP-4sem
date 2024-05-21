#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>  

using namespace std;

string RandomString(int len)
{
    string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string newstr;
    int pos;
    for (int i = 0; i < len; i++) {
        pos = rand() % str.size();
        newstr += str[pos];
    }
    return newstr;
}

int main()
{
    srand(time(0));

    cout << "String 300:" << endl;
    string random_str = RandomString(300);
    cout << random_str << endl << endl;

    cout << "String 200:" << endl;
    random_str = RandomString(200);
    cout << random_str << endl << endl;

    system("pause");
    return 0;
}