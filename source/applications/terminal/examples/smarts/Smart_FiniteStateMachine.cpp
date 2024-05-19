/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Smart_FinitStateMachine.cpp
 * Author: rlcancian
 * 
 * Created on 7 de agosto de 2022, 12:26
 */

#include "Smart_FiniteStateMachine.h"


// you have to included need libs

// GEnSyS Simulator
#include "../../../../kernel/simulator/Simulator.h"

// Model Components
#include "../../../../plugins/components/Create.h"
#include "../../../../plugins/components/FiniteStateMachine.h"
#include "../../../../plugins/components/Dispose.h"
#include "../../../TraitsApp.h"
#include <iostream>

Smart_FiniteStateMachine::Smart_FiniteStateMachine() {
}

/**
 * This is the main function of the application. 
 * It instanciates the simulator, builds a simulation model and then simulate that model.
 */



int Smart_FiniteStateMachine::main(int argc, char** argv) {
	/*Simulator* genesys = new Simulator();
	this->setDefaultTraceHandlers(genesys->getTracer());
	// crete model
	Model* model = genesys->getModels()->newModel();
	PluginManager* plugins = genesys->getPlugins();
	Create* create1 = plugins->newInstance<Create>(model);*/

	Simulator* genesys = new Simulator();
	genesys->getTracer()->setTraceLevel(TraitsApp<GenesysApplication_if>::traceLevel);
	setDefaultTraceHandlers(genesys->getTracer());
	PluginManager* plugins = genesys->getPlugins();
	plugins->autoInsertPlugins("/mnt/HD_EXTERNO/computerScience/course/14ºFASE/modSim/new/Genesys-Simulator/autoloadplugins.txt");
	Model* model = genesys->getModels()->newModel();
	// crete model
	Create *create1 = plugins->newInstance<Create>(model);
    create1->setTimeBetweenCreationsExpression("1", Util::TimeUnit::hour);
	
	FiniteStateMachine* fsm1 = plugins->newInstance<FiniteStateMachine>(model);
	std::cout << fsm1->getName() << " ";
	std::cout << fsm1->show() << " ";
	Dispose* dispose1 = plugins->newInstance<Dispose>(model);


	// connect model components to create a "workflow"
	fsm1->CreateInternalData(fsm1);
	fsm1->show();
	fsm1->getInternalDataDefinition()->getName();
	fsm1->getInternalDataDefinition()->show();

	create1->getConnections()->insert(fsm1);
	fsm1->getConnections()->insert(dispose1);

    dispose1->setReportStatistics(true);

	// set options, save and simulate
	/*model->getSimulation()->setReplicationLength(60);
	model->save("./models/Smart_FinitStateMachine.gen");
	model->getSimulation()->start();*/

    ModelSimulation *simulation = model->getSimulation();
    simulation->setNumberOfReplications(3);
    simulation->setReplicationLength(30, Util::TimeUnit::hour);
    simulation->setReplicationReportBaseTimeUnit(Util::TimeUnit::hour);

    model->save("./models/Smart_FinitStateMachine.gen");
	simulation->start();

	delete genesys;
	return 0;
};

