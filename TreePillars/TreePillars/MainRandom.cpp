#include <iostream>
#include <time.h>
#include <array>
#include <vector>
#include <algorithm>
#include "MainRandom.h"
#include <windows.h>


int GetRandomNumber(int start_range, int finish_range) {
	srand(time(NULL));
	int num = start_range + rand() % (finish_range - start_range + 1);
	return num;
}

std::vector<int> Mode_№1(int start_range, int finish_range) {
	std::vector<int> RandomArray={GetRandomNumber(start_range, finish_range) };
	return RandomArray;
}

std::vector<int> Mode_№2(std::vector<int> given_array) {
	int size= given_array.size()-1;
	std::vector<int> RandomArray={given_array[GetRandomNumber(0, size)]};
	return RandomArray;
}

std::vector<int> Mode_№3(int start_range, int finish_range, std::vector<int> exception) {
	std::vector<int> RandomArray;
	int i = start_range;
	while (i != finish_range + 1) {
		RandomArray.push_back(i);
		i++;
	}
	for (auto it = RandomArray.begin(); it != RandomArray.end();) {
		if (std::find(exception.begin(), exception.end(), *it) != exception.end()) {
			it = RandomArray.erase(it);
		}
		else {
			++it;
		}
	}
	return Mode_№2(RandomArray);
}

std::vector<int> Mode_№4(int start_range, int finish_range, int count_of_random_elements) {
	std::vector<int> RandomArray;
	if (count_of_random_elements > finish_range - start_range + 1) {
		std::cout << "Генерация такого массива невозможна";
		return RandomArray;
	}
	
	std::vector<int> exception;
	for (int i = 0; i < count_of_random_elements; ++i) {
		int a = Mode_№3(start_range, finish_range, exception)[0];
		exception.push_back(a);
		RandomArray.push_back(a);
	}
	return RandomArray;
}

std::vector<int> Mode_№5(int start_range, int finish_range, int count_of_random_elements, std::vector<int> exception) {
	std::vector<int> RandomArray;
	if (count_of_random_elements > finish_range - start_range + 1) {
		std::cout << "Генерация такого массива невозможна";
		return RandomArray;
	}

	for (int i = 0; i < count_of_random_elements; ++i) {
		int a = Mode_№3(start_range, finish_range, exception)[0];
		exception.push_back(a);
		RandomArray.push_back(a);
	}
	return RandomArray;
}


std::vector<int> MyRandom(int mode, int start_range, int finish_range, int count_of_random_elements, std::vector<int> given_array, std::vector<int> exception, bool sorted) {
	switch (mode)
	{
	case 1:
		return Mode_№1(start_range, finish_range);
		break;
	case 2:
		return Mode_№2(given_array);
		break;
	case 3:
		return Mode_№3(start_range, finish_range, exception);
		break;
	case 4:
		if (sorted) {
			std::vector<int> vec = Mode_№4(start_range, finish_range, count_of_random_elements);
			std::sort(vec.begin(), vec.end());
			return vec;
		}
		return Mode_№4(start_range, finish_range, count_of_random_elements);
		break;
	case 5:
		if (sorted) {
			std::vector<int> vec = Mode_№5(start_range, finish_range, count_of_random_elements, exception);
			std::sort(vec.begin(), vec.end());
			return vec;
		}
		return Mode_№5(start_range, finish_range, count_of_random_elements, exception);
		break;
	default:
		std::cout << "Неверно задан режим";
		break;
	}
}





