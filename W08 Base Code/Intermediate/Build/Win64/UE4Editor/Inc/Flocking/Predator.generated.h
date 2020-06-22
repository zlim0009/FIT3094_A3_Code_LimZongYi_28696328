// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef FLOCKING_Predator_generated_h
#error "Predator.generated.h already included, missing '#pragma once' in Predator.h"
#endif
#define FLOCKING_Predator_generated_h

#define W08_Base_Code_Source_Flocking_Predator_h_15_SPARSE_DATA
#define W08_Base_Code_Source_Flocking_Predator_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapBegin(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define W08_Base_Code_Source_Flocking_Predator_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapBegin(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define W08_Base_Code_Source_Flocking_Predator_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPredator(); \
	friend struct Z_Construct_UClass_APredator_Statics; \
public: \
	DECLARE_CLASS(APredator, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Flocking"), NO_API) \
	DECLARE_SERIALIZER(APredator)


#define W08_Base_Code_Source_Flocking_Predator_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAPredator(); \
	friend struct Z_Construct_UClass_APredator_Statics; \
public: \
	DECLARE_CLASS(APredator, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Flocking"), NO_API) \
	DECLARE_SERIALIZER(APredator)


#define W08_Base_Code_Source_Flocking_Predator_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APredator(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APredator) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APredator); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APredator); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APredator(APredator&&); \
	NO_API APredator(const APredator&); \
public:


#define W08_Base_Code_Source_Flocking_Predator_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APredator(APredator&&); \
	NO_API APredator(const APredator&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APredator); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APredator); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APredator)


#define W08_Base_Code_Source_Flocking_Predator_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComponent() { return STRUCT_OFFSET(APredator, CollisionComponent); }


#define W08_Base_Code_Source_Flocking_Predator_h_12_PROLOG
#define W08_Base_Code_Source_Flocking_Predator_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	W08_Base_Code_Source_Flocking_Predator_h_15_PRIVATE_PROPERTY_OFFSET \
	W08_Base_Code_Source_Flocking_Predator_h_15_SPARSE_DATA \
	W08_Base_Code_Source_Flocking_Predator_h_15_RPC_WRAPPERS \
	W08_Base_Code_Source_Flocking_Predator_h_15_INCLASS \
	W08_Base_Code_Source_Flocking_Predator_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define W08_Base_Code_Source_Flocking_Predator_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	W08_Base_Code_Source_Flocking_Predator_h_15_PRIVATE_PROPERTY_OFFSET \
	W08_Base_Code_Source_Flocking_Predator_h_15_SPARSE_DATA \
	W08_Base_Code_Source_Flocking_Predator_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	W08_Base_Code_Source_Flocking_Predator_h_15_INCLASS_NO_PURE_DECLS \
	W08_Base_Code_Source_Flocking_Predator_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FLOCKING_API UClass* StaticClass<class APredator>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID W08_Base_Code_Source_Flocking_Predator_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
