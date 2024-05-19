/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ConnectionManager.h
 * Author: rlcancian
 *
 * Created on 1 de Julho de 2019, 18:39
 */

#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <utility>
#include <map>
#include "../util/List.h"

//namespace GenesysKernel {

class ModelComponent;

//typedef unsigned int ConnectionPort; 
struct ConnectionChannel { /*< actually a port is only a uint, but it could be more complex, including type, presence or absence of data, etc */
	unsigned int portNumber = 0;
	std::string portDescription = "";
};


/*!
 * Defines a connection between two or more ModelComponents. 
 * A (receiver) component's inputPort may receive connection from one or more (sender) components' outputPorts.
 * A (sender) component's outputPort is connected to one and only one (receiver) component's inputPort.
 */
struct Connection {
	ModelComponent* component;
	ConnectionChannel channel;
};

/*!
 * ConnectionManager defines how a ModelComponent is output connected to none, one or more following ModelComponents. It has a list of nextConnections, where each Connection is a pair, defining the next ModelComponent and an input port on that component (usefull only if the next component has more than one input). The number of the output conection is its rank in the nextConnections list. Min and max number of input and output connectons can be defined.
 */
class ConnectionManager {
public:
	ConnectionManager();
	virtual ~ConnectionManager() = default;
public:
	unsigned int size();
	//ModelComponent* front(); /*!< DEPRECTED. Use  frontConnection instead */
	//ModelComponent* atRank(unsigned int rank); /*!< DEPRECTED. Use  getConnectionAtRank instead */
	Connection* getFrontConnection();
	Connection* getConnectionAtPort(unsigned int rank);
	void insert(ModelComponent* component, unsigned int inputPortNumber = 0); /*!< Insert a new connection by specifying the destnation component and optionally an input port, if not 0*/
	void insert(Connection* connection);
	void insertAtPort(unsigned int port, Connection* connection);
	void remove(Connection* connection);
	void removeAtPort(unsigned int port);
	std::map<unsigned int, Connection*>* connections() const;
	//void setCurrentOutputConnections(unsigned int _currentOutputConnections);
	unsigned int getCurrentOutputConnectionsSize() const;
	void setMaxOutputConnections(unsigned int _maxOutputConnections);
	unsigned int getMaxOutputConnections() const;
	void setMinOutputConnections(unsigned int _minOutputConnections);
	unsigned int getMinOutputConnections() const;
	//void setCurrentInputConnections(unsigned int _currentInputConnections);
	unsigned int getCurrentInputConnectionsSize() const;
	void setMaxInputConnections(unsigned int _maxInputConnections);
	unsigned int getMaxInputConnections() const;
	void setMinInputConnections(unsigned int _minInputConnections);
	unsigned int getMinInputConnections() const;
private:
	std::map<unsigned int, Connection*>* _nextConnections = new std::map<unsigned int, Connection*>();
	unsigned int _minInputConnections = 0;
	unsigned int _maxInputConnections = 0;
	unsigned int _currentInputConnections = 0;
	unsigned int _minOutputConnections = 0;
	unsigned int _maxOutputConnections = 0;
};
//namespace\\}
#endif /* CONNECTIONMANAGER_H */

