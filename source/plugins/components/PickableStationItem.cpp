/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PickableStationItem.cpp
 * Author: rlcancian
 * 
 * Created on 1 de dezembro de 2022, 14:00
 */

#include "PickableStationItem.h"
#include "../../kernel/simulator/Simulator.h"

PickableStationItem::PickableStationItem(Model* model, std::string stationName, std::string queueName, std::string resourceName) {
	ModelDataDefinition* station = model->getDataManager()->getDataDefinition(Util::TypeOf<Station>(), stationName);
	if (station == nullptr) {
		station = model->getParentSimulator()->getPlugins()->newInstance<Station>(model, stationName);
	}
	ModelDataDefinition* resource = model->getDataManager()->getDataDefinition(Util::TypeOf<Resource>(), resourceName);
	if (resource == nullptr) {
		resource = model->getParentSimulator()->getPlugins()->newInstance<Resource>(model, resourceName);
	}
	ModelDataDefinition* queue = model->getDataManager()->getDataDefinition(Util::TypeOf<Queue>(), queueName);
	if (queue == nullptr) {
		queue = model->getParentSimulator()->getPlugins()->newInstance<Queue>(model, queueName);
	}	
	if (queue != nullptr) {
		PickableStationItem(dynamic_cast<Station*>(station), dynamic_cast<Queue*>(queue));
	} else if (resource != nullptr) {
		PickableStationItem(dynamic_cast<Station*>(station), dynamic_cast<Resource*>(resource));
	}
}

PickableStationItem::PickableStationItem(Model* model, std::string stationName, std::string expression) {
	ModelDataDefinition* station = model->getDataManager()->getDataDefinition(Util::TypeOf<Station>(), stationName);
	if (station == nullptr) {
		station = model->getParentSimulator()->getPlugins()->newInstance<Station>(model, stationName);
	}
	PickableStationItem(dynamic_cast<Station*>(station),expression);
}

PickableStationItem::PickableStationItem(Station* station, Queue* queue) {
	_station = station;
	_queue = queue;
}

PickableStationItem::PickableStationItem(Station* station, Resource* resource) {
	_station = station;
	_resource = resource;
}

PickableStationItem::PickableStationItem(Station* station, std::string expression) {
	_station = station;
	_expression = expression;
}



std::string PickableStationItem::getExpression() const {
	return _expression;
}

Queue* PickableStationItem::getQueue() const {
	return _queue;
}

Resource* PickableStationItem::getResource() const {
	return _resource;
}

Station* PickableStationItem::getStation() const {
	return _station;
}

void PickableStationItem::setExpression(std::string _expression) {
	this->_expression = _expression;
}

void PickableStationItem::setQueue(Queue* _queue) {
	this->_queue = _queue;
}

void PickableStationItem::setResource(Resource* _resource) {
	this->_resource = _resource;
}

void PickableStationItem::setStation(Station* _station) {
	this->_station = _station;
}

