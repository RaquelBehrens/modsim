/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Smart_Record.cpp
 * Author: rlcancian
 * 
 * Created on 3 de Setembro de 2019, 18:34
 */

#include "Smart_Record.h"

// you have to included need libs

#include "../../../../kernel/simulator/EntityType.h"
#include "../../../../kernel/simulator/ModelSimulation.h"
#include "../../../../kernel/simulator/Simulator.h"

#include "../../../../plugins/components/Assign.h"
#include "../../../../plugins/components/Create.h"
#include "../../../../plugins/components/Delay.h"
#include "../../../../plugins/components/Dispose.h"
#include "../../../../plugins/components/Record.h"
#include "../../../TraitsApp.h"

Smart_Record::Smart_Record() {
}

/**
 * This is the main function of the application. 
 * It instanciates the simulator, builds a simulation model and then simulate that model.
 */
int Smart_Record::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	genesys->getTracer()->setTraceLevel(TraitsApp<GenesysApplication_if>::traceLevel);
	setDefaultTraceHandlers(genesys->getTracer());
	PluginManager* plugins = genesys->getPlugins();
	plugins->autoInsertPlugins("autoloadplugins.txt");
	Model* model = genesys->getModels()->newModel();
	// create model

    EntityType* entityType = new EntityType(model, "Person");
    Create* create = new Create(model);
    create->setDescription("Enter Store");
    create->setEntityType(entityType);
    create->setTimeBetweenCreationsExpression("EXPO(5)");
    create->setTimeUnit(Util::TimeUnit::minute);

    Assign* assign = new Assign(model);
    assign->setDescription("Mark Entry Time");
    Assignment* assignment = new Assignment("timeIn", "tnow");
    assign->getAssignments()->insert(assignment);
    new Attribute(model, "timeIn");
    create->getConnections()->insert(assign);

    Delay* delay = new Delay(model);
    delay->setDescription("Browse");
    delay->setDelayExpression("tria(3, 7, 11)");
    delay->setDelayTimeUnit(Util::TimeUnit::minute);
    assign->getConnections()->insert(delay);

    Record* record = new Record(model);
    record->setDescription("Time in Store");
    record->setExpression("timeIn");
    record->setExpressionName("Time in Store");
    delay->getConnections()->insert(record);

    Dispose* dispose = new Dispose(model);
    dispose->setDescription("Leave Store");
    record->getConnections()->insert(dispose);

    ModelSimulation* simulation = model->getSimulation();
    simulation->setReplicationLength(10);
    simulation->setReplicationLengthTimeUnit(Util::TimeUnit::minute);
    simulation->setNumberOfReplications(300);
    simulation->setWarmUpPeriod(0.05);
    simulation->setWarmUpPeriodTimeUnit(Util::TimeUnit::minute);
    model->save("./models/Smart_Record.gen");
    model->getSimulation()->start();
    while (model->getSimulation()-> isPaused());
    for (int i=0;i < 1e9;i++);
    delete genesys;
    return 0;
};
