// Author: Antonio Sidenko (Tonetfal), September 2025

#pragma once

#include "Modules/ModuleManager.h"

#define DEFINE_LOG_CATEGORY_INLINE(CategoryName, DefaultVerbosity, CompileTimeVerbosity) \
	inline struct FLogCategory##CategoryName : public FLogCategory<ELogVerbosity::DefaultVerbosity, ELogVerbosity::CompileTimeVerbosity> \
	{ \
		FORCEINLINE FLogCategory##CategoryName() : FLogCategory(TEXT(#CategoryName)) {} \
	} CategoryName;

template <ELogVerbosity::Type InDefaultVerbosity, ELogVerbosity::Type InCompileTimeVerbosity>
class FCVarDrivenLogVerbosity
{
public:
	using ThisClass = FCVarDrivenLogVerbosity;

public:
	FCVarDrivenLogVerbosity(FAutoConsoleVariableRef& CVar,
		FLogCategory<InDefaultVerbosity, InCompileTimeVerbosity>& InLogCategory)
			: LogCategory(InLogCategory)
	{
		CVar->OnChangedDelegate().AddRaw(this, &ThisClass::OnCVarChanged);
		OnCVarChanged(CVar->AsVariable());
	}

	void OnCVarChanged(IConsoleVariable* CVar)
	{
		const bool bIsEnabled = CVar->GetBool();
		const ELogVerbosity::Type NewVerbosity = bIsEnabled ? ELogVerbosity::Type::All : InDefaultVerbosity;
		LogCategory.SetVerbosity(NewVerbosity);
	}

private:
	FLogCategory<InDefaultVerbosity, InCompileTimeVerbosity>& LogCategory;
};
