// (C) 2010 Balp Allen
// Using LGPL, or any other OSI Licence

#include "llviewerprecompiledheaders.h"
#include "llviewercontrol.h"

#include <string>

void AutoCloseOOC(std::string &utf8text)
{
	std::string OOCOpen = gSavedSettings.getString("OOCOpenString");
	std::string OOCClose = gSavedSettings.getString("OOCCloseString");
	LL_DEBUGS("AutoOOC") << "AutoCloseOOC(" << utf8text << ")" << LL_ENDL;
	if (gSavedSettings.getBOOL("AutoCloseOOC"))
	{
		if (utf8text.find(OOCOpen) != std::string::npos && utf8text.find(OOCClose) == std::string::npos )
		{
			if(' ' == utf8text[utf8text.length() - 1])
			{
				utf8text += OOCClose;
			}
			else
			{
				utf8text += " " + OOCClose;
			}
		}
		LL_DEBUGS("AutoOOC") << "AutoCloseOOC(" << utf8text << "): after"
			<< LL_ENDL;

	}
}


