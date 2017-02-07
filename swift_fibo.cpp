#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cctype>

using namespace std;

bool chkprime(int n) {
	if(n <= 1) return false;
	if(n==2) return true;
	for(int i=2; i < n; i++){
		if(n%i == 0 ) return false;
	}
	return true;

}
const vector<int>& F(int n) {
	int f0 = 0, f1 = 1, tmp, i = 0;
	vector<int> fibo; fibo.push_back(f0); fibo.push_back(f1);
	while(i++ < n){
		tmp  = f1;
		f1 = f0+f1;
		f0  = tmp;
		fibo.push_back(f1);		
	}
	return fibo;
}

void dispfibo (const vector<int>& fibo) {
	cout << endl;
	for(int i=0; i <fibo.size(); i++){
		if(fibo[i]%15==0) cout << "FizzBuzz " ;
		else if(fibo[i]%5==0) cout << "Fizz ";		
		else if(fibo[i]%3==0) cout << "Buzz ";
		else if(chkprime(fibo[i])) cout << "BuzzFizz ";
		else {cout << fibo[i] << " ";}				
	}
	cout << endl;
	return;

}

int main(){
/*In the programming language of your choice, write a program generating the first n Fibonacci numbers F(n), printing

"Buzz" when F(n) is divisible by 3.
"Fizz" when F(n) is divisible by 5.
"FizzBuzz" when F(n) is divisible by 15.
"BuzzFizz" when F(n) is prime.
the value F(n) otherwise.
*/
int n;
cout << "\nEnter the value n: " ; 
cin >> n;

dispfibo(F(n));
return 0;
}
