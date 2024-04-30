/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   SorttFile.h
 * Author: rlcancian
 *
 * Created on 20 de novembro de 2019, 22:27
 */

#ifndef SORTTFILE_H
#define SORTTFILE_H

#include <string>

class SortFile {
public:
	SortFile();
	~SortFile() = default;
public:
	/*!
	 * \brief sort
	 * \return
	 */
	bool sort();
	/*!
	 * \brief setDataFilename
	 * \param filename
	 */
	void setDataFilename(std::string filename);
private:
	void run(int start, int end);
	void swap(int position1, int position2);
	int partition(int start, int end);
	void addValue(double value, int position);
	double getValue(unsigned long position);
private:
	std::string _filename;
	double _numElements = 0;
};

#endif /* SORTTFILE_H */

