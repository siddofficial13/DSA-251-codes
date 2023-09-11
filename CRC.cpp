#include <bits/stdc++.h>
using namespace std;

string xor1(string a, string b)
{
    int n = b.size();
    string result = "";
    for (int i = 1; i < n; i++)
    {
        if (a[i] == b[i])
            result += "0";
        else
            result += "1";
    }

    return result;
}

string mod2div(string dividend, string divisor)
{
    int pick = divisor.size();
    int n = dividend.size();
    string temp = dividend.substr(0, pick);

    while (pick < n)
    {
        if (temp[0] == '1')
            temp = xor1(divisor, temp) + dividend[pick];
        else
            temp = xor1(string(pick, '0'), temp) + dividend[pick];
        pick++;
    }

    if (temp[0] == '1')
        temp = xor1(divisor, temp);
    else
        temp = xor1(string(pick,'0'), temp);

    return temp;
}
string encodedata(string sdata, string key)
{

    int l = key.length();

    string data = sdata + string(l - 1, '0');
    string remainder = mod2div(data, key);

    return sdata + remainder;
}
int main()
{

    string sdata, key;

    int op1;
    cout << "enter 1 for crc 12" << endl;
    cout << "enter 2 for crc 16" << endl;
    cout << "enter 3 for crc 32" << endl;
    cin >> op1;
    switch (op1)
    {
        case 1:
            key = "1100000001111";
            break;
        case 2:
            key = "11000000000000101";
            break;
        case 3:
            key = "100000100110000010001110110110101";
    }
    cin >> sdata;

    string encoded = encodedata(sdata, key);
    cout << encoded << endl;

    string rdata;
    cin >> rdata;

    string r_remainder = mod2div(rdata, key);

    bool flag = false;
    for (int i = 0; i < key.size() - 1; i++)
        if (r_remainder[i] == '1')
        {
            flag = true;
            break;
        }

    if (flag)
        cout << "error in recieved data" << endl;
    else
        cout << "no error in recieved data" << endl;
    return 0;
}
