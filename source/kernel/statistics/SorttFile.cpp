/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   SorttFile.cpp
 * Author: rlcancian
 * 
 * Created on 20 de novembro de 2019, 22:27
 */

#include "SorttFile.h"
#include <fstream>
#include <iostream>
#include <iomanip> 

SortFile::SortFile() {
}

bool SortFile::sort() {
	run(0, _numElements - 1);
	return true; //???
}

void SortFile::setDataFilename(std::string filename) {
	_filename = filename;
	std::ifstream file;
	file.open(_filename, std::ifstream::binary | std::ifstream::in);
	file.seekg(0, file.end); // changed
	_numElements = (file.tellg() / sizeof (double));

}

void SortFile::run(int start, int end) {
	if (start >= end) return;
	int pivot = partition(start, end);
	run(start, pivot - 1);
	run(pivot + 1, end);
}

void SortFile::swap(int position1, int position2) {
	double value1 = getValue(position1);
	double value2 = getValue(position2);
	addValue(value1, position2);
	addValue(value2, position1);
}

int SortFile::partition(int start, int end) {
	int position = start;
	for (int i = start; i < end; i++) {
		if (getValue(i) <= getValue(end)) {
			swap(position++, i);
		}
	}
	swap(position, end);
	return position;
}

double SortFile::getValue(unsigned long position) {
	std::ifstream file;
	double value;
	try {
		file.open(_filename, std::ifstream::binary | std::ifstream::in);
		file.seekg(sizeof (double)*position);
		file.read(reinterpret_cast<char*> (&value), sizeof (double));
		file.close();
	} catch (const std::exception& e) {
		throw "ERROR - can't open the file or get the line ";
	}
	return value;
}

void SortFile::addValue(double value, int position) {
	try {
		std::fstream file(_filename);
		file.seekp(sizeof (double)*position);
		file.write(reinterpret_cast<char*> (&value), sizeof (double));
		file.close();
	} catch (const std::exception& e) {
		throw "ERROR - can't open the file ";
	}
}
