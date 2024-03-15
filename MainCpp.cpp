#include "MainCpp.h"

int main()
{
	CTOOL cTool;
	CCAL cCal;
	CCAN cCan;

	//start Announce
	// std::cout << "start main" << std::endl;
	char sLog[64] = {0};
	sprintf(sLog,"Start Main");
	cTool.OutputLog(sLog);
	sleep(2);

	//SWからシェルの呼び出しサンプル
	// system("bash echo.sh");

	//SWからlsコマンドを実行して中身を出力
	// cTool.OutputCurrentFileName();

	//test main
	cCal.CalTestMain();

	//CanTest
	CCAN::ST_CANMESSAGE StCanMessage;
	cCan.CanTxMain(StCanMessage);



	return 0;
}
