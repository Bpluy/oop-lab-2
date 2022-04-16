#include <algorithm>
#include <iostream>
#include <random>
#include <locale.h>
#include <set>
#include <map>
#include <fstream>
#include <iterator>

#define setLength 10
#define mapLength 10

using namespace::std;

random_device rd;
mt19937 gen(rd());

ofstream outfile("output.txt");

set<int> GenerateSet()
{	
	set<int> intSet;
	for (int i = 0; intSet.size() < setLength; i++)
	{
		intSet.insert(gen() % 1000);
	}
	return intSet;
}
map<int, int> GenerateMap()
{
	map<int, int> intMap;
	for (int i = 0; i < mapLength; i++)
	{
		intMap[i] = gen() % 1000;
	}
	return intMap;
}
set<int> DelByPos(set<int> intSet)
{
	int pos, i = 0;
	cout << "\nВведите позицию элемента множества для его удаления:" << endl;
	cin >> pos;
	set<int>::iterator iterSet = intSet.begin();
	while (iterSet != intSet.end())
	{
		if (i == pos)
		{
			intSet.erase(iterSet);
			break;
		}
		i++;
		iterSet++;
	}
	outfile << "\nМножество после удаления " << pos << "-го элемента:" << endl;
	copy(intSet.begin(), intSet.end(), ostream_iterator<int>(outfile, " "));
	return intSet;
}
set<int> DelByVal(set<int> intSet)
{	
	int val;
	cout << "\nВведите значение элемента множества для его удаления:" << endl;
	cin >> val;
	intSet.erase(intSet.find(val));
	outfile << "\nМножество после удаления элемента " << val << ":" << endl;
	copy(intSet.begin(), intSet.end(), ostream_iterator<int>(outfile, " "));
	return intSet;
}
set<int> AddFirst(set<int> intSet)
{
	set<int> bufSet;
	set<int>::iterator iterSet = intSet.begin();
	while (iterSet != intSet.end())
	{
		bufSet.insert(*iterSet + *(intSet.begin()));
		iterSet++;
	}
	outfile << "\nМножество после увеличения всех элементов на значение первого: " << endl;
	copy(intSet.begin(), intSet.end(), ostream_iterator<int>(outfile, " "));
	return bufSet;
}
map<int, int> SwapMap(map<int, int> intMap)
{
	map<int, int>::iterator iterMap = intMap.begin();
	int maxPos = (*iterMap).first;
	int max = (*iterMap).second;
	int minPos = (*iterMap).first;
	int min = (*iterMap).second;
	while (iterMap != intMap.end())
	{
		if ((*iterMap).second > max)
		{
			maxPos = (*iterMap).first;
			max = (*iterMap).second;
		}
		if ((*iterMap).second < min)
		{
			minPos = (*iterMap).first;
			min = (*iterMap).second;
		}
		iterMap++;
	}
	intMap[minPos] = max;
	intMap[maxPos] = min;
	iterMap = intMap.begin();
	outfile << "\nОтображение после смены максимального и минимального элементов:" << endl;
	while (iterMap != intMap.end())
	{
		outfile << (*iterMap).first << ": " << (*iterMap).second << endl;
		iterMap++;
	}
	return intMap;
}
int main()
{
	setlocale(LC_ALL, "Ru");
	int actionCode, isEnd = 0;

	set<int> intSet;
	intSet = GenerateSet();
	outfile << "Исходное множество:" << endl;
	copy(intSet.begin(), intSet.end(), ostream_iterator<int>(outfile, " "));
	map<int, int> intMap;
	intMap = GenerateMap();
	map<int, int>::iterator iterMap = intMap.begin();
	outfile << "\nИсходное отображение:" << endl;
	while (iterMap != intMap.end())
	{
		outfile << (*iterMap).first << ": " << (*iterMap).second << endl;
		iterMap++;
	}

	while (!isEnd)
	{
		cout << "\nМножество:" << endl;
		copy(intSet.begin(), intSet.end(), ostream_iterator<int>(cout, " "));

		cout << "\n\nОтображение:" << endl;
		iterMap = intMap.begin();
		while (iterMap != intMap.end())
		{
			cout << (*iterMap).first << ": " << (*iterMap).second << endl;
			iterMap++;
		}
		cout << "\nВыберите действие:\n"
			<< "1.\tУдалить элемент множества по позиции\n"
			<< "2.\tУдалить элемент множества по значению\n"
			<< "3.\tУвеличить все элементы множества на значение первого элемента\n"
			<< "4.\tВ отображении поменять местами максимальный и минимальный элементы\n"
			<< "0.\tЗавершить работу программы\n"
			<< endl;
		cin >> actionCode;
		switch (actionCode)
		{
		case 0: {isEnd++; break; }
		case 1: {intSet = DelByPos(intSet); break; }
		case 2: {intSet = DelByVal(intSet); break; }
		case 3: {intSet = AddFirst(intSet); break; }
		case 4: {intMap = SwapMap(intMap); break; }
		default: {cout << "\nВведено неправильное значение. Пожалуйста повторите попытку.\n" << endl; break; }
		}
	}
	outfile << "\nОкончательный вид множества после всех операций:" << endl;
	copy(intSet.begin(), intSet.end(), ostream_iterator<int>(outfile, " "));
	outfile << "\nОкончательный вид отображения после всех операций:" << endl;
	iterMap = intMap.begin();
	while (iterMap != intMap.end())
	{
		outfile << (*iterMap).first << ": " << (*iterMap).second << endl;
		iterMap++;
	}
}
