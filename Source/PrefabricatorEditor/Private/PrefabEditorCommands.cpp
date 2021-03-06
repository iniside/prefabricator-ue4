//$ Copyright 2015-19, Code Respawn Technologies Pvt Ltd - All Rights Reserved $//

#include "PrefabEditorCommands.h"

#include "Prefab/PrefabTools.h"
#include "PrefabEditorStyle.h"

#include "Framework/Commands/Commands.h"
#include "Framework/Commands/UIAction.h"
#include "Framework/Commands/UICommandList.h"
#include "UObject/Object.h"
#include "PrefabricatorEditorModule.h"

#define LOCTEXT_NAMESPACE "ContentBrowser"

FPrefabricatorCommands::FPrefabricatorCommands() : TCommands<FPrefabricatorCommands>(
	TEXT("Prefabricator"),
	NSLOCTEXT("Prefabricator", "Prefabricator", "Prefabricator"),
	NAME_None,
	FPrefabEditorStyle::GetStyleSetName())
{
}

void FPrefabricatorCommands::RegisterCommands() {
	UI_COMMAND(CreatePrefab, "Create Prefab (from selection)", "Create a new prefab from selection", EUserInterfaceActionType::Button, FInputChord(EKeys::Enter));

	LevelMenuActionList = MakeShareable(new FUICommandList);

	LevelMenuActionList->MapAction(
		CreatePrefab,
		FExecuteAction::CreateStatic(&FPrefabTools::CreatePrefab),
		FCanExecuteAction::CreateStatic(&FPrefabTools::CanCreatePrefab)
	);

	UI_COMMAND(AllowOnlyPrefabSelection, "Select Only Prefabs", "Allow only prefabs to be selected", EUserInterfaceActionType::ToggleButton, FInputChord(EKeys::NumPadOne));

	LevelMenuActionList->MapAction(
		AllowOnlyPrefabSelection
		, FExecuteAction::CreateStatic(&FPrefabTools::SetAllowOnlyPrefabSelection)
		, FCanExecuteAction()
		, FIsActionChecked::CreateStatic(&FPrefabTools::GetAllowOnlyPrefabSelection)
	);


	UI_COMMAND(CreatePrefabZeroPivot, "Create Prefab On Zero Oirgin", "Create New prefab on Zeroed pivot", EUserInterfaceActionType::Button, FInputChord(EKeys::NumPadTwo));

	LevelMenuActionList->MapAction(
		CreatePrefabZeroPivot
		, FExecuteAction::CreateStatic(&FPrefabTools::CreatePrefabOnZeroPivot)
		, FCanExecuteAction::CreateStatic(&FPrefabTools::CanCreatePrefab)
	);
}


#undef LOCTEXT_NAMESPACE

