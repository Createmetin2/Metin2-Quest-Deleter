#pragma once
#include <unordered_set>
#include <string>

namespace QuestDeleter
{
	std::string GetPath();
	void Process(const char* QuestName);
	void WriteVersion();
	void PrintDeletedCount();
}