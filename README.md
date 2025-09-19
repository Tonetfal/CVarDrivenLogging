## Installation

Clone the repository in your project's Plugin directory.

## Usage

```cpp
// Header file

DEFINE_LOG_CATEGORY_INLINE(LogInteraction, Warning, All);

namespace MyGame
{
	inline bool bDebugInteraction = false;
	inline FAutoConsoleVariableRef CVarDebugInteraction(
		TEXT("MyGame.Interaction.Debug"),
		bDebugInteraction,
		TEXT("")
	);

	inline FMESS_CVarDrivenLogVerbosity CVarDriverInteractionLogging(CVarDebugInteraction, LogInteraction);
}
```

When MyGame.Interaction.Debug CVar is set to 0, LogInteraction will use the default defined log category in the DEFINE_LOG_CATEGORY_INLINE (warning). When it's set to 1, it'll set it to VeryVerbose.

Note that the lowest verbosity is capped by the last argument in the DEFINE_LOG_CATEGORY_INLINE. Make sure to have it set to All if you want to have VeryVerbose as the lowest verbosity.
