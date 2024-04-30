/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ExFiStatMac.h
 * Author: rlcancian
 *
 * Created on 7 de agosto de 2022, 12:14
 */

#ifndef EXFISTATMAC_H
#define EXFISTATMAC_H

#include "../../kernel/simulator/ModelDataDefinition.h"
#include "../../kernel/simulator/PluginInformation.h"
#include "../../kernel/util/List.h"

class FSM_State : public PersistentObject_base {
public:

	FSM_State(std::string name, std::string refinementName = "", bool isInitialState = false, bool isFinalState = false) {
		_name = name;
		_refinementName = refinementName;
		_isInitialState = isInitialState;
		_isFinalState = isFinalState;
	}

	void setName(std::string _name) {
		this->_name = _name;
	}

	std::string getName() const {
		return _name;
	}

	void setIsFinalState(bool _isFinalState) {
		this->_isFinalState = _isFinalState;
	}

	bool isFinalState() const {
		return _isFinalState;
	}

	void setIsInitialState(bool _isInitialState) {
		this->_isInitialState = _isInitialState;
	}

	bool isInitialState() const {
		return _isInitialState;
	}

	void setRefinementName(std::string _refinementName) {
		this->_refinementName = _refinementName;
	}

	std::string getRefinementName() const {
		return _refinementName;
	}
private:
	std::string _name;
	std::string _refinementName;
	bool _isInitialState;
	bool _isFinalState;
};

class FSM_Transition : public PersistentObject_base {
public:

	struct TransitionType {
		bool isdefault = false;
		bool nondeterministic = false;
		bool immediatbe = false;
		bool preemptive = false;
		bool history = false;
		bool error = false;
		bool termination = false;
	};
public:

	FSM_Transition(std::string parameterName, FSM_State* originState, FSM_State* destinationState, std::string guardExpression = "", TransitionType* transitionType = nullptr) {
		_parameterName = parameterName;
		_originState = originState;
		_destinationState = destinationState;
		_guardExpression = guardExpression;
		if (transitionType == nullptr)
			transitionType = new TransitionType();
		_type = transitionType;
	}
private:
	std::string _parameterName;
	std::string _guardExpression;
	FSM_State* _originState;
	FSM_State* _destinationState;
	TransitionType* _type;
	List<std::string*>* _outputActions = new List<std::string*>();
	List<std::string*>* _setActions = new List<std::string*>();
};

class ExtendedFSM : public ModelDataDefinition {
public:
	ExtendedFSM(Model* model, std::string name = "");
	virtual ~ExtendedFSM() = default;
public: // static
	static ModelDataDefinition* LoadInstance(Model* model, PersistenceRecord *fields);
	static PluginInformation* GetPluginInformation();
	static ModelDataDefinition* NewInstance(Model* model, std::string name = "");
public:
	virtual std::string show();
protected: // must be overriden 
	virtual bool _loadInstance(PersistenceRecord *fields);
	virtual void _saveInstance(PersistenceRecord *fields, bool saveDefaultValues);
protected: // could be overriden .
	virtual bool _check(std::string* errorMessage);
	virtual void _initBetweenReplications();
	virtual void _createInternalAndAttachedData();
	//virtual ParserChangesInformation* _getParserChangesInformation();
private:

	const struct DEFAULT_VALUES {
		const std::string someString = "Test";
		const unsigned int someUint = 1;
	} DEFAULT;
	std::string _someString = DEFAULT.someString;
	unsigned int _someUint = DEFAULT.someUint;
	List<FSM_State*>* _states = new List<FSM_State*>();
	List<FSM_Transition*>* _transitions = new List<FSM_Transition*>();

};

#endif /* EXFISTATMAC_H */

