// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Flocking/BoidGenerator.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoidGenerator() {}
// Cross Module References
	FLOCKING_API UClass* Z_Construct_UClass_ABoidGenerator_NoRegister();
	FLOCKING_API UClass* Z_Construct_UClass_ABoidGenerator();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Flocking();
// End Cross Module References
	void ABoidGenerator::StaticRegisterNativesABoidGenerator()
	{
	}
	UClass* Z_Construct_UClass_ABoidGenerator_NoRegister()
	{
		return ABoidGenerator::StaticClass();
	}
	struct Z_Construct_UClass_ABoidGenerator_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABoidGenerator_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Flocking,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidGenerator_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BoidGenerator.h" },
		{ "ModuleRelativePath", "BoidGenerator.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABoidGenerator_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABoidGenerator>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABoidGenerator_Statics::ClassParams = {
		&ABoidGenerator::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABoidGenerator_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidGenerator_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABoidGenerator()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABoidGenerator_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABoidGenerator, 3969920152);
	template<> FLOCKING_API UClass* StaticClass<ABoidGenerator>()
	{
		return ABoidGenerator::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABoidGenerator(Z_Construct_UClass_ABoidGenerator, &ABoidGenerator::StaticClass, TEXT("/Script/Flocking"), TEXT("ABoidGenerator"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABoidGenerator);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
