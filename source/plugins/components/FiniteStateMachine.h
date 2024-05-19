/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   FiniteStateMachine.h
 * Author: rlcancian
 *
 * Created on 7 de agosto de 2022, 12:16
 */

#ifndef FINITESTATEMACHINE_H
#define FINITESTATEMACHINE_H

#include "../../kernel/simulator/ModelComponent.h"
#include "../data/EFSM.h"

/*!
 This component ...
 */
	class FiniteStateMachine : public ModelComponent {
public: // constructors
	FiniteStateMachine(Model* model, std::string name = "");
	virtual ~FiniteStateMachine() = default;
public: // virtual
	virtual std::string show();
public: // static
	static PluginInformation* GetPluginInformation();
	static ModelComponent* LoadInstance(Model* model, PersistenceRecord *fields);
	static ModelDataDefinition* NewInstance(Model* model, std::string name = "");
	ExtendedFSM* getInternalDataDefinition(){
		return _internalDataDefinition;
	}
	virtual void _createInternalAndAttachedData();
protected: // must be overriden 
	virtual bool _loadInstance(PersistenceRecord *fields);
	virtual void _saveInstance(PersistenceRecord *fields, bool saveDefaultValues);
	virtual void _onDispatchEvent(Entity* entity, unsigned int inputPortNumber);
protected: // could be overriden .
	virtual bool _check(std::string* errorMessage);
	virtual void _initBetweenReplications();
	//virtual void _createInternalAndAttachedData();
	//virtual ParserChangesInformation* _getParserChangesInformation();
private: // methods

public:
	ExtendedFSM* _internalDataDefinition = nullptr;
	

private: // attributes 1:1

	const struct DEFAULT_VALUES {
		const std::string someString = "Test";
		const unsigned int someUint = 1;
	} DEFAULT;
	std::string _someString = DEFAULT.someString;
	unsigned int _someUint = DEFAULT.someUint;
	//ExtendedFSM* _internalDataDefinition = nullptr;
private: // attributes 1:n
};

#endif /* FINITESTATEMACHINE_H */

