/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   State.cpp
 * Author: cancian
 * 
 * Created on 4 de abril de 2023, 23:08
 */

#include "State.h"

/* **************
 *  PUBLIC
 * **************/

State::State(ColorCA color, char character, double value, std::string name) {
    this->character = character;
    this->doubleValue = value;
    this->color = color;
    this->name = name;
}

State::State(const State& orig) {
    this->name = orig.name;
    this->doubleValue = orig.doubleValue;
}

/* **************
 *  PUBLIC
 * **************/

std::string State::show() {
    std::string m = "value=" + std::to_string((int)doubleValue);
    if (name != "")
        m += ", name=" + name;
    return m;
}

/* **************
 *  PUBLIC
 * **************/


void State::setName(std::string name) {
    this->name = name;
}

std::string State::getName() const {
    return name;
}

void State::setDoubleValue(double value) {
    this->doubleValue = value;
}

double State::getDoubleValue() const {
    return doubleValue;
}

void State::setColor(ColorCA color) {
    this->color = color;
}

ColorCA State::getColor() const {
    return color;
}

void State::setCharacter(char character) {
    this->character = character;
}

char State::getCharacter() const {
    return character;
}

void State::setLongValue(long longValue) {
    this->longValue = longValue;
}

long State::getLongValue() const {
    return longValue;
}


/* **************
 *  PUBLIC
 * **************/

