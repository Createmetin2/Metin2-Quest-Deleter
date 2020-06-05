#pragma once
#include <unordered_set>
#include <string>

namespace QuestDeleter
{
	std::string GetPath();
	void Process(const std::string& _DelString);
	void WriteVersion();
	void PrintDeletedCount();
}