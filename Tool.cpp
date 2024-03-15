#include "Tool.h"
using namespace std;

bool CTOOL::OutputLog(char* sLog)
{
	openlog("MainCpp", LOG_PERROR|LOG_PID,LOG_USER);
	syslog(LOG_INFO, "%s", sLog);
	closelog();

	return true;
}

bool CTOOL::OutputCurrentFileName(void)
{
    FILE* pipe = popen("ls", "r");
    if (!pipe) {
        std::cerr << "popen failed!" << std::endl;
        return 1;
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != NULL)
	{
        // 改行文字を削除して出力
        buffer[strlen(buffer) - 1] = '\0';
        std::cout << buffer << std::endl;
    }

    pclose(pipe);

	return true;
}