/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Event.cpp
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Junho de 2018, 19:41
 */

#include "Event.h"

//using namespace GenesysKernel;

Event::Event(double time, Entity* entity, ModelComponent* component, unsigned int componentinputPortNumber) {
	_time = time;
	_entity = entity;
	_component = component;
	_componentinputPortNumber = componentinputPortNumber;
}

Event::Event(double time, Entity* entity, Connection* connection) {
	_time = time;
	_entity = entity;
	_component = connection->component;
	_componentinputPortNumber = connection->channel.portNumber;
}

std::string Event::show() {
	std::string message = "time=" + std::to_string(_time) + //Util::StrTimeUnit(???)+
			",entity=" + _entity->getName() + //std::to_string(_entity->entityNumber()) +
			",component=\"" + _component->getName() + "\"<"+_component->getClassname()+">"; //+std::to_string(_component->getId())+"}";
	if (this->_componentinputPortNumber > 0) {
		message += ",input=" + std::to_string(this->_componentinputPortNumber);
	}
	return message;
}

void Event::setEntity(Entity* _entity) {
	this->_entity = _entity;
}

unsigned int Event::getComponentinputPortNumber() const {
	return _componentinputPortNumber;
}

double Event::getTime() const {
	return _time;
}

ModelComponent* Event::getComponent() const {
	return _component;
}

Entity* Event::getEntity() const {
	return _entity;
}
