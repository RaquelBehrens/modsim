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
	/*!
	 * \brief insert
	 * \param comp
	 * \return
	 */
	bool insert(ModelComponent* comp);
	/*!
	/*! * \brief remove
	/*! * \param comp
	/*! */
	void remove(ModelComponent* comp);
	/*!
	 * \brief find
	 * \param name
	 * \return
	 */
	ModelComponent* find(std::string name);
	/*!
	 * \brief find
	 * \param id
	 * \return
	 */
	ModelComponent* find(Util::identification id);
	/*!
	/*! * \brief clear
	*/
	void clear();
public:
	/*!
	 * \brief getNumberOfComponents
	 * \return
	 */
	unsigned int getNumberOfComponents();
	/*!
	 * \brief begin
	 * \return
	 */
	std::list<ModelComponent*>::iterator begin();
	/*!
	 * \brief end
	 * \return
	 */
	std::list<ModelComponent*>::iterator end();
	/*!
	 * \brief front
	 * \return
	 */
	ModelComponent* front();
	/*!
	 * \brief next
	 * \return
	 */
	ModelComponent* next();
	/*!
	/*! * \brief hasChanged
	/*! * \return
	*/
	bool hasChanged() const;
	/*!
	 * \brief setHasChanged
	 * \param _hasChanged
	 */
	void setHasChanged(bool _hasChanged);
public:
	/*!
	 * \brief getSourceComponents
	 * \return
	 */
	std::list<SourceModelComponent*>* getSourceComponents();
	/*!
	 * \brief getTransferInComponents
	 * \return
	 */
	std::list<ModelComponent*>* getTransferInComponents();
	/*!
	 * \brief getAllComponents
	 * \return
	 */
	std::list<ModelComponent*>* getAllComponents() const;
private:
	List<ModelComponent*>* _components;
	Model* _parentModel;
	bool _hasChanged = false;
	std::list<ModelComponent*>::iterator _componentIterator;
};
//namespace\\}
#endif /* COMPONENTMANAGER_H */

