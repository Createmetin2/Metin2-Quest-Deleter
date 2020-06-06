#pragma once
#include <string>

namespace QuestDeleter
{
	std::string GetPath();
	void Process(const char* QuestName);
	void WriteVersion();
	void PrintDeletedCount();
}