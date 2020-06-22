// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Flocking/MigratoryUrge.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMigratoryUrge() {}
// Cross Module References
	FLOCKING_API UClass* Z_Construct_UClass_AMigratoryUrge_NoRegister();
	FLOCKING_API UClass* Z_Construct_UClass_AMigratoryUrge();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Flocking();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AMigratoryUrge::StaticRegisterNativesAMigratoryUrge()
	{
	}
	UClass* Z_Construct_UClass_AMigratoryUrge_NoRegister()
	{
		return AMigratoryUrge::StaticClass();
	}
	struct Z_Construct_UClass_AMigratoryUrge_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MigratoryTargetVisual_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MigratoryTargetVisual;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMigratoryUrge_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Flocking,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMigratoryUrge_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MigratoryUrge.h" },
		{ "ModuleRelativePath", "MigratoryUrge.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMigratoryUrge_Statics::NewProp_MigratoryTargetVisual_MetaData[] = {
		{ "Category", "MigratoryUrge" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MigratoryUrge.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMigratoryUrge_Statics::NewProp_MigratoryTargetVisual = { "MigratoryTargetVisual", nullptr, (EPropertyFlags)0x0040000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMigratoryUrge, MigratoryTargetVisual), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMigratoryUrge_Statics::NewProp_MigratoryTargetVisual_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMigratoryUrge_Statics::NewProp_MigratoryTargetVisual_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMigratoryUrge_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMigratoryUrge_Statics::NewProp_MigratoryTargetVisual,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMigratoryUrge_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMigratoryUrge>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMigratoryUrge_Statics::ClassParams = {
		&AMigratoryUrge::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMigratoryUrge_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AMigratoryUrge_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMigratoryUrge_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMigratoryUrge_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMigratoryUrge()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMigratoryUrge_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMigratoryUrge, 2520586113);
	template<> FLOCKING_API UClass* StaticClass<AMigratoryUrge>()
	{
		return AMigratoryUrge::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMigratoryUrge(Z_Construct_UClass_AMigratoryUrge, &AMigratoryUrge::StaticClass, TEXT("/Script/Flocking"), TEXT("AMigratoryUrge"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMigratoryUrge);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
