#pragma once
#include "common.h"


struct ProcessNode {

	ProcessNode* previous;
	ProcessNode* next;
	Base* base;

	//0204d57c
	sym void unlink() __body

};
NTR_SIZE_GUARD(ProcessNode, 0xC);


struct PriorityNode : public ProcessNode {

	u16 currentPriority;
	u16 sortPriority;

	//0204d560
	sym void unlink() __body

};
NTR_SIZE_GUARD(PriorityNode, 0x10);


struct SceneNode {

	SceneNode* parent;
	SceneNode* firstChild;
	SceneNode* previous;
	SceneNode* next;
	Base* object;

	//02043b58
	sym SceneNode() __body

	//02043b40
	sym void reset() __body

	//02043a2c
	//returns the next tree's node or (if none could be found) the next parent's next node. May return null if no parent with siblings exists.
	sym SceneNode* getNext() __rbody

	//020439f0
	//Traverses the tree upwards and returns the next parent's next node. If no parent has siblings anymore, null is returned.
	sym SceneNode* getParentNext() __rbody

};
NTR_SIZE_GUARD(SceneNode, 0x14);


struct LinkedList {

	ProcessNode* first;
	ProcessNode* last;

	//020438e8
	sym bool append(ProcessNode* node) __rbody

	//02043920
	sym	bool remove(ProcessNode* node) __rbody

	//020438b0
	sym bool prepend(ProcessNode* node) __rbody

	//02043990
	sym bool insert(ProcessNode* node, ProcessNode* previous) __rbody

	//0204d428
	sym ProcessNode* getNodeByID(u32 id) __rbody


};
NTR_SIZE_GUARD(LinkedList, 0x8);


struct ProcessList : public LinkedList {

	BaseProcessFunction executor;

	//0204d46c
	//Traverses the whole list and calls the executor on every node. Always returns true.
	sym bool execute() __rbody

};
NTR_SIZE_GUARD(ProcessList, 0x10);


struct ProcessSet : public ProcessList {

	//0204d4e4
	sym bool add(PriorityNode* node) __rbody

};
NTR_SIZE_GUARD(ProcessSet, 0x10);


struct SceneGraph {

	SceneNode* root;
	BaseProcessFunction executor;

	//02043acc
	//Adds child to the scene graph as a child of parent. returns true if the node was added successfully, false if node is null or if parent is null (indicating the root node) but root is already set.
	sym bool addChild(SceneNode* child, SceneNode* parent) __rbody

	//02043a54
	//Removes the child from the scene graph. returns true only if child has no children itself, false otherwise.
	sym bool removeChild(SceneNode* child) __rbody

	//0204d7b4
	//Traverses the graph and calls the executor on every node. Always returns true.
	sym bool execute() __rbody

};
NTR_SIZE_GUARD(SceneGraph, 0xC);
