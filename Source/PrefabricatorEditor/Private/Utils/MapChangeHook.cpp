//$ Copyright 2015-18, Code Respawn Technologies Pvt Ltd - All Rights Reserved $//

#include "Utils/MapChangeHook.h"
#include "LevelEditor.h"
#include "ModuleManager.h"
#include "PrefabEditorTools.h"

DEFINE_LOG_CATEGORY_STATIC(LogMapChangeHook, Log, All);

void FMapChangeHook::Initialize()
{
	FLevelEditorModule& LevelEditorModule = FModuleManager::GetModuleChecked<FLevelEditorModule>("LevelEditor");
	CallbackHandle = LevelEditorModule.OnMapChanged().AddRaw(this, &FMapChangeHook::OnMapChanged);
}

void FMapChangeHook::Release()
{
	FLevelEditorModule& LevelEditorModule = FModuleManager::GetModuleChecked<FLevelEditorModule>("LevelEditor");
	LevelEditorModule.OnMapChanged().Remove(CallbackHandle);
}

void FMapChangeHook::OnMapChanged(UWorld* World, EMapChangeType MapChangeType)
{
	FPrefabEditorTools::ReloadPrefabsInLevel(World);
}
