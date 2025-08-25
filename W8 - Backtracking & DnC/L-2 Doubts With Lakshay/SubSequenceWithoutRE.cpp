#include<iostream>
using namespace std; 
void subsqn(string str)
{
    int num_sub = pow(2, str.size());

    for (int n = 0; n < num_sub; n++)
    {
        string out;
        int num = n;

        int i = 0;
        while (num)
        {
            int b = (num & 1);
            if (b)
                out.push_back(str[i]);
            i++;
            // cout << b << " ";
            num >>= 1;
        }
        cout << out << endl; 
    }
}

int main() 
{ 
    string str = "";
    cout << "Enter An String: "; 
    getline(cin, str);

    subsqn(str);
    return 0; 
}