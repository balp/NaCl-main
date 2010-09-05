// (C) 2010 Balp Allen
// Using LGPL, or any other OSI Licence

#include "llviewerprecompiledheaders.h"
#include "llviewercontrol.h"

#include <string>

void AutoCloseOOC(std::string &utf8text)
{
	LL_DEBUGS("_nacl_Chat") << "AutoCloseOOC(" << utf8text << ")" << LL_ENDL;
	LLCachedControl<bool> autoclose(gSavedSettings, "_nacl_AutoCloseOOC");
	if (autoclose)
	{
		LLCachedControl<std::string> OOCOpen(gSavedSettings, "_nacl_OOCOpenString");
		LLCachedControl<std::string> OOCClose(gSavedSettings, "_nacl_OOCCloseString");
		if (utf8text.find(OOCOpen) != std::string::npos && utf8text.find(OOCClose) == std::string::npos )
		{
			if(' ' == utf8text[utf8text.length() - 1])
			{
				utf8text += reinterpret_cast<std::string&>(OOCClose);
			}
			else
			{
				utf8text += " " + reinterpret_cast<std::string&>(OOCClose);
			}
		}
		LL_DEBUGS("_nacl_Chat") << "AutoCloseOOC(" << utf8text << "): after"
			<< LL_ENDL;

	}
}

void ExpandMUPose(std::string &utf8text)
{
	LL_DEBUGS("_nacl_Chat") << "ExpandMUPose(" << utf8text << ")" << LL_ENDL;
	LLCachedControl<bool> muexpand(gSavedSettings, "_nacl_ExpandMUPose");
	if (muexpand)
	{
		if(0 == utf8text.compare(0,2,": ")) {
			utf8text.replace(0,1,"/me");
		} else if(0 == utf8text.compare(0,2,":'")) {
			utf8text.replace(0,1,"/me");
		}
		LL_DEBUGS("_nacl_Chat") << "ExpandMUPose: to " << utf8text << LL_ENDL;
	}
}
