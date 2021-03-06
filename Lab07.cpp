// Lab07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void print_set(vector<int> set){
	for (int i=0; i<set.size(); i++){
		if (set[i]!=0){
			cout << i << " ";
		}
	}
	cout << endl;
}

void add_elements(vector<int> &set, int num_elements){
	int tmp;for (int i=0; i<num_elements; i++){
		cin >> tmp;set[tmp] = 1;
	}
}

void set_union(vector<int> &set1, vector<int> &set2){
	vector<int> result;
	set_union(set1.begin(), set1.end(),
		set2.begin(), set2.end(),
		std::back_inserter(result));

	for (const auto &i : result) {
		std::cout << i << ' ';
	}
	cout << '\n';
}

void set_difference(vector<int> &set1, vector<int> &set2){
	vector<int> result;
	set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),inserter(result, result.begin()));

	for (auto i : set1) std::cout << i << ' ';
	std::cout << "minus ";
	for (auto i : set2) std::cout << i << ' ';
	std::cout << "is: ";
	for (auto i : result) std::cout << i << ' ';
	std::cout << '\n';
}

void set_intersection(vector<int> &set1, vector<int> &set2){
	int size = 1000000;
	cout << "Intersection: ";
	for (int i=0; i<1000000; i++){
		if (set1[i] && set2[i]){
			cout << i << " ";
		}
	}
}

int main(){
	int tmp = 0;
	int array_max_size = 1000000;
	
	cout << "Enter size of desired array for vector1: " << endl;
	cin >> tmp;
	vector<int> set1(tmp, 0);

	cout << "Enter size of desired array for vector2: " << endl;
	cin >> tmp;
	vector<int> set2(tmp, 0);
	
	add_elements(set1, 5);
	add_elements(set2, 6);
	print_set(set1);
	print_set(set2);
	set_intersection(set1, set2);
	set_union(set1, set2);
	print_set(set1);
	print_set(set2);
	set_difference(set1, set2);
	print_set(set1);
	print_set(set2);
}


