// C++ program to find repeating sequence in a fraction

#include <bits/stdc++.h>

using namespace std;

// This function returns repeating sequence of

// a fraction. If repeating sequence doesn't

// exits, then returns empty string

string fractionToDecimal(int numr, int denr)

{

string res,str; // Initialize result

// Create a map to store already seen remainders

map <int, bool> mp;

mp.clear();

// Find first remainder

int rem = numr%denr;

// Keep finding remainder until either remainder

// becomes 0 or repeats

while ( (rem!=0) )

{

if (mp.find(rem) == mp.end()){

// Store this remainder

mp[rem] = 1;

// Multiply remainder with 10

rem = rem*10;

// Append rem / denr to result

int res_part = rem / denr;

res += to_string(res_part);

// Update remainder

rem = rem % denr;

}

else{

int res_part = (rem*10)/denr;

str.assign(to_string(res_part));

std::size_t pos = res.find(str);

res = res.substr (pos);

break;

}

}

return (rem == 0)? "": res;

}

// Driver code

int main()

{

int numr = 57, denr = 74;

string res = fractionToDecimal(numr, denr);

if (res == "")

cout << "No recurring sequence";

else

cout << "Recurring sequence is " << res;

return 0;

}
