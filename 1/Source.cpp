#include <algorithm>
#include <iostream>
#include <vector>	
#include <cmath>
#include <bitset>
#include <random>
#include <locale.h>

#define Length 10

using namespace::std;

bool bitComp(bitset<32>& a, bitset<32>& b)
{
	return (int)a.to_ulong() < (int)b.to_ulong();
}

vector<bitset<32>> generate(vector<bitset<32>> bitVector)
{
	random_device rd;
	mt19937 gen(rd());

	for (int i = 0; i < Length; i++)
	{
		bitVector.push_back(gen());
		cout << "BIN: " << bitVector.back() <<
			"\tHEX: " << hex << (int)bitVector.back().to_ulong() << 
			"\tDEC: " << dec << (int)bitVector.back().to_ulong() << endl;
	}
	return bitVector;
}

void output(vector<bitset<32>> bitVector)
{	
	for (auto i = bitVector.begin(); i < bitVector.end(); i++)
	{				
		cout << "BIN: " << *i <<
			"\tHEX: " << hex << (int)(*i).to_ulong() <<
			"\tDEC: " << dec << (int)(*i).to_ulong() << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Ru");
	vector<bitset<32>> bitVector;
	bitVector = generate(bitVector);
	try
	{
		if (bitVector.size() == 0)
			throw 0;
		auto min = min_element(bitVector.begin(), bitVector.end(), bitComp);
		auto max = max_element(bitVector.begin(), bitVector.end(), bitComp);

		cout << endl;
		cout << "MIN BIN: " << *min <<
			"\tHEX: " << hex << (int)(*min).to_ulong() <<
			"\tDEC: " << dec << (int)(*min).to_ulong() << endl;
		cout << "MAX BIN: " << *max <<
			"\tHEX: " << hex << (int)(*max).to_ulong() <<
			"\tDEC: " << dec << (int)(*max).to_ulong() << endl;
		cout << endl;

		swap(bitVector[distance(bitVector.begin(), min)], bitVector[distance(bitVector.begin(), max)]);

		output(bitVector);
	}
	catch(int i)
	{
		cout << "Ошибка " << i << "- в векторе нет элементов. Значение Lenght должно быть не менее 1."<<endl;
	}
}