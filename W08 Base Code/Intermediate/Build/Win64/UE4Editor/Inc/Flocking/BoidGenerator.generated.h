// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FLOCKING_BoidGenerator_generated_h
#error "BoidGenerator.generated.h already included, missing '#pragma once' in BoidGenerator.h"
#endif
#define FLOCKING_BoidGenerator_generated_h

#define W08_Base_Code_Source_Flocking_BoidGenerator_h_17_SPARSE_DATA
#define W08_Base_Code_Source_Flocking_BoidGenerator_h_17_RPC_WRAPPERS
#define W08_Base_Code_Source_Flocking_BoidGenerator_h_17_RPC_WRAPPERS_NO_PURE_DECLS
#define W08_Base_Code_Source_Flocking_BoidGenerator_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABoidGenerator(); \
	friend struct Z_Construct_UClass_ABoidGenerator_Statics; \
public: \
	DECLARE_CLASS(ABoidGenerator, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Flocking"), NO_API) \
	DECLARE_SERIALIZER(ABoidGenerator)


#define W08_Base_Code_Source_Flocking_BoidGenerator_h_17_INCLASS \
private: \
	static void StaticRegisterNativesABoidGenerator(); \
	friend struct Z_Construct_UClass_ABoidGenerator_Statics; \
public: \
	DECLARE_CLASS(ABoidGenerator, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Flocking"), NO_API) \
	DECLARE_SERIALIZER(ABoidGenerator)


#define W08_Base_Code_Source_Flocking_BoidGenerator_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABoidGenerator(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABoidGenerator) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoidGenerator); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoidGenerator); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABoidGenerator(ABoidGenerator&&); \
	NO_API ABoidGenerator(const ABoidGenerator&); \
public:


#define W08_Base_Code_Source_Flocking_BoidGenerator_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABoidGenerator(ABoidGenerator&&); \
	NO_API ABoidGenerator(const ABoidGenerator&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoidGenerator); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoidGenerator); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABoidGenerator)


#define W08_Base_Code_Source_Flocking_BoidGenerator_h_17_PRIVATE_PROPERTY_OFFSET
#define W08_Base_Code_Source_Flocking_BoidGenerator_h_14_PROLOG
#define W08_Base_Code_Source_Flocking_BoidGenerator_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	W08_Base_Code_Source_Flocking_BoidGenerator_h_17_PRIVATE_PROPERTY_OFFSET \
	W08_Base_Code_Source_Flocking_BoidGenerator_h_17_SPARSE_DATA \
	W08_Base_Code_Source_Flocking_BoidGenerator_h_17_RPC_WRAPPERS \
	W08_Base_Code_Source_Flocking_BoidGenerator_h_17_INCLASS \
	W08_Base_Code_Source_Flocking_BoidGenerator_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define W08_Base_Code_Source_Flocking_BoidGenerator_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	W08_Base_Code_Source_Flocking_BoidGenerator_h_17_PRIVATE_PROPERTY_OFFSET \
	W08_Base_Code_Source_Flocking_BoidGenerator_h_17_SPARSE_DATA \
	W08_Base_Code_Source_Flocking_BoidGenerator_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	W08_Base_Code_Source_Flocking_BoidGenerator_h_17_INCLASS_NO_PURE_DECLS \
	W08_Base_Code_Source_Flocking_BoidGenerator_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FLOCKING_API UClass* StaticClass<class ABoidGenerator>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID W08_Base_Code_Source_Flocking_BoidGenerator_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
