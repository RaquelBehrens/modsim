/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Exact.h
 * Author: rlcancian
 *
 * Created on 12 de agosto de 2021, 18:55
 */

#ifndef Exact_H
#define Exact_H

#include <iostream>
#include <iomanip>

class Exact {
	//friend ostream &operator<<(ostream&, const Exact &);
	//friend istream &operator>>(istream&, Exact &);
public:

	Exact() {
	};

	Exact(int num, int den = 1) {
		_num = num;
		_den = den;
	};

	const Exact &operator+(const Exact &right) {
		Exact e;
		e._num = this->_num * right._den + right._num * this->_den;
		e._den = this->_den * right._den;
		return &e;
	}

	const Exact &operator+=(const Exact &right) {
		this->_num = this->_num * right._den + right._num * this->_den;
		this->_den *= right._den;
	}

	const Exact &operator-=(const Exact &right) {
		this->_num = this->_num * right._den - right._num * this->_den;
		this->_den *= right._den;
	}

	const Exact &operator*=(const Exact &right) {
		this->_num *= right._num;
		this->_den *= right._den;
	}

	const Exact &operator/=(const Exact &right) {
		this->_num *= right._num;
		this->_den *= right._den;
	}

	const Exact &operator=(const Exact &right) {
		this->_num = right._num;
		this->_den = right._den;
	}

	const Exact &operator=(const int &right) {
		this->_num = right;
		this->_den = 1;
	}

	bool operator==(const Exact &right) {
		// verify proportionality is missing
		return (this->_num == right._num) && (this->_den == right._den);
	}

	bool operator==(const double &right) {
		// verify proportionality is missing
		return (this->_num / this->_den) == right;
	}

	bool operator<(const Exact &right) {
		// verify proportionality is missing
		return (this->_num / this->_den) < (right._num / right._den);
	}

	bool operator<(const double &right) {
		// verify proportionality is missing
		return (this->_num / this->_den) < right;
	}

	bool operator<=(const Exact &right) {
		// verify proportionality is missing
		return (this->_num / this->_den) <= (right._num / right._den);
	}

	bool operator<=(const double &right) {
		// verify proportionality is missing
		return (this->_num / this->_den) <= right;
	}

	bool operator>(const Exact &right) {
		// verify proportionality is missing
		return (this->_num / this->_den) > (right._num / right._den);
	}

	bool operator>(const double &right) {
		// verify proportionality is missing
		return (this->_num / this->_den) > right;
	}

	bool operator>=(const Exact &right) {
		// verify proportionality is missing
		return (this->_num / this->_den) >= (right._num / right._den);
	}

	bool operator>=(const double &right) {
		// verify proportionality is missing
		return (this->_num / this->_den) >= right;
	}

	void Simplify() {
	}

	double toFloat() {
		return _num / _den;
	};
protected:
private:
	double _num, _den;
};


/*
ostream &operator<<(ostream &output, const Exact &num) {
	output << num._num << "/" << num._den;
	return output;
}

/*
istream &operator>>(istream &input, Exact &num) {
	input >> num._num;
	input >> num._dem;
	return input;
}
 */


#endif /* Exact_H */

