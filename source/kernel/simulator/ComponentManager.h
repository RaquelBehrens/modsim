/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ComponentManager.h
 * Author: rafael.luiz.cancian
 *
 * Created on 28 de Maio de 2019, 10:41
 */

#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H

#include "ModelComponent.h"
#include "SourceModelComponent.h"

//namespace GenesysKernel {
//class Model;

/*!
 * ComponentManager allows to insert, access, find, remove and over Models
 */
class ComponentManager {
public:
	ComponentManager(Model* model);
	virtual ~ComponentManager() = default;
public:
	bool insert(ModelComponent* comp);
	void remove(ModelComponent* comp);
	ModelComponent* find(std::string name);
	ModelComponent* find(Util::identification id);
	void clear();
public:
	unsigned int getNumberOfComponents();
	std::list<ModelComponent*>::iterator begin();
	std::list<ModelComponent*>::iterator end();
	ModelComponent* front();
	ModelComponent* next();
	bool hasChanged() const;
	void setHasChanged(bool _hasChanged);
public:
	std::list<SourceModelComponent*>* getSourceComponents();
	std::list<ModelComponent*>* getTransferInComponents();
	std::list<ModelComponent*>* getAllComponents() const;
private:
	List<ModelComponent*>* _components;
	Model* _parentModel;
	bool _hasChanged = false;
	std::list<ModelComponent*>::iterator _componentIterator;
};
//namespace\\}
#endif /* COMPONENTMANAGER_H */

