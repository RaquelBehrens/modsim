/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   FiniteStateMachine.cpp
 * Author: rlcancian
 * 
 * Created on 7 de agosto de 2022, 12:16
 */

#include "FiniteStateMachine.h"

#include "../../kernel/simulator/Model.h"
#include "../../kernel/simulator/Simulator.h"
#include "../../kernel/simulator/PluginManager.h"

#ifdef PLUGINCONNECT_DYNAMIC

extern "C" StaticGetPluginInformation GetPluginInformation() {
	return &FiniteStateMachine::GetPluginInformation;
}
#endif

ModelDataDefinition* FiniteStateMachine::NewInstance(Model* model, std::string name) {
	return new FiniteStateMachine(model, name);
}

FiniteStateMachine::FiniteStateMachine(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<FiniteStateMachine>(), name) {
}

std::string FiniteStateMachine::show() {
	return ModelComponent::show() + " asdasdad";
}

// public static 

ModelComponent* FiniteStateMachine::LoadInstance(Model* model, PersistenceRecord *fields) {
	FiniteStateMachine* newComponent = new FiniteStateMachine(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

PluginInformation* FiniteStateMachine::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<FiniteStateMachine>(), &FiniteStateMachine::LoadInstance, &FiniteStateMachine::NewInstance);
	info->setDescriptionHelp("//@TODO");
	return info;
}

// protected virtual -- must be overriden

void FiniteStateMachine::_onDispatchEvent(Entity* entity, unsigned int inputPortNumber) {
	trace("I'm just a dummy model and I'll just send the entity forward");
	this->_parentModel->sendEntityToComponent(entity, this->getConnections()->getFrontConnection());
}

bool FiniteStateMachine::_loadInstance(PersistenceRecord *fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		// @TODO: not implemented yet
	}
	return res;
}

void FiniteStateMachine::_saveInstance(PersistenceRecord *fields, bool saveDefaultValues) {
	ModelComponent::_saveInstance(fields, saveDefaultValues);
	// @TODO: not implemented yet
}


// protected virtual -- could be overriden 

//ParserChangesInformation* DummyElement::_getParserChangesInformation() {}

bool FiniteStateMachine::_check(std::string* errorMessage) {
	bool resultAll = true;
	resultAll &= _someString != "";
	resultAll &= _someUint > 0;
	return resultAll;
}

void FiniteStateMachine::_initBetweenReplications() {
	_someString = "Test";
	_someUint = 1;
}

void FiniteStateMachine::_createInternalAndAttachedData() {
	if (_internalDataDefinition == nullptr) {
		PluginManager* pm = _parentModel->getParentSimulator()->getPlugins();
		_internalDataDefinition = pm->newInstance<ExtendedFSM>(_parentModel, getName() + "." + "efsm");
		_internalDataInsert("JustaDummy", _internalDataDefinition);
	}
}

