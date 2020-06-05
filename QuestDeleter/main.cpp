#include "QuestDeleter.h"

int main(int argc, char** argv)
{
	for (int i = 1; i < argc; ++i)
		QuestDeleter::Process(argv[i]);

	if (argc < 2)
		printf("You need to write a quest name!");

	QuestDeleter::PrintDeletedCount();
	QuestDeleter::WriteVersion();

	return 0;
}