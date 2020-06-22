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
#ifdef FLOCKING_Boid_generated_h
#error "Boid.generated.h already included, missing '#pragma once' in Boid.h"
#endif
#define FLOCKING_Boid_generated_h

#define W08_Base_Code_Source_Flocking_Boid_h_18_SPARSE_DATA
#define W08_Base_Code_Source_Flocking_Boid_h_18_RPC_WRAPPERS \
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


#define W08_Base_Code_Source_Flocking_Boid_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
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


#define W08_Base_Code_Source_Flocking_Boid_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABoid(); \
	friend struct Z_Construct_UClass_ABoid_Statics; \
public: \
	DECLARE_CLASS(ABoid, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Flocking"), NO_API) \
	DECLARE_SERIALIZER(ABoid)


#define W08_Base_Code_Source_Flocking_Boid_h_18_INCLASS \
private: \
	static void StaticRegisterNativesABoid(); \
	friend struct Z_Construct_UClass_ABoid_Statics; \
public: \
	DECLARE_CLASS(ABoid, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Flocking"), NO_API) \
	DECLARE_SERIALIZER(ABoid)


#define W08_Base_Code_Source_Flocking_Boid_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABoid(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABoid) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoid); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoid); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABoid(ABoid&&); \
	NO_API ABoid(const ABoid&); \
public:


#define W08_Base_Code_Source_Flocking_Boid_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABoid(ABoid&&); \
	NO_API ABoid(const ABoid&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoid); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoid); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABoid)


#define W08_Base_Code_Source_Flocking_Boid_h_18_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__BoidVisual() { return STRUCT_OFFSET(ABoid, BoidVisual); } \
	FORCEINLINE static uint32 __PPO__CollisionComponent() { return STRUCT_OFFSET(ABoid, CollisionComponent); }


#define W08_Base_Code_Source_Flocking_Boid_h_15_PROLOG
#define W08_Base_Code_Source_Flocking_Boid_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	W08_Base_Code_Source_Flocking_Boid_h_18_PRIVATE_PROPERTY_OFFSET \
	W08_Base_Code_Source_Flocking_Boid_h_18_SPARSE_DATA \
	W08_Base_Code_Source_Flocking_Boid_h_18_RPC_WRAPPERS \
	W08_Base_Code_Source_Flocking_Boid_h_18_INCLASS \
	W08_Base_Code_Source_Flocking_Boid_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define W08_Base_Code_Source_Flocking_Boid_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	W08_Base_Code_Source_Flocking_Boid_h_18_PRIVATE_PROPERTY_OFFSET \
	W08_Base_Code_Source_Flocking_Boid_h_18_SPARSE_DATA \
	W08_Base_Code_Source_Flocking_Boid_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	W08_Base_Code_Source_Flocking_Boid_h_18_INCLASS_NO_PURE_DECLS \
	W08_Base_Code_Source_Flocking_Boid_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FLOCKING_API UClass* StaticClass<class ABoid>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID W08_Base_Code_Source_Flocking_Boid_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
