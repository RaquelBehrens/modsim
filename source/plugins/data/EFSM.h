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

#ifndef EFSM_H
#define EFSM_H

#include "../../kernel/simulator/ModelDataDefinition.h"
#include "../../kernel/simulator/PluginInformation.h"
#include "../../kernel/simulator/Attribute.h"
#include "../data/AssignmentItem.h"
#include "../data/Variable.h"
#include "../../kernel/util/List.h"
#include "../components/FSM_Transition.h"
#include "../components/FSM_State.h"
#include <vector>
#include <map>
#include <string>

class FSM_State;

class ExtendedFSM : public ModelDataDefinition {
public: /// constructors
    ExtendedFSM(Model* model, std::string name = "");
    virtual ~ExtendedFSM() = default;

public: /// new public user methods for this component
    std::vector<Variable*>* getVariables() {
         return _variables;
    }

    std::string getCurrentState();

    void setInitialState(FSM_State* state);
    
    void insertVariable(Variable* variable);
    void enterEFSM(Entity* entity, ModelComponent* returnState);
    void leaveEFSM(Entity* entity, FSM_State* newCurrentState);
    void reset();
 
private:
    void setCurrentState(FSM_State* state);

public: /// virtual public methods
    virtual std::string show();

public: /// static public methods that must have implementations (Load and New just the same. GetInformation must provide specific infos for the new component
    static PluginInformation* GetPluginInformation();
    static ModelDataDefinition* LoadInstance(Model* model, PersistenceRecord *fields);
    static ModelDataDefinition* NewInstance(Model* model, std::string name = "");

protected: /// virtual protected method that must be overriden
    virtual bool _loadInstance(PersistenceRecord *fields);
    virtual void _saveInstance(PersistenceRecord *fields, bool saveDefaultValues);

protected: // could be overriden .
    virtual bool _check(std::string* errorMessage);
    virtual void _initBetweenReplications();
    virtual void _createInternalAndAttachedData();
    //virtual ParserChangesInformation* _getParserChangesInformation();

private:
    std::vector<Variable*>* _variables = new std::vector<Variable*>();
    std::vector<ModelComponent*>* _returnModels = new std::vector<ModelComponent*>();

    FSM_State* _initialState;
    FSM_State* _currentState;
};

#endif /* EFSM_H */

