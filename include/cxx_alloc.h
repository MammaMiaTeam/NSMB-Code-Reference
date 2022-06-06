#pragma once
#include "nitro_if.h"
#include <new>


extern "C" {

	struct DestructorChain {

		DestructorChain* next;
		void* destructor;
		void* object;

	};

	DestructorChain** __global_destructor_chain;

	void __destroy_global_chain(void);

	void __call_static_initializers(void);

	void* __register_global_object(void* object, void* destructor, DestructorChain* regmem);

	void __cxa_vec_delete(void* array_address, size_t element_size, size_t padding_size, void* destructor);

	void __cxa_vec_cleanup(void* array_address, size_t element_count, size_t element_size, void* destructor);

	void __cxa_vec_dtor(void* array_address, size_t element_count, size_t element_size, void* destructor);

	void* __cxa_vec_ctor(void* array_address, size_t element_count, size_t element_size, void* constructor, void* destructor);

	int __cxa_vec_new(size_t element_count, size_t element_size, size_t padding_size, void* constructor, void* destructor);

	/*
	*	Use these to define, initialize and register global objects
	*/

	// Store the overlayID
	struct DestructorChainExt : DestructorChain {

		u16 overlayID;
		u8 reserved[2];

	};

	// Define a global object
#define CXX_OBJ(type, name) \
	static inline void __dtor_##name(type* obj) { \
		obj->~type(); \
	} \
	DestructorChain name##_dc; \
	type name

	// Define a global object with the same lifetime as a given overlay
#define CXX_OBJ_OV(type, name) \
	static inline void __dtor_##name(type* obj) { \
		obj->~type(); \
	} \
	DestructorChainExt name##_dc; \
	type name

	// Initialize and register a global object
#define CXX_OBJ_INIT(name) \
	new (&name) decltype(name); \
	__register_global_object(&name, reinterpret_cast<void*>(&__dtor_##name), &name##_dc)

	// Initialize and register a global object with the same lifetime as the given overlay
#define CXX_OBJ_INIT_OV(ovID, name) \
	CXX_OBJ_INIT(name); \
	name##_dc.overlayID = ovID
	
}
