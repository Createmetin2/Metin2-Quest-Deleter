#include "QuestDeleter.h"

#if defined(__FreeBSD__)
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
static constexpr auto Slash = "/";
#else
#include <filesystem>
namespace fs = std::filesystem;
static constexpr auto Slash = "\\";
#endif

/*Setting*/
static constexpr auto VersionSTR = "1.3";
static constexpr auto DELETE_ORIGIN_FILE = false; // delete (lua/quest) file
static std::uint16_t U_DEL_COUNT;

namespace QuestDeleter
{
	/*Operation*/
	void Process(const char* QuestName)
	{			
		static auto SDelPath = GetPath();
		if (SDelPath.empty())
			return;

		static std::uint16_t stage = 1;
		printf("\n*******Stage %hu Started*******\n\n", stage);

		const auto _DelString(Slash + std::string(QuestName));

		for (const auto& FileIter : fs::recursive_directory_iterator(SDelPath)) {
			const auto& PathString = FileIter.path().u8string();

			if (PathString.find(_DelString + ".") == std::string::npos &&
				_DelString.compare(std::string_view(PathString).substr(PathString.length() - _DelString.length())))
				continue;

			if (!fs::is_directory(PathString) && fs::remove(PathString)) {
				printf("%s\n", PathString.c_str());
				U_DEL_COUNT++;
			}
		}

		printf("\n*******Stage %hu Finished*******\n", stage++);
	}

	/*Path*/
	std::string GetPath()
	{
		auto path(fs::current_path().u8string() + Slash + "quest");
		if (!DELETE_ORIGIN_FILE)
			path += Slash + std::string("object");

		if (!fs::is_directory(path)) {
			printf("Unable to open: %s", path.c_str());
			path.clear();
		}

		return path;
	}

	/*Version*/
	void WriteVersion()
	{
		printf("blackdragonx61\n");
		printf("Ver: %s", VersionSTR);
		printf("\n\n");
	}

	/*Deleted*/
	void PrintDeletedCount()
	{
		printf("\n");
		printf("%hu file(s) deleted...", U_DEL_COUNT);
		printf("\n\n");
	}
}